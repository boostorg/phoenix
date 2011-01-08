/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_FOR_HPP
#define PHOENIX_STATEMENT_FOR_HPP

#include <boost/phoenix/core/expression.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        for_
      , (meta_grammar) // Cond
        (meta_grammar) // Init
        (meta_grammar) // Step
        (meta_grammar) // Do
    )

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
    
    template <typename Dummy>
    struct default_actions::when<rule::for_, Dummy>
        : proto::call<
            for_eval(
                _env
              , proto::_child_c<0> // Cond
              , proto::_child_c<1> // Init
              , proto::_child_c<2> // Step
              , proto::_child_c<3> // Do
            )
          >
    {};
    
    template <typename Init, typename Cond, typename Step>
    struct for_gen
    {
        for_gen(Init const& init, Cond const& cond, Step const& step)
            : init(init), cond(cond), step(step) {}

        template <typename Do>
        typename expression::for_<Init, Cond, Step, Do>::type const
        operator[](Do const& do_) const
        {
            return
                expression::
                    for_<Init, Cond, Step, Do>::
                        make(init, cond, step, do_);
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
