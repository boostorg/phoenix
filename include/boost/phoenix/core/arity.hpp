/*==============================================================================
    Copyright (c) 2010 Thomas Heller
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ARITY_HPP
#define PHOENIX_CORE_ARITY_HPP

#include <boost/mpl/max.hpp>
#include <boost/mpl/int.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/matches.hpp>
#include <boost/proto/traits.hpp>
#include <boost/proto/tags.hpp>
#include <boost/proto/transform/arg.hpp>
#include <boost/proto/transform/default.hpp>
#include <boost/proto/transform/when.hpp>
#include <boost/proto/transform/fold.hpp>

namespace boost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    //
    //  Calculate the arity of an expression using proto transforms
    //
    /////////////////////////////////////////////////////////////////////////////
    
    struct argument;

    struct arity;

    namespace result_of
    {
        template <typename Expr>
        struct arity
            : mpl::int_<
                evaluator::impl<
                    Expr const&
                  , fusion::vector2<
                        mpl::int_<0>
                      , boost::phoenix::arity
                    >&
                >::result_type::value
            >
        {};
    }

    struct arity
    {
        template <typename Rule, typename Dummy = void>
        struct when
            : proto::fold<
                proto::_
              , mpl::int_<0>
              , mpl::max<
                    proto::_state
                  , evaluator(proto::_, _context)
                >()
            >
        {};
    };

    template <typename Dummy>
    struct arity::when<rule::argument, Dummy>
        : proto::make<is_placeholder<proto::_value>()>
    {};
    
    template <typename Dummy>
    struct arity::when<rule::custom_terminal, Dummy>
        : proto::make<mpl::int_<0>()>
    {};
    
    template <typename Dummy>
    struct arity::when<rule::terminal, Dummy>
        : proto::make<mpl::int_<0>()>
    {};
}}

#endif
