/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_DO_WHILE_HPP
#define PHOENIX_STATEMENT_DO_WHILE_HPP

#include <boost/phoenix/core/compose.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename Cond, typename Do>
        struct do_while
        {
            typedef void type;
        };
    }

    struct do_while_eval
    {
        typedef void result_type;

        template <typename Env, typename Cond, typename Do>
        result_type
        operator()(Env& env, Cond const& cond, Do const& do_) const
        {
            do
                eval(do_, env);
            while (eval(cond, env));
        }
    };

    template <typename Cond, typename Do>
    struct make_do_while : compose<do_while_eval, Cond, Do> {};

    template <typename Do>
    struct do_while_gen
    {
        do_while_gen(Do const& do_)
            : do_(do_) {}

        template <typename Cond>
        typename make_do_while<Cond, Do>::type const
        while_(Cond const& cond) const
        {
            return make_do_while<Cond, Do>()(cond, do_);
        }

        Do const& do_;
    };

    struct do_gen
    {
        template <typename Do>
        do_while_gen<Do> const
        operator[](Do const& do_) const
        {
            return do_while_gen<Do>(do_);
        }
    };

    do_gen const do_ = do_gen();

}}

#endif
