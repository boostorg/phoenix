/*==============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#define PHOENIX_typename_A(N)                                                   \
    BOOST_PP_ENUM_PARAMS(N, typename A)                                         \
/**/

#define PHOENIX_typename_A_void(N)                                              \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(N, typename A, void)                    \
/**/

#define PHOENIX_A(N)                                                            \
    BOOST_PP_ENUM_PARAMS(N, A)                                                  \
/**/

#define PHOENIX_A_ref(N)                                                        \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, & BOOST_PP_INTERCEPT)                     \
/**/

#define PHOENIX_A_const_ref(N)                                                  \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& BOOST_PP_INTERCEPT)                \
/**/

#define PHOENIX_A_a(N)                                                          \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, a)                                        \
/**/

#define PHOENIX_A_ref_a(N)                                                      \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, & a)                                      \
/**/

#define PHOENIX_A_const_ref_a(N)                                                \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& a)                                 \
/**/

#define PHOENIX_a(N)                                                            \
    BOOST_PP_ENUM_PARAMS(N, a)                                                  \
/**/

#else

#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/for_each_product.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

#define PHOENIX_ITERATION                                                       \
    BOOST_PP_ITERATION()                                                        \
/**/

#define PHOENIX_typename_A                                                      \
    BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename A)                         \
/**/

#define PHOENIX_typename_A_void                                                 \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(PHOENIX_ITERATION, typename A, void)    \
/**/

#define PHOENIX_A                                                               \
    BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, A)                                  \
/**/

#define PHOENIX_A_ref                                                           \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, & BOOST_PP_INTERCEPT)     \
/**/

#define PHOENIX_A_const_ref                                                     \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, const& BOOST_PP_INTERCEPT)\
/**/

#define PHOENIX_A_a                                                             \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, a)                        \
/**/

#define PHOENIX_A_ref_a                                                         \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, & a)                      \
/**/

#define PHOENIX_A_const_ref_a                                                   \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, const& a)                 \
/**/

#define PHOENIX_a                                                               \
    BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, a)                                  \
/**/

    /////////////////////////////////////////////////////////////////////////////
    // Begin Perfect Forward argument permutation calculation
    /////////////////////////////////////////////////////////////////////////////
#define PHOENIX_M0_R(_, N, __)                                                  \
    (((A ## N)(&))((A ## N)(const&)))                                           \
/**/

#define PHOENIX_M0                                                              \
    BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_M0_R, _)                         \
/**/

#define PHOENIX_M1_R_R(_, N, SEQ)                                               \
    BOOST_PP_SEQ_ELEM(N, SEQ)                                                   \
/**/

#define PHOENIX_M1_R(R, __, ___, ELEM)                                          \
    (BOOST_PP_REPEAT(BOOST_PP_SEQ_SIZE(ELEM), PHOENIX_M1_R_R, ELEM))            \
/**/

#define PHOENIX_M1(R, PRODUCT)                                                  \
    ((BOOST_PP_SEQ_ENUM                                                         \
        (BOOST_PP_SEQ_FOR_EACH_I_R                                              \
            (R, PHOENIX_M1_R, _, PRODUCT))))                                    \
/**/

#define PHOENIX_PERM_SEQ                                                        \
    BOOST_PP_SEQ_FOR_EACH_PRODUCT(PHOENIX_M1, PHOENIX_M0)                       \
/**/
    ////////////////////////////////////////////////////////////////////////////
    // End
    ////////////////////////////////////////////////////////////////////////////

#define PHOENIX_PERM_SIZE                                                       \
    BOOST_PP_SEQ_SIZE(PHOENIX_PERM_SEQ)                                         \
/**/

#define PHOENIX_M2(_, N, TUPLE)                                                 \
    BOOST_PP_COMMA_IF(N) BOOST_PP_TUPLE_ELEM(PHOENIX_ITERATION, N, TUPLE)       \
/**/
    
#define PHOENIX_M3(_, N, TUPLE)                                                 \
    BOOST_PP_COMMA_IF(N) BOOST_PP_TUPLE_ELEM(PHOENIX_ITERATION, N, TUPLE) a ## N\
/**/

#define PHOENIX_PERM_ELEM(N)                                                    \
    BOOST_PP_SEQ_ELEM(N, PHOENIX_PERM_SEQ)                                      \
/**/

#define PHOENIX_PERM_A(N)                                                       \
    BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_M2, PHOENIX_PERM_ELEM(N))        \
/**/

#define PHOENIX_PERM_A_a(N)                                                     \
    BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_M3, PHOENIX_PERM_ELEM(N))        \
/**/

#endif
