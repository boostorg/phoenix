/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ENVIRONMENT_HPP
#define PHOENIX_CORE_ENVIRONMENT_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/fusion/container/vector.hpp>
#include <boost/fusion/support/is_sequence.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/proto.hpp>
#include <boost/proto/functional/fusion/at.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/utility/result_of.hpp>

#include <typeinfo>

namespace boost { namespace phoenix 
{
    namespace functional
    {
    #define BOOST_PHOENIX_GET_ENVIRONMENT(NAME, N)                              \
        struct NAME                                                             \
        {                                                                       \
            BOOST_PROTO_CALLABLE()                                              \
                                                                                \
            template <typename Sig>                                             \
            struct result;                                                      \
                                                                                \
            template <typename This, typename Env>                              \
            struct result<This(Env)>                                            \
                : result<This(Env const &)>                                     \
            {};                                                                 \
                                                                                \
            template <typename This, typename Env>                              \
            struct result<This(Env &)>                                          \
                : fusion::result_of::at<Env, mpl::int_<N> >                     \
            {};                                                                 \
                                                                                \
            template <typename Env>                                             \
            typename result<NAME(Env const &)>::type                            \
            operator()(Env const & env) const                                   \
            {                                                                   \
                return proto::functional::at()(env, mpl::int_<N>());            \
            }                                                                   \
                                                                                \
            template <typename Env>                                             \
            typename result<args(Env &)>::type                                  \
            operator()(Env & env) const                                         \
            {                                                                   \
                return proto::functional::at()(env, mpl::int_<N>());            \
            }                                                                   \
        };                                                                      \
    /**/
        BOOST_PHOENIX_GET_ENVIRONMENT(args, 0)
        BOOST_PHOENIX_GET_ENVIRONMENT(actions, 1)
    #undef BOOST_PHOENIX_GET_ENVIRONMENT

    }

    struct _context
        : proto::transform<_context>
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : proto::transform_impl<Expr, State, Data>
        {
            typedef fusion::vector2<State, Data> result_type;

            result_type operator()(
                typename impl::expr_param
              , typename impl::state_param s
              , typename impl::data_param d
            ) const
            {
                return fusion::vector2<State, Data>(s, d);
            }
        };
    };

    struct _env
        : proto::transform<_env>
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : proto::transform_impl<Expr, State, Data>
        {
            typedef State result_type;

            result_type operator()(
                typename impl::expr_param
              , typename impl::state_param s
              , typename impl::data_param
            ) const
            {
                return s;
            }
        };
    };

    template <typename Expr, typename State>
    struct _env::impl<Expr, State, int>
        : proto::transform_impl<Expr, State, int>
    {
            typedef
                typename fusion::result_of::at_c<
                    typename boost::remove_reference<State>::type
                  , 0
                >::type
                result_type;

            result_type operator()(
                typename impl::expr_param
              , typename impl::state_param s
              , typename impl::data_param
            ) const
            {
                return fusion::at_c<0>(s);
            }
    };

    /*
    struct _actions
        : proto::transform<_actions>
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : proto::transform_impl<Expr, State, Data>
        {
            typedef Data result_type;

            result_type operator()(
                typename impl::expr_param
              , typename impl::state_param
              , typename impl::data_param d
            ) const
            {
                return d;
            }
        };
    };

    template <typename Expr, typename State>
    struct _actions::impl<Expr, State, int>
        : proto::transform_impl<Expr, State, int>
    {
            typedef
                typename fusion::result_of::at_c<
                    typename boost::remove_reference<State>::type
                  , 1
                >::type
                result_type;

            result_type operator()(
                typename impl::expr_param
              , typename impl::state_param s
              , typename impl::data_param
            ) const
            {
                return fusion::at_c<1>(s);
            }
    };
*/

    template <typename T, typename Enable = void>
    struct is_environment : fusion::traits::is_sequence<T> {};
}}

#endif

