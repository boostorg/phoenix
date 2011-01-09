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
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/is_nullary.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/make_expr.hpp>

namespace boost { namespace phoenix
{
    namespace tag
    {
        struct switch_case {};
        struct switch_default_case {};
    }

    namespace expression
    {
        template <typename N, typename A>
        struct switch_case
            : proto::binary_expr<tag::switch_case, N, A>
        {};
        
        template <typename A>
        struct switch_default_case
            : proto::unary_expr<tag::switch_default_case, A>
        {};
    }

    namespace rule
    {
        struct switch_case
            : expression::switch_case<
                proto::terminal<proto::_>
              , meta_grammar
            >
        {};
        
        struct switch_default_case
            : expression::switch_default_case<
                meta_grammar
            >
        {};
    }
    namespace detail
    {
        struct switch_case_grammar;
        struct switch_case_with_default_grammar;
        struct switch_grammar
            : proto::or_<
                detail::switch_case_grammar
              , detail::switch_case_with_default_grammar
            >
        {};
    }

    PHOENIX_DEFINE_EXPRESSION(
        switch_
      , (meta_grammar)           // Cond
        (detail::switch_grammar) // Cases
    )

    namespace detail
    {
        struct switch_case_is_nullary
            : proto::or_<
                proto::when<
                    proto::comma<
                        switch_case_is_nullary
                      , proto::or_<rule::switch_default_case, rule::switch_case>
                    >
                  , mpl::and_<
                        switch_case_is_nullary(
                            proto::_child_c<0>
                          , proto::_state
                        )
                      , evaluator(
                            proto::_child_c<0>(proto::_child_c<1>)
                          , proto::_state
                        )
                    >()
                >
              , proto::when<
                    proto::or_<rule::switch_default_case, rule::switch_case>
                  , evaluator(proto::_child_c<0>, proto::_state)
                >
            >
        {};

        struct switch_case_grammar
            : proto::or_<
                proto::when<
                    proto::comma<switch_case_grammar, rule::switch_case>
                  , proto::if_<
                        is_same<mpl::prior<proto::_data>(), proto::_state>()
                      , proto::_child_c<1>
                      , switch_case_grammar(
                            proto::_child_c<0>
                          , proto::_state
                          , mpl::prior<proto::_data>()
                        )
                    >
                >
              , proto::when<rule::switch_case, proto::_>
            >
        {};

        struct switch_case_with_default_grammar
            : proto::or_<
                proto::when<
                    proto::comma<switch_case_grammar, rule::switch_default_case>
                  , proto::if_<
                        is_same<mpl::prior<proto::_data>(), proto::_state>()
                      , proto::_child_c<1>
                      , switch_case_grammar(
                            proto::_child_c<0>
                          , proto::_state
                          , mpl::prior<proto::_data>()
                        )
                    >
                >
              , proto::when<rule::switch_default_case, proto::_>
            >
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
    }

    template <typename Dummy>
    struct is_nullary::when<rule::switch_, Dummy>
        : proto::make<
            mpl::and_<
                evaluator(proto::_child_c<0>, _env)
              , detail::switch_case_is_nullary(proto::_child_c<1>, _env)
            >()
        >
    {};

    struct switch_eval
    {
        typedef void result_type;
        
        template <typename Env>
        result_type
        operator()(Env & env) const
        {
        }

        template <typename Env, typename Cond, typename Cases>
        result_type
        operator()(Env & env, Cond const & cond, Cases const & cases) const
        {
            this->evaluate(
                    env
                  , cond
                  , cases
                  , typename boost::result_of<detail::switch_size(Cases)>::type()
                  , typename proto::matches<
                        Cases
                      , detail::switch_case_with_default_grammar
                    >::type()
                );
        }

        private:
            // Bring in the evaluation functions
            #include <boost/phoenix/statement/detail/switch.hpp>
    };
    
    template <typename Dummy>
    struct default_actions::when<rule::switch_, Dummy>
        : proto::call<
            switch_eval(
                _env
              , proto::_child_c<0> // Cond
              , proto::_child_c<1> // Cases
            )
          >
    {};

    template <int N, typename A>
    typename proto::result_of::make_expr<
        tag::switch_case
      , default_domain_with_basic_expr
      , mpl::int_<N>
      , A
    >::type const
    case_(A const & a)
    {
        return
            proto::make_expr<tag::switch_case, default_domain_with_basic_expr>(
                mpl::int_<N>()
              , a
            );
    }

    template <typename A>
    typename proto::result_of::make_expr<
        tag::switch_default_case
      , default_domain_with_basic_expr
      , A
    >::type const
    default_(A const& a)
    {
        return
            proto::make_expr<
                tag::switch_default_case, default_domain_with_basic_expr
            >(a);
    }

    template <typename Cond>
    struct switch_gen
    {
        switch_gen(Cond const& cond) : cond(cond) {}

        template <typename Cases>
        typename expression::switch_<
            Cond
          , Cases
        >::type
        operator[](Cases const& cases) const
        {
            return
                this->generate(
                    cases
                  , proto::matches<Cases, detail::switch_grammar>()
                );
        }

        private:
            Cond const& cond;

            template <typename Cases>
            typename expression::switch_<
                Cond
              , Cases
            >::type
            generate(Cases const & cases, mpl::true_) const
            {
                return expression::switch_<Cond, Cases>::make(cond, cases);
            }
            
            template <typename Cases>
            typename expression::switch_<
                Cond
              , Cases
            >::type
            generate(Cases const & cases, mpl::false_) const
            {
                BOOST_MPL_ASSERT_MSG(
                    false
                  , INVALID_SWITCH_CASE_STATEMENT
                  , (Cases)
                );
            }
    };

    template <typename Cond>
    switch_gen<Cond> const
    switch_(Cond const& cond)
    {
        return switch_gen<Cond>(cond);
    };

}}

#endif

