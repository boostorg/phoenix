/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_FOR_HPP
#define PHOENIX_STATEMENT_FOR_HPP

#include <boost/phoenix/core/compose.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <
            typename Env
          , typename Init
          , typename Cond
          , typename Step
          , typename Do>
        struct for_
        {
            typedef void type;
        };

    }

    struct for_eval
    {
        typedef void result_type;

        template <
            typename Env
          , typename Init
          , typename Cond
          , typename Step
          , typename Do>
        result_type
        operator()(
            Env& env
          , Init const& init
          , Cond const& cond
          , Step const& step
          , Do const& do_) const
        {
            for(eval(init, env); eval(cond, env); eval(step, env))
                eval(do_, env);
        }
    };
    
    template <typename Init, typename Cond, typename Step, typename Do>
    struct make_for : compose<for_eval, Init, Cond, Step, Do> {};

    template <typename Init, typename Cond, typename Step>
    struct for_gen
    {
        for_gen(Init const& init, Cond const& cond, Step const& step)
            : init(init), cond(cond), step(step) {}

        template <typename Do>
        typename make_for<Init, Cond, Step, Do>::type const
        operator[](Do const& do_) const
        {
            return make_for<Init, Cond, Step, Do>()(init, cond, step, do_);
        }

        Init const& init;
        Cond const& cond;
        Step const& step;
    };

    template <typename Init, typename Cond, typename Step>
    for_gen<Init, Cond, Step> const
    for_(Init const& init, Cond const& cond, Step const& step)
    {
        return for_gen<Init, Cond, Step>(init, cond, step);
    }

}}

#endif
