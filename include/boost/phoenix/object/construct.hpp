/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_CONSTRUCT_HPP
#define PHOENIX_OBJECT_CONSTRUCT_HPP

#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename T, PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)>
        struct construct
        {
            typedef T type;
        };
    }

    template <typename T>
    struct construct_eval
    {
        typedef T result_type;

        template <typename Env>
        result_type
        operator()(Env& env) const
        {
            return T();
        }

#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_COMPOSITE_LIMIT,                                        \
        <boost/phoenix/object/construct.hpp>,                                   \
        PHOENIX_ITERATE_OPERATOR))
#include PHOENIX_ITERATE()
    };

    template <typename T, PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)>
    struct make_construct : compose<construct_eval<T>, PHOENIX_A(PHOENIX_COMPOSITE_LIMIT)>
    {};

    template <typename T>
    typename make_construct<T>::type const
    construct()
    {
        make_construct<T>()();
    }

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (1, PHOENIX_COMPOSITE_LIMIT,                                        \
        <boost/phoenix/object/construct.hpp>))
#include PHOENIX_ITERATE()
}}

#endif

#else

#if BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_OPERATOR

        template <typename Env, PHOENIX_typename_A>
        result_type
        operator()(Env& env, PHOENIX_A_const_ref_a) const
        {
#define EVAL_a(_,n,__) \
            BOOST_PP_COMMA_IF(n) eval(a ## n, env)

            return T(BOOST_PP_REPEAT(PHOENIX_ITERATION, EVAL_a, _));
#undef EVAL_a
        }

#else

    template <typename T, PHOENIX_typename_A>
    typename make_construct<T, PHOENIX_A>::type const
    construct(PHOENIX_A_const_ref_a)
    {
        return make_construct<T, PHOENIX_A>()(PHOENIX_a);
    }

#endif

#endif
