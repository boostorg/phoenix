/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_IF_HPP_EAN_2008_05_09
#define BOOST_PHOENIX_IF_HPP_EAN_2008_05_09

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
        struct if_ {};
        struct else_ {};
    }

    namespace detail
    {
        // if_generator and else_generator are a bit of a hack to make
        // the if_(foo)[bar].else_[baz] syntax work. Would be nice to have
        // a cleaner mechanism for this, built into proto.

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        struct else_generator
        {
            typedef typename proto::result_of::left<Expr const &>::type condition_type;
            typedef typename proto::result_of::right<Expr const &>::type body1_type;

            explicit else_generator(Expr const &expr)
              : if_(expr)
            {}

            template<typename Body2>
            typename proto::result_of::make_expr<
                tag::else_
              , domain
              , condition_type
              , body1_type
              , Body2 const &
            >::type const
            operator[](Body2 const &body2) const
            {
                return proto::implicit_expr(proto::left(this->if_), proto::right(this->if_), body2);
            }

        private:
            Expr const &if_;
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        struct actor_with_else : Expr
        {
            actor_with_else(Expr const &expr)
              : Expr(expr)
              , else_(*this)
            {}

            actor_with_else(actor_with_else const &that)
              : Expr(that)
              , else_(*this)
            {}

            else_generator<Expr> else_;

        private:
            actor_with_else &operator=(actor_with_else const &);
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Cond>
        struct if_generator
        {
            explicit if_generator(Cond const &c)
              : cond(c)
            {}

            template<typename Body>
            actor_with_else<
                typename proto::result_of::make_expr<
                    tag::if_
                  , domain
                  , Cond const &
                  , Body const &
                >::type
            > const
            operator[](Body const &body) const
            {
                return proto::make_expr<tag::if_, domain>(boost::ref(this->cond), boost::ref(body));
            }

        private:
            Cond const &cond;
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        // Proto transform that evaluates if_(condition)[ expression ]
        struct if_evaluator : proto::transform<if_evaluator>
        {
            template<typename Expr, typename State, typename Data>
            struct impl : proto::transform_impl<Expr, State, Data>
            {
                typedef void result_type;

                result_type operator()(
                    typename impl::expr_param expr
                  , typename impl::state_param state
                  , typename impl::data_param data
                ) const
                {
                    if(evaluator()(proto::left(expr), state, data))
                    {
                        evaluator()(proto::right(expr), state, data);
                    }
                }
            };
        };

        ////////////////////////////////////////////////////////////////////////////////////////
        // Proto transform that evaluates if_(condition)[ expression ].else_[ expression ]
        struct if_else_evaluator : proto::transform<if_else_evaluator>
        {
            template<typename Expr, typename State, typename Data>
            struct impl : proto::transform_impl<Expr, State, Data>
            {
                typedef void result_type;

                result_type operator()(
                    typename impl::expr_param expr
                  , typename impl::state_param state
                  , typename impl::data_param data
                ) const
                {
                    if(evaluator()(proto::child_c<0>(expr), state, data))
                    {
                        evaluator()(proto::child_c<1>(expr), state, data);
                    }
                    else
                    {
                        evaluator()(proto::child_c<2>(expr), state, data);
                    }
                }
            };
        };
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Expr>
    detail::if_generator<Expr> const if_(Expr const &expr)
    {
        return detail::if_generator<Expr>(expr);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<>
    struct extension<tag::if_, void>
      : proto::when<
            proto::binary_expr<tag::if_, evaluator, evaluator>
          , detail::if_evaluator
        >
    {};

    ////////////////////////////////////////////////////////////////////////////////////////////
    template<>
    struct extension<tag::else_, void>
      : proto::when<
            proto::nary_expr<tag::else_, evaluator, evaluator, evaluator>
          , detail::if_else_evaluator
        >
    {};

}}

#ifdef _MSC_VER
# pragma warning(pop)
#endif

#endif
