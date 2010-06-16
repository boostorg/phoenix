/*==============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !BOOST_PP_IS_ITERATING

#ifndef PHOENIX_SUPPORT_DETAIL_ITERATE_HPP
#define PHOENIX_SUPPORT_DETAIL_ITERATE_HPP
#endif

#ifndef PHOENIX_ITERATION_PARAMS
#error "PHOENIX_ITERATION_PARAMS not define"
#endif

#define PHOENIX_ITERATION_PARAMS_SIZE                                           \
    BOOST_PP_TUPLE_ELEM(2, 0, PHOENIX_ITERATION_PARAMS)

#define PHOENIX_ITERATION_TUPLE                                                 \
    BOOST_PP_TUPLE_ELEM(2, 1, PHOENIX_ITERATION_PARAMS)

#define PHOENIX_ITERATION_START                                                 \
    BOOST_PP_TUPLE_ELEM(                                                        \
            PHOENIX_ITERATION_PARAMS_SIZE, 0, PHOENIX_ITERATION_TUPLE)

#define PHOENIX_ITERATION_END                                                   \
    BOOST_PP_TUPLE_ELEM(                                                        \
            PHOENIX_ITERATION_PARAMS_SIZE, 1, PHOENIX_ITERATION_TUPLE)


#define PHOENIX_ITERATION_FILE()                                                \
    BOOST_PP_TUPLE_ELEM(                                                        \
            PHOENIX_ITERATION_PARAMS_SIZE, 2, PHOENIX_ITERATION_TUPLE)

#if PHOENIX_ITERATION_PARAMS_SIZE == 3

#define BOOST_PP_ITERATION_PARAMS_1                                             \
    (3, (PHOENIX_ITERATION_START, PHOENIX_ITERATION_END,                        \
    <boost/phoenix/support/detail/iterate.hpp>))

#else

#define PHOENIX_ITERATION_FLAG                                                  \
    BOOST_PP_TUPLE_ELEM(                                                        \
            PHOENIX_ITERATION_PARAMS_SIZE, 3, PHOENIX_ITERATION_TUPLE)

#define BOOST_PP_ITERATION_PARAMS_1                                             \
    (4, (PHOENIX_ITERATION_START, PHOENIX_ITERATION_END,                        \
    <boost/phoenix/support/detail/iterate.hpp>,                                 \
    PHOENIX_ITERATION_FLAG))

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

#define PHOENIX_ITERATION BOOST_PP_ITERATION()

#undef PHOENIX_typename_A
#undef PHOENIX_typename_A_void
#undef PHOENIX_A
#undef PHOENIX_A_a
#undef PHOENIX_A_ref
#undef PHOENIX_A_const_ref
#undef PHOENIX_A_ref_a
#undef PHOENIX_A_const_ref_a
#undef PHOENIX_a

#define PHOENIX_typename_A BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename A)

#define PHOENIX_typename_A_void                                                 \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(PHOENIX_ITERATION, typename A, void)

#define PHOENIX_A                                                               \
    BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, A)

#define PHOENIX_A_ref                                                           \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, & BOOST_PP_INTERCEPT)

#define PHOENIX_A_const_ref                                                     \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, const& BOOST_PP_INTERCEPT)

#define PHOENIX_A_a BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, a)

#define PHOENIX_A_ref_a BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, & a)

#define PHOENIX_A_const_ref_a                                                   \
    BOOST_PP_ENUM_BINARY_PARAMS(PHOENIX_ITERATION, A, const& a)

#define PHOENIX_a                                                               \
    BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, a)

#define PHOENIX_M0_R_P(_, PRODUCT) (PRODUCT)

#define PHOENIX_M0_R(_, N, __)                                                  \
    (BOOST_PP_SEQ_FOR_EACH_PRODUCT( PHOENIX_M0_R_P, ((A ## N))((&)(const&))))

#define PHOENIX_M0 BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_M0_R, _)

#define PHOENIX_M1_R_F(_, STATE, ELEM) STATE ELEM

#define PHOENIX_M1_R(_, __, ___, ELEM)                                         \
    (BOOST_PP_SEQ_FOLD_RIGHT                                                   \
        (PHOENIX_M1_R_F, BOOST_PP_SEQ_HEAD(ELEM), BOOST_PP_SEQ_TAIL(ELEM)))

#define PHOENIX_M1(R, PRODUCT)                                                 \
    ((BOOST_PP_SEQ_ENUM                                                        \
        (BOOST_PP_SEQ_FOR_EACH_I_R                                             \
            (R, PHOENIX_M1_R, BOOST_PP_SEQ_SIZE( PRODUCT ), PRODUCT))))

#define PHOENIX_M2_R(_, __, I, ELEM)                                           \
    BOOST_PP_COMMA_IF(I)                                                       \
    BOOST_PP_SEQ_FOLD_LEFT                                                     \
        (PHOENIX_M1_R_F, BOOST_PP_SEQ_HEAD(ELEM), BOOST_PP_SEQ_TAIL(ELEM))     \
    a ## I

#define PHOENIX_M2(R, PRODUCT)                                                 \
    ((BOOST_PP_SEQ_FOR_EACH_I_R(R, PHOENIX_M2_R, _, PRODUCT)))

#define PHOENIX_SEQ_A BOOST_PP_SEQ_FOR_EACH_PRODUCT(PHOENIX_M1, PHOENIX_M0)

#define PHOENIX_SEQ_A_a BOOST_PP_SEQ_FOR_EACH_PRODUCT(PHOENIX_M2, PHOENIX_M0)

#define PHOENIX_PERM_SIZE BOOST_PP_SEQ_SIZE(PHOENIX_SEQ_A)

#ifdef BOOST_MSVC

#define PHOENIX_PERM_A(N)                                                           \
    BOOST_PP_TUPLE_REM(PHOENIX_ITERATION) BOOST_PP_SEQ_ELEM(N, PHOENIX_SEQ_A)

#define PHOENIX_PERM_A_a(N)                                                         \
    BOOST_PP_TUPLE_REM(PHOENIX_ITERATION) BOOST_PP_SEQ_ELEM(N, PHOENIX_SEQ_A_a)

#else

#define PHOENIX_PERM_A(N) BOOST_PP_EXPAND                                           \
    (BOOST_PP_TUPLE_REM(PHOENIX_ITERATION) BOOST_PP_SEQ_ELEM(N, PHOENIX_SEQ_A))

#define PHOENIX_PERM_A_a(N) BOOST_PP_EXPAND                                         \
    (BOOST_PP_TUPLE_REM(PHOENIX_ITERATION) BOOST_PP_SEQ_ELEM(N, PHOENIX_SEQ_A_a))

#endif

#include PHOENIX_ITERATION_FILE()

#undef PHOENIX_ITERATION
#undef PHOENIX_typename_A
#undef PHOENIX_typename_A_void
#undef PHOENIX_A
#undef PHOENIX_PERM_A
#undef PHOENIX_A_a
#undef PHOENIX_A_ref
#undef PHOENIX_A_const_ref
#undef PHOENIX_A_ref_a
#undef PHOENIX_A_const_ref_a
#undef PHOENIX_PERM_A_a
#undef PHOENIX_a

#define PHOENIX_ITERATE() \
    <boost/phoenix/support/detail/iterate.hpp>

#define PHOENIX_typename_A(N) BOOST_PP_ENUM_PARAMS(N, typename A)

#define PHOENIX_typename_A_void(N)                                              \
    BOOST_PP_ENUM_PARAMS_WITH_A_DEFAULT(N, typename A, void)

#define PHOENIX_A(N)                                                            \
    BOOST_PP_ENUM_PARAMS(N, A)

#define PHOENIX_A_ref(N)                                                        \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, & BOOST_PP_INTERCEPT)

#define PHOENIX_A_const_ref(N)                                                  \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& BOOST_PP_INTERCEPT)

#define PHOENIX_A_a(N) BOOST_PP_ENUM_BINARY_PARAMS(N, A, a)

#define PHOENIX_A_ref_a(N) BOOST_PP_ENUM_BINARY_PARAMS(N, A, & a)

#define PHOENIX_A_const_ref_a(N)                                                \
    BOOST_PP_ENUM_BINARY_PARAMS(N, A, const& a)

#define PHOENIX_a(N)                                                            \
    BOOST_PP_ENUM_PARAMS(N, a)

#undef PHOENIX_M0_R_P
#undef PHOENIX_M0_R
#undef PHOENIX_M0
#undef PHOENIX_M1_R_F
#undef PHOENIX_M1_R
#undef PHOENIX_M1
#undef PHOENIX_M2_R
#undef PHOENIX_M2
#undef PHOENIX_SEQ_A
#undef PHOENIX_SEQ_A_a
#undef PHOENIX_PERM_SIZE

#undef PHOENIX_IS_ITERATING
#define PHOENIX_IS_ITERATING 0

#endif
