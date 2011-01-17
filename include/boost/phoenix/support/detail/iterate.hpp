/*==============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !BOOST_PP_IS_ITERATING

#include <boost/preprocessor/tuple/elem.hpp>

#ifndef PHOENIX_ITERATION_PARAMS
#error "PHOENIX_ITERATION_PARAMS not defined"
#endif

#define PHOENIX_ITERATION_PARAMS_SIZE                                           \
    BOOST_PP_TUPLE_ELEM(2, 0, PHOENIX_ITERATION_PARAMS)                         \
/**/

#define PHOENIX_ITERATION_TUPLE                                                 \
    BOOST_PP_TUPLE_ELEM(2, 1, PHOENIX_ITERATION_PARAMS)                         \
/**/

#define PHOENIX_ITERATION_START                                                 \
    BOOST_PP_TUPLE_ELEM(                                                        \
        PHOENIX_ITERATION_PARAMS_SIZE, 0, PHOENIX_ITERATION_TUPLE)              \
/**/

#define PHOENIX_ITERATION_END                                                   \
    BOOST_PP_TUPLE_ELEM(                                                        \
        PHOENIX_ITERATION_PARAMS_SIZE, 1, PHOENIX_ITERATION_TUPLE)              \
/**/


#define PHOENIX_ITERATION_FILE()                                                \
    BOOST_PP_TUPLE_ELEM(                                                        \
        PHOENIX_ITERATION_PARAMS_SIZE, 2, PHOENIX_ITERATION_TUPLE)              \
/**/

#if PHOENIX_ITERATION_PARAMS_SIZE == 3

#define BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (PHOENIX_ITERATION_START, PHOENIX_ITERATION_END,                        \
    <boost/phoenix/support/detail/iterate.hpp>))                                \
/**/

#else

#define PHOENIX_ITERATION_FLAG                                                  \
    BOOST_PP_TUPLE_ELEM(                                                        \
        PHOENIX_ITERATION_PARAMS_SIZE, 3, PHOENIX_ITERATION_TUPLE)              \
/**/

#define BOOST_PP_ITERATION_PARAMS_1                                             \
    (4, (PHOENIX_ITERATION_START, PHOENIX_ITERATION_END,                        \
    <boost/phoenix/support/detail/iterate.hpp>,                                 \
    PHOENIX_ITERATION_FLAG))                                                    \
/**/

#endif

#include BOOST_PP_ITERATE()

#undef PHOENIX_ITERATION_PARAMS_SIZE
#undef PHOENIX_ITERATION_TUPLE
#undef PHOENIX_ITERATION_START
#undef PHOENIX_ITERATION_END
#undef PHOENIX_ITERATION_PARAMS

#else

#undef PHOENIX_IS_ITERATING
#define PHOENIX_IS_ITERATING 1

#include <boost/phoenix/support/detail/iterate_undef.hpp>
#include <boost/phoenix/support/detail/iterate_define.hpp>


#include PHOENIX_ITERATION_FILE()

#undef PHOENIX_ITERATION

#undef PHOENIX_IS_ITERATING
#define PHOENIX_IS_ITERATING 0

#include <boost/phoenix/support/detail/iterate_undef.hpp>
#include <boost/phoenix/support/detail/iterate_define.hpp>

#endif
