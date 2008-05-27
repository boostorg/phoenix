/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2008 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_SCOPE_LOCAL_VARIABLE_HPP_EAN_2008_05_21
#define BOOST_PHOENIX_SCOPE_LOCAL_VARIABLE_HPP_EAN_2008_05_21

#include <boost/ref.hpp>
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
        template<typename Local>
        struct local_variable_tag
        {
            typedef typename Local::tag_type type;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        // Find a variable in the immediately enclosing scope
        template<
            typename Tag
          , typename State
          , bool HasKey = fusion::result_of::has_key<typename State::locals_type, Tag>::type::value
        >
        struct find_local
        {
            typedef typename
                fusion::result_of::at_key<typename State::locals_type, Tag>::type
            result_type;

            result_type operator()(State &state) const
            {
                return fusion::at_key<Tag>(state.locals);
            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        // Find a variable in an outer scope
        template<typename Tag, typename State>
        struct find_local<Tag, State, false>
        {
            typedef typename
                find_local<Tag, typename State::state_type>::result_type
            result_type;

            result_type operator()(State &state) const
            {
                return find_local<Tag, typename State::state_type>()(state.state);
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
                typedef
                    typename find_local<Tag, typename impl::state>::result_type
                result_type;

                result_type operator()(
                    typename impl::expr_param expr
                  , typename impl::state_param state
                  , typename impl::data_param data
                ) const
                {
                    return find_local<Tag, typename impl::state>()(state);
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
    // Bare local variables (outside of a let() or lambda()) are not valid lambda expressions.
    template<typename Tag, typename SubGrammar>
    struct terminal_extension<detail::local_variable<Tag>, SubGrammar>
      : proto::not_<proto::_>
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
