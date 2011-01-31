/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LAMBDA_HPP
#define PHOENIX_SCOPE_LAMBDA_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/mpl/int.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/scope/local_variable.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        lambda
      , (proto::terminal<proto::_>) // OuterEnv 
        (rule::local_var_def_list)  // Locals
        (meta_grammar)              // Lambda
    )

    struct lambda_eval
    {
        BOOST_PROTO_CALLABLE()

        template <typename Sig>
        struct result;

        template <
            typename This
          , typename Context
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        struct result<This(Context, OuterEnv, Locals, Lambda)>
            : result<This(Context const &, OuterEnv &, Locals &, Lambda &)>
        {};

        template <
            typename This
          , typename Context
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        struct result<This(Context, OuterEnv &, Locals &, Lambda &)>
            : result<This(Context const &, OuterEnv &, Locals &, Lambda &)>
        {};

        template <
            typename This
          , typename Context
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        struct result<This(Context &, OuterEnv &, Locals &, Lambda &)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename result_of::env<Context>::type
                >::type
                env_type;

            typedef
                typename proto::detail::uncvref<
                    typename result_of::actions<Context>::type
                >::type
                actions_type;

            typedef
                typename proto::detail::uncvref<Locals>::type
                locals_type;

            typedef
                typename proto::detail::uncvref<OuterEnv>::type
                outer_env_type;

            typedef
                scoped_environment<env_type, outer_env_type const, locals_type const>
                scoped_env;

            typedef
                typename result_of::context<scoped_env, actions_type&>::type
                ctx_type;

            typedef
                typename evaluator::impl<Lambda const &, ctx_type&, int>::result_type
                type;
        };
        
        template <
            typename Context
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        typename result<
            lambda_eval(Context &, OuterEnv const&, Locals &, Lambda &)
        >::type
        operator()(
            Context& ctx
          , OuterEnv const & outer_env
          , Locals const& locals
          , Lambda const& lambda
        ) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename result_of::env<Context>::type
                >::type
                env_type;

            typedef
                typename proto::detail::uncvref<
                    typename result_of::actions<Context>::type
                >::type
                actions_type;

            typedef
                typename proto::detail::uncvref<Locals>::type
                locals_type;

            typedef
                typename proto::detail::uncvref<OuterEnv>::type
                outer_env_type;

            typedef
                scoped_environment<env_type, OuterEnv const, locals_type const>
                scoped_env_type;

            
            env_type e(env(ctx));

            scoped_env_type
                scoped_env(
                    e
                  , outer_env
                  , locals
                );

            typename result_of::context<scoped_env_type, actions_type&>::type
                new_ctx(scoped_env, actions(ctx));
            return eval(lambda, new_ctx);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::lambda, Dummy>
        : proto::call<
            lambda_eval(
                _context
              , proto::_value(proto::_child_c<0>)
              , proto::_child_c<1>
              , proto::_child_c<2>
            )
        >
    {};

    template <typename Dummy>
    struct is_nullary::when<rule::lambda, Dummy>
        : proto::when<
            expression::lambda<
                proto::terminal<proto::_>
              , rule::local_var_def_list
              , meta_grammar
            >
          , evaluator(
                proto::_child_c<2>
              , _context(
                    proto::_
                  , mpl::true_()
                  , detail::scope_is_nullary_actions()
                )
			  , int()
            )
        >
    {};

    namespace tag
    {
        struct lambda_actor {};
    }

    namespace expression
    {
        template <typename A0 = void, typename A1 = void, typename Dummy = void>
        struct lambda_actor;

        template <typename A0>
        struct lambda_actor<A0>
            : expr<tag::lambda_actor, A0>
        {};

        template <typename A0, typename A1>
        struct lambda_actor<A0, A1>
            : expr< tag::lambda_actor, A0, A1>
        {};
    }

    namespace rule
    {
        struct lambda_actor
            : proto::or_<
                expression::lambda_actor<meta_grammar>
              , expression::lambda_actor<rule::local_var_def_list, meta_grammar>
            >
        {};
    }

    template <typename Dummy>
    struct is_nullary::when<rule::lambda_actor, Dummy>
        : proto::or_<
            proto::when<
                expression::lambda_actor<meta_grammar>
              , mpl::true_()
            >
          , proto::when<
                expression::lambda_actor<
                    rule::local_var_def_list
                  , meta_grammar
                >
              , detail::local_var_def_is_nullary(
                    proto::_child_c<0>
                  , _context
                  , int()
                )
            >
        >
    {};

    template <typename Dummy>
    struct meta_grammar::case_<tag::lambda_actor, Dummy>
        : proto::when<rule::lambda_actor, proto::external_transform>
    {};

    struct lambda_actor_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Context, typename Lambda>
        struct result<This(Context, Lambda)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename result_of::env<Context>::type
                >::type
                env_type;

            typedef
                typename expression::lambda<
                    env_type
                  , mpl::void_
                  , typename proto::detail::uncvref<Lambda>::type
                >::type
                type;
        };

        template <typename This, typename Context, typename Locals, typename Lambda>
        struct result<This(Context, Locals, Lambda)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename rule::local_var_def_list::impl<
                        typename proto::detail::uncvref<Locals>::type &
                      , Context
                      , int
                    >::result_type
                >::type
                locals_type;

            typedef
                typename proto::detail::uncvref<
                    typename result_of::env<Context>::type
                >::type
                env_type;

            typedef
                typename expression::lambda<
                    env_type
                  , locals_type
                  , typename proto::detail::uncvref<Lambda>::type
                >::type const
                type;
        };

        template <typename Context, typename Lambda>
        typename result<lambda_actor_eval(Context&, Lambda const&)>::type
        operator()(Context & ctx, Lambda const& lambda) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename result_of::env<Context>::type
                >::type
                env_type;

            mpl::void_ t;
            return
                expression::
                    lambda<env_type, mpl::void_, Lambda>::
                        make(env(ctx), t, lambda);
        }

        template <
            typename Context
          , typename Locals
          , typename Lambda
        >
        typename result<
            lambda_actor_eval(Context&, Locals const&, Lambda const&)
        >::type
        operator()(Context & ctx, Locals const& locals, Lambda const& lambda) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename rule::local_var_def_list::impl<
                        Locals &
                      , Context
                      , int
                    >::result_type
                >::type
                locals_type;

            locals_type l = 
                   rule::local_var_def_list()(
                      locals
                    , ctx
                    );

            typedef
                typename proto::detail::uncvref<
                    typename result_of::env<Context>::type
                >::type
                env_type;

            return
                expression::
                    lambda<env_type, locals_type, Lambda>::
                        make(env(ctx), l, lambda);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::lambda_actor, Dummy>
        : proto::or_<
            proto::when<
                expression::lambda_actor<meta_grammar>
              , lambda_actor_eval(_context, proto::_child_c<0>)
            >
          , proto::when<
                expression::lambda_actor<
                    rule::local_var_def_list
                  , meta_grammar
                >
              , lambda_actor_eval(_context, proto::_child_c<0>, proto::_child_c<1>)
            >
        >
    {};
    
    template <typename Locals = void, typename Dummy = void>
    struct lambda_actor_gen;

    template <>
    struct lambda_actor_gen<void, void>
    {
        template <typename Expr>
        typename expression::lambda_actor<Expr>::type const
        operator[](Expr const & expr) const
        {
            return expression::lambda_actor<Expr>::make(expr);
        }
    };

    template <typename Locals>
    struct lambda_actor_gen<Locals>
    {
        lambda_actor_gen(Locals const & locals)
            : locals(locals)
        {}

        template <typename Expr>
        typename expression::lambda_actor<
            Locals
          , Expr
        >::type const
        operator[](Expr const & expr) const
        {
            return expression::lambda_actor<Locals, Expr>::make(locals, expr);
        }

        Locals locals;
    };

    struct lambda_local_gen
        : lambda_actor_gen<>
    {
        lambda_actor_gen<> const
        operator()() const
        {
            return lambda_actor_gen<>();
        }

        template <typename Expr0>
        lambda_actor_gen<Expr0> const
        operator()(Expr0 const& expr0) const
        {
            return expr0;
        }

    #define PHOENIX_LAMBDA_LOCAL_GEN(Z, N, DATA)                                \
        template <PHOENIX_typename_A(N)>                                        \
        lambda_actor_gen<                                                       \
            typename detail::make_locals<PHOENIX_A(N)>::type                    \
        > const                                                                 \
        operator()(PHOENIX_A_const_ref_a(N)) const                              \
        {                                                                       \
            return detail::make_locals<PHOENIX_A(N)>::make(PHOENIX_a(N));       \
        }                                                                       \
    /**/
        BOOST_PP_REPEAT_FROM_TO(2, PHOENIX_LOCAL_LIMIT, PHOENIX_LAMBDA_LOCAL_GEN, _)

    };

    lambda_local_gen const lambda = lambda_local_gen();

}}

#endif
