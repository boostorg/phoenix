/*==============================================================================
    Copyright (c) 2005-2008 Hartmut Kaiser
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_FUSION_AT_HPP
#define PHOENIX_FUSION_AT_HPP

#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        at_c
      , (proto::terminal<proto::_>)
        (meta_grammar)
    )
    
    template <typename Dummy>
    struct default_actions::when<rule::at_c, Dummy>
        : proto::call<
            proto::functional::at(
                evaluator(proto::_child_c<1>)
              , proto::_value(proto::_child_c<0>)
            )
        >
    {};

    template <int N, typename Tuple>
    typename expression::at_c<mpl::int_<N>, Tuple>::type const
    at_c(Tuple const& tuple)
    {
        return
            expression::
                at_c<mpl::int_<N>, Tuple>::
                    make(mpl::int_<N>(), tuple);
    }
}}

#endif
