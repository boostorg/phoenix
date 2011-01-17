/*==============================================================================
    Copyright (c) 2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(PHOENIX_PREPROCESSED_ACTOR_OPERATOR)
#define PHOENIX_PREPROCESSED_ACTOR_OPERATOR

#if PHOENIX_LIMIT <= 10
#include <boost/phoenix/core/detail/preprocessed/actor_operator_10.hpp>
#elif PHOENIX_LIMIT <= 20
#include <boost/phoenix/core/detail/preprocessed/actor_operator_20.hpp>
#elif PHOENIX_LIMIT <= 30
#include <boost/phoenix/core/detail/preprocessed/actor_operator_30.hpp>
#elif PHOENIX_LIMIT <= 40
#include <boost/phoenix/core/detail/preprocessed/actor_operator_40.hpp>
#elif PHOENIX_LIMIT <= 50
#include <boost/phoenix/core/detail/preprocessed/actor_operator_50.hpp>
#else
#error "PHOENIX_LIMIT out of bounds for preprocessed headers"
#endif

#endif
