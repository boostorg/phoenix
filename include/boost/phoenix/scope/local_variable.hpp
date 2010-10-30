/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LOCAL_VARIABLE_HPP
#define PHOENIX_SCOPE_LOCAL_VARIABLE_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/scope/detail/local_variable.hpp>

namespace boost { namespace phoenix
{
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

    namespace local_names
    {
        make_local_variable<struct _a_key>::type const _a = {};
        make_local_variable<struct _b_key>::type const _b = {};
        make_local_variable<struct _c_key>::type const _c = {};
        make_local_variable<struct _d_key>::type const _d = {};
        make_local_variable<struct _e_key>::type const _e = {};
        make_local_variable<struct _f_key>::type const _f = {};
        make_local_variable<struct _g_key>::type const _g = {};
        make_local_variable<struct _h_key>::type const _h = {};
        make_local_variable<struct _i_key>::type const _i = {};
        make_local_variable<struct _j_key>::type const _j = {};
        make_local_variable<struct _k_key>::type const _k = {};
        make_local_variable<struct _l_key>::type const _l = {};
        make_local_variable<struct _m_key>::type const _m = {};
        make_local_variable<struct _n_key>::type const _n = {};
        make_local_variable<struct _o_key>::type const _o = {};
        make_local_variable<struct _p_key>::type const _p = {};
        make_local_variable<struct _q_key>::type const _q = {};
        make_local_variable<struct _r_key>::type const _r = {};
        make_local_variable<struct _s_key>::type const _s = {};
        make_local_variable<struct _t_key>::type const _t = {};
        make_local_variable<struct _u_key>::type const _u = {};
        make_local_variable<struct _v_key>::type const _v = {};
        make_local_variable<struct _w_key>::type const _w = {};
        make_local_variable<struct _x_key>::type const _x = {};
        make_local_variable<struct _y_key>::type const _y = {};
        make_local_variable<struct _z_key>::type const _z = {};
    }

}}

#endif
