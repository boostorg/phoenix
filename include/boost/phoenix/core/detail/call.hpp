
/*
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_CORE_DETAIL_CALL_HPP
#define PHOENIX_CORE_DETAIL_CALL_HPP

#endif
#else
*/
#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_CALL_HPP
#define PHOENIX_CORE_DETAIL_CALL_HPP

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/construct_eval_" PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#define M0(Z, N ,D) \
            typedef \
                typename proto::result_of::child_c<Expr, N>::type \
                BOOST_PP_CAT(A, N); \
/**/
#define M1(Z, N ,D) \
    BOOST_PP_COMMA() proto::child_c<N>(e)
/**/
    

    namespace detail
    {
#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_LIMIT,                                                      \
    <boost/phoenix/core/detail/call.hpp>))
#include PHOENIX_ITERATE()
    }

#undef M0
#undef M1

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
        
        template <typename Fun, typename Expr, typename State, typename Data>
        struct call_impl<Fun, Expr, State, Data, PHOENIX_ITERATION>
            : proto::transform_impl<Expr, State, Data>
        {
            typedef
                typename result_of::context<State, Data>::type
                context_type;

            BOOST_PP_REPEAT(PHOENIX_ITERATION, M0, _)

            typedef
                typename boost::result_of<Fun(context_type, PHOENIX_A)>::type
                result_type;

            result_type operator()(
                typename call_impl::expr_param e
              , typename call_impl::state_param s
              , typename call_impl::data_param d
            ) const
            {
                return Fun()(context(s, d) BOOST_PP_REPEAT(PHOENIX_ITERATION, M1, _));
            }
        };

#endif

//#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
