/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_META_GRAMMAR_HPP
#define PHOENIX_CORE_META_GRAMMAR_HPP

#include <boost/mpl/deref.hpp>
#include <boost/phoenix/core/environment.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/matches.hpp>
#include <boost/proto/traits.hpp>
#include <boost/proto/tags.hpp>
#include <boost/proto/transform/arg.hpp>
#include <boost/proto/transform/default.hpp>
#include <boost/proto/transform/when.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // The grammar defining valid phoenix expressions
    struct meta_grammar
        : proto::switch_<meta_grammar>
    {
        template <typename Tag, typename Dummy = void>
        struct case_
            : proto::not_<proto::_>
        {};
    };

    ////////////////////////////////////////////////////////////////////////////
    // An evaluation transform you can call to dispatch to different actions
    namespace detail
    {
        template <typename Expr>
        struct grammar_of
        {
            typedef typename proto::domain_of<Expr>::type domain_type;
            typedef typename domain_type::proto_grammar domain_grammar;
            typedef
                typename mpl::if_<
                    is_same<domain_grammar, proto::_>
                  , meta_grammar
                  , domain_grammar
                >::type
                type;
        };

        template <typename Expr, typename State, typename Data>
        struct evaluator_impl
            : proto::transform_impl<Expr, State, Data>
        {
            typedef typename grammar_of<Expr>::type grammar_type;
            typedef
                typename grammar_type::
                    template impl<Expr, State, Data>::result_type
                result_type;
            
            result_type
            operator()(
                typename evaluator_impl::expr_param  expr
              , typename evaluator_impl::state_param state
              , typename evaluator_impl::data_param  data
            )
            {
                //std::cout << "evaluator<Expr, State, Data>\n";
                return
                    typename grammar_type::
                        template impl<Expr, State, Data>()(
                            expr, state, data
                        );
            }
        };
        
        template <typename Expr, typename State>
        struct evaluator_impl<Expr, State, int>
            : proto::transform_impl<Expr, State, int>
        {
            typedef typename grammar_of<Expr>::type grammar_type;
            typedef typename boost::result_of<functional::args(State)>::type args_type;
            typedef typename boost::result_of<functional::actions(State)>::type actions_type;
            typedef typename grammar_type::template impl<Expr, args_type, actions_type>::result_type result_type;
            
            result_type
            operator()(
                typename evaluator_impl::expr_param  expr
              , typename evaluator_impl::state_param state
              , typename evaluator_impl::data_param  data
            )
            {
                /*
                std::cout << "evaluator<Expr, State, int>\n";
                std::cout << typeid(grammar_type).name() << "\n";
                std::cout << typeid(Expr).name() << "\n";
                */
                return
                    typename grammar_type::
                        template impl<Expr, args_type, actions_type>()(
                            expr, functional::args()(state), functional::actions()(state)
                        );
            }
        };
        
        template <typename Expr, typename State>
        struct evaluator_impl<Expr, State, State>
            : proto::transform_impl<Expr, State, State>
        {
            typedef typename grammar_of<Expr>::type grammar_type;
            typedef typename boost::result_of<functional::args(State)>::type args_type;
            typedef typename boost::result_of<functional::actions(State)>::type actions_type;
            typedef typename grammar_type::template impl<Expr, args_type, actions_type>::result_type result_type;
            
            result_type
            operator()(
                typename evaluator_impl::expr_param  expr
              , typename evaluator_impl::state_param state
              , typename evaluator_impl::data_param  data
            )
            {
                //std::cout << "evaluator<Expr, State, State>\n";
                return typename grammar_type::template impl<Expr, args_type, actions_type>()(expr, functional::args()(state), functional::actions()(state));
            }
        };
    }

    struct evaluator
        : proto::transform<evaluator>
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : detail::evaluator_impl<Expr, State, Data>
        {};
        /*
            : proto::transform_impl<Expr, State, Data>
        {
            typedef typename boost::result_of<functional::args(State)>::type args_type;
            typedef typename boost::result_of<functional::actions(State)>::type actions_type;
            typedef typename meta_grammar::template impl<Expr, args_type, actions_type>::result_type result_type;
            
            result_type
            operator()(
                typename impl::expr_param  expr
              , typename impl::state_param state
              , typename impl::data_param  data
            )
            {
                return typename meta_grammar::template impl<Expr, args_type, actions_type>()(expr, functional::args()(state), functional::actions()(state));
                //return meta_grammar()(expr
            }
        };
        */
    };
    /*
        : proto::call<
            meta_grammar(
                proto::_
              , functional::args(proto::_state)
              , functional::actions(proto::_state)
            )
        >
    {};
    */
    
    ////////////////////////////////////////////////////////////////////////////
    // Set of default actions. Extend this whenever you add a new phoenix construct
    struct default_actions
    {
        template <typename Rule, typename Dummy = void>
        struct when
            : proto::_default<evaluator>
        {};
    };

    ////////////////////////////////////////////////////////////////////////////
    // A function object we can call to evaluate our expression
    evaluator const eval = evaluator();
}}

#endif
