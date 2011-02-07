
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP
#define PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP

#include <boost/phoenix/object/detail/preprocessed/new_eval.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP
#define PHOENIX_OBJECT_DETAIL_NEW_EVAL_HPP

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/new_eval_" PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (2, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/object/detail/new_eval.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename This, typename Context, PHOENIX_typename_A>
        struct result<This(Context, PHOENIX_A)>
        {
            typedef typename proto::detail::uncvref<typename proto::result_of::value<A0>::type>::type target_type;
            typedef typename target_type::type  construct_type;
            typedef typename target_type::type * type;
        };

        template <typename Context, PHOENIX_typename_A>
        typename result<new_eval(Context const &, PHOENIX_A_const_ref)>::type
        operator()(Context const & ctx, PHOENIX_A_const_ref_a) const
        {
#define EVAL_a(_,n,__) \
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) eval(a ## n, ctx)
            return new typename result<new_eval(Context const &, PHOENIX_A_const_ref)>::construct_type(
                    BOOST_PP_REPEAT_FROM_TO(1, PHOENIX_ITERATION, EVAL_a, _)
                );
#undef EVAL_a
        }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
