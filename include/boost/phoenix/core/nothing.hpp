/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_NOTHING_HPP
#define PHOENIX_CORE_NOTHING_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/mpl/void.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/expression.hpp>

    
PHOENIX_DEFINE_EXPRESSION(
    (boost)(phoenix)(null)
  , (proto::terminal<mpl::void_>::type)
)

namespace boost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    //
    //  null_actor
    //
    //      An actor that does nothing (a "bum", if you will :-).
    //
    /////////////////////////////////////////////////////////////////////////////
    
    struct null_eval
    {
        BOOST_PROTO_CALLABLE()

        typedef void result_type;

        void operator()() const
        {}
    };

    template <typename Dummy>
    struct default_actions::when<rule::null, Dummy>
        : proto::call<null_eval()>
    {};

    template <typename Dummy>
    struct is_nullary::when<rule::null, Dummy>
        : proto::make<mpl::true_()>
    {};

    expression::null<mpl::void_>::type const nothing = {};
}}

#endif
