/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LOCAL_VARIABLE_HPP
#define PHOENIX_SCOPE_LOCAL_VARIABLE_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/reference.hpp>
#include <boost/phoenix/core/value.hpp>
#include <boost/phoenix/scope/scoped_environment.hpp>
#include <boost/phoenix/statement/sequence.hpp>

namespace boost { namespace phoenix
{

    namespace detail
    {
        template <typename Key>
        struct local
        {
            typedef Key type;
        };
    }

    namespace tag
    {
        struct local_variable {};
    }

    namespace expression
    {
        template <typename Key, typename _ = proto::is_proto_expr>
        struct local_variable
        {
            typedef expr<tag::local_variable, Key> expr_type;
            typedef typename expr_type::type type;
            typedef typename expr_type::proto_grammar proto_grammar;
        };
    }

    namespace rule
    {
        struct local_variable
            : expression::local_variable<proto::_>
        {};

        struct local_var_def
            : proto::assign<local_variable, meta_grammar>
        {};

        struct local_eval
            : proto::callable
        {
            template <typename Sig>
            struct result;

            template <typename This, typename Expr, typename Env>
            struct result<This(Expr&, Env)>
                : result<This(Expr&, Env const&)>
            {};

            template <typename This, typename Expr, typename Env>
            struct result<This(Expr&, Env &)>
            {
                typedef 
                    typename evaluator::impl<Expr const &, Env &, int>::result_type
                    result_type;
                typedef
                    typename mpl::eval_if<
                        is_reference<result_type>
                      , expression::reference<
                            typename boost::remove_reference<result_type>::type
                        >
                      , expression::value<result_type>
                    >::type
                    type;
            };

            template <typename Expr, typename Env>
            typename result<local_eval(Expr const&, Env&)>::type
            operator()(Expr const& expr, Env & env) const
            {
                typedef
                    typename result<local_eval(Expr const&, Env&)>::result_type
                    result_type;

                return
                    this->make(
                        expr
                      , env
                      , typename is_reference<result_type>::type()
                    );
            }

            private:
                template <typename Expr, typename Env>
                typename result<local_eval(Expr const&, Env&)>::type
                make(Expr const& expr, Env & env, mpl::true_) const
                {
                    typedef
                        typename remove_reference<
                            typename result<
                                local_eval(Expr const&, Env&)
                            >::result_type
                        >::type
                        result_type;
                
                    return
                        this->make_ref(
                            expr
                          , env
                          , typename is_const<result_type>::type()
                        );
                }
                
                template <typename Expr, typename Env>
                typename result<local_eval(Expr const&, Env&)>::type
                make_ref(Expr const& expr, Env & env, mpl::true_) const
                {
                    return phoenix::cref(eval(expr, env));
                }
                
                template <typename Expr, typename Env>
                typename result<local_eval(Expr const&, Env&)>::type
                make_ref(Expr const& expr, Env & env, mpl::false_) const
                {
                    return phoenix::ref(eval(expr, env));
                }
                
                template <typename Expr, typename Env>
                typename result<local_eval(Expr const&, Env&)>::type
                make(Expr const& expr, Env & env, mpl::false_) const
                {
                    return phoenix::val(eval(expr, env));
                }

        };

        struct local_var_def_list
            : proto::or_<
                proto::when<
                    proto::comma<local_var_def_list, local_var_def>
                  , proto::comma<
                        local_var_def_list(proto::_left , proto::_state)
                      , local_var_def_list(proto::_right, proto::_state)
                    >(
                        local_var_def_list(proto::_left , proto::_state)
                      , local_var_def_list(proto::_right, proto::_state)
                    )
                >
              , proto::when<
                    local_var_def
                  , proto::assign<
                        proto::_left
                      , local_eval(proto::_right, proto::_state)
                    >(
                        proto::_left
                      , local_eval(proto::_right, proto::_state)
                    )
                >
              , proto::terminal<mpl::void_>
            >
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<tag::local_variable, Dummy>
        : proto::when<
            rule::local_variable
          , proto::external_transform
        >
    {};

    template <typename Dummy>
    struct is_nullary::when<rule::local_variable, Dummy>
        : proto::make<mpl::false_()>/*proto::if_<
            is_scoped_environment<functional::args(_env)>()
          , mpl::true_()
          , mpl::false_()
        >*/
    {};

    namespace detail
    {
        struct local_var_def_is_nullary
            : proto::or_<
                proto::when<
                    proto::comma<
                        detail::local_var_def_is_nullary
                      , rule::local_var_def
                    >
                  , mpl::and_<
                        detail::local_var_def_is_nullary(proto::_left, proto::_state)
                      , evaluator(
                            proto::_right(proto::_right)
                          , fusion::vector2<
                                mpl::true_
                              , boost::phoenix::is_nullary
                            >()
                        )
                    >()
                >
              , proto::when<
                    rule::local_var_def
                  , evaluator(
                        proto::_child_c<1>
                      , fusion::vector2<
                            mpl::true_
                          , boost::phoenix::is_nullary
                        >()
                    )
                >
            >
        {};
        
        struct scope_is_nullary_actions
        {
            template <typename Rule, typename Dummy = void>
            struct when : boost::phoenix::is_nullary::when<Rule, Dummy>
            {};
        };

        template <typename Dummy>
        struct scope_is_nullary_actions::when<rule::local_variable, Dummy>
            : proto::make<mpl::true_()>
        {};


        struct local_var_not_found
        {
            template <typename T>
            T const & operator=(T const & t)
            {
                return t;
            }
        };

        struct find_local
            : proto::or_<
                proto::when<
                    proto::terminal<mpl::void_>
                  , detail::local_var_not_found()
                >
              , proto::when<
                    proto::comma<find_local, rule::local_var_def>
                  , proto::if_<
                        proto::matches<
                            proto::_left(proto::_right)
                          , proto::_data
                        >()
                      , evaluator(
                            proto::_right(proto::_right)
                          , proto::_state
                        )
                      , find_local(
                            proto::_left
                          , proto::_state
                          , proto::_data
                        )
                    >
                >
              , proto::when<
                    rule::local_var_def
                  , proto::if_<
                        proto::matches<proto::_left, proto::_data>()
                      , evaluator(proto::_right, proto::_state)
                      , detail::local_var_not_found()
                    >
                >
            >
        {};

        template<typename This, typename Args, typename Env, typename Key>
        struct get_local_result_impl
            : mpl::eval_if<
                is_same<
                    typename Args::locals_type
                  , mpl::void_
                >
              , typename This:: template result<This(typename Args::outer_env_type&)>
              , mpl::eval_if<
                    is_same<
                        typename proto::detail::uncvref<
                            typename detail::find_local::impl<
                                typename Args::locals_type &
                              , Env
                              , Key
                            >::result_type
                        >::type
                      , detail::local_var_not_found
                    >
                  , typename This:: template result<This(typename Args::outer_env_type&)>
                  , mpl::identity<
                        typename detail::find_local::impl<
                            typename Args::locals_type &
                          , Env
                          , Key
                        >::result_type
                    >
                >
            >
        {};

    }

    template <typename Key>
    struct get_local
    {
        template <typename Sig>
        struct result;
        
        template <typename This, typename Env>
        struct result<This(Env)>
            : result<This(Env const &)>
        {};

        template <typename This, typename Env>
        struct result<This(Env &)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                env_type;

            typedef
                typename mpl::eval_if<
                    is_scoped_environment<env_type>
                  , detail::get_local_result_impl<This, env_type, Env, Key>
                  , mpl::identity<detail::local_var_not_found>
                >::type
                type;
        };

        template <typename Env>
        typename result<get_local<Key>(Env&)>::type
        operator()(Env &env) const
        {
            typedef
                typename proto::detail::uncvref<
                    typename functional::args::result<
                        functional::args(Env)
                    >::type
                >::type
                env_type;

            return this->evaluate(
                env
              , typename is_scoped_environment<env_type>::type()
            );
        }

        private:
            // is a scoped environment
            template <typename Env>
            typename result<get_local<Key>(Env&)>::type
            evaluate(Env & env, mpl::true_) const
            {
                typedef
                    typename proto::detail::uncvref<
                        typename functional::args::result<
                            functional::args(Env)
                        >::type
                    >::type
                    env_type;

                return
                    this->evaluate_scoped(
                        env
                      , typename is_same<
                            typename proto::detail::uncvref<
                                typename detail::find_local::impl<
                                    typename env_type::locals_type
                                  , Env &
                                  , Key
                                >::result_type
                            >::type
                          , detail::local_var_not_found
                        >::type()
                    );
                    
            }

            // is a scoped environment
            // --> we need to look in the outer environment
            template <typename Env>
            typename result<get_local<Key>(Env&)>::type
            evaluate_scoped(Env & env, mpl::false_) const
            {
                Key k;
                return
                    detail::find_local()(
                        functional::args()(env).locals
                      , env
                      , k
                    );
            }
            
            // is a scoped environment
            // --> we have the local in our environment
            template <typename Env>
            typename result<get_local<Key>(Env&)>::type
            evaluate_scoped(Env & env, mpl::true_) const
            {
                return get_local<Key>()(functional::args()(env).outer_env);
            }
            
            template <typename Env>
            typename result<get_local<Key>(Env&)>::type
            evaluate(Env & env, mpl::false_) const
            {
                return detail::local_var_not_found();
            }

    };

    struct local_var_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Local, typename Env>
        struct result<This(Local &, Env)>
        {
            typedef
                typename expression::local_variable<Local>::type
                lookup_grammar;

            typedef get_local<lookup_grammar> get_local_type;
            typedef
                typename get_local_type::template result<get_local_type(Env)>::type
                type;
        };

        template <typename Local, typename Env>
        typename result<local_var_eval(Local const &, Env&)>::type
        operator()(Local & local, Env & env)
        {
            typedef
                typename expression::local_variable<Local>::type
                lookup_grammar;
            return get_local<lookup_grammar>()(env);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::local_variable, Dummy>
        : proto::call<local_var_eval(proto::_value(proto::_child_c<0>), _env)>
    {};
    
    namespace local_names
    {
        expression::local_variable<detail::local<struct _a_key> >::type const _a = {};
        expression::local_variable<detail::local<struct _b_key> >::type const _b = {};
        expression::local_variable<detail::local<struct _c_key> >::type const _c = {};
        expression::local_variable<detail::local<struct _d_key> >::type const _d = {};
        expression::local_variable<detail::local<struct _e_key> >::type const _e = {};
        expression::local_variable<detail::local<struct _f_key> >::type const _f = {};
        expression::local_variable<detail::local<struct _g_key> >::type const _g = {};
        expression::local_variable<detail::local<struct _h_key> >::type const _h = {};
        expression::local_variable<detail::local<struct _i_key> >::type const _i = {};
        expression::local_variable<detail::local<struct _j_key> >::type const _j = {};
        expression::local_variable<detail::local<struct _k_key> >::type const _k = {};
        expression::local_variable<detail::local<struct _l_key> >::type const _l = {};
        expression::local_variable<detail::local<struct _m_key> >::type const _m = {};
        expression::local_variable<detail::local<struct _n_key> >::type const _n = {};
        expression::local_variable<detail::local<struct _o_key> >::type const _o = {};
        expression::local_variable<detail::local<struct _p_key> >::type const _p = {};
        expression::local_variable<detail::local<struct _q_key> >::type const _q = {};
        expression::local_variable<detail::local<struct _r_key> >::type const _r = {};
        expression::local_variable<detail::local<struct _s_key> >::type const _s = {};
        expression::local_variable<detail::local<struct _t_key> >::type const _t = {};
        expression::local_variable<detail::local<struct _u_key> >::type const _u = {};
        expression::local_variable<detail::local<struct _v_key> >::type const _v = {};
        expression::local_variable<detail::local<struct _w_key> >::type const _w = {};
        expression::local_variable<detail::local<struct _x_key> >::type const _x = {};
        expression::local_variable<detail::local<struct _y_key> >::type const _y = {};
        expression::local_variable<detail::local<struct _z_key> >::type const _z = {};
    }
    
    namespace detail
    {
        template <
            PHOENIX_typename_A_void(PHOENIX_LOCAL_LIMIT)
          , typename Dummy = void
        >
        struct make_locals;

        template <typename A0, typename A1>
        struct make_locals<A0, A1>
        {
            typedef
                typename expression::sequence<A0, A1>::type
                type;

            static type const make(A0 a0, A1 a1)
            {
                return expression::sequence<A0, A1>::make(a0, a1);
            }
        };

        #include <boost/phoenix/scope/detail/make_locals.hpp>
    }
}}

#endif
