/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ENVIRONMENT_HPP
#define PHOENIX_CORE_ENVIRONMENT_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost { namespace phoenix 
{
    template <typename T, typename Enable = void>
    struct is_environment : fusion::traits::is_sequence<T> {};
    
    namespace result_of 
    {
        template <typename Env, typename N, typename Dummy = void>
        struct get_environment_argument
            : fusion::result_of::at_c<Env, N::value> {};
    }

    template <int N, typename Env>
    typename boost::enable_if<
        is_environment<Env>
      , typename result_of::get_environment_argument<Env, mpl::int_<N> >::type
    >::type
    get_environment_argument_c(Env& env)
    {
        return fusion::at_c<N>(env);
    }

    // Get the Nth argument from the environment
    struct get_environment_argument
    {
        template <typename Sig>
        struct result;
        
        template <typename This, typename Env, typename N>
        struct result<This(Env&, N)>
            : result_of::get_environment_argument<Env, N> {};
        
        template <typename Env, typename N>
        typename result_of::get_environment_argument<Env, N>::type
        operator()(Env& env, N) const
        {
            return get_environment_argument_c<N::value>(env);
            //return fusion::at_c<N::value>(env);
        }
    };
    
    template <PHOENIX_typename_A_void(PHOENIX_ARG_LIMIT), typename Dummy = void>
    struct make_basic_environment;
    
    template <>
    struct make_basic_environment<>
        : mpl::identity<fusion::vector0<> > {};

    template <typename A0>
    struct make_basic_environment<A0>
        : mpl::identity<fusion::vector1<A0> > {};

    template <typename A0, typename A1>
    struct make_basic_environment<A0, A1>
        : mpl::identity<fusion::vector2<A0, A1> > {};

    template <typename A0, typename A1, typename A2>
    struct make_basic_environment<A0, A1, A2>
        : mpl::identity<fusion::vector3<A0, A1, A2> > {};

    // Bring in the rest
    #include <boost/phoenix/core/detail/make_basic_environment.hpp>
}}

#endif

