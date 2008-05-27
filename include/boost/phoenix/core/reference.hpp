/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_REFERENCE_HPP_EAN_2008_05_10
#define BOOST_PHOENIX_REFERENCE_HPP_EAN_2008_05_10

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    struct reference
      : proto::terminal<T &>::type
    {
        explicit reference(T &t)
          : proto::terminal<T &>::type(
                proto::terminal<T &>::type::make(t)
            )
        {}

        reference(reference<T> const volatile &that)
          : proto::terminal<T &>::type(
                proto::terminal<T &>::type::make(that.child0)
            )
        {}

        operator actor<reference<T> >() const
        {
            // work around strange infinite recursion issue on gcc
            reference<T> const volatile &vthis = *this;
            actor<reference<T> > that = {vthis};
            return that;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    actor<reference<T> > const
    ref(T &t)
    {
        return reference<T>(t);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    actor<reference<T const> > const
    cref(T const &t)
    {
        return reference<T const>(t);
    }

}}

#endif
