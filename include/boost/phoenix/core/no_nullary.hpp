/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_NO_NULLARY_HPP
#define PHOENIX_CORE_NO_NULLARY_HPP

#include <boost/mpl/or.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/matches.hpp>
#include <boost/proto/traits.hpp>
#include <boost/proto/tags.hpp>
#include <boost/proto/transform/arg.hpp>
#include <boost/proto/transform/when.hpp>
#include <boost/proto/transform/fold.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    template <typename Fun>
    struct funcwrap;

    template <typename Func, typename Dummy = void>
    struct enable_nullary
        : mpl::true_
    {};
    

    template <typename Expr>
    struct no_nullary;

    namespace detail
    {
        struct no_nullary_transform
          : proto::or_<
                proto::when<
                    proto::terminal<funcwrap<proto::_> >
                  , mpl::not_<
                        mpl::deref<
                            enable_nullary<
                                mpl::deref<proto::_value>
                            >
                        >
                    >()
                >
              , proto::when<proto::terminal<proto::_>, mpl::false_()>
              , proto::otherwise<
                    proto::fold<
                        proto::_
                      , mpl::false_()
                      , mpl::or_<no_nullary_transform, proto::_state>()
                    >
                >
            >
        {};
    }

    template <typename Expr>
    struct no_nullary
        : boost::result_of<detail::no_nullary_transform(Expr const&)>
    {};

}}

#endif
