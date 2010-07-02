/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_STATIC_CAST_HPP
#define PHOENIX_OBJECT_STATIC_CAST_HPP

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename T, typename U>
        struct static_cast_
        {
            typedef T type;
        };
    }

    template <typename T>
    struct static_cast_eval
    {
        typedef T result_type;

        template <typename Env, typename U>
        result_type
        operator()(Env& env, U const& u)
        {
            return static_cast<T>(eval(u, env));
        }
    };

    template <typename T, typename U>
    struct make_static_cast : compose<static_cast_eval<T>, U> {};

    template <typename T, typename U>
    typename make_static_cast<T, U>::type const
    static_cast_(U const& u)
    {
        return make_static_cast<T, U>()(u);
    }

}}

#endif
