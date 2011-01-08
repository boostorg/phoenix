/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP
#define PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/object/detail/new_eval.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

        template <typename Env, PHOENIX_typename_A>
        result_type
        operator()(Env& env, PHOENIX_A_const_ref_a) const
        {
#define EVAL_a(_,n,__) \
            BOOST_PP_COMMA_IF(n) eval(a ## n, env)

            return
                new construct_type(
                    BOOST_PP_REPEAT(PHOENIX_ITERATION, EVAL_a, _)
                );
#undef EVAL_a
        }

#endif
