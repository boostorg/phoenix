/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_LOCAL_VARIABLE_HPP
#define PHOENIX_SCOPE_LOCAL_VARIABLE_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/fusion/container/map.hpp>
#include <boost/fusion/container/generation/make_map.hpp>
#include <boost/phoenix/core/call.hpp>
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
    }

    template <typename Dummy>
    struct meta_grammar::case_<tag::local_variable, Dummy>
        : enable_rule<rule::local_variable, Dummy>
    {};

    template <typename Dummy>
    struct is_nullary::when<rule::local_variable, Dummy>
        : proto::make<mpl::false_()>
    {};

    namespace detail
    {
        template <typename Locals, typename Context>
        struct local_var_def_is_nullary;


        struct local_var_def_eval;
            
        #include <boost/phoenix/scope/detail/local_var_def.hpp>
        
        struct scope_is_nullary_actions
        {
            template <typename Rule, typename Dummy = void>
            struct when
                : boost::phoenix::is_nullary::when<Rule, Dummy>
            {};
        };

        template <typename Dummy>
        struct scope_is_nullary_actions::when<rule::local_variable, Dummy>
            : proto::make<mpl::true_()>
        {};


        struct local_var_not_found
        {
        };
    }

    struct get_local
    {
        template <typename Sig>
        struct result;
        
        template <typename This, typename Env, typename OuterEnv, typename Locals, typename Key>
        struct result<This(scoped_environment<Env, OuterEnv, Locals> const&, Key)>
            : mpl::eval_if_c<
                fusion::result_of::has_key<Locals, Key>::type::value
              , fusion::result_of::at_key<Locals, Key>
              , result<This(OuterEnv&, Key)>
            >
        {};

        template <typename This, typename Env, typename OuterEnv, typename Locals, typename Key>
        struct result<This(scoped_environment<Env, OuterEnv, Locals>&, Key)>
            : mpl::eval_if_c<
                fusion::result_of::has_key<Locals, Key>::type::value
              , fusion::result_of::at_key<Locals, Key>
              , result<This(typename proto::detail::uncvref<OuterEnv>::type&, Key)>
            >
        {};

        template <typename This, typename Env, typename OuterEnv, typename Key>
        struct result<This(scoped_environment<Env, OuterEnv, mpl::void_> const&, Key)>
            : result<This(OuterEnv&, Key)>
        {};

        template <typename This, typename Env, typename OuterEnv, typename Key>
        struct result<This(scoped_environment<Env, OuterEnv, mpl::void_>&, Key)>
            : result<This(OuterEnv&, Key)>
        {};
        
        template <typename This, typename Env, typename Key>
        struct result<This(Env &, Key)>
        {
            typedef detail::local_var_not_found type;
        };

        template <typename Env, typename OuterEnv, typename Locals, typename Key>
        typename result<get_local(scoped_environment<Env, OuterEnv, Locals>&, Key)>::type
        operator()(scoped_environment<Env, OuterEnv, Locals>& env, Key k) const
        {
            return this->evaluate(env, k, typename fusion::result_of::has_key<Locals, Key>::type());
        }

        template <typename Env, typename OuterEnv, typename Locals, typename Key>
        typename result<get_local(scoped_environment<Env, OuterEnv, Locals>&, Key)>::type
        operator()(scoped_environment<Env, OuterEnv, Locals> const& env, Key k) const
        {
            return this->evaluate(env, k, typename fusion::result_of::has_key<Locals, Key>::type());
        }
        
        template <typename Env, typename OuterEnv, typename Key>
        typename result<get_local(scoped_environment<Env, OuterEnv, mpl::void_>&, Key)>::type
        operator()(scoped_environment<Env, OuterEnv, mpl::void_>& env, Key k) const
        {
            return (*this)(env.outer_env, k);
        }
        
        template <typename Env, typename OuterEnv, typename Key>
        typename result<get_local(scoped_environment<Env, OuterEnv, mpl::void_>&, Key)>::type
        operator()(scoped_environment<Env, OuterEnv, mpl::void_> const& env, Key k) const
        {
            return (*this)(env.outer_env, k);
        }

        template <typename Env, typename Key>
        typename result<get_local(Env&, Key)>::type
        operator()(Env &env, Key k) const
        {
            return detail::local_var_not_found();
        }

        private:
            // is a scoped environment
            template <typename Env, typename Key>
            typename result<get_local(Env&, Key)>::type
            evaluate(Env & env, Key, mpl::true_) const
            {
                return fusion::at_key<Key>(env.locals);
            }
            
            // --> we need to look in the outer environment
            template <typename Env, typename Key>
            typename result<get_local(Env&, Key)>::type
            evaluate(Env & env, Key k, mpl::false_) const
            {
                return (*this)(env.outer_env, k);
            }

    };

    struct local_var_eval
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Context, typename Local>
        struct result<This(Context, Local const &)>
        {
            typedef
                typename get_local::
                    template result<
                        get_local(
                            typename result_of::env<Context>::type
                          , typename proto::result_of::value<Local>::type
                        )
                    >::type
                type;
        };

        template <typename Local, typename Context>
        typename result<local_var_eval(Context const&, Local const &)>::type
        operator()(Context const & ctx, Local const & local)
        {
            return get_local()(env(ctx), proto::value(local));
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::local_variable, Dummy>
        : call<local_var_eval, Dummy>
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
        
        #include <boost/phoenix/scope/detail/make_locals.hpp>
    }
}}

#endif
