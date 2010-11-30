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
                type e = {local_variable<Key>()};
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

        struct local_var_def_list
            : proto::or_<
                proto::when<
                    proto::comma<local_var_def_list, local_var_def>
                  , proto::comma<
                        local_var_def_list(proto::_left , proto::_state, proto::_data)
                      , local_var_def_list(proto::_right, proto::_state, proto::_data)
                    >(
                        local_var_def_list(proto::_left , proto::_state, proto::_data)
                      , local_var_def_list(proto::_right, proto::_state, proto::_data)
                    )
                >
              , proto::when<
                    local_var_def
                  , proto::assign<
                        proto::_left
                      , proto::terminal<
                            evaluator(proto::_right, _env)
                        >
                    >(
                        proto::_left
                      , proto::terminal<
                            evaluator(proto::_right, _env)
                        >(
                            evaluator(proto::_right, _env)
                        )
                    )
                >
            >
        {};
    }

    namespace detail
    {
        struct local_var_not_found {};
    }

    struct find_local
        : proto::or_<
            proto::when<
                proto::comma<find_local, rule::local_var_def>
              , proto::if_<
                    proto::matches<proto::_right, proto::_state>()
                  , proto::_value(proto::_right(proto::_right))
                  , find_local(proto::_left, proto::_state)
                >
          , proto::when<
                rule::local_var_def
              , proto::if_<
                    proto::matches<proto::_right, proto::_state>()
                  , proto::_value(proto::_right(proto::_right))
                  , detail::local_var_not_found()
                >
            >
        >
    {};
                

    struct scope_grammar
        : proto::or_<
            proto::when<rule::local_variable, proto::external_transform>
          , meta_grammar
        >
    {};

    struct local_var_eval
        : proto::callable
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Env, typename Local>
        struct result<This(Env&, Local)>
        {
            typedef int type;
        };

        typedef int result_type;

        template <typename Env, typename Local>
        typename result<local_var_eval(Env&, Local)>::type
        operator()(Env & env, Local local)
        {
            std::cout << "blubb\n";
            return 5;
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::local_variable, Dummy>
        : proto::call<local_var_eval(_env, proto::_value)>
    {};

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
