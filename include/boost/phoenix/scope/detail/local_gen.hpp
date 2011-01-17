
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_SCOPE_DETAIL_LOCAL_GEN_HPP
#define PHOENIX_SCOPE_DETAIL_LOCAL_GEN_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/scope/detail/preprocessed/local_gen.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_SCOPE_DETAIL_LOCAL_GEN_HPP
#define PHOENIX_SCOPE_DETAIL_LOCAL_GEN_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/local_gen_" PHOENIX_LIMIT_STR ".hpp")
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

#define PHOENIX_LOCAL_GEN_KEY_TYPES(_, N, __)                                   \
    BOOST_PP_COMMA_IF(N)                                                        \
    typename proto::result_of::value<                                           \
        typename proto::result_of::child_c<                                     \
            typename proto::result_of::child_c<A ## N, 0>::type                 \
          , 0                                                                   \
        >::type                                                                 \
    >::type::type::key_type                                                     \
/**/

#define PHOENIX_LOCAL_GEN_ACTOR(_, N, __)                                       \
    BOOST_PP_COMMA_IF(N) proto::child_c<1>(a ## N)                              \
/**/

#define PHOENIX_LOCAL_GEN_ACTOR_TYPES(_, n, __)                                 \
    BOOST_PP_COMMA_IF(n) typename proto::result_of::child_c<A ## n, 1>::type    \
/**/

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (3, PHOENIX_LOCAL_LIMIT,                                                \
    <boost/phoenix/scope/detail/local_gen.hpp>))
#include PHOENIX_ITERATE()

#undef PHOENIX_LOCAL_GEN_KEY_TYPES
#undef PHOENIX_LOCAL_GEN_ACTOR
#undef PHOENIX_LOCAL_GEN_ACTOR_TYPES

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <PHOENIX_typename_A>
        PHOENIX_LOCAL_GEN_NAME<
            BOOST_PP_CAT(fusion::vector, PHOENIX_ITERATION)<PHOENIX_LOCAL_GEN_ACTOR_TYPES>
          , detail::map_local_index_to_tuple<BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_LOCAL_GEN_KEY_TYPES, _)>
        > const
        operator()(PHOENIX_A_const_ref_a) const
        {
            return
                BOOST_PP_CAT(
                     fusion::vector, PHOENIX_ITERATION)<BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_LOCAL_GEN_ACTOR_TYPES_I, _)>(BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_LOCAL_GEN_ACTOR, _));
        }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
