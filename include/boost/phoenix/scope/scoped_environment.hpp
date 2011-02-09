/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_SCOPED_ENVIRONMENT_HPP
#define PHOENIX_SCOPE_SCOPED_ENVIRONMENT_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/mpl/int.hpp>
#include <boost/fusion/sequence/sequence_facade.hpp>
#include <boost/fusion/sequence/intrinsic/begin.hpp>
#include <boost/fusion/sequence/intrinsic/end.hpp>
#include <boost/fusion/sequence/intrinsic/size.hpp>
#include <boost/fusion/sequence/intrinsic/value_at.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/support/category_of.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    template<typename Env, typename OuterEnv, typename Locals>
    struct scoped_environment
        : fusion::sequence_facade<
            scoped_environment<Env, OuterEnv, Locals>
          , fusion::random_access_traversal_tag
        >
    {
        /*
        typedef typename boost::remove_reference<Env>::type env_type;
        typedef typename boost::remove_reference<OuterEnv>::type outer_env_type;
        typedef typename boost::remove_reference<Locals>::type locals_type;
        */
        typedef Env env_type;
        typedef OuterEnv outer_env_type;
        typedef Locals locals_type;

        scoped_environment(
                /*
            env_type& env
          , outer_env_type& outer_env
          , locals_type & locals
          */
            Env env
          , OuterEnv outer_env
          , Locals locals
        )
            : env(env)
            , outer_env(outer_env)
            , locals(locals)
        {}

        scoped_environment(scoped_environment const& o)
            : env(o.env)
            , outer_env(o.outer_env)
            , locals(o.locals)
        {}

        /*
        env_type env;
        outer_env_type outer_env;
        locals_type locals;
        */
        Env      env;
        OuterEnv outer_env;
        Locals   locals;
    
        #define PHOENIX_ADAPT_SCOPED_ENVIRONMENT(INTRINSIC)                     \
        template <typename Seq>                                                 \
        struct INTRINSIC                                                        \
        {                                                                       \
            typedef typename fusion::result_of::INTRINSIC<typename Seq::env_type>::type type; \
                                                                                \
            static type call(Seq & seq)                                         \
            {                                                                   \
                return fusion::INTRINSIC(seq.env);                              \
            }                                                                   \
        }                                                                       \
        /**/
        PHOENIX_ADAPT_SCOPED_ENVIRONMENT(begin);
        PHOENIX_ADAPT_SCOPED_ENVIRONMENT(end);
        PHOENIX_ADAPT_SCOPED_ENVIRONMENT(size);
        #undef PHOENIX_ADAPT_SCOPED_ENVIRONMENT
    
        template <typename Seq, typename N>
        struct value_at
        {
            typedef
                typename fusion::result_of::value_at<typename proto::detail::uncvref<typename Seq::env_type>::type, N>::type
                type;
        };
        
        template <typename Seq, typename N>
        struct at
        {
            typedef typename fusion::result_of::at<typename proto::detail::uncvref<typename Seq::env_type>::type, N>::type type;

            static type call(Seq & seq)
            {
                return fusion::at<N>(seq.env);
            }
        };
    };

    template <typename Env, typename Dummy = void>
    struct is_scoped_environment : mpl::false_ {};
    
    template <typename Env>
    struct is_scoped_environment<Env&> : is_scoped_environment<Env> {};
    
    template <typename Env, typename OuterEnv, typename Locals>
    struct is_scoped_environment<scoped_environment<Env, OuterEnv, Locals> >
        : mpl::true_
    {};

    template <typename Env, typename OuterEnv, typename Locals>
    struct is_scoped_environment<scoped_environment<Env, OuterEnv, Locals> const>
        : mpl::true_
    {};
}}

#endif
