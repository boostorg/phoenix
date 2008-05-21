/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2008 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_OBJECT_DELETE_HPP_EAN_2008_05_21
#define BOOST_PHOENIX_OBJECT_DELETE_HPP_EAN_2008_05_21

#include <boost/proto/proto.hpp>
#include <boost/checked_delete.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{

    namespace detail
    {
        struct delete_
        {
            typedef void result_type;

            template<typename T>
            void operator()(T const *t) const
            {
                boost::checked_delete(t);
            }
        };
    }

    template<typename T>
    typename proto::result_of::make_expr<
        proto::tag::function
      , detail::domain
      , detail::delete_
      , T const &
    >::type const
    delete_(T const &t)
    {
        detail::delete_ del;
        return proto::implicit_expr(del, t);
    }

}}

#endif
