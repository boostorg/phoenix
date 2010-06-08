/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_HPP
#define PHOENIX_CORE_ACTOR_HPP

#include <boost/fusion/container/vector/vector10.hpp>
#include <boost/phoenix/core/actor_result.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/proto/extends.hpp>
#include <boost/proto/debug.hpp>
#include <boost/utility/result_of.hpp>

#include <boost/mpl/void.hpp>
namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // The actor class. The main thing! In phoenix, everything is an actor
    // This class is responsible for full function evaluation. Partial
    // function evaluation involves creating a hierarchy of actor objects.
    ////////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, actor<Expr>, phoenix_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

        template <typename Sig>
        struct result : actor_result<Sig> {};

        typedef actor<Expr> actor_type;

        struct dummy {};

        //typename boost::result_of<actor_type()>::type
        //typename actor_result<actor_type()>::type
        //typename boost::result_of<eval_grammar(actor_type&, fusion::vector0<>&)>::type
        void
        operator()() const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            fusion::vector0<> args;

            eval(*this, args);
            //return eval(*this, args);
        }

        template <typename A0>
        //typename boost::result_of<actor_type(A0 const&)>::type
        typename actor_result<actor_type(A0 const&)>::type
        //typename boost::result_of<eval_grammar(actor_type&, fusion::vector1<A0>&)>::type
        operator()(A0 const& a0) const
        {
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);
            fusion::vector1<A0 const&> args(a0);

            return eval(*this, args);
        }

        template <typename A0, typename A1>
        //typename boost::result_of<actor_type(A0 const&, A1 const&)>::type
        typename actor_result<actor_type(A0 const&, A1 const&)>::type
        //typename boost::result_of<eval_grammar(actor_type&, fusion::vector1<A0, A1>&)>::type
        operator()(A0 const& a0, A1 const& a1) const
        {
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);
            fusion::vector2<A0 const&, A1 const &> args(a0, a1);

            std::cout << typeid( eval( *this, args ) ).name() << "\n";

            return eval(*this, args);
        }
        
        /*... more...*/
    };
}

    template<typename Expr>
    struct result_of<phoenix::actor<Expr>() >
    {
        typedef phoenix::actor<Expr> F;
        typedef typename F::template result<F()>::type type;
    };

}

#endif
