/*==============================================================================
    Copyright (c) 2011 Hartmut Kaiser

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !defined(PHOENIX_PREPROCESSED_FUNCTION_RESULT_OF)
#define PHOENIX_PREPROCESSED_FUNCTION_RESULT_OF

#if PHOENIX_LIMIT <= 10
#include <boost/phoenix/function/detail/preprocessed/function_result_of_10.hpp>
#elif PHOENIX_LIMIT <= 20
#include <boost/phoenix/function/detail/preprocessed/function_result_of_20.hpp>
#elif PHOENIX_LIMIT <= 30
#include <boost/phoenix/function/detail/preprocessed/function_result_of_30.hpp>
#elif PHOENIX_LIMIT <= 40
#include <boost/phoenix/function/detail/preprocessed/function_result_of_40.hpp>
#elif PHOENIX_LIMIT <= 50
#include <boost/phoenix/function/detail/preprocessed/function_result_of_50.hpp>
#else
#error "PHOENIX_LIMIT out of bounds for preprocessed headers"
#endif

#endif
