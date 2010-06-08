/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_NOTHING_HPP
#define PHOENIX_CORE_NOTHING_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/as_actor.hpp>

namespace boost { namespace phoenix
{
///////////////////////////////////////////////////////////////////////////////
//
//  null_actor
//
//      A actor that does nothing (a "bum", if you will :-).
//
///////////////////////////////////////////////////////////////////////////////
    struct null_actor
    {
        typedef void result_type;

        template <typename Env>
        void
        eval(Env const&) const
        {
        }
    };

    as_actor<null_actor, actor>::result_type const nothing = {};

}}

#endif
