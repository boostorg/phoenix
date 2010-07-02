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
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/tags.hpp>
#include <boost/proto/make_expr.hpp>

namespace foo { template< typename T > struct wrap{}; }

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Create an actor (TR1 function) from a proto transform and data type
    // we will associte with it (the actor).
    ////////////////////////////////////////////////////////////////////////////

    template <typename Expr>
    struct actor;

    struct default_domain_with_basic_expr
      : proto::domain<proto::use_basic_expr<proto::default_generator> >
    {};
    
    template <typename F, template< typename > class Actor
        , PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)
        , typename Dummy = void>
    struct compose_ex;
    
    template <typename F
        , PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)
        , typename Dummy = void>
    struct compose : compose_ex<F, actor, PHOENIX_A(PHOENIX_COMPOSITE_LIMIT)> {};

    template <typename F, template<typename> class Actor>
    struct compose_ex<F, Actor>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , funcwrap<F>
                , env>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type const
        operator()() const
        {
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}}};
            return e;
        }
    };

    template <typename F, template<typename> class Actor, typename A0>
    struct compose_ex<F, Actor, A0>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , funcwrap<F>
                , env
                , A0>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type const
        operator()(typename call_traits<A0>::param_type a0) const
        {
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, a0}};
            return e;
        }
    };

    template <typename F, template<typename> class Actor, typename A0, typename A1>
    struct compose_ex<F, Actor, A0, A1>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , funcwrap<F>
                , env
                , A0
                , A1>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type const
        operator()(typename call_traits<A0>::param_type a0,typename call_traits<A1>::param_type a1) const
        {
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, a0, a1}};
            return e;
        }
    };

    template <typename F, template<typename> class Actor, typename A0, typename A1, typename A2>
    struct compose_ex<F, Actor, A0, A1, A2>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , funcwrap<F>
                , env
                , A0
                , A1
                , A2>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type const
        operator()(
            typename call_traits<A0>::param_type a0,
            typename call_traits<A1>::param_type a1,
            typename call_traits<A2>::param_type a2) const
        {
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, a0, a1, a2}};
            return e;
        }
    };

    // Bring in the rest
    #include <boost/phoenix/core/detail/compose_ex.hpp>

}}

#endif

