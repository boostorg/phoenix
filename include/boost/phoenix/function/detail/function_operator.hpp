
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP
#define PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP

#include <boost/phoenix/function/detail/preprocessed/function_operator.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP
#define PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/function_operator_" PHOENIX_LIMIT_STR ".hpp")
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
    (3, (1, PHOENIX_ACTOR_LIMIT,                                                \
    <boost/phoenix/function/detail/function_operator.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else
        template <typename This, PHOENIX_typename_A>
        struct result<This(PHOENIX_A_const_ref)>
            : expression::function<F, PHOENIX_A>
        {};

        template <PHOENIX_typename_A>
        typename expression::function<F, PHOENIX_A>::type const
        operator()(PHOENIX_A_const_ref_a) const
        {
            return expression::function<F, PHOENIX_A>::make(f, PHOENIX_a);
        }

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
