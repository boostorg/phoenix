
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EXPRESSION_HPP
#define PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EXPRESSION_HPP

#include <boost/phoenix/support/iterate.hpp>

#include <boost/phoenix/statement/detail/preprocessed/try_catch_expression.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EXPRESSION_HPP
#define PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EXPRESSION_HPP

#include <boost/phoenix/support/iterate.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/try_catch_expression_" PHOENIX_LIMIT_STR ".hpp")
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
    (3, (0, PHOENIX_CATCH_LIMIT,                                                \
    <boost/phoenix/statement/detail/try_catch_expression.hpp>))
#include PHOENIX_ITERATE()

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else

        template <typename Try BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_typename_A>
        struct try_catch<Try BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_A>
            : expr_ext<
                try_catch_actor
              , tag::try_catch
              , Try
              BOOST_PP_COMMA_IF(PHOENIX_ITERATION) PHOENIX_A>
        {};
    /**/

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
