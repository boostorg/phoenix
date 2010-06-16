/*==============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SUPPORT_ITERATE_HPP
#define PHOENIX_SUPPORT_ITERATE_HPP

#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_params_with_a_default.hpp>
#include <boost/preprocessor/tuple/elem.hpp>

#define PHOENIX_IS_ITERATING 0

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

#endif

