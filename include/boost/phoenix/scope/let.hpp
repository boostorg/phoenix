/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LET_HPP
#define PHOENIX_SCOPE_LET_HPP

//#include <boost/fusion/include/transform.hpp>
//#include <boost/fusion/include/as_vector.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/statement/sequence.hpp>
#include <boost/phoenix/scope/local_variable.hpp>
//#include <boost/phoenix/support/element_at.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        let
      , (proto::_)//(rule::local_variables)
        (proto::_)//(rule::let_grammar)
    )

    struct let_eval
    {
        typedef void result_type;

        template <typename Env, typename Locals, typename Let>
        result_type
        operator()(Env & env, Locals const & locals, Let const & let) const
        {
            std::cout << "yeha!\n";
            std::cout << typeid(Locals).name() << "\n\n";
            std::cout << typeid(rule::local_var_def_list()(locals, functional::args()(env), functional::actions()(env))).name() << "\n\n-------\n";
            std::cout << typeid(find_local()(rule::local_var_def_list()(locals, functional::args()(env), functional::actions()(env)), _a)).name() << "\n\n-------\n";
            scope_grammar()(let, functional::args()(env), functional::actions()(env));
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::let, Dummy>
        : proto::call<let_eval(_env, proto::_child_c<0>, proto::_child_c<1>)>
    {};

    template <typename Locals = void, typename Dummy = void>
    struct let_actor_gen;

    template <>
    struct let_actor_gen<void, void>
    {
        template <typename Expr>
        Expr const &
        operator[](Expr const& expr) const
        {
            return expr;
        }
    };

    template <typename Locals>
    struct let_actor_gen<Locals>
    {
        let_actor_gen(Locals const & locals)
            : locals(locals)
        {}

        template <typename Expr>
        typename expression::let<Locals, Expr>::type const
        operator[](Expr const& expr) const
        {
            return expression::let<Locals, Expr>::make(locals, expr);
        }

        Locals const& locals;
    };

    namespace detail
    {
        template <PHOENIX_typename_A_void(PHOENIX_LOCAL_LIMIT)>
        struct make_locals;

        template <typename A0, typename A1>
        struct make_locals<A0, A1>
        {
            typedef
                typename proto::result_of::make_expr<
                    proto::tag::comma
                  , default_domain_with_basic_expr
                  , A0
                  , A1
                >::type
                type;

            static type make(A0 a0, A1 a1)
            {
                return proto::make_expr<proto::tag::comma, default_domain_with_basic_expr>(a0, a1);
            }
        };

        template <typename A0, typename A1, typename A2>
        struct make_locals<A0, A1, A2>
        {
            typedef
                typename proto::result_of::make_expr<
                    proto::tag::comma
                  , default_domain_with_basic_expr
                  , typename make_locals<A0, A1>::type
                  , A2
                >::type
                type;
            
            static type make(A0 a0, A1 a1, A2 a2)
            {
                return proto::make_expr<proto::tag::comma, default_domain_with_basic_expr>(make_locals<A0, A1>::make(a0, a1), a2);
            }
        };

        template <typename A0, typename A1, typename A2, typename A3>
        struct make_locals<A0, A1, A2, A3>
            : proto::result_of::make_expr<
                proto::tag::comma
              , default_domain_with_basic_expr
              , typename make_locals<A0, A1, A2>::type
              , A3
            >
        {
            typedef
                typename proto::result_of::make_expr<
                    proto::tag::comma
                  , default_domain_with_basic_expr
                  , typename make_locals<A0, A1, A2>::type
                  , A3
                >::type
                type;
            
            static type make(A0 a0, A1 a1, A2 a2, A3 a3)
            {
                return proto::make_expr<proto::tag::comma, default_domain_with_basic_expr>(make_locals<A0, A1, A2>::make(a0, a1, a2), a3);
            }
        };
    }

    struct let_local_gen
    {
        let_actor_gen<> const
        operator()() const
        {
            return let_actor_gen<>();
        }

        template <typename Expr0>
        let_actor_gen<Expr0> const
        operator()(Expr0 const& expr0) const
        {
            return expr0;
        }

        template <typename Expr0, typename Expr1>
        let_actor_gen<
            typename detail::make_locals<Expr0, Expr1>::type
        > const
        operator()(Expr0 const& expr0, Expr1 const& expr1) const
        {
            std::cout << typeid(typename detail::make_locals<Expr0, Expr1>::type).name() << "\n\n";
            return detail::make_locals<Expr0, Expr1>::make(expr0, expr1);
        }

        template <typename Expr0, typename Expr1, typename Expr2>
        let_actor_gen<
            typename detail::make_locals<Expr0, Expr1, Expr2>::type
        > const
        operator()(Expr0 const& expr0, Expr1 const& expr1, Expr2 const& expr2) const
        {
            std::cout << typeid(typename detail::make_locals<Expr0, Expr1, Expr2>::type).name() << "\n\n";
            return detail::make_locals<Expr0, Expr1, Expr2>::make(expr0, expr1, expr2);
        }

        template <typename Expr0, typename Expr1, typename Expr2, typename Expr3>
        let_actor_gen<
            typename detail::make_locals<Expr0, Expr1, Expr2, Expr3>::type
        > const
        operator()(Expr0 const& expr0, Expr1 const& expr1, Expr2 const& expr2, Expr3 const & expr3) const
        {
            std::cout << typeid(typename detail::make_locals<Expr0, Expr1, Expr2, Expr3>::type).name() << "\n\n";
            return detail::make_locals<Expr0, Expr1, Expr2, Expr3>::make(expr0, expr1, expr2, expr3);
        }
    };

    let_local_gen const let = let_local_gen();
    /*
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
    */
}}

#endif
