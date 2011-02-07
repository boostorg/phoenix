/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_NEW_HPP
#define PHOENIX_OBJECT_NEW_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/object/detail/target.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>

PHOENIX_DEFINE_EXPRESSION_VARARG(
    (boost)(phoenix)(new_)
  , (proto::terminal<detail::target<proto::_> >)
    (meta_grammar)
  , PHOENIX_COMPOSITE_LIMIT
)

namespace boost { namespace phoenix
{

    //template <typename T>
    struct new_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Context, typename A0>
        struct result<This(Context, A0)>
        {
            typedef typename proto::detail::uncvref<typename proto::result_of::value<A0>::type>::type target_type;
            typedef typename target_type::type  construct_type;
            typedef typename target_type::type * type;
        };

        template <typename Context, typename Target>
        typename result<new_eval(Context const &, Target)>::type
        operator()(Context const&, Target) const
        {
            return new typename result<new_eval(Context const &, Target)>::construct_type;
        }

        // Bring in the rest
        #include <boost/phoenix/object/detail/new_eval.hpp>
    };

    template <typename Dummy>
    struct default_actions::when<rule::new_, Dummy>
        : call<new_eval>
    {};

    template <typename T>
    typename expression::new_<detail::target<T> >::type const
    new_()
    {
        return
            expression::
                new_<detail::target<T> >::
                    make(detail::target<T>());
    }

    // Bring in the rest
    #include <boost/phoenix/object/detail/new.hpp>
}}

#endif

