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
    namespace detail
    {
        struct domain;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    struct reference
      : proto::extends<typename proto::terminal<T &>::type, reference<T>, detail::domain>
    {
        explicit reference(T &t)
          : proto::extends<typename proto::terminal<T &>::type, reference<T>, detail::domain>(
                proto::terminal<T &>::type::make(t)
            )
        {}

        // For backwards compatibility
        operator actor<reference<T> >() const
        {
            actor<reference<T> > that = {*this};
            return that;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    actor<typename proto::terminal<T &>::type> const
    ref(T &t)
    {
        actor<typename proto::terminal<T &>::type> that = {{t}};
        return that;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    actor<typename proto::terminal<T const &>::type> const
    cref(T const &t)
    {
        actor<typename proto::terminal<T const &>::type> that = {{t}};
        return that;
    }

}}

#endif
