/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ENVIRONMENT_HPP
#define PHOENIX_CORE_ENVIRONMENT_HPP

#include <boost/fusion/support/is_sequence.hpp>
#include <boost/fusion/container/vector/vector10.hpp>
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
    
//    template <typename Actor, typename Env, typename Enable = void>
//    struct get_signature<Actor, Env, 
//        typename enable_if<fusion::traits::is_sequence<T> >::type>
//    {
//    };
}}

#endif
