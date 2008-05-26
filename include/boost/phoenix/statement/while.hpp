/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_WHILE_HPP_EAN_2008_05_09
#define BOOST_PHOENIX_WHILE_HPP_EAN_2008_05_09

#include <boost/ref.hpp>
#include <boost/mpl/void.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////////////////////
    namespace tag
    {
        struct while_ {};
    }

    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Cond>
        struct while_generator
        {
            explicit while_generator(Cond const &c)
              : cond(c)
            {}

            template<typename Body>
            typename proto::result_of::make_expr<
                tag::while_
              , domain
              , Cond const &
              , Body const &
            >::type const
            operator[](Body const &body) const
            {
                return proto::implicit_expr(this->cond, body);
            }

        private:
            while_generator &operator =(while_generator const &);
            Cond const &cond;
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        // Proto transform that evaluates if_(condition)[ expression ]
        template<typename SubGrammar, typename X = proto::callable>
        struct while_evaluator : proto::transform<while_evaluator<SubGrammar> >
        {
            template<typename Expr, typename State, typename Data>
            struct impl : proto::transform_impl<Expr, State, Data>
            {
                typedef void result_type;

                void operator()(
                    typename impl::expr_param expr
                  , typename impl::state_param state
                  , typename impl::data_param data
                ) const
                {
                    while(evaluator<SubGrammar>()(proto::left(expr), state, data))
                    {
                        evaluator<SubGrammar>()(proto::right(expr), state, data);
                    }
                }
            };
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Expr>
    detail::while_generator<Expr> const
    while_(Expr const &expr)
    {
        return detail::while_generator<Expr>(expr);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename SubGrammar>
    struct extension<tag::while_, SubGrammar>
      : proto::when<
            proto::binary_expr<tag::while_, evaluator<SubGrammar>, evaluator<SubGrammar> >
          , detail::while_evaluator<SubGrammar>
        >
    {};

}}

#endif
