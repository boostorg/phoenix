/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_DETAIL_CONSTRUCT_HPP
#define PHOENIX_OBJECT_DETAIL_CONSTRUCT_HPP

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/object/detail/construct.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

    template <typename T, PHOENIX_typename_A>
    typename expression::construct<detail::target<T>, PHOENIX_A>::type const
    construct(PHOENIX_A_const_ref_a)
    {
        return
            expression::
                construct<detail::target<T>, PHOENIX_A>::
                    make(detail::target<T>(), PHOENIX_a);
    }

#endif
