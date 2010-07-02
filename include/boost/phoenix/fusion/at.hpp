/*==============================================================================
    Copyright (c) 2005-2008 Hartmut Kaiser
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_FUSION_AT_HPP
#define PHOENIX_FUSION_AT_HPP

#include <boost/fusion/include/at.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/compose.hpp>
#include <boost/type_traits/remove_reference.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Env, typename Tuple, int N>
        struct at
            : fusion::result_of::at_c<
                typename remove_reference<
                    boost::result_of<
                        eval_grammar(Tuple const&, Env&)
                    >::type
                >
              , N
            >
        {};
    }

    template <int N>
    struct at_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Tuple>
        struct result<This(Env&, Tuple const&)>
            : result_of::at<Env, Tuple, N>
        {};

        template <typename Env, typename Tuple>
        typename result_of::at<Env, Tuple, N>::type
        operator()(Env& env, Tuple const& tuple) const
        {
            return fusion::at_c<N>(eval(tuple, env));
        }
    };

    template <int N, typename Tuple>
    struct make_at : compose<at_eval<N>, Tuple> {};

    template <int N, typename Tuple>
    typename make_at<N, Tuple>::type const
    at_c(Tuple const& tuple)
    {
        return make_at<N, Tuple>()(tuple);
    }

    template <typename N, typename Tuple>
    typename make_at<N::value, Tuple>::type const
    at(Tuple const& tuple)
    {
        return make_at<N::value, Tuple>()(tuple);
    }

}}

#endif
