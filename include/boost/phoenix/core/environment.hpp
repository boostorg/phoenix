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
#include <boost/utility/enable_if.hpp>
#include <boost/utility/result_of.hpp>

#include <typeinfo>

namespace boost { namespace phoenix 
{
    namespace functional
    {
        template <typename N>
        struct at
            : proto::callable
        {
            typedef typename boost::remove_reference<N>::type index;

            template <typename Sig>
            struct result;

            template <typename This, typename Seq>
            struct result<This(Seq)>
                : result<This(Seq const&)>
            {};

            template <typename This, typename Seq>
            struct result<This(Seq &)>
                : fusion::result_of::at_c<Seq, index::value>
            {};

            template <typename Seq>
            typename fusion::result_of::at_c<Seq, index::value>::type
            operator()(Seq& seq) const
            {
                return fusion::at_c<index::value>(seq);
            }
        };

        typedef at<mpl::int_<0> > args;
        typedef at<mpl::int_<1> > actions;

        struct args_at
            : proto::callable
        {
            template <typename Sig>
            struct result;

            template <typename This, typename N, typename Env>
            struct result<This(N, Env)>
                : result<This(N, Env const&)>
            {};

            template <typename This, typename N, typename Env>
            struct result<This(N, Env &)>
                : boost::result_of<
                    at<N>(typename args::result<args(Env &)>::type)
                >
            {};

            template <typename N, typename Env>
            typename result<args_at(N, Env &)>::type
            operator()(N, Env& env) const
            {
                return at<N>()(args()(env));
            }
        };
    }

    struct _env
        : proto::transform<_env>
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

    template <typename T, typename Enable = void>
    struct is_environment : fusion::traits::is_sequence<T> {};
}}

namespace boost { namespace proto
{
    template <typename N>
    struct is_callable<boost::phoenix::functional::at<N> > : mpl::true_ {};
}}

#endif

