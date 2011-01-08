/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_SCOPE_DETAIL_LET_LOCAL_GEN_HPP
#define PHOENIX_SCOPE_DETAIL_LET_LOCAL_GEN_HPP

#include <boost/phoenix/support/iterate.hpp>

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (2, PHOENIX_LOCAL_LIMIT,                                                \
    <boost/phoenix/scope/detail/let_local_gen.hpp>))
#include PHOENIX_ITERATE()

#endif

#else

        template <PHOENIX_typename_A>
        let_actor_gen<
            typename detail::make_locals<PHOENIX_A>::type
        > const
        operator()(PHOENIX_A_const_ref_a) const
        {
            return detail::make_locals<PHOENIX_A>::make(PHOENIX_a);
        }

#endif
