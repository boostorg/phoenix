/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_RESULT_OF_HPP

#include <boost/phoenix/support/iterate.hpp>

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ACTOR_LIMIT,                                                \
    <boost/phoenix/core/detail/actor_result_of.hpp>))
#include PHOENIX_ITERATE()

#endif
       
#else

        template <typename Expr, PHOENIX_typename_A>
        struct actor<Expr, PHOENIX_A>
        {
            typedef
                typename phoenix::evaluator::
                    impl<
                        Expr const&
                      , fusion::vector2<
                            BOOST_PP_CAT(
                                fusion::vector
                              , PHOENIX_ITERATION
                            )<PHOENIX_A>
                          , default_actions
                        >
                      , int
                    >::result_type
                type;
        };

#endif

