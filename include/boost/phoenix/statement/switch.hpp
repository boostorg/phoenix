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
      , (meta_grammar) // Cond
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
                        switch_case_is_nullary(proto::_child_c<0>, proto::_state)
                      , evaluator(proto::_child_c<0>(proto::_child_c<1>), proto::_state)
                    >()
                >
              , proto::when<
                    proto::or_<rule::switch_default_case, rule::switch_case>
                  , evaluator(proto::_child_c<0>, proto::_state)
                >
            >
        {};

        template <typename Dummy>
        struct is_nullary_::when<rule::switch_, Dummy>
            : proto::make<
                mpl::and_<
                    evaluator(proto::_child_c<0>, _env)
                  , switch_case_is_nullary(proto::_child_c<1>, _env)
                >()
            >
        {};
        struct switch_case_grammar
            : proto::or_<
                proto::when<
                    proto::comma<switch_case_grammar, rule::switch_case>
                  , proto::if_<
                        is_same<mpl::prior<proto::_data>(), proto::_state>()
                      , proto::_child_c<1>
                      , switch_case_grammar(proto::_child_c<0>, proto::_state, mpl::prior<proto::_data>())
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
                      , switch_case_grammar(proto::_child_c<0>, proto::_state, mpl::prior<proto::_data>())
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
                  , typename proto::matches<Cases, detail::switch_case_with_default_grammar>::type()
                );
        }

        private:
        #define PHOENIX_SWITCH_EVAL_TYPEDEF_R(Z, N, DATA) \
            typedef                                       \
                typename boost::result_of<                \
                    detail::switch_grammar(               \
                        Cases                             \
                      , mpl::int_<N>                      \
                      , mpl::int_<DATA>                   \
                    )                                     \
                >::type                                   \
                BOOST_PP_CAT(case, N);                    \
            typedef \
                typename proto::result_of::value<         \
                    typename proto::result_of::child_c<   \
                        BOOST_PP_CAT(case, N)             \
                      , 0                                 \
                    >::type \
                >::type \
                BOOST_PP_CAT(case_label, N); \
            mpl::int_<N> BOOST_PP_CAT(idx, N); \
        /**/

        #define PHOENIX_SWITCH_EVAL_R(Z, N, DATA) \
        case BOOST_PP_CAT(case_label, N)::value : \
            eval(proto::child_c<1>(detail::switch_grammar()(cases, BOOST_PP_CAT(idx, N), size)), env); \
            break;
        /**/

        #define PHOENIX_SWITCH_EVAL(Z, N, DATA) \
            template <typename Env, typename Cond, typename Cases> \
            result_type evaluate(Env & env, Cond const & cond, Cases const & cases, mpl::int_<N> size, mpl::false_) const\
            { \
                BOOST_PP_REPEAT(N, PHOENIX_SWITCH_EVAL_TYPEDEF_R, N) \
                switch(eval(cond, env)) \
                { \
                    BOOST_PP_REPEAT(N, PHOENIX_SWITCH_EVAL_R, _) \
                } \
            } \
            \
            template <typename Env, typename Cond, typename Cases> \
            result_type evaluate(Env & env, Cond const & cond, Cases const & cases, mpl::int_<N> size, mpl::true_) const\
            { \
                BOOST_PP_REPEAT(BOOST_PP_DEC(N), PHOENIX_SWITCH_EVAL_TYPEDEF_R, N) \
                mpl::int_<BOOST_PP_DEC(N)> BOOST_PP_CAT(idx, BOOST_PP_DEC(N)); \
                switch(eval(cond, env)) \
                { \
                    BOOST_PP_REPEAT(BOOST_PP_DEC(N), PHOENIX_SWITCH_EVAL_R, _) \
                    default: eval(proto::child_c<0>(detail::switch_grammar()(cases, BOOST_PP_CAT(idx, BOOST_PP_DEC(N)), size)), env); \
                } \
            } \
        /**/
        BOOST_PP_REPEAT_FROM_TO(0, PHOENIX_LIMIT, PHOENIX_SWITCH_EVAL, _)
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
    typename proto::result_of::make_expr<tag::switch_case, default_domain_with_basic_expr, mpl::int_<N>, A>::type const
    case_(A const & a)
    {
        return proto::make_expr<tag::switch_case, default_domain_with_basic_expr>(mpl::int_<N>(), a);
    }

    template <typename A>
    typename proto::result_of::make_expr<tag::switch_default_case, default_domain_with_basic_expr, A>::type const
    default_(A const& a)
    {
        return proto::make_expr<tag::switch_default_case, default_domain_with_basic_expr>(a);
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
            BOOST_MPL_ASSERT((proto::matches<Cases, detail::switch_grammar>));

            return expression::switch_<Cond, Cases>::make(cond, cases);
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

