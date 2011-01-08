/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_SCOPE_DETAIL_MAKE_LOCALS_HPP
#define PHOENIX_SCOPE_DETAIL_MAKE_LOCALS_HPP

#include <boost/phoenix/support/iterate.hpp>

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (3, PHOENIX_LOCAL_LIMIT,                                                \
    <boost/phoenix/scope/detail/make_locals.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

        template <PHOENIX_typename_A>
        struct make_locals<PHOENIX_A>
        {
            typedef
                typename make_locals<
                    BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_ITERATION), A)
                >::type const
                type0;

            typedef
                typename expression::sequence<
                    type0
                  , BOOST_PP_CAT(A, BOOST_PP_DEC(PHOENIX_ITERATION))
                >::type
                type;

            static type const make(PHOENIX_A_a)
            {
                return
                    expression::sequence<
                        type0
                      , BOOST_PP_CAT(A, BOOST_PP_DEC(PHOENIX_ITERATION))
                    >::make(
                        make_locals<
                            BOOST_PP_ENUM_PARAMS(
                                BOOST_PP_DEC(PHOENIX_ITERATION)
                              , A
                            )
                        >::make(
                            BOOST_PP_ENUM_PARAMS(
                                BOOST_PP_DEC(PHOENIX_ITERATION)
                              , a
                            )
                        )
                      , BOOST_PP_CAT(a, BOOST_PP_DEC(PHOENIX_ITERATION))
                    );
            }
        };

#endif
