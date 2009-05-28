/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_CORE_LIMITS_HPP
#define BOOST_PHOENIX_CORE_LIMITS_HPP

#if !defined(BOOST_PHOENIX_LIMIT)
# define BOOST_PHOENIX_LIMIT 10
#endif

#if !defined(BOOST_PHOENIX_ARG_LIMIT)
# define BOOST_PHOENIX_ARG_LIMIT BOOST_PHOENIX_LIMIT
#endif

#if !defined(BOOST_PHOENIX_PERFECT_FORWARD_LIMIT)
# define BOOST_PHOENIX_PERFECT_FORWARD_LIMIT 0
#endif

#if !defined(BOOST_PHOENIX_ACTOR_LIMIT)
# define BOOST_PHOENIX_ACTOR_LIMIT BOOST_PHOENIX_LIMIT
#elif (BOOST_PHOENIX_ACTOR_LIMIT > BOOST_PHOENIX_LIMIT)
# error BOOST_PHOENIX_ACTOR_LIMIT is set too high
#endif

#if !defined(FUSION_MAX_TUPLE_SIZE)
# define FUSION_MAX_TUPLE_SIZE BOOST_PHOENIX_LIMIT
#elif (FUSION_MAX_TUPLE_SIZE < BOOST_PHOENIX_LIMIT)
# error FUSION_MAX_TUPLE_SIZE is set too low
#endif

#if !defined(BOOST_PROTO_MAX_FUNCTION_CALL_ARITY)
# if BOOST_PHOENIX_LIMIT < 6
#  define BOOST_PROTO_MAX_FUNCTION_CALL_ARITY BOOST_PHOENIX_LIMIT
# else
#  define BOOST_PROTO_MAX_FUNCTION_CALL_ARITY 6
# endif
#endif

#if defined(BOOST_PROTO_MAX_ARITY)
# if BOOST_PROTO_MAX_ARITY < BOOST_PHOENIX_LIMIT
#  error BOOST_PROTO_MAX_ARITY must be at least as large as BOOST_PHOENIX_LIMIT
# endif
#else
# if BOOST_PHOENIX_LIMIT > 5
#  define BOOST_PROTO_MAX_ARITY BOOST_PHOENIX_LIMIT
# else
#  define BOOST_PROTO_MAX_ARITY 5
# endif
#endif

#if defined(BOOST_MPL_LIMIT_METAFUNCTION_ARITY)
# if BOOST_MPL_LIMIT_METAFUNCTION_ARITY < BOOST_PHOENIX_LIMIT
#  error BOOST_MPL_LIMIT_METAFUNCTION_ARITY must be at least as large as BOOST_PHOENIX_LIMIT
# endif
#else
# if BOOST_PHOENIX_LIMIT > 5
#  define BOOST_MPL_LIMIT_METAFUNCTION_ARITY BOOST_PHOENIX_LIMIT
# else
#  define BOOST_MPL_LIMIT_METAFUNCTION_ARITY 5
# endif
#endif

//// this include will bring in mpl::vectorN and
//// fusion::tupleN where N is BOOST_PHOENIX_ACTOR_LIMIT
//#include <boost/fusion/include/vector.hpp>

// OK, limits set. Include Proto.
#include <boost/proto/proto.hpp>

#endif
