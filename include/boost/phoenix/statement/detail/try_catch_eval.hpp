
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EVAL_HPP
#define PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EVAL_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/statement/detail/preprocessed/try_catch_eval.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EVAL_HPP
#define PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EVAL_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/try_catch_eval_" PHOENIX_LIMIT_STR ".hpp")
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

    #define PHOENIX_TRY_CATCH_EVAL_R(Z, N, DATA)                                \
            catch(                                                              \
                typename proto::result_of::value<                               \
                    typename proto::result_of::child_c<                         \
                        BOOST_PP_CAT(A, N)                                      \
                      , 0                                                       \
                    >::type                                                     \
                >::type::type &                                                 \
            )                                                                   \
            {                                                                   \
                eval(proto::child_c<1>(BOOST_PP_CAT(a, N)), env);               \
            }                                                                   \
    /**/


#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (1, PHOENIX_CATCH_LIMIT,                                            \
        <boost/phoenix/statement/detail/try_catch_eval.hpp>))
#include PHOENIX_ITERATE()

    #undef PHOENIX_TRY_CATCH_EVAL_R

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename Env, typename Try, PHOENIX_typename_A>
        typename boost::enable_if<
            proto::matches<
                BOOST_PP_CAT(A, BOOST_PP_DEC(PHOENIX_ITERATION))
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, PHOENIX_A_const_ref_a) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_TRY_CATCH_EVAL_R, _)
        }

        template <typename Env, typename Try, PHOENIX_typename_A>
        typename boost::disable_if<
            proto::matches<
                BOOST_PP_CAT(A, BOOST_PP_DEC(PHOENIX_ITERATION))
              , rule::catch_
            >
          , result_type
        >::type
        operator()(Env & env, Try const & try_, PHOENIX_A_const_ref_a) const
        {
            try
            {
                eval(proto::child_c<0>(try_), env);
            }
            BOOST_PP_REPEAT(
                BOOST_PP_DEC(PHOENIX_ITERATION)
              , PHOENIX_TRY_CATCH_EVAL_R, _
            )
            catch(...)
            {
                eval(
                    proto::child_c<0>(
                        BOOST_PP_CAT(a, BOOST_PP_DEC(PHOENIX_ITERATION))
                    )
                  , env);
            }
        }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
