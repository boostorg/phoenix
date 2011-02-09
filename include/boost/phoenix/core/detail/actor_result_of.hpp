
/*
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/core/detail/preprocessed/actor_result_of.hpp>

#endif
#else
*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/actor_result_of_" PHOENIX_LIMIT_STR ".hpp")
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

    namespace result_of
    {
        template <typename Expr
            , PHOENIX_typename_A_void(PHOENIX_ACTOR_LIMIT)
            , typename Dummy = void>
        struct actor;

        template <typename Expr>
        struct nullary_actor_result
        {
            typedef
                typename evaluator::impl<
                    Expr const&
                  , vector2<
                        vector1<const ::boost::phoenix::actor<Expr> *> &
                      , default_actions
                    > const &
                  , int
                >::result_type
                type;
        };

        template <typename Expr>
        struct actor<Expr>
        {
            typedef
                // avoid calling result_of::actor when this is false
                typename mpl::eval_if<
                    result_of::is_nullary<Expr>
                  , nullary_actor_result<Expr>
                  , mpl::identity<detail::error_expecting_arguments>
                >::type
            type;
        };

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ACTOR_LIMIT,                                                \
    <boost/phoenix/core/detail/actor_result_of.hpp>))
#include PHOENIX_ITERATE()

    }

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename Expr, PHOENIX_typename_A>
        struct actor<Expr, PHOENIX_A>
        {
            typedef
                typename phoenix::evaluator::
                    impl<
                        Expr const&
                      , vector2<
                            BOOST_PP_CAT(
                                vector
                              , BOOST_PP_INC(PHOENIX_ITERATION)
                            )<const ::boost::phoenix::actor<Expr> *, PHOENIX_A> &
                          , default_actions
                        > const &
                      , int
                    >::result_type
                type;
        };

#endif

//#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
