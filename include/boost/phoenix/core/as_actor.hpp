/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_AS_ACTOR_HPP_EAN_2008_06_03
#define BOOST_PHOENIX_AS_ACTOR_HPP_EAN_2008_06_03

#include <iosfwd> // for std::ios_base
#include <boost/mpl/or.hpp>
#include <boost/proto/proto.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/is_abstract.hpp>
#include <boost/type_traits/is_function.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/add_reference.hpp>

namespace boost { namespace phoenix
{
    namespace actorns_
    {
        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        struct actor;
    }

    using actorns_::actor;

    namespace detail
    {
        ////////////////////////////////////////////////////////////////////////////////////////
        // These terminal types are always stored by reference
        template<typename Value>
        struct storage
        {
            typedef
                typename mpl::eval_if_c<
                    mpl::or_<
                        is_abstract<Value>
                      , is_function<Value>
                      , is_base_of<std::ios_base, Value>
                    >::type::value
                  , add_reference<Value>
                  , remove_const<Value>
                >::type
            type;
        };

        template<typename T, std::size_t N>
        struct storage<T[N]>
        {
            typedef T (&type)[N];
        };

        template<typename T, std::size_t N>
        struct storage<T const[N]>
        {
            typedef T const (&type)[N];
        };
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////    
    template<typename T>
    struct as_actor
    {
        typedef
            proto::expr<
                proto::tag::terminal
              , proto::term<typename detail::storage<T>::type>
            >
        term_type;

        typedef
            actor<term_type>
        type;
        
        static type const
        convert(T const &t)
        {
            return type::make(term_type::make(t));
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////    
    template<typename Expr>
    struct as_actor<actor<Expr> >
    {
        typedef actor<Expr> type;
        
        static actor<Expr> const
        convert(actor<Expr> const &expr)
        {
            return expr;
        }
    };

    ////////////////////////////////////////////////////////////////////////////////////////////////    
    template<typename Expr>
    struct as_actor<actor<Expr> const>
    {
        typedef actor<Expr> type;
        
        static actor<Expr> const
        convert(actor<Expr> const &expr)
        {
            return expr;
        }
    };
}}

#endif
