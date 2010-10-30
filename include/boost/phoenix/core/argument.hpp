/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ARGUMENT_HPP
#define PHOENIX_CORE_ARGUMENT_HPP

/*
#include <boost/phoenix/core/compose.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/no_nullary.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/environment.hpp>
*/
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>

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
    
    template <typename I>
    struct argument
    {
        typedef I type;
        typedef typename I::value_type value_type;
        static value_type const value = I::value;
    };

}}

namespace boost {
    template <typename I>
    struct is_placeholder<phoenix::argument<I> >
        : mpl::true_
    {};
}

namespace boost { namespace phoenix
{
    #define BOOST_PHOENIX_ARGUMENT_N(_, N, name)                                \
    actor<                                                                      \
        proto::terminal<argument<mpl::int_<N> > >::type const                   \
    > const BOOST_PP_CAT(name, BOOST_PP_INC(N)) = {};

    namespace placeholders
    {
        BOOST_PP_REPEAT(PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, arg)
        BOOST_PP_REPEAT(PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, _)
    }

    namespace arg_names
    {
        BOOST_PP_REPEAT(PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, arg)
        BOOST_PP_REPEAT(PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, _)
    }

/*
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
        struct result<This(Env&, N const&)>
            : result_of::argument<Env, N>
        {};

        template <typename Env, typename N>
        typename result_of::argument<Env, N>::type
        operator()(Env& env, N const&) const
        {
            typedef typename boost::result_of<eval_grammar(N)>::type argument_id;
            return get_environment_argument_c<argument_id::value>(env);
        }
    };

    template <typename Dummy>
    struct enable_nullary<argument, Dummy>
        : mpl::false_
    {};

    
    template <typename N>
    struct make_argument : boost::phoenix::compose<argument, N> {};

    namespace placeholders
    {
    //  Phoenix style names
        make_argument<mpl::int_<0> >::type const arg1 = {};
        make_argument<mpl::int_<1> >::type const arg2 = {};
        make_argument<mpl::int_<2> >::type const arg3 = {};
        make_argument<mpl::int_<3> >::type const arg4 = {};
        make_argument<mpl::int_<4> >::type const arg5 = {};

    //  BLL style names
        make_argument<mpl::int_<0> >::type const _1 = {};
        make_argument<mpl::int_<1> >::type const _2 = {};
        make_argument<mpl::int_<2> >::type const _3 = {};
        make_argument<mpl::int_<3> >::type const _4 = {};
        make_argument<mpl::int_<4> >::type const _5 = {};
        make_argument<mpl::int_<5> >::type const _6 = {};
        make_argument<mpl::int_<6> >::type const _7 = {};
        make_argument<mpl::int_<7> >::type const _8 = {};
        make_argument<mpl::int_<8> >::type const _9 = {};
    }

    namespace arg_names
    {
        // bring in names for backwards compatibility

        using placeholders::arg1;
        using placeholders::arg2;
        using placeholders::arg3;
        using placeholders::arg4;
        using placeholders::arg5;

        using placeholders::_1;
        using placeholders::_2;
        using placeholders::_3;
    }
*/
}}

#endif
