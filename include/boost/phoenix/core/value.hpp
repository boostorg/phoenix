/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_VALUE_HPP
#define PHOENIX_CORE_VALUE_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/terminal.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    //
    // values
    //
    //      function for evaluating values, e.g. val(123)
    //
    ////////////////////////////////////////////////////////////////////////////
 
    namespace expression
    {
        template <typename T>
        struct value
            : proto::terminal<T>
        {
            typedef actor<typename proto::terminal<T>::type> type;
            
            static const type make(T t)
            {
                typename value<T>::type const e = {{t}};
                return e;
            }
        };
        
        template <typename T, int N>
        struct value<T[N]>
            : proto::terminal<T>
        {
            typedef actor<typename proto::terminal<T* >::type> type;

            static const type make(T t[N])
            {
                typename value<T *>::type const e = {{t}};
                return e;
            }
        };
    }

    template <typename T>
    typename expression::value<T>::type const
    val(T t)
    {
        return expression::value<T>::make(t);
    }

    // Call out actor for special handling
    template<typename Expr>
    struct is_custom_terminal<actor<Expr> >
      : mpl::true_
    {};
    
    // Special handling for actor
    template<typename Expr>
    struct custom_terminal<actor<Expr> >
    {
        template <typename Sig>
        struct result;

        template <typename This, typename Actor, typename Context>
        struct result<This(Actor, Context)>
            : boost::remove_reference<
                typename evaluator::impl<Actor, Context, int>::result_type
            >
        {};     

        template <typename Context>
        typename result<custom_terminal(actor<Expr> const &, Context &)>::type
        operator()(actor<Expr> const & expr, Context & ctx) const
        {
            return eval(expr, ctx);
        }
    };
}}

#endif
