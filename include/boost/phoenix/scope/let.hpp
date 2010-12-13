/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2004 Daniel Wallin
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LET_HPP
#define PHOENIX_SCOPE_LET_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/scope/local_variable.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        let
      , (rule::local_var_def_list)
        (scope_grammar)
        //(meta_grammar)
    )

    namespace detail
    {
        struct let_is_nullary_actions
        {
            template <typename Rule, typename Dummy = void>
            struct when : is_nullary_::when<Rule, Dummy>
            {};
        };

        template <typename Dummy>
        struct let_is_nullary_actions::when<rule::local_variable, Dummy>
            : proto::make<mpl::true_()>
        {};

        template <typename Dummy>
        struct is_nullary_::when<rule::let, Dummy>
            : proto::make<
                mpl::and_<
                    detail::local_var_def_is_nullary(proto::_child_c<0>, _env)
                    //mpl::true_()
                  //, mpl::true_()//let_evaluator(proto::_child_c<1>, _env)
                  , evaluator(proto::_child_c<1>, //fusion::vector2<scoped_environment<_env, _env, mpl::void_()>(), functional::actions(_env)>()
                          fusion::vector2<fusion::vector0<>&, let_is_nullary_actions>()
                          )
                >()
            >
            //: proto::make<mpl::true_()>
        {};
    }

    struct let_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Locals, typename Let>
        struct result<This(Env, Locals const &, Let const&)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        functional::actions(Env)
                    >::type
                >::type
                actions_type;

            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        rule::local_var_def_list(
                            Locals const &
                          , Env
                        )
                    >::type
                >::type
                locals_type;

            typedef
                typename boost::result_of<
                    evaluator(
                        Let const &
                      , fusion::vector2<scoped_environment<Env, Env, locals_type&> &, actions_type> &
                      //, fusion::vector2<scoped_environment<Env, Env, locals_type&> &, let_actions>&//actions_type> &
                    )
                >::type
                type;
        };

        template <typename Env, typename Locals, typename Let>
        typename result<let_eval(Env&, Locals const &, Let const &)>::type
        operator()(Env & env, Locals const & locals, Let const & let) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        functional::actions(Env &)
                    >::type
                >::type
                actions_type;

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

            scoped_environment<Env, Env, locals_type&>
                scoped_env(
                    env
                  , env
                  , l
                );

            fusion::vector2<scoped_environment<Env, Env, locals_type &> &, actions_type>
            //fusion::vector2<scoped_environment<Env, Env, locals_type &> &, let_actions>
                new_env(scoped_env, functional::actions()(env));
                //new_env(scoped_env, let_actions());//functional::actions()(env));

            std::cout << ":(\n";
            //std::cout << typeid(Let).name() << "\n";

            //return let_evaluator()(let, new_env);
            return eval(let, new_env);
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
        operator[](Expr const & expr) const
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
        typename expression::let<
            Locals
          , Expr
        >::type const
        operator[](Expr const & expr) const
        {
            return expression::let<Locals, Expr>::make(locals, expr);
        }

        Locals locals;
    };


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

#define PHOENIX_LET_LOCAL_GEN(Z, N, DATA) \
        template <PHOENIX_typename_A(N)> \
        let_actor_gen< \
            typename detail::make_locals<PHOENIX_A(N)>::type \
        > const \
        operator()(PHOENIX_A_const_ref_a(N)) const \
        { \
            return detail::make_locals<PHOENIX_A(N)>::make(PHOENIX_a(N)); \
        } \
        /**/
        BOOST_PP_REPEAT_FROM_TO(2, PHOENIX_LOCAL_LIMIT, PHOENIX_LET_LOCAL_GEN, _)
    };

    let_local_gen const let = {};
}}

#endif
