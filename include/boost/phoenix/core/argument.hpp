/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ARGUMENT_HPP
#define PHOENIX_CORE_ARGUMENT_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/as_actor.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>

#include <boost/fusion/sequence/intrinsic/at.hpp>

#include <boost/mpl/int.hpp>

#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    // function for evaluating argument placeholders like: _1
    struct argument
    {
        template<typename N, template<typename> class Actor = actor >
        struct as_actor : boost::phoenix::as_actor<argument, Actor, N>
        {};

        template<typename Signature>
        struct result;

        template<typename This, typename Env, typename N>
        struct result<This(Env &, N &)>
            : fusion::result_of::at<
                Env, typename boost::result_of<eval_grammar(N)>::type>
        {};

        template<typename Env, typename N>
        typename boost::result_of<argument(Env &, N &)>::type
        operator()(Env & env, N &) const
        {
            return fusion::at<
                typename boost::result_of<eval_grammar(N)>::type>(env);
        }
    };

    namespace placeholders
    {
    //  Phoenix style names
        argument::as_actor<mpl::int_<0> >::result_type const arg1 = {};
        argument::as_actor<mpl::int_<1> >::result_type const arg2 = {};
        argument::as_actor<mpl::int_<2> >::result_type const arg3 = {};

    //  BLL style names
        argument::as_actor<mpl::int_<0> >::result_type const _1 = {};
        argument::as_actor<mpl::int_<1> >::result_type const _2 = {};
        argument::as_actor<mpl::int_<2> >::result_type const _3 = {};
    }

    namespace arg_names
    {
        // bring in names for backwards compatibility

        using placeholders::arg1;
        using placeholders::arg2;
        using placeholders::arg3;

        using placeholders::_1;
        using placeholders::_2;
        using placeholders::_3;
    }
}}

#endif
