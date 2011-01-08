/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_REFERENCE_HPP
#define PHOENIX_CORE_REFERENCE_HPP

#include <boost/ref.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/terminal.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    //
    // reference
    //
    //      function for evaluating references, e.g. ref(123)
    //
    /////////////////////////////////////////////////////////////////////////////
    template <typename T>
    struct reference
        : proto::terminal<reference_wrapper<T> >
    {
        typedef actor<typename proto::terminal<reference_wrapper<T> >::type> type;
    };

    template <typename T>
    typename reference<T>::type const
    ref(T & t)
    {
        typename reference<T>::type const e = {{boost::ref(t)}};
        return e;
    }

    template <typename T>
    typename reference<T const>::type const
    cref(T const & t)
    {
        typename reference<T const>::type const e = {{boost::cref(t)}};
        return e;
    }

    // Call out boost::reference_wrapper for special handling
    template<typename T>
    struct is_custom_terminal<boost::reference_wrapper<T> >
      : mpl::true_
    {};

    // Special handling for boost::reference_wrapper
    template<typename T>
    struct custom_terminal<boost::reference_wrapper<T> >
    {
        typedef T &result_type;

        template <typename Env>
        T &operator()(boost::reference_wrapper<T> r, Env &) const
        {
            return r;
        }
    };
}}

#endif
