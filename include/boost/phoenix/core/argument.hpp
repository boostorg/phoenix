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
#include <boost/phoenix/core/compose.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/environment.hpp>

#include <boost/fusion/sequence/intrinsic/at.hpp>

#include <boost/mpl/int.hpp>

#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    //
    //  argument
    //
    //      function for evaluating argument placeholders like: _1
    //
    ////////////////////////////////////////////////////////////////////////////

    namespace result_of
    {
        template <typename Env, typename N>
        struct argument
            : result_of::get_environment_argument<
                Env, typename boost::result_of<eval_grammar(N)>::type>
        {};
    }
    
    struct argument
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename N>
        struct result<This(Env&, N&)>
            : result_of::argument<Env, N>
        {};

        template <typename Env, typename N>
        typename result_of::argument<Env, N>::type
        operator()(Env& env, N& n) const
        {
            return get_environment_argument()(env, eval(n));
        }
    };
    
    template <typename N>
    struct make_argument : boost::phoenix::compose<argument, N> {};

    namespace placeholders
    {
    //  Phoenix style names
        make_argument<mpl::int_<0> >::type const arg1 = {};
        make_argument<mpl::int_<1> >::type const arg2 = {};
        make_argument<mpl::int_<2> >::type const arg3 = {};

    //  BLL style names
        make_argument<mpl::int_<0> >::type const _1 = {};
        make_argument<mpl::int_<1> >::type const _2 = {};
        make_argument<mpl::int_<2> >::type const _3 = {};
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
