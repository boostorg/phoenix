/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_COMPOSE_HPP
#define PHOENIX_CORE_COMPOSE_HPP

#include <boost/call_traits.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/support/iterate.hpp>
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

        result_type
        operator()() const
        {
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}}};
            return e;
        }
    };

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/core/compose.hpp>))
#include PHOENIX_ITERATE()

}}

#endif

#else

    template <typename F, template<typename> class Actor, PHOENIX_typename_A>
    struct compose_ex<F, Actor, PHOENIX_A>
    {
        typedef
            typename proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , funcwrap<F>
                , env
                , PHOENIX_A>::type
            base_type;
        typedef Actor<base_type> result_type;
        typedef result_type type;

        result_type
        operator()(
            BOOST_PP_ENUM_BINARY_PARAMS(
                PHOENIX_ITERATION,
                typename call_traits< A, >::param_type a)) const
        {
#if PHOENIX_ITERATION == 1
            // silence gcc warnings
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, {a0}}};
#else
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, PHOENIX_a}};
#endif
            return e;
        }
    };

#endif
