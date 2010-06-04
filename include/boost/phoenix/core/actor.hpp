/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_HPP
#define PHOENIX_CORE_ACTOR_HPP

#include <boost/proto/proto.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // The actor class. The main thing! In phoenix, everything is an actor
    // This class is responsible for full function evaluation. Partial
    // function evaluation involves creating a hierarchy of actor objects.
    ////////////////////////////////////////////////////////////////////////////
    template <class Expr>
    struct actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, actor<Expr>, phoenix_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

        template <class Sig>
        struct result : actor_result<Sig> {};

        typedef actor<Expr> actor_type;

        template <class A0>
        typename boost::result_of<actor_type(A0 const&)>::type
        operator()(A0 const& a0) const
        {
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);
            fusion::vector<A0 const&> args(a0);
            return eval(*this, args);
        }
        
        /*... more...*/
    };
}}

#endif
