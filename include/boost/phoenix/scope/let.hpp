/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LET_HPP
#define PHOENIX_SCOPE_LET_HPP

#include <boost/fusion/include/transform.hpp>
#include <boost/fusion/include/as_vector.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/scope/detail/local_variable.hpp>
#include <boost/phoenix/support/element_at.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    template <typename Map>
    struct let_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Expr, typename Vars>
        struct result<This(Env&, Expr const&, Vars const&)>
        {
            typedef typename
                fusion::result_of::as_vector<
                    typename fusion::result_of::transform<
                        typename proto::result_of::value<Vars>::type
                      , detail::initialize_local<Env>
                    >::type
                >::type
            locals_type;
            
            typedef scoped_environment<Env, Env, locals_type, Map> env_type;

            typedef typename boost::result_of<eval_grammar(Expr const&, env_type&)>::type type;
        };

        template <typename Env, typename Expr, typename Vars>
        typename result<let_eval(Env&, Expr const&, Vars const&)>::type
        operator()(Env& env, Expr const& expr, Vars const& vars) const
        {
            typename result<let_eval(Env&, Expr const&, Vars const&)>::env_type
                args(
                    env
                  , env
                  , fusion::as_vector(
                      fusion::transform(
                          proto::value(vars)
                        , detail::initialize_local<Env>(env)
                      )
                    )
                );

            return eval(expr, args);
        }
    };
    
    template <typename Map, typename Dummy>
    struct enable_nullary<let_eval<Map>, Dummy>
        : mpl::true_
    {};
    
    template <typename Expr, typename Vars, typename Map>
    struct make_let: compose<let_eval<Map>, Expr, Vars> {};

    template <typename Vars, typename Map>
    struct let_actor_gen
    {
        template <typename Expr>
        typename make_let<Expr, Vars, Map>::type const
        operator[](Expr const& expr) const
        {
            return make_let<Expr, Vars, Map>()(expr, vars);
        }

        let_actor_gen(Vars const& vars)
            : vars(vars) {}

        Vars vars;
    };

    struct let_gen
        : let_actor_gen<
            fusion::vector0<>
          , detail::map_local_index_to_tuple<> >
    {
        typedef let_actor_gen<fusion::vector0<>, detail::map_local_index_to_tuple<> > base_type;

        let_gen()
            : base_type(fusion::vector0<>())
        {}

        template <typename A0>
        let_actor_gen<
            fusion::vector1<typename proto::result_of::child_c<A0, 1>::type>
          , detail::map_local_index_to_tuple<
                typename proto::result_of::value<
                    typename proto::result_of::child_c<
                        typename proto::result_of::child_c<A0, 0>::type, 0
                    >::type
                >::type::type::key_type
            >
        > const
        operator()(A0 const& a0) const
        {
            return fusion::vector1<typename proto::result_of::child_c<A0, 1>::type>(proto::child_c<1>(a0));
        }

        template <typename A0, typename A1>
        let_actor_gen<
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

        #define PHOENIX_LOCAL_GEN_NAME let_actor_gen
        #include <boost/phoenix/scope/detail/local_gen.hpp>
        #undef PHOENIX_LOCAL_GEN_NAME
    };

    let_gen const let = let_gen();
}}

#endif
