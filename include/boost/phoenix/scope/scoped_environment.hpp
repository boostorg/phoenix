/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_SCOPED_ENVIRONMENT_HPP
#define PHOENIX_SCOPE_SCOPED_ENVIRONMENT_HPP

#include <boost/mpl/int.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/phoenix/core/environment.hpp>

namespace boost { namespace phoenix
{
    template <typename Env, typename OuterEnv, typename Locals, typename Map>
    struct scoped_environment;

    template <typename Env, typename Dummy = void>
    struct is_scoped_environment : mpl::false_ {};

    template <typename Env, typename OuterEnv, typename Locals, typename Map>
    struct is_scoped_environment<scoped_environment<Env, OuterEnv, Locals, Map> >
        : mpl::true_
    {};

    template <typename Env, typename OuterEnv, typename Locals, typename Map>
    struct is_scoped_environment<scoped_environment<Env, OuterEnv, Locals, Map> const>
        : mpl::true_
    {};

    // overload result_of::get_environment_argument to return the correct result type
    namespace result_of
    {
        template <typename Env, typename OuterEnv, typename Locals, typename Map, typename N>
        struct get_environment_argument<scoped_environment<Env, OuterEnv, Locals, Map> const, N>
            : fusion::result_of::at_c<Env, N::value>
        {};
        
        template <typename Env, typename OuterEnv, typename Locals, typename Map, typename N>
        struct get_environment_argument<scoped_environment<Env, OuterEnv, Locals, Map>, N>
            : fusion::result_of::at_c<Env, N::value>
        {};
    }
    
    // overload get_environment_argument to return the correct argument
    template <typename N, typename Env, typename OuterEnv, typename Locals, typename Map>
    typename result_of::get_environment_argument<scoped_environment<Env, OuterEnv, Locals, Map>, N>::type
    get_environment_argument_c(scoped_environment<Env, OuterEnv, Locals, Map>& env)
    {
        return fusion::at_c<N::value>(env.env);
    }
    
    template <typename N, typename Env, typename OuterEnv, typename Locals, typename Map>
    typename result_of::get_environment_argument<scoped_environment<Env, OuterEnv, Locals, Map>, N>::type
    get_environment_argument_c(scoped_environment<Env, OuterEnv, Locals, Map> const& env)
    {
        return fusion::at_c<N::value>(env.env);
    }


    // overload get_environment_argument_c to return the correct argument
    template <int N, typename Env, typename OuterEnv, typename Locals, typename Map>
    typename result_of::get_environment_argument<scoped_environment<Env, OuterEnv, Locals, Map>, mpl::int_<N> >::type
    get_environment_argument_c(scoped_environment<Env, OuterEnv, Locals, Map>& env)
    {
        return fusion::at_c<N>(env.env);
    }
    
    template <int N, typename Env, typename OuterEnv, typename Locals, typename Map>
    typename result_of::get_environment_argument<scoped_environment<Env, OuterEnv, Locals, Map>, mpl::int_<N> >::type
    get_environment_argument_c(scoped_environment<Env, OuterEnv, Locals, Map> const& env)
    {
        return fusion::at_c<N>(env.env);
    }

    template <typename Env, typename OuterEnv, typename Locals, typename Map>
    struct scoped_environment
    {
        typedef OuterEnv outer_env_type;
        typedef Locals locals_type;
        typedef Map map_type;

        scoped_environment(Env& env, OuterEnv& outer_env, Locals const& locals)
            : env(env)
            , outer_env(outer_env)
            , locals(locals) {}

        Env& env;
        OuterEnv& outer_env;
        Locals locals;
    };

}}

#endif
