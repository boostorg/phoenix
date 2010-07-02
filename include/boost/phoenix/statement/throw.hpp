/*==============================================================================
    Copyright (c) 2005-2007 Dan Marsden
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_THROW_HPP
#define PHOENIX_STATEMENT_THROW_HPP

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename ThrowExpr = void, typename Dummy=void>
        struct throw_
        {
            typedef void type;
        };
    }

    struct throw_eval
    {
        typedef void result_type;

        template <typename Env>
        result_type
        operator()(Env& env) const
        {
            throw;
        }

        template <typename Env, typename ThrowExpr>
        result_type
        operator()(Env& env, ThrowExpr const& throw_expr) const
        {
            throw eval(throw_expr, env);
        }
    };

    template <typename ThrowExpr = void>
    struct make_throw : compose<throw_eval, ThrowExpr> {};

    make_throw<>::type const
    throw_()
    {
        return make_throw<>()();
    }

    template <typename ThrowExpr>
    typename make_throw<ThrowExpr>::type const
    throw_(ThrowExpr const& throw_expr)
    {
        return make_throw<ThrowExpr>()(throw_expr);
    }

}}

#endif
