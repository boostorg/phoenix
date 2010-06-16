/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_ARITY_HPP
#define PHOENIX_CORE_ARITY_HPP

#include <boost/mpl/max.hpp>
#include <boost/mpl/int.hpp>
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
    ////////////////////////////////////////////////////////////////////////////
    //
    //  Calculate the arity of an expression using proto transforms
    //
    ////////////////////////////////////////////////////////////////////////////
    
    struct argument;

    template <typename F>
    struct funcwrap;

    struct env;

    namespace detail
    {
        struct arity
          : proto::or_<
                proto::when<proto::terminal<proto::_>, mpl::int_<0>()>
              , proto::when<
                    proto::function<
                        proto::terminal<funcwrap<argument> >
                      , proto::terminal<env>
                      , proto::_
                    >
                  , mpl::next<proto::_value(proto::_child2)>()
                >
              , proto::otherwise<
                    proto::fold<
                        proto::_
                      , mpl::int_<0>()
                      , mpl::max<arity, proto::_state>()
                    >
                >
            >
        {};
    }

    namespace result_of
    {
        template <typename Expr>
        struct arity
            : boost::result_of<detail::arity(Expr)>
        {};
    }

    template <typename Expr>
    int arity()
    {
        return result_of::arity<Expr>::type::value;
    }

    template <typename Expr>
    int arity(Expr const&)
    {
        return result_of::arity<Expr>::type::value;
    }

}}

#endif
