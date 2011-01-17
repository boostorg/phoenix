
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_OBJECT_DETAIL_NEW_HPP
#define PHOENIX_OBJECT_DETAIL_NEW_HPP

#include <boost/phoenix/object/detail/preprocessed/new.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_DETAIL_NEW_HPP
#define PHOENIX_OBJECT_DETAIL_NEW_HPP

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/new_" PHOENIX_LIMIT_STR ".hpp")
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

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/object/detail/new.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

    template <typename T, PHOENIX_typename_A>
    typename expression::new_<detail::target<T>, PHOENIX_A>::type const
    new_(PHOENIX_A_const_ref_a)
    {
        return
            expression::
                new_<detail::target<T>, PHOENIX_A>::
                    make(detail::target<T>(), PHOENIX_a);
    }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
