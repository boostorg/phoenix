/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_COMPOSE_HPP
#define PHOENIX_CORE_COMPOSE_HPP

#include <boost/call_traits.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing_params.hpp>
#include <boost/preprocessor/iteration/local.hpp>
#include <boost/proto/tags.hpp>
#include <boost/proto/make_expr.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Create an actor (TR1 function) from a proto transform and data type
    // we will associte with it (the actor).
    ////////////////////////////////////////////////////////////////////////////

    template <typename Expr>
    struct actor;
    
    template <typename F, template< typename > class Actor
        , typename A0 = void, typename A1 = void, typename A2 = void, typename A3 = void
        /* ... more ... */
        , typename Dummy = void>
    struct compose_ex;
    
    template <typename F
        , typename A0 = void, typename A1 = void, typename A2 = void, typename A3 = void
    /* ... more ... */
    , typename Dummy = void>
    struct compose : compose_ex<F, actor, A0, A1, A2, A3 /** ... more ... **/> {};

    template <typename F, template<typename> class Actor>
    struct compose_ex<F, Actor>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , proto::default_domain
                , funcwrap<F>
                , env>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type
        operator()() const
        {
            actor<base_type> const e = {{funcwrap<F>(), env()}};
            return e;
        }
    };

    template <typename F, template<typename> class Actor, typename A0>
    struct compose_ex<F, Actor, A0>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , proto::default_domain
                , funcwrap<F>
                , env
                , A0>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type
        operator()( typename call_traits<A0>::param_type a0 ) const
        {
            actor<base_type> const e = {{funcwrap<F>(), env(), a0}};
            return e;
        }
    };

    template <typename F, template<typename> class Actor, 
        typename A0, typename A1>
    struct compose_ex<F, Actor, A0, A1>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , proto::default_domain
                , funcwrap<F>
                , env
                , A0
                , A1>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type
        operator()( 
            typename call_traits<A0>::param_type a0, 
            typename call_traits<A1>::param_type a1) const
        {
            actor<base_type> const e = {{funcwrap<F>(), env(), a0, a1}};
            return e;
        }
    };

    template <typename F, template<typename> class Actor, 
        typename A0, typename A1, typename A2>
    struct compose_ex<F, Actor, A0, A1, A2>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , proto::default_domain
                , funcwrap<F>
                , env
                , A0
                , A1
                , A2>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type
        operator()( 
            typename call_traits<A0>::param_type a0, 
            typename call_traits<A1>::param_type a1, 
            typename call_traits<A2>::param_type a2) const
        {
            actor<base_type> const e = {{funcwrap<F>(), env(), a0, a1, a2}};
            return e;
        }
    };

}}

/*
#define BOOST_PP_LOCAL_MACRO( N )                                               \
namespace boost { namespace phoenix                                             \
{                                                                               \
    template <typename F, template<typename> class Actor                        \
        BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)>                           \
    struct compose_ex<F, Actor BOOST_PP_ENUM_TRAILING_PARAMS(N, A)>             \
    {                                                                           \
        typedef                                                                 \
            typename proto::result_of::make_expr<                               \
                  proto::tag::function                                          \
                , proto::default_domain                                         \
                , funcwrap< F >                                                 \
                , env BOOST_PP_ENUM_TRAILING_PARAMS(N, A)                       \
                >::type                                                         \
            base_type;                                                          \
                                                                                \
            typedef Actor<base_type> result_type;                               \
            typedef result_type type;                                           \
                                                                                \
            result_type                                                         \
            operator()(                                                         \
                BOOST_PP_ENUM_BINARY_PARAMS(N,                                  \
                    typename call_traits< A, >::param_type a)) const            \
            {                                                                   \
                actor<base_type> const e = {{                                   \
                    funcwrap< F >(), env() BOOST_PP_ENUM_TRAILING_PARAMS(N, a)  \
                }};                                                             \
                return e;                                                       \
            }                                                                   \
    };                                                                          \
}}

#define BOOST_PP_LOCAL_LIMITS ( 0, 3 )
#include BOOST_PP_LOCAL_ITERATE()
*/

#endif
