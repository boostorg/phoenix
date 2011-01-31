/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_WHILE_HPP
#define PHOENIX_STATEMENT_WHILE_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        while_
      , (meta_grammar) // Cond
        (meta_grammar) // Do
    )

    struct while_eval
    {
        typedef void result_type;

        template <typename Context, typename Cond, typename Do>
        result_type
        operator()(Context& ctx, Cond const& cond, Do const& do_) const
        {
            while(eval(cond, ctx))
            {
                eval(do_, ctx);
            }
        }
    };
    
    template <typename Dummy>
    struct default_actions::when<rule::while_, Dummy>
        : proto::call<
            while_eval(
                _context
              , proto::_child_c<0> // Cond
              , proto::_child_c<1> // Do
            )
          >
    {};

    template <typename Cond>
    struct while_gen
    {
        while_gen(Cond const& cond) : cond(cond) {}

        template <typename Do>
        typename expression::while_<Cond, Do>::type const
        operator[](Do const& do_) const
        {
            return expression::while_<Cond, Do>::make(cond, do_);
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
