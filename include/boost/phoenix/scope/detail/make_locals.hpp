
/*
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_SCOPE_DETAIL_MAKE_LOCALS_HPP
#define PHOENIX_SCOPE_DETAIL_MAKE_LOCALS_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/scope/detail/preprocessed/make_locals.hpp>

#endif
#else
*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_SCOPE_DETAIL_MAKE_LOCALS_HPP
#define PHOENIX_SCOPE_DETAIL_MAKE_LOCALS_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/make_locals_" PHOENIX_LIMIT_STR ".hpp")
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

#define PHOENIX_TYPEDEF_LOCAL_TYPES(Z, N, D) \
            typedef \
                typename proto::result_of::value< \
                    typename proto::result_of::child_c< \
                        typename proto::result_of::child_c< \
                            BOOST_PP_CAT(A, N) \
                          , 0 \
                        >::type \
                      , 0 \
                    >::type \
                >::type \
                BOOST_PP_CAT(tag_type, N); \
\
            typedef \
                typename proto::result_of::child_c< \
                    BOOST_PP_CAT(A, N) \
                  , 1 \
                >::type \
                BOOST_PP_CAT(var_type, N);\

#define PHOENIX_TYPEDEF_LOCAL_PAIR_TYPES(Z, N, D) \
    BOOST_PP_COMMA_IF(N) fusion::pair<BOOST_PP_CAT(tag_type, N), BOOST_PP_CAT(var_type, N)>

#define PHOENIX_CHILD_OF(Z, N, D) \
    BOOST_PP_COMMA_IF(N) proto::child_c<1>(BOOST_PP_CAT(a, N))


#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_LOCAL_LIMIT,                                                \
    <boost/phoenix/scope/detail/make_locals.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <PHOENIX_typename_A>
        struct make_locals<PHOENIX_A>
        {
            BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_TYPEDEF_LOCAL_TYPES, _)
            typedef fusion::map<BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_TYPEDEF_LOCAL_PAIR_TYPES, _)> type;

            static type const make(PHOENIX_A_a)
            {
                return type(BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_CHILD_OF, _));
            }
        };

#endif

//#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
