/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EXPRESSION_HPP
#define PHOENIX_STATEMENT_DETAIL_TRY_CATCH_EXPRESSION_HPP

#include <boost/phoenix/support/iterate.hpp>

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (0, PHOENIX_CATCH_LIMIT,                                                \
    <boost/phoenix/statement/detail/try_catch_expression.hpp>))
#include PHOENIX_ITERATE()

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
