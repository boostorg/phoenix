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
#include <boost/phoenix/scope/scope_actor.hpp>
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
            /*
            typedef
                typename proto::result_of::make_expr<
                    tag::local_variable
                  , default_domain_with_basic_expr
                  , Key
                >::type
                base_type;

            typedef scope_actor<base_type> type;

            typedef
                typename proto::nary_expr<tag::local_variable, Key>::proto_grammar
                proto_grammar;
            */
                
            typedef expr<tag::local_variable, Key> expr_type;
            typedef typename expr_type::type type;
            typedef typename expr_type::proto_grammar proto_grammar;
            //BOOST_PROTO_BASIC_EXTENDS(typename expr_type::type, local_variable, phoenix_domain)
        };
        /*    : proto::transform<local_variable<Key>, int>
        {
            typedef detail::local_expr<tag::local_variable, detail::local<Key> > type;
            typedef detail::local_expr<tag::local_variable, detail::local<Key> > proto_grammar;

            template <typename Expr, typename State, typename Data>
            struct impl : proto::transform_impl<Expr, State, Data>
            {
                typedef Expr result_type;
                
                result_type
                operator ()(
                    typename impl::expr_param e
                  , typename impl::state_param
                  , typename impl::data_param
                ) const
                {
                    return e;
                }
            };

            /// INTERNAL ONLY
            typedef tag::local_variable proto_tag;
            /// INTERNAL ONLY
            typedef detail::local<Key> proto_child0;

        };
        */
        /*
            : proto::terminal< ::boost::phoenix::local_variable<Key> >
        {
            typedef
                actor<
                    typename proto::terminal<
                        ::boost::phoenix::local_variable<Key>
                    >::type
                >
                type;
            
            static
            actor<
                typename proto::terminal<
                    ::boost::phoenix::local_variable<Key>
                >::type
            >
            make()
            {
                actor<type> e = {{local_variable<Key>()}};
                return e;
            }
        };
        */
    }

    namespace rule
    {
        struct local_variable
            //: expression::local_variable<proto::_>
            : proto::and_<
                //proto::if_<is_scoped_environment<_env>()>
                //proto::if_<blubb<_env>()>
              //, rule::local_variable
              expression::local_variable<proto::_>
            >
            //: proto::terminal< ::boost::phoenix::local_variable<proto::_> >
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
            {
                typedef 
                    typename boost::result_of<
                        evaluator(Expr const &, Env &)
                    >::type
                    result_type;
                typedef
                    typename mpl::eval_if<
                        is_reference<result_type>
                      , reference<typename boost::remove_reference<result_type>::type>
                      , value<result_type>
                    >::type
                    type;
            };

            template <typename Expr, typename Env>
            typename result<local_eval(Expr&, Env&)>::type
            operator()(Expr& expr, Env & env) const
            {
                typedef typename result<local_eval(Expr const&, Env&)>::result_type result_type;

                return this->make(expr, env, typename is_reference<result_type>::type());
            }

            private:
                template <typename Expr, typename Env>
                typename result<local_eval(Expr const&, Env&)>::type
                make(Expr const& expr, Env & env, mpl::true_) const
                {
                    typedef
                        typename remove_reference<
                            typename result<local_eval(Expr const&, Env&)>::result_type
                        >::type
                        result_type;
                
                    return this->make_ref(expr, env, typename is_const<result_type>::type());
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
            >
        {};
    }

    template <typename Dummy>
    //struct scope_grammar::case_<tag::local_variable, Dummy>
    struct meta_grammar::case_<tag::local_variable, Dummy>
        : proto::when<
            rule::local_variable
          , proto::external_transform
        >
    {};

    namespace detail
    {
        template <typename Dummy>
        struct is_nullary_::when<rule::local_variable, Dummy>
            //: proto::make<mpl::true_()>
            : proto::if_<
                is_scoped_environment<functional::args(_env)>()
                //foo(functional::args(proto::_state))
              , mpl::true_()
              , mpl::false_()
            >
        {};

        struct local_var_def_is_nullary
            : proto::or_<
                proto::when<
                    proto::comma<local_var_def_is_nullary, rule::local_var_def>
                  , mpl::and_<
                        local_var_def_is_nullary(proto::_left, proto::_state)
                      //, mpl::false_()//, local_var_def_is_nullary(proto::_right, proto::_state)
                      //, evaluator(proto::_right(proto::_right), proto::_state)
                      //, is_nullary<proto::_right(proto::_right)>()
                      , evaluator(proto::_right(proto::_right), fusion::vector2<fusion::vector0<>, detail::is_nullary_>(), int())
                    >()
                >
              , proto::when<
                    //proto::_
                    rule::local_var_def
                  //, mpl::false_()
                  , evaluator(proto::_child_c<1>, fusion::vector2<fusion::vector0<>, detail::is_nullary_>(), int())
                  //, is_nullary<proto::_child_c<1> >()
                  //, proto::lazy<is_nullary<custom_terminal<proto::_child_c<1> > >(proto::_child_c<1>, _env)>
                >
            >
        {};
    }

    namespace detail
    {
        struct local_var_not_found
        {
            template <typename T>
            T const & operator=(T const & t)
            {
                return t;
            }
        };

        template <typename T>
        T operator+(local_var_not_found const&, T const & t)
        {
            return t;
        }

        /*
        template <typename T>
        T operator+(T const & t, local_var_not_found const&)
        {
            return t;
        }
        */

        struct find_local
            : proto::or_<
                proto::when<proto::terminal<mpl::void_>, detail::local_var_not_found()>
              , proto::when<
                    proto::comma<find_local, rule::local_var_def>
                  , proto::if_<
                        proto::matches<proto::_left(proto::_right), proto::_data>()
                      //, evaluator(proto::_right(proto::_right), proto::_state)
                      , evaluator(proto::_right(proto::_right), proto::_state)
                      //, int()
                      , find_local(proto::_left, proto::_state, proto::_data)
                    >
                >
              , proto::when<
                    rule::local_var_def
                  , proto::if_<
                        proto::matches<proto::_left, proto::_data>()
                      , evaluator(proto::_right, proto::_state)
                      //, int()
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
              , boost::result_of<
                    This(typename Args::outer_env_type&)
                >
              , mpl::eval_if<
                    is_same<
                        typename proto::detail::uncvref<
                            typename boost::result_of<
                                detail::find_local(typename Args::locals_type &, Env, Key)
                            >::type
                        >::type
                      , detail::local_var_not_found
                    >
                  , boost::result_of<
                        This(typename Args::outer_env_type&)
                    >
                  , boost::result_of<
                        detail::find_local(typename Args::locals_type &, Env, Key)
                    >
                >
            >
        /*
        : mpl::if_<
                typename is_same<
                    typename proto::detail::uncvref<
                        typename boost::result_of<
                            detail::find_local(typename Args::locals_type &, Env, Key)
                       >::type
                    >::type
                  , detail::local_var_not_found
                >::type
              , typename boost::result_of<
                    This(typename Args::outer_env_type&)
                >::type
              , typename boost::result_of<
                    detail::find_local(typename Args::locals_type &, Env, Key)
                >::type
            >
            */
        {};

    }

    template <typename Key>
    struct get_local
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env>
        struct result<This(Env)>
        {
            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
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
                    typename boost::result_of<
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
                        typename boost::result_of<
                            functional::args(Env)
                        >::type
                    >::type
                    env_type;

                return
                    this->evaluate_scoped(
                        env
                      , typename is_same<
                            typename proto::detail::uncvref<
                                typename boost::result_of<detail::find_local(typename env_type::locals_type, Env &, Key)>::type
                            >::type
                          , detail::local_var_not_found
                        >::type()
                    );
                    
            }

            // is a scoped environment, and we need to look in the outer environment
            template <typename Env>
            typename result<get_local<Key>(Env&)>::type
            evaluate_scoped(Env & env, mpl::false_) const
            {
                Key k;
                return detail::find_local()(functional::args()(env).locals, env, k);
            }
            
            // is a scoped environment, and we have the local in our environment
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

    /*
    template<typename T>
    struct is_custom_terminal<local_variable<T> >
      : mpl::true_
    {};

    template<typename T>
    struct custom_terminal<local_variable<T> >
        : proto::callable
        */
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

            typedef
                typename boost::result_of<get_local<lookup_grammar>(Env)>::type
                type;
        };

        template <typename Local, typename Env>
        //typename result<custom_terminal(Local const &, Env&)>::type
        typename result<local_var_eval(Local const &, Env&)>::type
        operator()(Local & local, Env & env)
        {
            typedef
                typename expression::local_variable<Local>::type
                lookup_grammar;
            std::cout << "muuh ...\n";
            std::cout << typeid(lookup_grammar).name() << "\n";
            return get_local<lookup_grammar>()(env);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::local_variable, Dummy>
        : proto::call<local_var_eval(proto::_value(proto::_child_c<0>), _env)>
    {};

#if 0
    struct foo
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env>
        struct result<This(Env)>
            : is_scoped_environment<Env>
        {};
    };
#endif
    
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
        template <PHOENIX_typename_A_void(PHOENIX_LOCAL_LIMIT)>
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

        #define PHOENIX_MAKE_LOCALS(Z, N, DATA)                                 \
        template <PHOENIX_typename_A(N)>                                        \
        struct make_locals<PHOENIX_A(N)>                                        \
        {                                                                       \
            typedef                                                             \
                typename make_locals<PHOENIX_A(BOOST_PP_DEC(N))>::type const         \
                type0;                                                          \
                                                                                \
            typedef                                                             \
                typename expression::sequence<                                  \
                    type0                                                       \
                  , BOOST_PP_CAT(A, BOOST_PP_DEC(N))                            \
                >::type                                                         \
                type;                                                           \
                                                                                \
            static type const make(PHOENIX_A_a(N))                                    \
            {                                                                   \
                return                                                          \
                    expression::sequence<                                       \
                        type0                                                   \
                      , BOOST_PP_CAT(A, BOOST_PP_DEC(N))                        \
                    >::make(                                                    \
                        make_locals<                                            \
                            PHOENIX_A(BOOST_PP_DEC(N))                          \
                        >::make(                                                \
                            PHOENIX_a(BOOST_PP_DEC(N))                          \
                        )                                                       \
                      , BOOST_PP_CAT(a, BOOST_PP_DEC(N))                        \
                    );                                                          \
            }                                                                   \
        };                                                                      \
        /**/
        BOOST_PP_REPEAT_FROM_TO(3, PHOENIX_LOCAL_LIMIT, PHOENIX_MAKE_LOCALS, _)
        #undef PHOENIX_MAKE_LOCALS
    }
}}

#endif
