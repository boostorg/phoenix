/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2008 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_SCOPE_LOCAL_VARIABLE_HPP_EAN_2008_05_21
#define BOOST_PHOENIX_SCOPE_LOCAL_VARIABLE_HPP_EAN_2008_05_21

#include <boost/phoenix/core/actor.hpp>
#include <boost/fusion/include/map.hpp>

namespace boost { namespace phoenix
{

    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag>
        struct local_variable
        {
            typedef Tag tag_type;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        // Find a variable in the immediately enclosing scope
        template<
            typename Tag
          , typename State
          , typename Map = typename State::map_type
          , typename Elem = typename fusion::result_of::at_key<Map, Tag>::type
        >
        struct lookup
        {
            typedef Elem result_type;

            result_type operator()(State &state) const
            {
                return fusion::at_key<Tag>(state.map);
            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        // Find a variable in an outer scope
        template<typename Tag, typename State, typename Map>
        struct lookup<Tag, State, Map, fusion::void_ const &>
        {
            typedef typename State::state_type that_state;
            typedef typename lookup<Tag, that_state>::result_type result_type;

            result_type operator()(State &state) const
            {
                return lookup<Tag, that_state>()(state.state);
            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag, typename Callable = proto::callable>
        struct local_variable_evaluator
          : proto::transform<local_variable_evaluator<Tag> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl
              : proto::transform_impl<Expr, State, Data>
            {
                typedef typename impl::state this_state;
                typedef typename state::state_type that_state;

                typedef
                    typename lookup<Tag, this_state>::result_type
                local_var_init;

                typedef
                    typename result_of<evaluator(local_var_init, that_state &, Data)>::type
                result_type;

                result_type operator()(
                    typename impl::expr_param expr
                  , typename impl::state_param state
                  , typename impl::data_param data
                ) const
                {
                    return evaluator()(lookup<Tag, this_state>()(state), state.state, data);
                }
            };
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Tag, typename _ = proto::is_proto_expr>
    struct local_variable
    {
        typedef typename proto::terminal<detail::local_variable<Tag> >::type base_type;
        BOOST_PROTO_BASIC_EXTENDS(base_type, local_variable<Tag>, proto::default_domain)

        operator actor<local_variable<Tag> >() const
        {
            actor<local_variable<Tag> > that = {{{{}}}};
            return that;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Tag>
    struct terminal_extension<detail::local_variable<Tag> >
      : detail::local_variable_evaluator<Tag>
    {};

    ////////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Tag>
    struct is_terminal_nullary<detail::local_variable<Tag> >
      : mpl::false_
    {};

    ////////////////////////////////////////////////////////////////////////////////////////////////
    namespace local_names
    {
        actor<local_variable<struct _a_key> > const _a = {{{{}}}};
        actor<local_variable<struct _b_key> > const _b = {{{{}}}};
        actor<local_variable<struct _c_key> > const _c = {{{{}}}};
        actor<local_variable<struct _d_key> > const _d = {{{{}}}};
        actor<local_variable<struct _e_key> > const _e = {{{{}}}};
        actor<local_variable<struct _f_key> > const _f = {{{{}}}};
        actor<local_variable<struct _g_key> > const _g = {{{{}}}};
        actor<local_variable<struct _h_key> > const _h = {{{{}}}};
        actor<local_variable<struct _i_key> > const _i = {{{{}}}};
        actor<local_variable<struct _j_key> > const _j = {{{{}}}};
        actor<local_variable<struct _k_key> > const _k = {{{{}}}};
        actor<local_variable<struct _l_key> > const _l = {{{{}}}};
        actor<local_variable<struct _m_key> > const _m = {{{{}}}};
        actor<local_variable<struct _n_key> > const _n = {{{{}}}};
        actor<local_variable<struct _o_key> > const _o = {{{{}}}};
        actor<local_variable<struct _p_key> > const _p = {{{{}}}};
        actor<local_variable<struct _q_key> > const _q = {{{{}}}};
        actor<local_variable<struct _r_key> > const _r = {{{{}}}};
        actor<local_variable<struct _s_key> > const _s = {{{{}}}};
        actor<local_variable<struct _t_key> > const _t = {{{{}}}};
        actor<local_variable<struct _u_key> > const _u = {{{{}}}};
        actor<local_variable<struct _v_key> > const _v = {{{{}}}};
        actor<local_variable<struct _w_key> > const _w = {{{{}}}};
        actor<local_variable<struct _x_key> > const _x = {{{{}}}};
        actor<local_variable<struct _y_key> > const _y = {{{{}}}};
        actor<local_variable<struct _z_key> > const _z = {{{{}}}};
    }

}}

#endif
