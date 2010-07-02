/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_CONST_CAST_HPP
#define PHOENIX_OBJECT_CONST_CAST_HPP

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename T, typename U>
        struct const_cast_
        {
            typedef T type;
        };
    }

    template <typename T>
    struct const_cast_eval
    {
        typedef T result_type;

        template <typename Env, typename U>
        result_type
        operator()(Env& env, U const& u)
        {
            return const_cast<T>(eval(u, env));
        }
    };

    template <typename T, typename U>
    struct make_const_cast : compose<const_cast_eval<T>, U> {};

    template <typename T, typename U>
    typename make_const_cast<T, U>::type const
    const_cast_(U const& u)
    {
        return make_const_cast<T, U>()(u);
    }

}}

#endif
