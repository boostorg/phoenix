
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_STATEMENT_DETAIL_SWITCH_HPP
#define PHOENIX_STATEMENT_DETAIL_SWITCH_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/statement/detail/preprocessed/switch.hpp>

#endif
#else

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
                typename boost::result_of<                                      \
                    detail::switch_grammar(                                     \
                        Cases                                                   \
                      , mpl::int_<N>                                            \
                      , mpl::int_<DATA>                                         \
                    )                                                           \
                >::type                                                         \
                BOOST_PP_CAT(case, N);                                          \
            typedef                                                             \
                typename proto::result_of::value<                               \
                    typename proto::result_of::child_c<                         \
                        BOOST_PP_CAT(case, N)                                   \
                      , 0                                                       \
                    >::type                                                     \
                >::type                                                         \
                BOOST_PP_CAT(case_label, N);                                    \
            mpl::int_<N> BOOST_PP_CAT(idx, N);                                  \
    /**/

    #define PHOENIX_SWITCH_EVAL_R(Z, N, DATA)                                   \
        case BOOST_PP_CAT(case_label, N)::value :                               \
            eval(                                                               \
                proto::child_c<1>(                                              \
                    detail::switch_grammar()(                                   \
                        cases, BOOST_PP_CAT(idx, N), size                       \
                    )                                                           \
                )                                                               \
              , env                                                             \
            );                                                                  \
            break;
    /**/

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (0, PHOENIX_LIMIT,                                                  \
        <boost/phoenix/statement/detail/switch.hpp>))
#include PHOENIX_ITERATE()

        #undef PHOENIX_SWITCH_EVAL_R
        #undef PHOENIX_SWITCH_EVAL_TYPEDEF

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
            template <typename Env, typename Cond, typename Cases>
            result_type
            evaluate(
                Env & env
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<PHOENIX_ITERATION> size
              , mpl::false_
            ) const
            {
                BOOST_PP_REPEAT(
                    PHOENIX_ITERATION
                  , PHOENIX_SWITCH_EVAL_TYPEDEF_R
                  , PHOENIX_ITERATION
                )
                switch(eval(cond, env))
                {
                    BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_SWITCH_EVAL_R, _)
                }
            }

            template <typename Env, typename Cond, typename Cases>
            result_type
            evaluate(
                Env & env
              , Cond const & cond
              , Cases const & cases
              , mpl::int_<PHOENIX_ITERATION> size
              , mpl::true_
            ) const
            {
                BOOST_PP_REPEAT(
                    BOOST_PP_DEC(PHOENIX_ITERATION)
                  , PHOENIX_SWITCH_EVAL_TYPEDEF_R
                  , PHOENIX_ITERATION
                )
                mpl::int_<BOOST_PP_DEC(PHOENIX_ITERATION)>
                    BOOST_PP_CAT(idx, BOOST_PP_DEC(PHOENIX_ITERATION));
                switch(eval(cond, env))
                {
                    BOOST_PP_REPEAT(
                        BOOST_PP_DEC(PHOENIX_ITERATION)
                      , PHOENIX_SWITCH_EVAL_R, _
                    )
                    default:
                        eval(
                            proto::child_c<0>(
                                detail::switch_grammar()(
                                    cases
                                  , BOOST_PP_CAT(
                                        idx
                                      , BOOST_PP_DEC(PHOENIX_ITERATION)
                                    )
                                  , size
                                )
                            )
                            , env
                        );
                }
            }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
