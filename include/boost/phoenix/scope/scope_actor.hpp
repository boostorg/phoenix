/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_SCOPE_ACTOR_HPP
#define PHOENIX_SCOPE_SCOPE_ACTOR_HPP

#include <boost/phoenix/scope/scope_domain.hpp>
#include <boost/phoenix/scope/scope_grammar.hpp>

namespace boost { namespace phoenix
{
    template <typename Expr>
    struct scope_actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, scope_actor<Expr>, scope_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

    };
}}

#endif
