/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_BIND_BIND_HPP
#define PHOENIX_BIND_BIND_HPP

#include <boost/phoenix/function.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Bind
    ////////////////////////////////////////////////////////////////////////////
    
    template <typename F>
    typename boost::result_of<function<F>()>::type const
    bind(F f)
    {
        return function<F>(f)();
    }

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ARG_LIMIT,                                                  \
    <boost/phoenix/bind/bind.hpp>))
#include PHOENIX_ITERATE()

}}

#endif

#else
    
    template <typename F, PHOENIX_typename_A>
    typename result_of::function<F, PHOENIX_A>::type const
    bind(F f, PHOENIX_A_const_ref_a)
    {
        return function<F>(f)(PHOENIX_a);
    }

#endif
