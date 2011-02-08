
/*
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_STATEMENT_DETAIL_SWITCH_HPP
#define PHOENIX_STATEMENT_DETAIL_SWITCH_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/statement/detail/preprocessed/switch.hpp>

#endif
#else
*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_DETAIL_SWITCH_HPP
#define PHOENIX_STATEMENT_DETAIL_SWITCH_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/switch_" PHOENIX_LIMIT_STR ".hpp")
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

        #define PHOENIX_SWITCH_EVAL_TYPEDEF_R(Z, N, DATA)                       \
            typedef                                                             \
                typename fusion::result_of::deref<                              \
                    typename fusion::result_of::advance_c<                      \
                        flat_view_begin                                         \
                      , N                                                       \
                    >::type                                                     \
                >::type                                                         \
                BOOST_PP_CAT(case, N);                                          \
            typedef                                                             \
                typename proto::detail::uncvref<                                \
                    typename proto::result_of::value<                           \
                      typename proto::result_of::child_c<                       \
                            BOOST_PP_CAT(case, N)                               \
                          , 0                                                   \
                        >::type                                                 \
                    >::type                                                     \
                >::type                                                         \
                BOOST_PP_CAT(case_label, N);                                    \
    /**/

    #define PHOENIX_SWITCH_EVAL_R(Z, N, DATA)                                   \
        case BOOST_PP_CAT(case_label, N)::value :                               \
            eval(                                                               \
                proto::child_c<1>(                                              \
                    fusion::deref(                                              \
                        fusion::advance_c<N>(fusion::begin(flat_view))          \
                    )                                                           \
                )                                                               \
              , ctx                                                             \
            );                                                                  \
            break;                                                              \
    /**/

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (2, PHOENIX_LIMIT,                                                  \
        <boost/phoenix/statement/detail/switch.hpp>))
#include PHOENIX_ITERATE()

        #undef PHOENIX_SWITCH_EVAL_R
        #undef PHOENIX_SWITCH_EVAL_TYPEDEF

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<PHOENIX_ITERATION> size
              , mpl::false_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;

                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;

                flat_view_type flat_view(proto::flatten(cases));

                BOOST_PP_REPEAT(
                    PHOENIX_ITERATION
                  , PHOENIX_SWITCH_EVAL_TYPEDEF_R
                  , PHOENIX_ITERATION
                )

                switch(eval(cond, ctx))
                {
                    BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_SWITCH_EVAL_R, _)
                }
            }

            template <typename Context, typename Cond, typename Cases>
            result_type
            evaluate(
                Context & ctx
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<PHOENIX_ITERATION> size
              , mpl::true_
            ) const
            {
                typedef 
                    typename proto::result_of::flatten<Cases const&>::type
                    flat_view_type;

                typedef
                    typename fusion::result_of::begin<flat_view_type>::type
                    flat_view_begin;

                flat_view_type flat_view(proto::flatten(cases));

                BOOST_PP_REPEAT(
                    BOOST_PP_DEC(PHOENIX_ITERATION)
                  , PHOENIX_SWITCH_EVAL_TYPEDEF_R
                  , PHOENIX_ITERATION
                )

                switch(eval(cond, ctx))
                {
                    BOOST_PP_REPEAT(
                        BOOST_PP_DEC(PHOENIX_ITERATION)
                      , PHOENIX_SWITCH_EVAL_R, _
                    )
                    default:
                        eval(
                            proto::child_c<0>(
                                fusion::deref(
                                    fusion::advance_c<
                                        BOOST_PP_DEC(PHOENIX_ITERATION)
                                    >(fusion::begin(flat_view))
                                )
                            )
                            , ctx
                        );
                }
            }

#endif

//#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
