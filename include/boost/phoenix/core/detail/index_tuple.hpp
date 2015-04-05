/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_PHOENIX_CORE_DETAIL_INDEX_TUPLE_HPP
#define BOOST_PHOENIX_CORE_DETAIL_INDEX_TUPLE_HPP

#include <cstddef>
#include <boost/config.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/identity.hpp>

#ifdef BOOST_NO_CXX11_VARIADIC_TEMPLATES
#   error "Require C++11 variadic templates."
#endif

namespace boost { namespace phoenix { namespace detail
{
    // C++14 like index_tuple
    template <std::size_t... Indices>
    struct index_tuple { };

    template <std::size_t N, typename T>
    struct make_index_tuple_impl_;

    template <std::size_t N, std::size_t... Indices>
    struct make_index_tuple_impl_<N, index_tuple<Indices...> >
        : mpl::if_c<
            N == 0
          , mpl::identity<index_tuple<Indices...> >
          , make_index_tuple_impl_<N - 1, index_tuple<N - 1, Indices...> >
        >::type
    {
    };

    template <std::size_t N>
    struct make_index_tuple
        : make_index_tuple_impl_<N, index_tuple<> >
    {
    };
}}}

#endif

