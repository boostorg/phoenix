/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_HPP
#define PHOENIX_CORE_ACTOR_HPP

#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/phoenix/core/arity.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/environment.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/support/iterate.hpp>
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
        template <typename Expr
            , PHOENIX_typename_A_void(PHOENIX_ACTOR_LIMIT)
            , typename Dummy = void>
        struct actor;

        template <typename Expr>
        struct actor<Expr>
        {
            static const int arity = result_of::arity<Expr>::type::value;

            typedef typename
                mpl::eval_if_c<
                    arity == 0 // avoid calling result_of::actor when this is true
                  , boost::result_of<eval_grammar(Expr const&, 
                        typename make_basic_environment<>::type&)>
                  , mpl::identity<detail::error_expecting_arguments>
                >::type
            type;
        };

        template <typename Expr, typename A0>
        struct actor<Expr, A0>
            : boost::result_of<eval_grammar(
                ::boost::phoenix::actor<Expr> const &,
                typename make_basic_environment<A0>::type&)
            >
        {};

        template <typename Expr, typename A0, typename A1>
        struct actor<Expr, A0, A1>
            : boost::result_of<eval_grammar(
                ::boost::phoenix::actor<Expr> const &,
                typename make_basic_environment<A0, A1>::type&)
            >
        {};

        template <typename Expr, typename A0, typename A1, typename A2>
        struct actor<Expr, A0, A1, A2>
            : boost::result_of<eval_grammar(
                ::boost::phoenix::actor<Expr> const &,
                typename make_basic_environment<A0, A1, A2>::type&)
            >
        {};

        // Bring in the rest
        #include <boost/phoenix/core/detail/actor_result_of.hpp>
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

        typename result_of::actor<Expr>::type
        operator()() const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<>::type args;

            return eval(this->proto_base(), args);
        }

        template <typename This, typename A0>
        struct result<This(A0)>
            : result_of::actor<Expr, A0>
        {};

        template <typename A0>
        typename result_of::actor<Expr, A0&>::type
        operator()(A0& a0) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&>::type args(a0);
            
            return eval(*this, args);
        }

        template <typename A0>
        typename result_of::actor<Expr, A0 const&>::type
        operator()(A0 const& a0) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0 const&>::type args(a0);
            
            return eval(*this, args);
        }

        template <typename This, typename A0, typename A1>
        struct result<This(A0&, A1&)>
            : result_of::actor<Expr, A0, A1>
        {};

        template <typename A0, typename A1>
        typename result_of::actor<Expr, A0&, A1&>::type
        operator()(A0& a0, A1& a1) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1&>::type args(a0, a1);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1>
        typename result_of::actor<Expr, A0&, A1 const&>::type
        operator()(A0& a0, A1 const& a1) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1 const&>::type args(a0, a1);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1>
        typename result_of::actor<Expr, A0 const&, A1&>::type
        operator()(A0 const& a0, A1& a1) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0 const&, A1&>::type args(a0, a1);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1>
        typename result_of::actor<Expr, A0 const&, A1 const&>::type
        operator()(A0 const& a0, A1 const& a1) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1&>::type args(a0, a1);
            
            return eval(this->proto_base(), args);
        }

        template <typename This, typename A0, typename A1, typename A2>
        struct result<This(A0, A1, A2)>
            : result_of::actor<Expr, A0, A1, A2>
        {};

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0&, A1&, A2&>::type
        operator()(A0& a0, A1& a1, A2& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1&, A2&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0 const&, A1&, A2&>::type
        operator()(A0 const& a0, A1& a1, A2& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0 const&, A1&, A2&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        } 

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0&, A1 const&, A2&>::type
        operator()(A0& a0, A1 const& a1, A2& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1 const&, A2&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0&, A1&, A2 const&>::type
        operator()(A0& a0, A1& a1, A2 const& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1&, A2 const&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0 const&, A1 const&, A2&>::type
        operator()(A0 const& a0, A1 const& a1, A2& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0 const&, A1 const&, A2&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0&, A1 const&, A2 const&>::type
        operator()(A0& a0, A1 const& a1, A2 const& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0&, A1 const&, A2 const&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        } 

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0 const&, A1&, A2 const&>::type
        operator()(A0 const& a0, A1& a1, A2 const& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0 const&, A1&, A2 const&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        }

        template <typename A0, typename A1, typename A2>
        typename result_of::actor<Expr, A0 const&, A1 const&, A2 const&>::type
        operator()(A0 const& a0, A1 const& a1, A2 const& a2) const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<A0 const&, A1 const&, A2 const&>::type args(a0, a1, a2);
            
            return eval(*this, args);
        }

        // Bring in the rest
        #include <boost/phoenix/core/detail/actor_operator.hpp>
    };
}}

namespace boost
{
    // specialize boost::result_of to return the proper result type
    template <typename Expr>
    struct result_of<phoenix::actor<Expr>()>
        : phoenix::result_of::actor<Expr>
    {};
    
    template <typename Expr>
    struct result_of<phoenix::actor<Expr> const()>
        : result_of<phoenix::actor<Expr>()>
    {};
}

#endif

