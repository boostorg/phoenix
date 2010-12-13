/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ACTOR_HPP
#define PHOENIX_CORE_ACTOR_HPP

#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/environment.hpp>
#include <boost/phoenix/core/is_nullary.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/extends.hpp>
#include <boost/utility/result_of.hpp>
#include <boost/mpl/void.hpp>

namespace boost { namespace phoenix
{
    template <typename Expr>
    struct actor;

    namespace detail
    {
        struct error_expecting_arguments
        {
            template <typename T>
            error_expecting_arguments(T const&) {}
        };
        
        struct error_invalid_lambda_expr
        {
            template <typename T>
            error_invalid_lambda_expr(T const&) {}
        };
    }

    namespace result_of
    {
        template <typename Expr
            , PHOENIX_typename_A_void(PHOENIX_ACTOR_LIMIT)
            , typename Dummy = void>
        struct actor;

        template <typename Expr>
        struct result_matches
                  : mpl::eval_if<
                        typename is_nullary<Expr>::type // avoid calling result_of::actor when this is false
                      , boost::result_of<
                            evaluator(
                                Expr const &
                              , fusion::vector2<fusion::vector0<>&, default_actions>&
                            )
                        >
                      , mpl::identity<detail::error_expecting_arguments>
                    >
        {};

        template <typename Expr>
        struct actor<Expr>
        {
            //static const int arity = result_of::arity<Expr>::type::value;

            typedef
                typename mpl::eval_if<
                    typename proto::matches<Expr, meta_grammar>::type
                  , result_matches<Expr>
                  , mpl::identity<detail::error_invalid_lambda_expr>
                >::type
            type;
        };

        template <typename Expr, typename A0>
        struct actor<Expr, A0>
            : boost::result_of<
                evaluator(
                    Expr const &
                  , fusion::vector2<fusion::vector1<A0>&, default_actions>&
                )
            >
        {};

        template <typename Expr, typename A0, typename A1>
        struct actor<Expr, A0, A1>
            : boost::result_of<
                evaluator(
                    Expr const&
                  , fusion::vector2<fusion::vector2<A0, A1>&, default_actions>&
                )
            >
        {};

        template <typename Expr, typename A0, typename A1, typename A2>
        struct actor<Expr, A0, A1, A2>
            : boost::result_of<
                evaluator(
                    Expr const&
                  , fusion::vector2<fusion::vector3<A0, A1, A2>&, default_actions>&
                )
            >
        {};

        // Bring in the rest
        #include <boost/phoenix/core/detail/actor_result_of.hpp>
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    //  actor
    //
    //      The actor class. The main thing! In phoenix, everything is an actor
    //      This class is responsible for full function evaluation. Partial
    //      function evaluation involves creating a hierarchy of actor objects.
    //
    ////////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, actor<Expr>, phoenix_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

        template <typename Sig>
        struct result;

        /*
        template <typename This>
        struct result<This()>
            : result_of::actor<Expr>
        {};
        */
        //BOOST_MPL_ASSERT((proto::matches<actor<Expr>, meta_grammar>));

        typename result_of::actor<Expr>::type
        operator()()
        {
            /*
            typedef make_basic_environment<default_actions> env_type;
            typename env_type::type env = env_type::make();
            */
            typedef fusion::vector0<> args_type;
            args_type args;
            fusion::vector2<args_type&, default_actions> env(args, default_actions());
            
            return eval(*this, env);
        }

        typename result_of::actor<Expr>::type
        operator()() const
        {
            /*
            typedef make_basic_environment<default_actions> env_type;
            typename env_type::type env = env_type::make();
            */
            typedef fusion::vector0<> args_type;
            args_type args;
            fusion::vector2<args_type&, default_actions> env(args, default_actions());

            typedef typename proto::domain_of<actor<Expr> >::type domain_type;
            typedef typename domain_type::proto_grammar grammar_type;

            std::cout << typeid(actor<Expr>).name() << "\n";
            std::cout << typeid(grammar_type).name() << "\n";
            
            return eval(*this, env);
        }
        
        // Bring in the rest
        #include <boost/phoenix/core/detail/actor_operator.hpp>
    };

}}

namespace boost
{
    // specialize boost::result_of to return the proper result type
    template <typename Expr>
    struct result_of<phoenix::actor<Expr>()>
        : phoenix::result_of::actor<Expr>
    {};
    
    template <typename Expr>
    struct result_of<phoenix::actor<Expr> const()>
        : result_of<phoenix::actor<Expr>()>
    {};
}

#endif

