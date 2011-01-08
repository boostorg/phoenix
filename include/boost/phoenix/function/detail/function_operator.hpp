/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP
#define PHOENIX_FUNCTION_DETAIL_FUNCTION_OPERATOR_HPP

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ACTOR_LIMIT,                                                \
    <boost/phoenix/function/detail/function_operator.hpp>))
#include PHOENIX_ITERATE()

#endif

#else
        template <typename This, PHOENIX_typename_A>
        struct result<This(PHOENIX_A)>
            :result<This(PHOENIX_A_const_ref)>
        {};

        template <typename This, PHOENIX_typename_A>
        struct result<This(PHOENIX_A_ref)>
            : result_of::function<F, PHOENIX_A>
        {};

        template <PHOENIX_typename_A>
        typename result_of::function<F, PHOENIX_A>::type const
        operator()(PHOENIX_A_ref_a) const
        {
            return proto::make_expr<
                proto::tag::function, phoenix_domain>(f, PHOENIX_a);
        }

        template <PHOENIX_typename_A>
        typename result_of::function<F, PHOENIX_A>::type const
        operator()(PHOENIX_A_const_ref_a) const
        {
            return proto::make_expr<
                proto::tag::function, phoenix_domain>(f, PHOENIX_a);
        }

#endif
