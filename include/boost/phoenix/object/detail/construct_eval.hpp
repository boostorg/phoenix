
/*
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_OBJECT_DETAIL_CONSTRUCT_EVAL_HPP
#define PHOENIX_OBJECT_DETAIL_CONSTRUCT_EVAL_HPP

#include <boost/phoenix/object/detail/preprocessed/construct_eval.hpp>

#endif
#else
*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_DETAIL_CONSTRUCT_EVAL_HPP
#define PHOENIX_OBJECT_DETAIL_CONSTRUCT_EVAL_HPP

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/object/detail/construct_eval.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
        
        template <typename Context, PHOENIX_typename_A>
        result_type
        operator()(Context& ctx, PHOENIX_A_const_ref_a) const
        {
#define EVAL_a(_,n,__) \
            BOOST_PP_COMMA_IF(n) eval(a ## n, ctx)

            return result_type(BOOST_PP_REPEAT(PHOENIX_ITERATION, EVAL_a, _));
#undef EVAL_a
        }

#endif

//#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
