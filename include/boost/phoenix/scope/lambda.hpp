/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LAMBDA_HPP
#define PHOENIX_SCOPE_LAMBDA_HPP

#include <boost/fusion/include/transform.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>
#include <boost/phoenix/scope/local_actor.hpp>
#include <boost/phoenix/scope/detail/local_variable.hpp>
#include <boost/phoenix/support/element_at.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
//#if 0
    namespace result_of
    {
        template <typename Env, typename Expr>
        struct lambda
        {
            typedef typename boost::result_of<eval_grammar(Expr const&, Env&)>::type type;
        };
    }

    template <typename Map>
    struct lambda_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Expr, typename OuterEnv, typename Locals>
        struct result<This(Env&, Expr const&, OuterEnv const&, Locals const&)>
        {
            typedef scoped_environment<
                Env
              , typename proto::result_of::value<OuterEnv>::type
              , typename proto::result_of::value<Locals>::type
              , Map
            > environment;

            typedef typename boost::result_of<eval_grammar(Expr const&, environment&)>::type type;
        };

        template <typename Env, typename Expr, typename OuterEnv, typename Locals>
        typename result<lambda_eval(Env&, Expr const&, OuterEnv const&, Locals const&)>::type
        operator()(Env& env, Expr const& expr, OuterEnv const& outer_env, Locals const& locals) const
        {
            typedef typename result<lambda_eval(Env&, Expr const&, OuterEnv const&, Locals const&)>::environment environment;
            environment args(env, proto::value(outer_env), proto::value(locals));

            return eval(expr, args);
        }
    };
    
    template <typename Expr, typename OuterEnv, typename Locals, typename Map>
    struct make_lambda : compose<lambda_eval<Map>, Expr, OuterEnv, Locals> {};

    template <typename Map>
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
        operator()(Env& env, A const& a)
        {
            return proto::value(a)(env);
        }
    };

    template <typename Expr, typename Vars, typename Map>
    struct lambda_actor
    {
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

            return make_lambda<Expr, Env, locals_type, Map>()(expr, env, fusion::transform(vars, detail::initialize_local<Env>(env)));
        }

        Expr expr;
        Vars vars;
    };

    template <typename Expr, typename Vars, typename Map>
    struct make_lambda_actor: compose<lambda_actor_eval<Map>, lambda_actor<Expr, Vars, Map> > {};

    template <typename Vars, typename Map>
    struct lambda_actor_gen
    {

        template <typename Expr>
        typename make_lambda_actor<Expr, Vars, Map>::type const
        operator[](Expr const expr) const
        {
            return make_lambda_actor<Expr, Vars, Map>()(lambda_actor<Expr, Vars, Map>(expr, vars));
        }

        lambda_actor_gen(Vars const& vars)
            : vars(vars) {}

        Vars const& vars;
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
    };

    lambda_gen const lambda = lambda_gen();

//#endif
#if 0

    /*
    namespace result_of
    {
        template <typename Expr, typename OuterEnv, typename Locals, typename Map, typename A0 = void, typename A1 = void>
        struct lambda;

        template <typename Expr, typename OuterEnv, typename Locals, typename Map, typename A0>
        struct lambda<Expr, OuterEnv, Locals, Map, A0>
        {
            typedef typename make_basic_environment<A0>::type basic_env;
            typedef scoped_environment<basic_env, OuterEnv, Locals, Map> args;

            typedef typename boost::result_of<eval_grammar(Expr const&, args&)>::type type;
        };
    }

    template <typename LambdaExpr, typename OuterEnv, typename Locals, typename Map>
    struct lambda_eval
        : LambdaExpr
    {
        typedef LambdaExpr base_type;

        lambda_eval(LambdaExpr const& lambda_expr, OuterEnv const& outer_env, Locals const& locals)
            : base_type(lambda_expr)
            , outer_env(outer_env)
            , locals(locals)
        {}

        template <typename Sig>
        struct result;

        template <typename This, typename A0>
        struct result<This(A0)>
            : result_of::lambda<LambdaExpr, OuterEnv, Locals, Map, A0>
        {};

        int
        operator()() const
        {
            typename make_basic_environment<>::type env;
            scoped_environment<typename make_basic_environment<>::type, OuterEnv, Locals, Map> args(env, outer_env, locals);

            return eval(*this, args);
        }

        template <typename A0>
        typename result_of::lambda<LambdaExpr, OuterEnv, Locals, Map, A0 const&>::type
        operator()(A0 const& a0) const
        {
            typename make_basic_environment<A0 const&>::type env(a0);
            scoped_environment<typename make_basic_environment<A0 const&>::type, OuterEnv, Locals, Map> args(env, outer_env, locals);

            return eval(*this, args);
        }
        
        template <typename A0>
        typename result_of::lambda<LambdaExpr, OuterEnv, Locals, Map, A0&>::type
        operator()(A0& a0) const
        {
            typename make_basic_environment<A0&>::type env(a0);
            scoped_environment<typename make_basic_environment<A0&>::type, OuterEnv, Locals, Map> args(env, outer_env, locals);

            return eval(*this, args);
        }

        OuterEnv outer_env;
        Locals locals;
    };
    */

    template <typename LambdaExpr, typename Vars, typename Map>
    struct lambda_actor_eval
    {
        lambda_actor_eval(LambdaExpr const& lambda_expr, Vars const& vars) : lambda_expr(lambda_expr), vars(vars) {}

        LambdaExpr lambda_expr;
        Vars vars;

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
            /*
            typedef lambda_eval<LambdaExpr, Env, locals_type, Map> type;
            */

            typedef typename make_local_actor<LambdaExpr, Env, locals_type, Map>::type type;
        };
        
        template <typename Env>
        typename result<lambda_actor_eval(Env&)>::type const
        operator()(Env& env) const
        {
            typedef typename result<lambda_actor_eval(Env&)>::locals_type locals_type;
            return make_local_actor<LambdaExpr, Env, locals_type, Map>()(lambda_expr, env, fusion::as_vector(fusion::transform(vars, detail::initialize_local<Env>(env))));
        }

        /*
        template <typename Env>
        typename result<lambda_actor_eval(Env&)>::type const
        operator()(Env& env) const
        {
            typedef typename result<lambda_actor_eval(Env&)>::locals_type locals_type;
            return lambda_eval<LambdaExpr, Env, locals_type, Map>(lambda_expr, env, fusion::as_vector(fusion::transform(vars, detail::initialize_local<Env>(env))));
        }
        */
    };

    template <typename LambdaExpr, typename Vars, typename Map>
    struct make_lambda_actor_eval
    {
        typedef typename
            proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , lambda_actor_eval<LambdaExpr, Vars, Map>
                , env
            >::type
            base_type;

        typedef actor<base_type> type;
    };

    template <typename Vars, typename Map>
    struct lambda_gen_actor
    {
        lambda_gen_actor(Vars const& vars) : vars(vars) {}

        template <typename LambdaExpr>
        typename make_lambda_actor_eval<LambdaExpr, Vars, Map>::type const
        operator[](LambdaExpr const& lambda_expr) const
        {
            typename make_lambda_actor_eval<LambdaExpr, Vars,Map>::type const e = {{lambda_actor_eval<LambdaExpr, Vars, Map>(lambda_expr, vars), env()}};
            return e;
        }

        Vars const & vars;
    };
    
    namespace local_names { struct _a_key; struct _b_key; }

    struct lambda_gen
        : lambda_gen_actor<fusion::vector0<>, detail::map_local_index_to_tuple<> >
    {
        typedef lambda_gen_actor<fusion::vector0<>, detail::map_local_index_to_tuple<> > base_type;

        lambda_gen()
            : base_type( fusion::vector0<>() )
        {}

        template <typename A0>
        lambda_gen_actor<
            fusion::vector1<typename proto::result_of::child_c<A0, 1>::type>
          , detail::map_local_index_to_tuple<local_names::_a_key>
        > const
        operator()( A0 const& a0) const
        {
            return fusion::vector1<typename proto::result_of::child_c<A0, 1>::type>(proto::child_c<1>(a0));
        }

        template <typename A0, typename A1>
        lambda_gen_actor<
            fusion::vector2<
                typename proto::result_of::child_c<A0, 1>::type
              , typename proto::result_of::child_c<A1, 1>::type
            >
          , detail::map_local_index_to_tuple<local_names::_a_key, local_names::_b_key>
        > const
        operator()( A0 const& a0, A1 const& a1) const
        {
            return fusion::vector2<
                typename proto::result_of::child_c<A0, 1>::type
              , typename proto::result_of::child_c<A1, 1>::type
                >(
                    proto::child_c<1>(a0)
                  , proto::child_c<1>(a1)
                );
        }

    };

    lambda_gen const lambda = lambda_gen();
#endif
}}

#endif
