/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_DO_WHILE_HPP
#define PHOENIX_STATEMENT_DO_WHILE_HPP

#include <boost/phoenix/core/expression.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        do_while
      , (meta_grammar) // Cond
        (meta_grammar) // Do
    )

    struct do_while_eval
        : proto::callable
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
    
    template <typename Dummy>
    struct default_actions::when<rule::do_while, Dummy>
        : proto::call<
            do_while_eval(
                _context
              , proto::_child_c<0> // Cond
              , proto::_child_c<1> // Do
            )
          >
    {};

    template <typename Do>
    struct do_while_gen
    {
        do_while_gen(Do const& do_)
            : do_(do_) {}

        template <typename Cond>
        typename expression::do_while<Cond, Do>::type const
        while_(Cond const& cond) const
        {
            return expression::do_while<Cond, Do>::make(cond, do_);
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

    do_gen const do_ = {};

}}

#endif
