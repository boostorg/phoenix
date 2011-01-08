/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#define PHOENIX_LOCAL_GEN_KEY_TYPES(_, N, __)                                   \
	BOOST_PP_COMMA_IF(N)                                                        \
    typename proto::result_of::value<                                           \
        typename proto::result_of::child_c<                                     \
            typename proto::result_of::child_c<A ## N, 0>::type                 \
          , 0                                                                   \
        >::type                                                                 \
    >::type::type::key_type                                                     \
/**/

#define PHOENIX_LOCAL_GEN_ACTOR(_, N, __)                                     \
	BOOST_PP_COMMA_IF(N) proto::child_c<1>(a ## N)                              \
/**/

#define PHOENIX_LOCAL_GEN_ACTOR_TYPES(_, n, __)                               \
	BOOST_PP_COMMA_IF(n) typename proto::result_of::child_c<A ## n, 1>::type    \
/**/

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (3, PHOENIX_LOCAL_LIMIT,                                                \
    <boost/phoenix/scope/detail/local_gen.hpp>))
#include PHOENIX_ITERATE()

#undef PHOENIX_LOCAL_GEN_KEY_TYPES
#undef PHOENIX_LOCAL_GEN_ACTOR
#undef PHOENIX_LOCAL_GEN_ACTOR_TYPES

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
