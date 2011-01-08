/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_FUNCTION_DETAIL_FUNCTION_RESULT_OF_HPP
#define PHOENIX_FUNCTION_DETAIL_FUNCTION_RESULT_OF_HPP

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ACTOR_LIMIT,                                                \
    <boost/phoenix/function/detail/function_result_of.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

        template <typename F, PHOENIX_typename_A>
        struct function<F, PHOENIX_A>
            : proto::result_of::make_expr<
                proto::tag::function
              , phoenix_domain
              , F
              , PHOENIX_A
            >
        {};

#endif
