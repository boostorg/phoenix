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

    template <typename A0>
    struct switch_eval<A0>
    {
        typedef void result_type;
        
        template <typename Env, typename Cond, typename Case0>
        result_type
        operator()(Env& env, Cond const& cond, Case0 const& case0) const
        {
            /*
            switch(eval(cond, env))
            {
                case A0::value: eval(case0, env); break;
            }
            */
        }
    };

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 1, true>
    {
        typedef typename fusion::result_of::value_at_c<Cases, 0>::type case0;

        typedef compose<
            switch_default_eval<>
          , Cond
          , typename case0::case_type
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, fusion::at_c<0>(cases).case_);
        }
    };
    
    template <typename A0, typename A1>
    struct switch_eval<A0, A1>
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Case0, typename Case1>
        result_type
        operator()(Env& env, Cond const& cond, Case0 const& case0, Case1 const& case1) const
        {
            switch(eval(cond, env))
            {
                case A0::value: eval(case0, env); break;
                case A1::value: eval(case1, env); break;
            }
        }
    };
    
    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 2, false>
    {
        typedef typename fusion::result_of::value_at_c<Cases, 0>::type case0;
        typedef typename fusion::result_of::value_at_c<Cases, 1>::type case1;

        typedef compose<
            switch_eval<typename case0::value_type, typename case1::value_type >
          , Cond
          , typename case0::case_type
          , typename case1::case_type
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, fusion::at_c<0>(cases).case_, fusion::at_c<1>(cases).case_);
        }
    };
    
    template <typename A0, typename A1, typename A2>
    struct switch_eval<A0, A1, A2>
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Case0, typename Case1, typename Case2>
        result_type
        operator()(Env& env, Cond const& cond, Case0 const& case0, Case1 const& case1, Case2 const& case2) const
        {
            switch(eval(cond, env))
            {
                case A0::value: eval(case0, env); break;
                case A1::value: eval(case1, env); break;
                case A2::value: eval(case2, env); break;
            }
        }
    };
    
    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 3, false>
    {
        typedef typename fusion::result_of::value_at_c<Cases, 0>::type case0;
        typedef typename fusion::result_of::value_at_c<Cases, 1>::type case1;
        typedef typename fusion::result_of::value_at_c<Cases, 2>::type case2;

        typedef compose<
            switch_eval<typename case0::value_type, typename case1::value_type, typename case2::value_type >
          , Cond
          , typename case0::case_type
          , typename case1::case_type
          , typename case2::case_type
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, fusion::at_c<0>(cases).case_, fusion::at_c<1>(cases).case_, fusion::at_c<2>(cases).case_);
        }
    };

    template<>
    struct switch_default_eval<>
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Default>
        result_type
        operator()(Env& env, Cond const& cond, Default const& default_) const
        {
            switch(eval(cond, env))
            {
                default: eval(default_, env); break;
            }
        }
    };

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 1, false>
    {
        typedef typename fusion::result_of::value_at_c<Cases, 0>::type case0;

        typedef compose<
            switch_eval<typename case0::value_type >
          , Cond
          , typename case0::case_type
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, fusion::at_c<0>(cases).case_);
        }
    };

    template<typename A0>
    struct switch_default_eval<A0>
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Case0, typename Default>
        result_type
        operator()(Env& env, Cond const& cond, Case0 const& case0, Default const& default_) const
        {
            switch(eval(cond, env))
            {
                case A0::value: eval(case0, env); break;
                default: eval(default_, env); break;
            }
        }
    };

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 2, true>
    {
        typedef typename fusion::result_of::value_at_c<Cases, 0>::type case0;
        typedef typename fusion::result_of::value_at_c<Cases, 1>::type case1;

        typedef compose<
            switch_default_eval<typename case0::value_type>
          , Cond
          , typename case0::case_type
          , case1
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, fusion::at_c<0>(cases).case_, fusion::at_c<1>(cases).case_);
        }
    };

    template<typename A0, typename A1>
    struct switch_default_eval<A0, A1>
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Case0, typename Case1, typename Default>
        result_type
        operator()(Env& env, Cond const& cond, Case0 const& case0, Case1 const& case1, Default const& default_) const
        {
            switch(eval(cond, env))
            {
                case A0::value: eval(case0, env); break;
                case A1::value: eval(case1, env); break;
                default: eval(default_, env); break;
            }
        }
    };
    
    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, 3, true>
    {
        typedef typename fusion::result_of::value_at_c<Cases, 0>::type case0;
        typedef typename fusion::result_of::value_at_c<Cases, 1>::type case1;
        typedef typename fusion::result_of::value_at_c<Cases, 2>::type case2;

        typedef compose<
            switch_default_eval<typename case0::value_type, typename case1::value_type>
          , Cond
          , typename case0::case_type
          , typename case1::case_type
          , typename case2::case_type
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond, fusion::at_c<0>(cases).case_, fusion::at_c<1>(cases).case_, fusion::at_c<2>(cases).case_);
        }
    };

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (4, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/statement/detail/switch.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

#define PHOENIX_typename_CaseCond BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename CaseCond)
#define PHOENIX_CaseCond BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, CaseCond)
#define PHOENIX_typename_CaseCond_default BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_ITERATION), typename CaseCond)
#define PHOENIX_CaseCond_default BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_ITERATION), CaseCond)

    template <PHOENIX_typename_CaseCond>
    struct switch_eval<PHOENIX_CaseCond>
    {
        typedef void result_type;
        
        template <typename Env, typename Cond, PHOENIX_typename_A>
        result_type
        operator()(Env& env, Cond const& cond, PHOENIX_A_const_ref_a) const
        {
#define CASES(_,n,__) case CaseCond ## n ::value : eval( a ##n, env ); break;

            switch(eval(cond, env))
            {
                BOOST_PP_REPEAT(PHOENIX_ITERATION, CASES, _)
            }
        }
    };

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, PHOENIX_ITERATION, false>
    {
#define CASE_TYPEDEF(_,n,__) typedef typename fusion::result_of::value_at_c<Cases, n>::type case ## n;
        BOOST_PP_REPEAT(PHOENIX_ITERATION, CASE_TYPEDEF, _)

        typedef compose<
            switch_eval<BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, typename case, ::value_type BOOST_PP_INTERCEPT)>
          , Cond
          , BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, typename case, ::case_type BOOST_PP_INTERCEPT)
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
#define FUSION_AT_C(_, n, __) BOOST_PP_COMMA_IF(n) fusion::at_c< n >(cases).case_
            return composite_type()(cond,
                    BOOST_PP_REPEAT(PHOENIX_ITERATION, FUSION_AT_C, _));
        }
    };

    template <PHOENIX_typename_CaseCond_default>
    struct switch_default_eval<PHOENIX_CaseCond_default>
    {
        typedef void result_type;
        
        template <typename Env, typename Cond, PHOENIX_typename_A>
        result_type
        operator()(Env& env, Cond const& cond, PHOENIX_A_const_ref_a) const
        {
            switch(eval(cond, env))
            {
                BOOST_PP_REPEAT(BOOST_PP_DEC(PHOENIX_ITERATION), CASES, _)
                default: eval(BOOST_PP_CAT(a, BOOST_PP_DEC(PHOENIX_ITERATION)), env);
            }
        }
    };

    template <typename Cond, typename Cases>
    struct make_switch<Cond, Cases, PHOENIX_ITERATION, true>
    {
        BOOST_PP_REPEAT(PHOENIX_ITERATION, CASE_TYPEDEF, _)

        typedef compose<
            switch_default_eval<BOOST_PP_ENUM_BINARY_PARAMS(BOOST_PP_DEC(PHOENIX_ITERATION), typename case, ::value_type BOOST_PP_INTERCEPT)>
          , Cond
          , BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, typename case, ::case_type BOOST_PP_INTERCEPT)
          > composite_type;

        typedef typename composite_type::type type;
        
        type const
        operator()( Cond const& cond, Cases const& cases) const
        {
            return composite_type()(cond,
                    BOOST_PP_REPEAT(PHOENIX_ITERATION, FUSION_AT_C, _));
        }
    };

#undef FUSION_AT_C
#undef CASE_TYPEDEF
#undef CASES
#undef PHOENIX_typename_CaseCond
#undef PHOENIX_CaseCond
#undef PHOENIX_typename_CaseCond_default
#undef PHOENIX_CaseCond_default

#endif

