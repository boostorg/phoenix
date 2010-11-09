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

namespace boost { namespace phoenix 
{
    namespace functional
    {
        template <typename N, typename Callable = proto::callable>
        struct at
            : proto::callable
        {
            typedef typename boost::remove_reference<N>::type index;

            template <typename Sig>
            struct result;

            template <typename This, typename Seq>
            struct result<This(Seq)>
                : fusion::result_of::at_c<
                    typename boost::remove_reference<Seq>::type
                  , index::value
                >
            {};

            template <typename Seq>
            typename result<at(Seq &)>::type
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
                : boost::result_of<at<N>(typename boost::result_of<args(Env)>::type)>
            {};

            template <typename N, typename Env>
            typename result<args_at(N, Env &)>::type
            operator()(N const &, Env& env) const
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
    
    /*
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

    template <typename N, typename Env>
    typename boost::enable_if<
        is_environment<Env>
      , typename result_of::get_environment_argument<Env, N>::type
    >::type
    get_environment_argument_c(Env& env)
    {
        return fusion::at_c<N::value>(env);
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
    */
    
    template <typename Actions, PHOENIX_typename_A_void(PHOENIX_ARG_LIMIT), typename Dummy = void>
    struct make_basic_environment;
    
    template <typename Actions>
    struct make_basic_environment<Actions>
    {
		 typedef fusion::vector0<>                     params_type;
		 typedef fusion::vector2<params_type, Actions> type;

		 static type make()
		 {
			 return type(params_type(), Actions());
		 }
	 };

    template <typename Actions, typename A0>
    struct make_basic_environment<Actions, A0>
    {
		 typedef fusion::vector1<A0>                   params_type;
		 typedef fusion::vector2<params_type, Actions> type;

		 static type make(A0 a0)
		 {
			 return type(params_type(a0), Actions());
		 }
	 };

    template <typename Actions, typename A0, typename A1>
    struct make_basic_environment<Actions, A0, A1>
    {
		 typedef fusion::vector2<A0, A1>               params_type;
		 typedef fusion::vector2<params_type, Actions> type;

		 static type make(A0 a0, A1 a1)
		 {
			 params_type params(a0, a1);
			 return type(params, Actions());
		 }
	 };

    template <typename Actions, typename A0, typename A1, typename A2>
    struct make_basic_environment<Actions, A0, A1, A2>
    {
		 typedef fusion::vector3<A0, A1, A2>               params_type;
		 typedef fusion::vector2<params_type, Actions> type;

		 static type make(A0 a0, A1 a1, A2 a2)
		 {
			 return type(params_type(a0, a1, a2), Actions());
		 }
	 };

    // Bring in the rest
    #include <boost/phoenix/core/detail/make_basic_environment.hpp>
}}

#endif

