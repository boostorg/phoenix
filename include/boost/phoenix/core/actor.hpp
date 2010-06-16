/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_HPP
#define PHOENIX_CORE_ACTOR_HPP

#include <boost/fusion/container/vector/vector10.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/phoenix/core/arity.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/proto/extends.hpp>
#include <boost/proto/debug.hpp>
#include <boost/utility/result_of.hpp>

#include <boost/mpl/void.hpp>
namespace boost { namespace phoenix
{
    template <typename Expr>
    struct actor;

    namespace detail
    {
        struct error_expecting_arguments
        {
            template <typename T>
            error_expecting_arguments(T const&) {}
        };
    }

    namespace result_of
    {
        template <typename Expr, typename A0 = void, typename A1 = void
            /* ... more ... */
            , typename Dummy = void>
        struct actor;

        template <typename Expr>
        struct actor<Expr>
        {
            static const int arity = result_of::arity<Expr>::type::value;

            typedef typename
                mpl::eval_if_c<
                    arity == 0 // avoid calling result_of::actor when this is true
                  , boost::result_of<eval_grammar(Expr const&, fusion::vector0<>&)>
                  , mpl::identity<detail::error_expecting_arguments>
                >::type
            type;
        };
        
        template <typename Expr, typename A0>
        struct actor<Expr, A0>
            : boost::result_of<eval_grammar(
                ::boost::phoenix::actor<Expr> const&, fusion::vector1<A0>&)>
        {};
        
        template <typename Expr, typename A0, typename A1>
        struct actor<Expr, A0, A1>
            : boost::result_of<eval_grammar(
                ::boost::phoenix::actor<Expr> const&, fusion::vector2<A0, A1>&)>
        {};
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    //  actor
    //
    //      The actor class. The main thing! In phoenix, everything is an actor
    //      This class is responsible for full function evaluation. Partial
    //      function evaluation involves creating a hierarchy of actor objects.
    //
    ////////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, actor<Expr>, phoenix_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

        template <typename Sig>
        struct result;

        template <typename This>
        struct result<This()>
            : result_of::actor<Expr>
        {};

        template <typename This, typename A0>
        struct result<This(A0)>
            : result_of::actor<Expr, A0>
        {};

        template <typename This, typename A0, typename A1>
        struct result<This(A0, A1)>
            : result_of::actor<Expr, A0, A1>
        {};

        typename result_of::actor<Expr>::type
        operator()() const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            fusion::vector0<> args;

            return eval(this->proto_base(), args);
        }

        template <typename A0>
        typename result_of::actor<Expr, A0 const &>::type
        operator()(A0 const& a0) const
        {
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);
            fusion::vector1<A0 const&> args(a0);

            return eval(*this, args);
        }

        template <typename A0, typename A1>
        typename result_of::actor<Expr, A0 const &, A1 const &>::type
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

//  $$$ Why is this needed??? $$$
//    template<typename Expr>
//    struct result_of<phoenix::actor<Expr>() >
//    {
//        typedef typename phoenix::actor<Expr>::nullary_result type;
//    };

}

#endif
