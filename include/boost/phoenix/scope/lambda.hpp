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
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/scope/local_variable.hpp>

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
          , typename Env
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        struct result<This(Env, OuterEnv, Locals, Lambda)>
            : result<This(Env const &, OuterEnv &, Locals &, Lambda &)>
        {};

        template <
            typename This
          , typename Env
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        struct result<This(Env, OuterEnv &, Locals &, Lambda &)>
            : result<This(Env const &, OuterEnv &, Locals &, Lambda &)>
        {};

        template <
            typename This
          , typename Env
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        struct result<This(Env &, OuterEnv &, Locals &, Lambda &)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                args_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::actions::result<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                fusion::vector2<args_type, actions_type>
                env_type;

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
                fusion::vector2<scoped_env, actions_type&>
                new_env_type;

            typedef
                typename evaluator::impl<Lambda const &, new_env_type&, int>::result_type
                type;
        };
        
        template <
            typename Env
          , typename OuterEnv
          , typename Locals
          , typename Lambda
        >
        typename result<
            lambda_eval(Env &, OuterEnv const&, Locals &, Lambda &)
        >::type
        operator()(
            Env& env
          , OuterEnv const & outer_env
          , Locals const& locals
          , Lambda const& lambda
        ) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                args_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::actions::result<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                fusion::vector2<args_type, actions_type>
                env_type;
            
            typedef
                typename proto::detail::uncvref<Locals>::type
                locals_type;

            typedef
                typename proto::detail::uncvref<OuterEnv>::type
                outer_env_type;

            typedef
                scoped_environment<env_type, OuterEnv const, locals_type const>
                scoped_env_type;

            env_type e(functional::args()(env), functional::actions()(env));

            scoped_env_type
                scoped_env(
                    e
                  , outer_env
                  , locals
                );

            fusion::vector2<scoped_env_type, actions_type>
                new_env(scoped_env, functional::actions()(env));
            return eval(lambda, new_env);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::lambda, Dummy>
        : proto::call<
            lambda_eval(
                _env
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
              , fusion::vector2<
                    mpl::true_
                  , detail::scope_is_nullary_actions
                >()
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
              , detail::local_var_def_is_nullary(proto::_child_c<0>, _env)// mpl::true_()//evaluator(proto::_child_c<1>, _env)
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

        template <typename This, typename Env, typename Lambda>
        struct result<This(Env, Lambda &)>
        {
            typedef
                typename proto::detail::uncvref<Env>::type
                env_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                args_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::actions::result<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                fusion::vector2<args_type, actions_type>
                outer_env_type;

            typedef
                typename expression::lambda<
                    outer_env_type
                  , mpl::void_
                  , typename proto::detail::uncvref<Lambda>::type
                >::type
                type;
        };

        template <typename This, typename Env, typename Locals, typename Lambda>
        struct result<This(Env, Locals, Lambda)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename rule::local_var_def_list::impl<
                        typename proto::detail::uncvref<Locals>::type &
                      , Env
                      , int
                    >::result_type
                >::type
                locals_type;

            typedef
                typename proto::detail::uncvref<Env>::type
                env_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                args_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::actions::result<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                fusion::vector2<args_type, actions_type>
                outer_env_type;
            
            typedef
                typename expression::lambda<
                    outer_env_type
                  , locals_type
                  , typename proto::detail::uncvref<Lambda>::type
                >::type const
                type;
        };

        template <typename Env, typename Lambda>
        typename result<lambda_actor_eval(Env&, Lambda const&)>::type
        operator()(Env & env, Lambda const& lambda) const
        {
            typedef
                typename proto::detail::uncvref<Env>::type
                env_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                args_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::actions::result<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                fusion::vector2<args_type, actions_type>
                outer_env_type;

            outer_env_type
                outer_env(fusion::at_c<0>(env), fusion::at_c<1>(env));

            mpl::void_ t;
            return
                expression::
                    lambda<outer_env_type, mpl::void_, Lambda>::
                        make(outer_env, t, lambda);
        }

        template <
            typename Env
          , typename Locals
          , typename Lambda
        >
        typename result<
            lambda_actor_eval(Env&, Locals const&, Lambda const&)
        >::type
        operator()(Env & env, Locals const& locals, Lambda const& lambda) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename rule::local_var_def_list::impl<
                        Locals &
                      , Env
                      , int
                    >::result_type
                >::type
                locals_type;

            locals_type l = 
                   rule::local_var_def_list()(
                      locals
                    , env
                    );

            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                args_type;

            typedef
                typename proto::detail::uncvref<
                    typename functional::actions::result<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                fusion::vector2<args_type, actions_type>
                outer_env_type;

            outer_env_type
                outer_env(fusion::at_c<0>(env), fusion::at_c<1>(env));

            return
                expression::
                    lambda<outer_env_type, locals_type, Lambda>::
                        make(outer_env, l, lambda);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::lambda_actor, Dummy>
        : proto::or_<
            proto::when<
                expression::lambda_actor<meta_grammar>
              , lambda_actor_eval(_env, proto::_child_c<0>)
            >
          , proto::when<
                expression::lambda_actor<
                    rule::local_var_def_list
                  , meta_grammar
                >
              , lambda_actor_eval(_env, proto::_child_c<0>, proto::_child_c<1>)
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
