/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_DETAIL_SWITCH_HPP
#define PHOENIX_STATEMENT_DETAIL_SWITCH_HPP

#include <boost/preprocessor/cat.hpp>

    struct switch_eval
    {
        typedef void result_type;
        
        template <typename Env, typename Cond, typename Case0>
        void
        operator()(Env& env, Cond const& cond, Case0 const& case0) const
        {
            return evaluate(env, cond, case0, result_of::is_default_case<Case0>());
        }
        
        template <typename Env, typename Cond, typename Case0>
        void
        evaluate(Env& env, Cond const& cond, Case0 const& case0, mpl::false_) const
        {
            typedef typename result_of::case_label<Case0>::type label0;

            switch(eval(cond, env))
            {
                case label0::value: eval(case_statement(case0), env); break;
            }
        }
        
        template <typename Env, typename Cond, typename Case0>
        void
        evaluate(Env& env, Cond const& cond, Case0 const& case0, mpl::true_) const
        {
            switch(eval(cond, env))
            {
                default: eval(proto::child(case0), env); break;
            }
        }

#define PHOENIX_SWITCH_EVAL_LABEL_TYPEDEF(_,n,__)\
        typedef typename result_of::case_label<BOOST_PP_CAT(A, n)>::type BOOST_PP_CAT(label, n);

#define PHOENIX_SWITCH_EVAL_CASE_EVAL(_,n,__)\
        case BOOST_PP_CAT(label,n)::value: eval(case_statement(BOOST_PP_CAT(a, n)), env); break;


#define PHOENIX_SWITCH_EVAL_OVERLOADS(_,n,__) \
        template <typename Env, typename Cond, PHOENIX_typename_A(n)> \
        void \
        operator()(Env& env, Cond const& cond, PHOENIX_A_const_ref_a(n)) const \
        { \
            return evaluate(env, cond, PHOENIX_a(n), result_of::is_default_case<BOOST_PP_CAT(A, BOOST_PP_DEC(n))>()); \
        }\
        \
        template <typename Env, typename Cond, PHOENIX_typename_A(n)>\
        void\
        evaluate(Env& env, Cond const& cond, PHOENIX_A_const_ref_a(n), mpl::false_) const\
        {\
            BOOST_PP_REPEAT(n, PHOENIX_SWITCH_EVAL_LABEL_TYPEDEF, _)\
            switch(eval(cond, env))\
            {\
                BOOST_PP_REPEAT(n, PHOENIX_SWITCH_EVAL_CASE_EVAL, _)\
            }\
        }\
        \
        template <typename Env, typename Cond, PHOENIX_typename_A(n)>\
        void\
        evaluate(Env& env, Cond const& cond, PHOENIX_A_const_ref_a(n), mpl::true_) const\
        {\
            BOOST_PP_REPEAT(BOOST_PP_DEC(n), PHOENIX_SWITCH_EVAL_LABEL_TYPEDEF, _)\
            switch(eval(cond, env))\
            {\
                BOOST_PP_REPEAT(BOOST_PP_DEC(n), PHOENIX_SWITCH_EVAL_CASE_EVAL, _)\
                default: eval(proto::child(BOOST_PP_CAT(a, BOOST_PP_DEC(n))), env); break;\
            }\
        }

        BOOST_PP_REPEAT_FROM_TO(2, PHOENIX_COMPOSITE_LIMIT, PHOENIX_SWITCH_EVAL_OVERLOADS, _)

#undef PHOENIX_SWITCH_EVAL_LABEL_TYPEDEF
#undef PHOENIX_SWITCH_EVAL_CASE_EVAL
#undef PHOENIX_SWITCH_EVAL_OVERLOADS
    };

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 1>
    {
        typedef typename result_of::case_compound<Cases, mpl::int_<0> >::type case0;

        typedef
            compose<
                switch_eval
              , Cond
              , case0
            >
            composite_type;

        typedef typename composite_type::type type;

        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, case_compound_c<0>(cases));
        }
    };

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (2, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/statement/detail/switch.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, PHOENIX_ITERATION>
    {
#define CASE_TYPEDEF(_,n,__) \
        typedef typename result_of::case_compound<Cases, mpl::int_< n > >::type BOOST_PP_CAT(case, n);
        BOOST_PP_REPEAT(PHOENIX_ITERATION, CASE_TYPEDEF, _)

        typedef
            compose<
                switch_eval
              , Cond
              , BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, case)
            >
            composite_type;

        typedef typename composite_type::type type;

        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(
                cond,
#define CASE_COMPOUND(_,n,__)\
                BOOST_PP_COMMA_IF(n) case_compound_c< n >(cases)
                BOOST_PP_REPEAT(PHOENIX_ITERATION, CASE_COMPOUND, _));
        }
    };

#undef CASE_TYPEDEF
#undef CASE_COMPOUND

#endif

