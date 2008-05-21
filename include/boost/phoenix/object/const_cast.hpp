/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2008 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_OBJECT_CONST_CAST_HPP_EAN_2008_05_21
#define BOOST_PHOENIX_OBJECT_CONST_CAST_HPP_EAN_2008_05_21

#include <boost/proto/proto.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{

    namespace detail
    {
        template<typename T>
        struct const_cast_
        {
            typedef T result_type;
            
            template<typename U>
            T operator()(U &u) const
            {
                return const_cast<T>(u);
            }
        };
    }

    template<typename T, typename U>
    actor<
        typename proto::result_of::make_expr<
            proto::tag::function
          , proto::default_domain
          , detail::const_cast_<T>
          , U
        >::type
    > const
    const_cast_(U const &u)
    {
        detail::const_cast_<T> cast;
        return proto::implicit_expr(cast, u);
    }

}}

#endif
