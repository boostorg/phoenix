/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_DELETE_HPP
#define PHOENIX_OBJECT_DELETE_HPP

namespace boost { namespace phoenix
{

    namespace result_of
    {
        template <typename Env, typename P>
        struct delete_
        {
            typedef void type;
        };
    }

    struct delete_eval
    {
        typedef void result_type;

        template <typename Env, typename P>
        result_type
        operator()(Env& env, P const& p) const
        {
            return delete eval(p, env);
        }
    };

    template <typename P>
    struct make_delete : compose<delete_eval, P> {};

    template <typename P>
    typename make_delete<P>::type const
    delete_(P const& p)
    {
        return make_delete<P>()(p);
    }

}}

#endif
