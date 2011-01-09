/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_IS_NULLARY_HPP
#define PHOENIX_CORE_IS_NULLARY_HPP

#include <boost/proto/proto.hpp>
#include <boost/phoenix/core/environment.hpp>
#include <boost/phoenix/core/is_actor.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/terminal.hpp>

namespace boost { namespace phoenix
{
    namespace result_of
    {
        template <typename Expr, typename Enable = void>
        struct is_nullary;
    }

    struct is_nullary
    {
        template <typename Rule, typename Dummy = void>
        struct when
            : proto::fold<
                proto::_
              , mpl::true_()
              , mpl::and_<
                    proto::_state
                  , evaluator(proto::_, _env)
                >()
            >
        {};
    };
    
    template <typename Dummy>
    struct is_nullary::when<rule::argument, Dummy>
        : proto::make<mpl::false_()>
    {};
    
    template <typename Dummy>
    struct is_nullary::when<rule::custom_terminal, Dummy>
        : proto::lazy<
            result_of::is_nullary<custom_terminal<proto::_value> >(
                proto::_
              , _env
            )
        >
    {};
    
    template <typename Dummy>
    struct is_nullary::when<rule::terminal, Dummy>
        : proto::make<mpl::true_()>
    {};

    namespace result_of
    {
        template <typename Expr, typename Enable>
        struct is_nullary
        {
            typedef
                typename boost::phoenix::evaluator::impl<
                    Expr const &
                  , fusion::vector2<
                        mpl::true_
                      , boost::phoenix::is_nullary
                    >
                  , int
                >::result_type
                type;
        };
        
        template <typename T>
        struct is_nullary<T & >
            : is_nullary<T>
        {};

        template <typename T>
        struct is_nullary<T const & >
            : is_nullary<T>
        {};

        template <typename T>
        struct is_nullary<T const >
            : is_nullary<T>
        {};
        
        template <typename T>
        struct is_nullary<custom_terminal<T>, typename disable_if<is_actor<T> >::type>
            : proto::make<mpl::true_()>
        {};
        
        template <typename T>
        struct is_nullary<custom_terminal<T>, typename enable_if<is_actor<T> >::type>
            : proto::call<evaluator(proto::_value)>
        {};
    }

}}

#endif

