/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_CONSTRUCT_HPP
#define PHOENIX_OBJECT_CONSTRUCT_HPP

#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename T, PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)>
        struct construct
        {
            typedef T type;
        };
    }

    template <typename T>
    struct construct_eval
    {
        typedef T result_type;

        template <typename Env>
        result_type
        operator()(Env& env) const
        {
            return T();
        }

        template <typename Env, typename A0>
        result_type
        operator()(Env& env, A0 const& a0) const
        {
            return T(eval(a0, env));
        }

        template <typename Env, typename A0, typename A1>
        result_type
        operator()(Env& env, A0 const& a0, A1 const& a1) const
        {
            return T(eval(a0, env), eval(a1, env));
        }

        template <typename Env, typename A0, typename A1, typename A2>
        result_type
        operator()(Env& env, A0 const& a0, A1 const& a1, A2 const& a2) const
        {
            return T(eval(a0, env), eval(a1, env), eval(a2, env));
        }

        // Bring in the rest
        #include <boost/phoenix/object/detail/construct_eval.hpp>

    };

    template <typename T, PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)>
    struct make_construct
        : compose<construct_eval<T>, PHOENIX_A(PHOENIX_COMPOSITE_LIMIT)>
    {};

    template <typename T>
    typename make_construct<T>::type const
    construct()
    {
        make_construct<T>()();
    }

    template <typename T, typename A0>
    typename make_construct<T, A0>::type const
    construct(A0 const& a0)
    {
        return make_construct<T, A0>()(a0);
    }

    template <typename T, typename A0, typename A1>
    typename make_construct<T, A0, A1>::type const
    construct(A0 const& a0, A1 const& a1)
    {
        return make_construct<T, A0, A1>()(a0, a1);
    }

    template <typename T, typename A0, typename A1, typename A2>
    typename make_construct<T, A0, A1, A2>::type const
    construct(A0 const& a0, A1 const& a1, A2 const& a2)
    {
        return make_construct<T, A0, A1, A2>()(a0, a1, a2);
    }
        
    // Bring in the rest
    #include <boost/phoenix/object/detail/construct.hpp>

}}

#endif

