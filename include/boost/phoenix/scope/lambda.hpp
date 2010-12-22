/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LAMBDA_HPP
#define PHOENIX_SCOPE_LAMBDA_HPP

/*
#include <boost/fusion/include/transform.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/fusion/include/mpl.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/scope/detail/local_variable.hpp>
#include <boost/phoenix/support/element_at.hpp>
#include <boost/phoenix/support/iterate.hpp>
*/
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/scope/local_variable.hpp>

namespace boost { namespace phoenix
{
    //template <typename> struct lambda_actor;
    
    PHOENIX_DEFINE_EXPRESSION(
        lambda
      , (proto::terminal<proto::_>) // OuterEnv 
        (rule::local_var_def_list)  // Locals
        (meta_grammar)              // Lambda
    )

    struct lambda_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename OuterEnv, typename Locals, typename Lambda>
        struct result<This(Env, OuterEnv, Locals &, Lambda &)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef typename proto::detail::uncvref<Locals>::type locals_type;
            typedef typename proto::detail::uncvref<OuterEnv>::type outer_env_type;
            typedef typename proto::detail::uncvref<Env>::type env_type;
            typedef scoped_environment<env_type const, outer_env_type const, locals_type const> scoped_env;
            typedef fusion::vector2<scoped_env, actions_type&> new_env_type;
            typedef
                typename mpl::eval_if<
                    /*proto::matches<
                        typename proto::detail::uncvref<Locals>::type
                      , proto::terminal<mpl::void_>
                    >*/mpl::false_
                  , boost::result_of<evaluator(Lambda &, Env)>
                  , boost::result_of<evaluator(Lambda &, new_env_type)>
                >::type type;
            //typedef int type;
        };
        
        template <typename Env, typename OuterEnv, typename Locals, typename Lambda>
        typename result<lambda_eval(Env &, OuterEnv const&, Locals &, Lambda &)>::type
        operator()(Env& env, OuterEnv const & outer_env, Locals const& locals, Lambda const& lambda) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        functional::actions(Env &)
                    >::type
                >::type
                actions_type;
            
            typedef typename proto::detail::uncvref<Locals>::type locals_type;
            typedef typename proto::detail::uncvref<OuterEnv>::type outer_env_type;
            typedef typename proto::detail::uncvref<Env>::type env_type;
            typedef scoped_environment<env_type const, outer_env_type const, locals_type const> scoped_env_type;

            outer_env_type o = outer_env;
            env_type e = env;
            locals_type l = locals;

            scoped_env_type
                scoped_env(
                    e
                  , o
                  , l
                );

            std::cout << typeid(env).name() << "\n";
            std::cout << typeid(outer_env).name() << "\n";
            std::cout << typeid(fusion::at_c<0>(env)).name() << "\n";
            std::cout << typeid(fusion::at_c<0>(outer_env)).name() << "\n";
            //std::cout << fusion::at_c<0>(fusion::at_c<0>(env)) << "\n";
            std::cout << "fuuu\n";
            //std::cout << fusion::at_c<0>(fusion::at_c<0>(outer_env)) << "\n";
            //std::cout << fusion::at_c<0>(outer_env) << "\n";
            
            fusion::vector2<scoped_env_type, actions_type>
                new_env(scoped_env, functional::actions()(env));

            //std::cout << eval(lambda, new_env) << "\n";
            /*
            //std::cout << "success!\n";
            return eval(lambda, new_env);
            */
            //std::cout << typeid(Locals).name() << "\n";
            return eval(lambda, new_env);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::lambda, Dummy>
        : proto::call<lambda_eval(_env, proto::_value(proto::_child_c<0>), proto::_child_c<1>, proto::_child_c<2>)>
    {};

    namespace detail
    {
        template <typename Dummy>
        struct is_nullary_::when<rule::lambda, Dummy>
            : proto::when<
                expression::lambda<
                    proto::terminal<proto::_>
                  , rule::local_var_def_list
                  , meta_grammar
                >
              , evaluator(proto::_child_c<2>, fusion::vector2<fusion::vector0<>&, scope_is_nullary_actions>())
            >
        {};
    }

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
            : expr/*_ext<lambda_actor,*/< tag::lambda_actor, A0>
        {};

        template <typename A0, typename A1>
        struct lambda_actor<A0, A1>
            : expr/*_ext<lambda_actor,*/< tag::lambda_actor, A0, A1>
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

    namespace detail
    {
        template <typename Dummy>
        struct is_nullary_::when<rule::lambda_actor, Dummy>
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
                  , evaluator(proto::_child_c<1>, _env)
                >
            >
        {};
    }
            

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
            typedef typename proto::detail::uncvref<Env>::type env_type;
            typedef typename expression::lambda<env_type, mpl::void_, typename proto::detail::uncvref<Lambda>::type>::type const type;
        };

        template <typename This, typename Env, typename Locals, typename Lambda>
        struct result<This(Env, Locals, Lambda)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        rule::local_var_def_list(
                            typename proto::detail::uncvref<Locals>::type &
                          , Env
                        )
                    >::type
                >::type
                locals_type;
            typedef typename proto::detail::uncvref<Env>::type env_type;
            
            typedef
                typename expression::lambda<env_type, locals_type, typename proto::detail::uncvref<Lambda>::type>::type const type;
        };

        template <typename Env, typename Lambda>
        typename result<lambda_actor_eval(Env&, Lambda const&)>::type
        operator()(Env & env, Lambda const& lambda) const
        {
            typedef typename proto::detail::uncvref<Env>::type env_type;
            //proto::terminal<mpl::void_>::type t = {mpl::void_()};
            //return expression::lambda<env_type, proto::terminal<mpl::void_>::type, Lambda>::make(env, t, lambda);
            mpl::void_ t;
            return expression::lambda<env_type, mpl::void_, Lambda>::make(env, t, lambda);
        }

        template <typename Env, typename Locals, typename Lambda>
        typename result<lambda_actor_eval(Env&, Locals const&, Lambda const&)>::type
        operator()(Env & env, Locals const& locals, Lambda const& lambda) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        rule::local_var_def_list(
                            Locals &
                          , Env &
                        )
                    >::type
                >::type
                locals_type;

            locals_type l = 
                   rule::local_var_def_list()(
                      locals
                    , env
                    );

            typedef typename proto::detail::uncvref<Env>::type env_type;
            static env_type e(env);

            std::cout << "outer env - begin\n";
            std::cout << typeid(env).name() << "\n";
            std::cout << "outer env - end\n";

            return expression::lambda<env_type, locals_type, Lambda>::make(e, l, lambda);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::lambda_actor, Dummy>
        : proto::call<lambda_actor_eval(_env, unpack)>
    {};
    
    /*
    template <typename Expr>
    struct lambda_actor
        : actor<Expr>
    {
        typedef actor< Expr > base_type;

        lambda_actor(base_type const & base)
            : base_type( base )
        {}
    };
    */

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

#define PHOENIX_LAMBDA_LOCAL_GEN(Z, N, DATA) \
        template <PHOENIX_typename_A(N)> \
        lambda_actor_gen< \
            typename detail::make_locals<PHOENIX_A(N)>::type \
        > const \
        operator()(PHOENIX_A_const_ref_a(N)) const \
        { \
            return detail::make_locals<PHOENIX_A(N)>::make(PHOENIX_a(N)); \
        } \
        /**/
        BOOST_PP_REPEAT_FROM_TO(2, PHOENIX_LOCAL_LIMIT, PHOENIX_LAMBDA_LOCAL_GEN, _)

    };

    lambda_local_gen const lambda = lambda_local_gen();

#if 0
    namespace result_of
    {
        template <typename Env, typename Expr, typename OuterEnv, typename Locals, typename Map>
        struct lambda
        {
            typedef scoped_environment<
                Env
              , typename proto::result_of::value<OuterEnv>::type
              , typename proto::result_of::value<Locals>::type
              , Map
            > environment;

            typedef typename boost::result_of<eval_grammar(Expr const&, environment&)>::type type;
        };
    }

    template <typename Map>
    struct lambda_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Expr, typename OuterEnv, typename Locals>
        struct result<This(Env&, Expr const&, OuterEnv const&, Locals const&)>
              : result_of::lambda<Env, Expr, OuterEnv, Locals, Map>
        {};

        template <typename Env, typename Expr, typename OuterEnv, typename Locals>
        typename result_of::lambda<Env, Expr, OuterEnv, Locals, Map>::type
        operator()(Env& env, Expr const& expr, OuterEnv const& outer_env, Locals const& locals) const
        {
            typedef typename result_of::lambda<Env, Expr, OuterEnv, Locals, Map>::environment environment;

            typename remove_const<
                typename remove_reference<
                    typename boost::result_of<eval_grammar(OuterEnv const&)>::type
                >::type
            >::type a(eval(outer_env));

            environment args(env, a, proto::value(locals));

            return eval(expr, args);
        }
    };
    
    template <typename Expr, typename OuterEnv, typename Locals, typename Map>
    struct make_lambda : compose<lambda_eval<Map>, Expr, OuterEnv, Locals> {};

    template <typename Vars>
    struct lambda_actor_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename A>
        struct result<This(Env&, A const&)>
            : boost::result_of<typename proto::result_of::value<A>::type(Env&)>
        {};

        template <typename Env, typename A>
        typename result<lambda_actor_eval(Env&, A const&)>::type const
        operator()(Env& env, A const& a) const
        {
            return proto::value(a)(env);
        }
    };
    
    template <typename Vars, typename Dummy>
    struct enable_nullary<lambda_actor_eval<Vars>, Dummy>
        : mpl::false_/*mpl::not_< typename mpl::fold<
            Vars
          , mpl::false_
          , detail::compute_no_nullary
        >::type >*/
    {};


    template <typename Expr, typename Vars, typename Map>
    struct lambda_actor
    {
        lambda_actor() {}

        lambda_actor(Expr const& expr, Vars const& vars)
            : expr(expr)
            , vars(vars)
        {}

        template <typename Sig>
        struct result;
        
        template <typename This, typename Env>
        struct result<This(Env&)>
        {
            typedef typename
                fusion::result_of::as_vector<
                    typename fusion::result_of::transform<
                        Vars
                      , detail::initialize_local<Env>
                    >::type
                >::type
            locals_type;

            typedef typename make_lambda<Expr, Env, locals_type, Map>::type type;
        };

        template <typename Env>
        typename result<lambda_actor(Env&)>::type const
        operator()(Env& env) const
        {
            typedef typename result<lambda_actor(Env&)>::locals_type locals_type;

            return make_lambda<
                    Expr, Env, locals_type, Map
                    >()(expr, env, fusion::as_vector(fusion::transform(vars, detail::initialize_local<Env>(env))));
        }

        Expr expr;
        Vars vars;
    };

    template <typename Expr, typename Vars, typename Map>
    struct make_lambda_actor: compose<lambda_actor_eval<Vars>, lambda_actor<Expr, Vars, Map> > {};
    
    template <typename Vars, typename Map>
    struct lambda_actor_gen
    {

        template <typename Expr>
        typename make_lambda_actor<Expr, Vars, Map>::type const
        operator[](Expr const& expr) const
        {
            return make_lambda_actor<Expr, Vars, Map>()(lambda_actor<Expr, Vars, Map>(expr, vars));
        }

        lambda_actor_gen(Vars const& vars)
            : vars(vars) {}

        Vars vars;
    };

    struct lambda_gen
        : lambda_actor_gen<
            fusion::vector0<>
          , detail::map_local_index_to_tuple<> >
    {
        typedef lambda_actor_gen<fusion::vector0<>, detail::map_local_index_to_tuple<> > base_type;

        lambda_gen()
            : base_type(fusion::vector0<>())
        {}

        template <typename A0>
        lambda_actor_gen<
            fusion::vector1<typename proto::result_of::child_c<A0, 1>::type>
          , detail::map_local_index_to_tuple<
                typename proto::result_of::value<
                    typename proto::result_of::child_c<
                        typename proto::result_of::child_c<A0, 0>::type, 0
                    >::type
                >::type::type::key_type
            >
        > const
        operator()( A0 const& a0) const
        {
            return fusion::vector1<typename proto::result_of::child_c<A0, 1>::type>(proto::child_c<1>(a0));
        }

        template <typename A0, typename A1>
        lambda_actor_gen<
            fusion::vector2<
                typename proto::result_of::child_c<A0, 1>::type
              , typename proto::result_of::child_c<A1, 1>::type
            >
          , detail::map_local_index_to_tuple<
                typename proto::result_of::value<
                    typename proto::result_of::child_c<
                        typename proto::result_of::child_c<A0, 0>::type, 0
                    >::type
                >::type::type::key_type
              , typename proto::result_of::value<
                    typename proto::result_of::child_c<
                        typename proto::result_of::child_c<A1, 0>::type, 0
                    >::type
                >::type::type::key_type
            >
        > const
        operator()(A0 const& a0, A1 const& a1) const
        {
            return fusion::vector2<
                typename proto::result_of::child_c<A0, 1>::type
              , typename proto::result_of::child_c<A1, 1>::type
            >(
                proto::child_c<1>(a0)
              , proto::child_c<1>(a1)
            );
        }

          #define PHOENIX_LOCAL_GEN_NAME lambda_actor_gen
          #include <boost/phoenix/scope/detail/local_gen.hpp>
          #undef PHOENIX_LOCAL_GEN_NAME
    };

    lambda_gen const lambda = lambda_gen();
#endif
}}

#endif
