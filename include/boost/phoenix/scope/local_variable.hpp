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
//#include <boost/phoenix/scope/detail/local_variable.hpp>

namespace boost { namespace phoenix
{
    template <typename Key>
    struct local_variable
    {
        typedef Key type;
    };

    namespace expression
    {
        template <typename Key>
        struct local_variable
        {
            typedef proto::terminal< ::boost::phoenix::local_variable<Key> > proto_grammar;
            typedef typename proto_grammar::type base_type;
            typedef base_type type;
            
            static type make()
            {
                base_type e = {local_variable<Key>()};
                return e;
            }
        };
    }

    namespace rule
    {
        struct local_variable
            : proto::terminal< ::boost::phoenix::local_variable<proto::_> >
        {};

        struct local_var_def
            : proto::assign<local_variable, meta_grammar>
        {};

        struct test_eval
            : proto::callable
        {
            template <typename Sig>
            struct result;

            template <typename This, typename Expr, typename Env>
            struct result<This(Expr const&, Env)>
            {
                typedef 
                    typename boost::result_of<
                        evaluator(Expr const &, Env &)
                    >::type
                    result_type;
                /*
                typedef
                    typename proto::terminal<
                        typename mpl::if_<
                            is_reference<result_type>
                          , reference_wrapper<
                                typename boost::remove_reference<
                                    result_type
                                >::type
                            >
                          , result_type
                        >::type
                    >::type
                    type;
                */
                typedef
                    typename mpl::eval_if<
                        is_reference<result_type>
                      , reference<typename boost::remove_reference<result_type>::type>
                      , value<result_type>//typename boost::remove_reference<result_type>::type>
                    >::type
                    type;
            };

            template <typename Expr, typename Env>
            typename result<test_eval(Expr const&, Env&)>::type
            operator()(Expr const& expr, Env & env) const
            {
                typedef typename result<test_eval(Expr const&, Env&)>::result_type result_type;
                    
                std::cout << "precompute locals ... ";

                return this->make(expr, env, typename is_reference<result_type>::type());
            }

            private:
                template <typename Expr, typename Env>
                typename result<test_eval(Expr const&, Env&)>::type
                make(Expr const& expr, Env & env, mpl::true_) const
                {
                    typedef
                        typename remove_reference<
                            typename result<test_eval(Expr const&, Env&)>::result_type
                        >::type
                        result_type;
                
                    std::cout << "as reference ... ";

                    return this->make_ref(expr, env, typename is_const<result_type>::type());//phoenix::ref(eval(expr, env));
                }
                
                template <typename Expr, typename Env>
                typename result<test_eval(Expr const&, Env&)>::type
                make_ref(Expr const& expr, Env & env, mpl::true_) const
                {
                    std::cout << "const ...\n";
                    std::cout << typeid(Expr).name() << "\n";
                    return phoenix::cref(eval(expr, env));
                }
                
                template <typename Expr, typename Env>
                typename result<test_eval(Expr const&, Env&)>::type
                make_ref(Expr const& expr, Env & env, mpl::false_) const
                {
                    std::cout << "non-const ...\n";
                    std::cout << typeid(phoenix::ref(eval(expr, env))).name() << "\n";
                    //int &i = eval(expr, env);
                    return phoenix::ref(eval(expr, env));
                }
                
                template <typename Expr, typename Env>
                typename result<test_eval(Expr const&, Env&)>::type
                make(Expr const& expr, Env & env, mpl::false_) const
                {
                    typedef typename result<test_eval(Expr const&, Env&)>::result_type result_type;
                    result_type i = eval(expr, env);
                    std::cout << "as value\n";
                    std::cout << typeid(Expr).name() << "\n";
                    std::cout << typeid(boost::ref(fusion::at_c<0>(env))).name() << "\n";
                    std::cout << typeid(reference_wrapper<typename boost::result_of<evaluator(Expr const &, Env &)>::type>).name() << "\n";
                    return phoenix::val(i);//eval(expr, env));
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
                      , test_eval(proto::_right, proto::_state)
                      /*, proto::terminal<
                            evaluator(proto::_right, _env)
                        >
                        */
                    >(
                        proto::_left
                      , test_eval(proto::_right, proto::_state)
                      /*
                      , proto::terminal<
                            evaluator(proto::_right, _env)
                        >(
                            evaluator(proto::_right, _env)
                        )
                        */
                    )
                >
            >
        {};
    }

    namespace detail
    {
        struct local_var_not_found {};

        struct find_local
            : proto::or_<
                proto::when<
                    proto::comma<find_local, rule::local_var_def>
                  , proto::if_<
                        proto::matches<proto::_left(proto::_right), proto::_data>()
                      , evaluator(proto::_right(proto::_right), proto::_state)
                      //, proto::_value(proto::_right(proto::_right))
                      //, proto::_right(proto::_right)
                      , find_local(proto::_left, proto::_state, proto::_data)
                    >
                >
              , proto::when<
                    rule::local_var_def
                  , proto::if_<
                        proto::matches<proto::_left, proto::_data>()
                      , evaluator(proto::_right, proto::_state)
                      //, proto::_value(proto::_right)
                      //, proto::_right
                      , detail::local_var_not_found()
                    >
                >
            >
        {};

        template<typename This, typename Args, typename Env, typename Key>
        struct get_local_result_impl
            : mpl::if_<
                typename is_same<
                    typename proto::detail::uncvref<
                        typename boost::result_of<
                            detail::find_local(typename Args::locals_type, Env, Key)
                       >::type
                    >::type
                  , detail::local_var_not_found
                >::type
              , typename boost::result_of<
                    This(typename Args::outer_env_type&)
                >::type
              , //typename proto::result_of::value<
                    typename boost::result_of<
                        detail::find_local(typename Args::locals_type, Env, Key)
                    >::type
                //>::type
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
            typedef typename result<get_local<Key>(Env&)>::type result_type;

            typedef
                typename proto::detail::uncvref<
                    typename boost::result_of<
                        functional::args(Env)
                    >::type
                >::type
                env_type;
            std::cout << "getting local var\n";
            //std::cout << typeid(boost::ref(this->evaluate(env, typename is_scoped_environment<env_type>::type()))).name() << "\n";

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
    struct scope_grammar
        : proto::or_<
            proto::when<rule::local_variable, proto::external_transform>
          , meta_grammar
        >
    {};
    */
    
    template<typename T>
    struct is_custom_terminal<local_variable<T> >
      : mpl::true_
    {};

    struct local_var_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Local, typename Env>
        struct result<This(Local const &, Env)>
        {
            typedef
                proto::terminal< local_variable<typename Local::type> >
                lookup_grammar;
            /*
            typedef
                typename boost::result_of<
                    functional::args(Env &)
                >::type
                args_type;
            */
            typedef
                typename boost::result_of<get_local<lookup_grammar>(Env)>::type
                type;
        };

        //typedef int result_type;

        template <typename Local, typename Env>
        typename result<local_var_eval(Local const &, Env&)>::type
        operator()(Local const& local, Env & env)
        {
            typedef
                proto::terminal< local_variable<typename Local::type> >
                lookup_grammar;


            std::cout << "local_var_eval\n";

            //std::cout << "local_var_eval\n";
            //std::cout << typeid(typename boost::result_of<functional::args(Env&)>::type).name() << "\n";
            //std::cout << typeid(Local).name() << "\n\n";
            //std::cout << typeid(typename boost::result_of<get_local<lookup_grammar>(typename boost::result_of<functional::args(Env &)>::type&)>::type).name() << "\n";
            //std::cout << detail::find_local()(functional::args()(env).locals, lookup_grammar()) << "\n";
            //std::cout << get_local<lookup_grammar>()(functional::args()(env)) << "\n";
            //std::cout << typeid(boost::ref(get_local<lookup_grammar>()(env))).name() << "\n";
            //get_local<lookup_grammar>()(env);
            return get_local<lookup_grammar>()(env);//functional::args()(env));
        }
    };
    
    template<typename T>
    struct custom_terminal<local_variable<T> >
        : local_var_eval
    {};

    /*
    template <typename Dummy>
    struct default_actions::when<rule::local_variable, Dummy>
        : proto::call<local_var_eval(_env, proto::_value)>
    {};
    */

    /*
    template <typename Env, typename OuterEnv, typename Locals, typename Map>
    struct scoped_environment;

    namespace result_of
    {
        template <typename Env, typename Key>
        struct local_variable
            : boost::phoenix::detail::apply_local<
                Key//typename boost::result_of<eval_grammar(Key const&)>::type
              , Env>
        {};
    }
    

    template <typename Key>
    struct local_variable
    {

        typedef Key key_type;

        template <typename Sig>
        struct result;

        template <typename This, typename Env>
        struct result<This(Env&)>
            : result_of::local_variable<Env, Key>
        {};

        template <typename Env>
        typename result_of::local_variable<Env, Key>::type
        operator()(Env & env)
        {
            typedef typename result_of::local_variable<Env, Key>::type return_type;
            typedef typename Env::map_type map_type;
            typedef typename 
                detail::get_index<map_type, Key>::type 
            index_type;

            typedef detail::eval_local<Key> eval_local;

            return eval_local::template get<return_type>(
                env
              , index_type());
        }
    };

    template <typename Key>
    struct make_local_variable : compose<local_variable<Key> > {};
    
    template <typename Key, typename Dummy>
    struct enable_nullary<local_variable<Key>, Dummy>
        : mpl::false_
    {};
    */

    namespace local_names
    {
        expression::local_variable<struct _a_key>::type const _a = {};
        expression::local_variable<struct _b_key>::type const _b = {};
        expression::local_variable<struct _c_key>::type const _c = {};
        expression::local_variable<struct _d_key>::type const _d = {};
        expression::local_variable<struct _e_key>::type const _e = {};
        expression::local_variable<struct _f_key>::type const _f = {};
        expression::local_variable<struct _g_key>::type const _g = {};
        expression::local_variable<struct _h_key>::type const _h = {};
        expression::local_variable<struct _i_key>::type const _i = {};
        expression::local_variable<struct _j_key>::type const _j = {};
        expression::local_variable<struct _k_key>::type const _k = {};
        expression::local_variable<struct _l_key>::type const _l = {};
        expression::local_variable<struct _m_key>::type const _m = {};
        expression::local_variable<struct _n_key>::type const _n = {};
        expression::local_variable<struct _o_key>::type const _o = {};
        expression::local_variable<struct _p_key>::type const _p = {};
        expression::local_variable<struct _q_key>::type const _q = {};
        expression::local_variable<struct _r_key>::type const _r = {};
        expression::local_variable<struct _s_key>::type const _s = {};
        expression::local_variable<struct _t_key>::type const _t = {};
        expression::local_variable<struct _u_key>::type const _u = {};
        expression::local_variable<struct _v_key>::type const _v = {};
        expression::local_variable<struct _w_key>::type const _w = {};
        expression::local_variable<struct _x_key>::type const _x = {};
        expression::local_variable<struct _y_key>::type const _y = {};
        expression::local_variable<struct _z_key>::type const _z = {};
    }
}}

#endif
