/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_ENVIRONMENT_HPP
#define PHOENIX_CORE_ENVIRONMENT_HPP

#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/container/vector/vector10.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/utility/enable_if.hpp>

namespace boost { namespace phoenix 
{
    template <typename T, typename Enable = void>
    struct is_environment : fusion::traits::is_sequence<T> {};
    
    namespace result_of 
    {
        template <typename Env, typename N>
        struct get_environment_argument
            : fusion::result_of::at_c<Env, N::value> {};
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
            return fusion::at_c<N::value>(env);
        }
    };
    
    template <PHOENIX_typename_A_void(PHOENIX_ARG_LIMIT), typename Dummy = void>
    struct make_basic_environment;
    
    template <>
    struct make_basic_environment<>
        : mpl::identity<fusion::vector0<> > {};

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ARG_LIMIT,                                                  \
    <boost/phoenix/core/environment.hpp>))
#include PHOENIX_ITERATE()

}}

#endif

#else
    
    template <PHOENIX_typename_A>
    struct make_basic_environment<PHOENIX_A>
        : mpl::identity<
            BOOST_PP_CAT(fusion::vector, PHOENIX_ITERATION)<PHOENIX_A> > {};

#endif
