/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_SWITCH_HPP
#define PHOENIX_STATEMENT_SWITCH_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/compose.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/make_expr.hpp>

namespace boost { namespace phoenix
{
    struct switch_case_tag {};
    struct switch_default_tag {};

    namespace detail
    {
        struct case_label
            : proto::terminal<proto::_>
        {};

        struct case_statement
            : proto::binary_expr<switch_case_tag, case_label, eval_grammar>
        {};

        struct default_statement
            : proto::unary_expr<switch_default_tag, eval_grammar>
        {};

        struct switch_size
            : proto::or_<
                proto::when<
                    proto::comma<switch_size, proto::_>
                  , mpl::next<switch_size(proto::_left)>()
                >
              , proto::when<proto::_, mpl::int_<1>()>
            >
        {};

        struct switch_has_default
            : proto::or_<
                proto::when<
                    proto::comma<switch_size, case_statement>
                  , mpl::false_()
                >
              , proto::when<
                    proto::comma<switch_size, default_statement>
                  , mpl::true_()
                >
              , proto::when<
                    case_statement
                  , mpl::false_()
                >
              , proto::when<
                    default_statement
                  , mpl::true_()
                >
            >
        {};

        struct switch_case_statement
            : proto::or_<
                proto::when<
                    proto::comma<switch_case_statement, proto::_>
                  , proto::if_<
                        is_same<mpl::prior<proto::_data>(), proto::_state>()
                      , proto::_right
                      , switch_case_statement(proto::_left, proto::_state, mpl::prior<proto::_data>())
                    >
                >
              , proto::otherwise<proto::_>
            >
        {};
    }

    namespace result_of
    {
        template <typename Cases>
        struct cases_size : boost::result_of<detail::switch_size(Cases)> {};

        template <typename Cases, typename N>
        struct case_compound
            : mpl::eval_if<
                mpl::less<N, typename cases_size<Cases>::type >
              , boost::result_of<detail::switch_case_statement(Cases, N, typename cases_size<Cases>::type)>
              , mpl::void_
            >
        {};

        template <typename Case>
        struct case_statement
            : proto::result_of::right<Case>
        {};

        template <typename Case>
        struct case_label
            : proto::result_of::value<
                typename proto::result_of::left<
                    Case
                >::type
            >
        {};

        template <typename Cases>
        struct switch_has_default : boost::result_of<detail::switch_has_default(Cases)> {};

        template <typename Case>
        struct is_default_case
            : proto::matches<Case, detail::default_statement>
        {};
    }

    template <int N, typename Cases>
    typename result_of::case_compound<Cases, mpl::int_<N> >::type const &
    case_compound_c(Cases const& cases)
    {
        typename result_of::cases_size<Cases>::type size;
        return detail::switch_case_statement()(cases, mpl::int_<N>(), size);
    }

    template <typename N, typename Cases>
    typename result_of::case_compound<Cases, N>::type const &
    case_compound(Cases const& cases)
    {
        typename result_of::cases_size<Cases>::type size;
        return detail::switch_case_statement()(cases, N(), size);
    }

    template <typename Case>
    typename result_of::case_statement<Case>::type const &
    case_statement(Case const& case_)
    {
        return proto::right(case_);
    }

    template <
        typename Cond,
        typename Cases,
        int N = result_of::cases_size<Cases>::type::value,
        typename Dummy = void>
    struct make_switch;

    // Bring in the rest ....
    #include <boost/phoenix/statement/detail/switch.hpp>

    template <int N, typename A0>
    typename proto::result_of::make_expr<
        switch_case_tag
      , default_domain_with_basic_expr
      , mpl::int_<N>
      , A0
    >::type const
    case_(A0 const& a0)
    {
        typedef typename
            proto::result_of::make_expr<
                switch_case_tag
              , default_domain_with_basic_expr
              , mpl::int_<N>
              , A0
            >::type
            expr_type;

        expr_type const e = {mpl::int_<N>(), a0};
        return e;
    }
    
    template <typename A0>
    typename proto::result_of::make_expr<
        switch_default_tag
      , default_domain_with_basic_expr
      , A0
    >::type const
    default_(A0 const& a0)
    {
        typedef typename
            proto::result_of::make_expr<
                switch_default_tag
              , default_domain_with_basic_expr
              , A0
            >::type
            expr_type;

        expr_type const e = {a0};
        return e;
    }

    template <typename Cond>
    struct switch_gen
    {
        switch_gen(Cond const& cond) : cond(cond) {}

        template <typename Cases>
        typename make_switch<
            Cond
          , Cases
        >::type
        operator[](Cases const& cases) const
        {
            BOOST_MPL_ASSERT((proto::matches<Cases, detail::switch_case_statement>));

            return make_switch<Cond, Cases>()(cond, cases);
        }

        Cond const& cond;
    };

    template <typename Cond>
    switch_gen<Cond> const
    switch_(Cond const& cond)
    {
        return switch_gen<Cond>(cond);
    };

}}

#endif

