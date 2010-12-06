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

    namespace result_of
    {
        template <typename Env, typename Tuple, int N>
        struct at_c
            : fusion::result_of::at_c<
                typename boost::remove_reference<
                    typename boost::result_of<
                        evaluator(Tuple const&, Env)
                    >::type
                >::type
              , N
            >
        {};
    }


    template <typename N>
    struct at_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Tuple>
        struct result<This(Env, Tuple const&)>
            : result_of::at_c<Env, Tuple, N::value>
        {};

        template <typename Env, typename Tuple>
        typename result_of::at_c<Env &, Tuple, N::value>::type
        operator()(Env& env, Tuple const& tuple) const
        {
            return fusion::at_c<0>(eval(tuple, env));
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::at_c, Dummy>
        : proto::lazy<at_eval<proto::_value(proto::_child_c<0>)>(_env, proto::_child_c<1>)>
    {};

    template <int N, typename Tuple>
    typename expression::at_c<mpl::int_<N>, Tuple>::type const
    at_c(Tuple const& tuple)
    {
        return expression::at_c<mpl::int_<N>, Tuple>::make(mpl::int_<N>(), tuple);
    }
}}

#endif
