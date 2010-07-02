/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_MAKE_BASIC_ENVIRONMENT_HPP
#define PHOENIX_CORE_DETAIL_MAKE_BASIC_ENVIRONMENT_HPP

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (4, PHOENIX_ARG_LIMIT,                                                  \
    <boost/phoenix/core/detail/make_basic_environment.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

    template <PHOENIX_typename_A>
    struct make_basic_environment<PHOENIX_A>
        : mpl::identity<
            BOOST_PP_CAT(fusion::vector, PHOENIX_ITERATION)<PHOENIX_A> > {};

#endif
