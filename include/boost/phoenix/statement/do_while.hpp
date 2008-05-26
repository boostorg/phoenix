/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_DO_WHILE_HPP_EAN_2008_05_09
#define BOOST_PHOENIX_DO_WHILE_HPP_EAN_2008_05_09

#include <boost/ref.hpp>
#include <boost/mpl/void.hpp>
#include <boost/phoenix/core/actor.hpp>

#ifdef _MSC_VER
# pragma warning(push)
# pragma warning(disable: 4355) // 'this' : used in base member initializer list
#endif

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////////////////////
    namespace tag
    {
        struct do_while_ {};
    }

    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Body>
        struct do_while_generator
        {
            explicit do_while_generator(Body const &b)
              : body(b)
            {}

            template<typename Cond>
            typename proto::result_of::make_expr<
                tag::do_while_
              , domain
              , Body const &
              , Cond const &
            >::type const
            operator()(Cond const &cond) const
            {
                return proto::implicit_expr(this->body, cond);
            }

        private:
            do_while_generator &operator =(do_while_generator const &);
            Body const &body;
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Body>
        struct do_body
        {
            explicit do_body(Body const &body)
              : while_(body)
            {}

            do_while_generator<Body> while_;
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        struct do_generator
        {
            template<typename Body>
            do_body<Body> const
            operator[](Body const &body) const
            {
                return do_body<Body>(body);
            }
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        // Proto transform that evaluates do_[ body ].while_( condition )
        template<typename SubGrammar, typename X = proto::callable>
        struct do_while_evaluator : proto::transform<do_while_evaluator<SubGrammar> >
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
                    do
                    {
                        evaluator<SubGrammar>()(proto::child_c<0>(expr), state, data);
                    }
                    while(evaluator<SubGrammar>()(proto::child_c<1>(expr), state, data));
                }
            };
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    detail::do_generator const do_ = {};

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename SubGrammar>
    struct extension<tag::do_while_, SubGrammar>
      : proto::when<
            proto::nary_expr<tag::do_while_, evaluator<SubGrammar>, evaluator<SubGrammar> >
          , detail::do_while_evaluator<SubGrammar>
        >
    {};

}}

#ifdef _MSC_VER
# pragma warning(pop)
#endif

#endif
