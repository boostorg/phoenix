/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LOCAL_ACTOR_HPP
#define PHOENIX_SCOPE_LOCAL_ACTOR_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/support/element_at.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Expr, typename OuterEnv, typename Locals, typename Map, typename A0 = void, typename A1 = void>
        struct local_actor;

        template <typename Expr, typename OuterEnv, typename Locals, typename Map, typename A0>
        struct local_actor<Expr, OuterEnv, Locals, Map, A0>
        {
            typedef typename make_basic_environment<A0>::type basic_env;
            typedef scoped_environment<basic_env, OuterEnv, Locals, Map> args;

            typedef typename boost::result_of<eval_grammar(Expr const&, args&)>::type type;
        };
    }

    template <typename Expr>//, typename OuterEnv, typename Locals, typename Map>
    struct local_actor
        : actor<Expr>
    {
        typedef actor<Expr> base_type;

        local_actor(base_type const& base)//LambdaExpr const& lambda_expr, OuterEnv const& outer_env, Locals const& locals)
            : base_type(base)
            //, outer_env(eval(element_at_c<0>(*this)))
            //, locals(eval(element_at_c<1>(*this)))
            /*: base_type(lambda_expr)
            , outer_env(outer_env)
            , locals(locals)*/
        {}

        typedef typename boost::result_of<eval_grammar(typename result_of::element_value_at_c<Expr, 0>::type const&)>::type outer_env_type;
        typedef typename boost::result_of<eval_grammar(typename result_of::element_value_at_c<Expr, 1>::type const&)>::type locals_type;
        typedef typename boost::result_of<eval_grammar(typename result_of::element_value_at_c<Expr, 2>::type const&)>::type map_type;

        template <typename Sig>
        struct result;

        template <typename This, typename A0>
        struct result<This(A0)>
            : result_of::local_actor<Expr, outer_env_type, locals_type, map_type, A0>
        {};
        /*

        int
        operator()() const
        {
            typename make_basic_environment<>::type env;
            scoped_environment<typename make_basic_environment<>::type, outer_env_type, locals_type, map_type> args(env, outer_env, locals);

            return eval(*this, args);
        }

        template <typename A0>
        int//typename result_of::local_actor<outer_env_type, locals_type, map_type, A0 const&>::type
        operator()(A0 const& a0) const
        {
            typename make_basic_environment<A0 const&>::type env(a0);
            scoped_environment<typename make_basic_environment<A0 const&>::type, outer_env_type, locals_type, map_type> args(env, outer_env, locals);

            return eval(*this, args);
        }
        
        template <typename A0>
        typename result_of::local_actor<Expr, outer_env_type, locals_type, map_type, A0&>::type
        operator()(A0& a0) const
        {
            typename make_basic_environment<A0&>::type env(a0);
            scoped_environment<typename make_basic_environment<A0&>::type, outer_env_type, locals_type, map_type> args(env, outer_env, locals);

            return eval(*this, args);
        }

        outer_env_type const& outer_env;
        locals_type const& locals;
        */
    };

    template <typename Expr>
    struct local_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename OuterEnv, typename Locals, typename Map>
        struct result<This(Env&, OuterEnv const&, Locals const&, Map const&)>
            : boost::result_of<eval_grammar(Expr const&, scoped_environment<Env, OuterEnv, Locals, Map>&)>
        {};

        local_eval(Expr const& expr) : expr(expr) {}

        template <typename Env, typename OuterEnv, typename Locals, typename Map>
        typename boost::result_of<eval_grammar(Expr const&, scoped_environment<Env, OuterEnv, Locals, Map>&)>::type
        operator()(Env& env, OuterEnv const& outer_env, Locals const& locals, Map const&) const
        {
            std::cout << typeid(Env).name() << "\n\n";
            std::cout << typeid(OuterEnv).name() << "\n\n";
            std::cout << typeid(Locals).name() << "\n\n";
            std::cout << typeid(Expr).name() << "\n\n";
            scoped_environment<Env, OuterEnv, Locals, Map> args(env, outer_env, locals);
            return eval(expr, args);
        }

        Expr expr;
    };

    template <typename Expr, typename OuterEnv, typename Locals, typename Map>
    struct make_local_actor //: compose_ex<local_eval, local_actor, OuterEnv, Locals, Map>
    {
        typedef typename
            proto::result_of::make_expr<
                  proto::tag::function
                , default_domain_with_basic_expr
                , local_eval<Expr>//, Map>//lambda_actor_eval<LambdaExpr, Vars, Map>
                , env
                , OuterEnv
                , Locals
                , Map
            >::type
            base_type;

        typedef local_actor<base_type> type;
        typedef type result_type;

        result_type const
        operator()(Expr const& expr, OuterEnv const& outer_env, Locals const& locals) const
        {
            actor<base_type> const e = {local_eval<Expr>(expr), env(), outer_env, locals, Map()};

            return e;
        }
    };

}}

#endif
