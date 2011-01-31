/*==============================================================================
    Copyright (c) 2005-2007 Dan Marsden
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_THROW_HPP
#define PHOENIX_STATEMENT_THROW_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/terminal.hpp>

namespace boost { namespace phoenix
{
    namespace tag
    {
        struct throw_ {};
    }

    namespace expression
    {
        template <typename A = mpl::na>
        struct throw_
            : expr<tag::throw_, A>
        {};
    }

    namespace rule
    {
        struct throw_
            : expression::throw_<meta_grammar>
        {};

        struct rethrow_
            : expression::throw_<proto::terminal<mpl::na> >
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<tag::throw_, Dummy>
        : proto::or_<
            proto::when<rule::rethrow_, proto::external_transform>
          , proto::when<rule::throw_, proto::external_transform>
        >
    {};

    struct throw_eval
    {
        typedef void result_type;

        template <typename Context>
        result_type
        operator()(Context& ctx) const
        {
            throw;
        }

        template <typename Context, typename ThrowExpr>
        result_type
        operator()(Context& ctx, ThrowExpr const& throw_expr) const
        {
            throw eval(throw_expr, ctx);
        }
    };
    
    template <typename Dummy>
    struct default_actions::when<rule::rethrow_, Dummy>
        : proto::call<throw_eval(_context)>
    {};

    template <typename Dummy>
    struct default_actions::when<rule::throw_, Dummy>
        : proto::call<throw_eval(_context, proto::_child_c<0>)>
    {};

    expression::throw_<>::type const
    throw_()
    {
        return expression::throw_<>::make(mpl::na());
    }

    template <typename ThrowExpr>
    typename expression::throw_<ThrowExpr>::type const
    throw_(ThrowExpr const& throw_expr)
    {
        return expression::throw_<ThrowExpr>::make(throw_expr);
    }

}}

#endif
