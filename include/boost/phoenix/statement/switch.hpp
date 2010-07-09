/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_SWITCH_HPP
#define PHOENIX_STATEMENT_SWITCH_HPP

#include <boost/fusion/algorithm/transformation/push_front.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/support/element_at.hpp>
#include <boost/phoenix/support/iterate.hpp>

#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/context/callable.hpp>
#include <boost/proto/extends.hpp>
#include <boost/proto/make_expr.hpp>

namespace boost { namespace phoenix
{
    struct switch_case_tag {};
    struct switch_default_tag {};

    template <typename Value, typename Case>
    struct switch_case
    {
        typedef Value value_type;
        typedef Case  case_type;

        switch_case(Case const& case_) : case_(case_) {};

        Case const& case_;
    };
    
    template <typename Case>
    struct switch_default
    {
        typedef mpl::false_ value_type;
        typedef Case  case_type;

        switch_default(Case const& case_) : case_(case_) {};

        Case const& case_;
    };

    namespace detail
    {
        struct push_front
            : proto::callable
        {
            template <typename Sig>
            struct result;

            template <typename This, typename Expr, typename State>
            struct result<This(Expr, State)>
                : fusion::result_of::push_front<typename remove_reference<State>::type const, Expr>
            {};

            template <typename Expr, typename State>
            typename fusion::result_of::push_front<State const, Expr>::type
            operator()(Expr const& expr, State const& state)
            {
                return fusion::push_front(state, expr);
            }

        };
        
        template <typename Case>
        struct is_default
            : mpl::false_
        {};

        template <typename Case>
        struct is_default<switch_default<Case> >
            : mpl::true_
        {};
    }

    struct switch_grammar
        : /// FIXME
          /*proto::and_<
            // switch_(...)[default_(...), default_(...)] not allowed
            proto::not_<
                proto::comma<
                    proto::unary_expr<switch_default_tag, eval_grammar>
                  , proto::unary_expr<switch_default_tag, eval_grammar>
                >
            >
            // switch_(...)[case_<...>(...), default_(...), case<...>(...)] not allowed
          , proto::not_<
                proto::comma<proto::comma<switch_grammar, proto::unary_expr<switch_default_tag, eval_grammar> >, switch_grammar >
            >
            // switch_(...)[case_<...>(...), default_(...), default_(...)] not allowed
          , proto::not_<
                proto::comma<proto::comma<switch_grammar, proto::unary_expr<switch_default_tag, eval_grammar> >, proto::unary_expr<switch_default_tag, eval_grammar> >
            >
          // and finally the transforms to create the fusion vector of the actors
          ,*/ proto::or_<
                proto::when<
                    proto::comma<switch_grammar, switch_grammar>
                  , switch_grammar(proto::_left, switch_grammar(proto::_right))
                >
              , proto::when<
                    proto::binary_expr<switch_case_tag, proto::_, eval_grammar>
                  , detail::push_front(switch_case<proto::_value(proto::_left), proto::_right>(proto::_right), proto::_state)
                >
              , proto::when<
                    proto::unary_expr<switch_default_tag, eval_grammar>
                  , detail::push_front(switch_default<proto::_child>(proto::_child), proto::_state)
                >
            >
        //>
    {};

    template <PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT), typename Dummy = void>
    struct switch_eval;

    template <PHOENIX_typename_A_void(BOOST_PP_DEC(PHOENIX_COMPOSITE_LIMIT)), typename Dummy = void>
    struct switch_default_eval;

    template <
        typename Cond,
        typename Cases, int N = fusion::result_of::size<Cases>::type::value,
        bool with_default = detail::is_default<typename fusion::result_of::value_at_c<Cases, N-1>::type >::value>
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
          , typename fusion::result_of::as_vector<
                typename boost::result_of<
                    switch_grammar(Cases const&, fusion::vector0<> const&)
                >::type
            >::type
        >::type
        operator[](Cases const& cases) const
        {
            BOOST_PROTO_ASSERT_MATCHES( cases, switch_grammar );
            typedef
                typename fusion::result_of::as_vector<
                    typename boost::result_of<
                        switch_grammar(Cases const&, fusion::vector0<> const&)
                    >::type
                >::type
                cases_type;

            return make_switch<Cond, cases_type>()(cond, fusion::as_vector(switch_grammar()(cases, fusion::vector0<>())));
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

