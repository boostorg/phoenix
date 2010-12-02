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
    PHOENIX_DEFINE_EXPRESSION(
        lambda
      , (rule::local_var_def_list)
        (meta_grammar)
    )

    template <typename Locals = void, typename Dummy = void>
    struct lambda_actor_gen;

    template <>
    struct lambda_actor_gen<void, void>
    {
        template <typename Expr>
        Expr const &
        operator[](Expr const & expr) const
        {
            return expr;
        }
    };

    template <typename Locals>
    struct lambda_actor_gen<Locals>
    {
        lambda_actor_gen(Locals const & locals)
            : locals(locals)
        {}

        template <typename Expr>
        typename expression::lambda<
            Locals
          , Expr
        >::type const
        operator[](Expr const & expr) const
        {
            return expression::lambda<Locals, Expr>::make(locals, expr);
        }

        Locals locals;
    };

    struct lambda_local_gen
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

    lambda_local_gen const lambda = {};

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
