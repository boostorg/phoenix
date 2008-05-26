/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_FOR_HPP_EAN_2008_05_09
#define BOOST_PHOENIX_FOR_HPP_EAN_2008_05_09

#include <boost/ref.hpp>
#include <boost/mpl/void.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////////////////////
    namespace tag
    {
        struct for_ {};
    }

    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Init, typename Cond, typename Oper>
        struct for_generator
        {
            explicit for_generator(Init const &i, Cond const &c, Oper const &o)
              : init(i)
              , cond(c)
              , oper(o)
            {}

            template<typename Body>
            typename proto::result_of::make_expr<
                tag::for_
              , domain
              , Init const &
              , Cond const &
              , Oper const &
              , Body const &
            >::type const
            operator[](Body const &body) const
            {
                return proto::implicit_expr(this->init, this->cond, this->oper, body);
            }

        private:
            for_generator &operator =(for_generator const &);
            Init const &init;
            Cond const &cond;
            Oper const &oper;
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        // Proto transform that evaluates for_(x,y,z)[expr]
        template<typename SubGrammar, typename X = proto::callable>
        struct for_evaluator : proto::transform<for_evaluator<SubGrammar> >
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
                    for(evaluator<SubGrammar>()(proto::child_c<0>(expr), state, data)
                      ; evaluator<SubGrammar>()(proto::child_c<1>(expr), state, data)
                      ; evaluator<SubGrammar>()(proto::child_c<2>(expr), state, data))
                    {
                        evaluator<SubGrammar>()(proto::child_c<3>(expr), state, data);
                    }
                }
            };
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Init, typename Cond, typename Oper>
    detail::for_generator<Init, Cond, Oper> const
    for_(Init const &i, Cond const &c, Oper const &o)
    {
        return detail::for_generator<Init, Cond, Oper>(i, c, o);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename SubGrammar>
    struct extension<tag::for_, SubGrammar>
      : proto::when<
            proto::nary_expr<
                tag::for_
              , evaluator<SubGrammar>
              , evaluator<SubGrammar>
              , evaluator<SubGrammar>
              , evaluator<SubGrammar>
            >
          , detail::for_evaluator<SubGrammar>
        >
    {};

}}

#endif
