/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_CORE_TERMINAL_HPP
#define BOOST_PHOENIX_CORE_TERMINAL_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/is_placeholder.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/as_actor.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/terminal_fwd.hpp>
#include <boost/proto/matches.hpp>
#include <boost/proto/transform/lazy.hpp>
#include <boost/proto/functional/fusion/at.hpp>
#include <boost/type_traits/remove_pointer.hpp>

namespace boost { namespace phoenix
{
    template <typename T, typename Dummy>
    struct is_custom_terminal
        : mpl::false_ {};

    template <typename T, typename Dummy>
    struct custom_terminal;
 
    namespace expression
    {
        template <typename T>
        struct terminal
            : proto::terminal<T>
        {
            typedef actor<typename proto::terminal<T>::type> type;
            
            static const type make(T t)
            {
                typename terminal<T>::type const e = {{t}};
                return e;
            }
        };
        
        template <typename T, int N>
        struct terminal<T[N]>
            : proto::terminal<T>
        {
            typedef actor<typename proto::terminal<T* >::type> type;

            static const type make(T t[N])
            {
                typename terminal<T *>::type const e = {{t}};
                return e;
            }
        };
    }

    namespace rule
    {
        struct argument
            : proto::if_<boost::is_placeholder<proto::_value>()>
        {};

        struct custom_terminal
            : proto::if_<boost::phoenix::is_custom_terminal<proto::_value>()>
        {};
        
        struct terminal
            : proto::terminal<proto::_>
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<proto::tag::terminal, Dummy>
        : proto::or_<
            enable_rule<rule::argument       , Dummy>
          , enable_rule<rule::custom_terminal, Dummy>
          , enable_rule<rule::terminal       , Dummy>
        >
    {};

    template <typename Dummy>
    struct default_actions::when<rule::custom_terminal, Dummy>
        : proto::lazy<
            custom_terminal<proto::_value>(
                proto::_value
			  , _context
			)
		>
    {};

    namespace detail
    {
        template <typename N>
        struct placeholder_idx
            : mpl::int_<N::value>
        {};
    }
    
    template <typename Grammar>
    struct default_actions::when<rule::argument, Grammar>
        : proto::call<
            proto::functional::at(
                _env
              , detail::placeholder_idx<boost::is_placeholder<proto::_value>()>()
            )
        >
    {};

    namespace meta
    {
        template<typename T>
        struct const_ref
            : add_reference<typename add_const<T>::type>
        {};

        template<typename T>
        struct argument_type
            : mpl::eval_if<
            is_function<typename remove_pointer<T>::type>,
            mpl::identity<T>,
            const_ref<T> >
        {
            typedef T type;
        };
    }

    template <typename T>
    struct as_actor_base
    {
        typedef typename expression::terminal<T>::type type;

        static typename expression::terminal<T>::type
        convert(typename meta::argument_type<T>::type x)
        {
            return expression::terminal<T>::make(x);
        }
    };

    // Sometimes it is necessary to auto-convert references to
    // a value<T>. This happens when we are re-currying. This
    // cannot happen through the standard public actor interfaces.
    template <typename T>
    struct as_actor_base<T&>
    {
        typedef typename expression::terminal<T>::type type;

        static typename expression::terminal<T>::type
        convert(T& x)
        {
            return expression::terminal<T>::make(x);
        }
    };

    template <typename T, int N>
    struct as_actor_base<T[N]>
    {
        typedef typename expression::terminal<T const *>::type type;

        static typename expression::terminal<T const *>::type
        convert(T const x[N])
        {
            return expression::terminal<T const *>::make(x);
        }
    };

}}

#endif
