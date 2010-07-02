/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_COMPOSE_RESULT_OF_HPP
#define PHOENIX_CORE_DETAIL_COMPOSE_RESULT_OF_HPP

#include <boost/phoenix/support/iterate.hpp>

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/core/detail/compose_ex.hpp>))
#include PHOENIX_ITERATE()

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

        result_type const
        operator()(
            BOOST_PP_ENUM_BINARY_PARAMS(
                PHOENIX_ITERATION,
                typename call_traits< A, >::param_type a)) const
        {
#if PHOENIX_ITERATION == 1
            // silence gcc warnings
            //actor<base_type> const e = {{{funcwrap<F>()}, {env()}, {a0}}};
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, a0}};
#elif PHOENIX_ITERATION == 2
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, a0, a1}};
#else
            actor<base_type> const e = {{{funcwrap<F>()}, {env()}, PHOENIX_a}};
#endif
            return e;
        }
    };

#endif
