/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_WHILE_HPP
#define PHOENIX_STATEMENT_WHILE_HPP

#include <boost/phoenix/core/compose.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename Cond, typename Do>
        struct while_
        {
            typedef void type;
        };
    }

    struct while_eval
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Do>
        result_type
        operator()(Env& env, Cond const& cond, Do const& do_) const
        {
            while(eval(cond, env))
            {
                eval(do_, env);
            }
        }
    };

    template <typename Cond, typename Do>
    struct make_while : compose<while_eval, Cond, Do> {};

    template <typename Cond>
    struct while_gen
    {
        while_gen(Cond const& cond) : cond(cond) {}

        template <typename Do>
        typename make_while<Cond, Do>::type const
        operator[](Do const& do_) const
        {
            return make_while<Cond, Do>()(cond, do_);
        }

        Cond const& cond;
    };

    template <typename Cond>
    while_gen<Cond> const
    while_(Cond const& cond)
    {
        return while_gen<Cond>(cond);
    }


}}

#endif
