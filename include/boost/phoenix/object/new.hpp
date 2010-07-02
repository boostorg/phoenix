/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_NEW_HPP
#define PHOENIX_OBJECT_NEW_HPP

#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename T, PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)>
        struct new_
        {
            typedef T* type;
        };
    }

    template <typename T>
    struct new_eval
    {
        typedef T* result_type;

        template <typename Env>
        result_type
        operator()(Env& env) const
        {
            return new T;
        }

        template <typename Env, typename A0>
        result_type
        operator()(Env& env, A0 const& a0) const
        {
            return new T(eval(a0, env));
        }

        template <typename Env, typename A0, typename A1>
        result_type
        operator()(Env& env, A0 const& a0, A1 const& a1) const
        {
            return new T(eval(a0, env), eval(a1, env));
        }

        template <typename Env, typename A0, typename A1, typename A2>
        result_type
        operator()(Env& env, A0 const& a0, A1 const& a1, A2 const& a2) const
        {
            return new T(eval(a0, env), eval(a1, env), eval(a2, env));
        }

        // Bring in the rest
        #include <boost/phoenix/object/detail/new_eval.hpp>
    };

    template <typename T, PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)>
    struct make_new : compose<new_eval<T>, PHOENIX_A(PHOENIX_COMPOSITE_LIMIT)>
    {};

    template <typename T>
    typename make_new<T>::type const
    new_()
    {
        make_new<T>()();
    }

    template <typename T, typename A0>
    typename make_new<T, A0>::type const
    new_(A0 const& a0)
    {
        make_new<T, A0>()(a0);
    }

    template <typename T, typename A0, typename A1>
    typename make_new<T, A0, A1>::type const
    new_(A0 const& a0, A1 const& a1)
    {
        make_new<T, A0>()(a0, a1);
    }

    template <typename T, typename A0, typename A1, typename A2>
    typename make_new<T, A0, A1, A2>::type const
    new_(A0 const& a0, A1 const& a1, A2 const& a2)
    {
        make_new<T, A0>()(a0, a1, a2);
    }

    // Bring in the rest
    #include <boost/phoenix/object/detail/new.hpp>
}}

#endif

