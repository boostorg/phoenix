/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_BIND_BIND_HPP
#define PHOENIX_BIND_BIND_HPP

#include <boost/phoenix/function/function.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{

    ////////////////////////////////////////////////////////////////////////////
    // Bind
    ////////////////////////////////////////////////////////////////////////////
    
    template<typename F>
    typename boost::result_of<function<F>()>::type
    bind(F f)
    {
        return function<F>(f)();
    }
    
    template<typename F, typename A0>
    typename boost::result_of<function<F>(A0 const &)>::type
    bind(F f, A0 const & a0)
    {
        return function<F>(f)(a0);
    }

    template<typename F, typename A0, typename A1>
    typename boost::result_of<function<F>(A0 const &, A1 const &)>::type
    bind(F f, A0 const & a0, A1 const & a1)
    {
        return function<F>(f)(a0, a1);
    }

    /* ... more ... */

}}

#endif
