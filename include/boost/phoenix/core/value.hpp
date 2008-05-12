/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_VALUE_HPP_EAN_2008_05_10
#define BOOST_PHOENIX_VALUE_HPP_EAN_2008_05_10

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
    struct value
      : proto::extends<typename proto::terminal<T>::type, value<T>, detail::domain>
    {
        explicit value(T const &t)
          : proto::extends<typename proto::terminal<T>::type, value<T>, detail::domain>(
                proto::terminal<T>::type::make(t)
            )
        {}

        // For backwards compatibility
        operator actor<value<T> >() const
        {
            actor<value<T> > that = {*this};
            return that;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename T>
    actor<typename proto::terminal<T>::type> const
    val(T const &t)
    {
        actor<typename proto::terminal<T>::type> that = {{t}};
        return that;
    }

    template<typename T, std::size_t N>
    actor<typename proto::terminal<T(&)[N]>::type> const
    val(T (&t)[N])
    {
        actor<typename proto::terminal<T(&)[N]>::type> that = {{t}};
        return that;
    }

    template<typename T, std::size_t N>
    actor<typename proto::terminal<T const(&)[N]>::type> const
    val(T const (&t)[N])
    {
        actor<typename proto::terminal<T const(&)[N]>::type> that = {{t}};
        return that;
    }

}}

#endif
