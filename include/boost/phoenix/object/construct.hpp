/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_CONSTRUCT_HPP
#define PHOENIX_OBJECT_CONSTRUCT_HPP

#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/unpack.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/fusion.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION_VARARG(
        construct
      , (proto::terminal<detail::target<proto::_> >)
        (meta_grammar)
      , PHOENIX_COMPOSITE_LIMIT
    )

    template <typename T>
    struct construct_eval
    {
        typedef typename T::type result_type;

        template <typename Env>
        result_type
        operator()(Env& env) const
        {
            return result_type();
        }

        // Bring in the rest
        #include <boost/phoenix/object/detail/construct_eval.hpp>

    };

    template <typename Dummy>
    struct default_actions::when<rule::construct, Dummy>
        : proto::lazy<
            construct_eval<
                proto::_value(proto::_child_c<0>)
            >(_env, unpack(proto::functional::pop_front(proto::_)))
        >
    {};

    template <typename T>
    typename expression::construct<detail::target<T> >::type const
    construct()
    {
        return
            expression::
                construct<detail::target<T> >::
                    make(detail::target<T>());
    }

    // Bring in the rest
    #include <boost/phoenix/object/detail/construct.hpp>

}}

#endif

