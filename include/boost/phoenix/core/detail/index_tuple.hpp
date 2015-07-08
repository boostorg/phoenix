/*=============================================================================
    Copyright (c) 2015 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef BOOST_PHOENIX_CORE_DETAIL_INDEX_TUPLE_HPP
#define BOOST_PHOENIX_CORE_DETAIL_INDEX_TUPLE_HPP

#include <cstddef>
#include <boost/config.hpp>

#ifdef BOOST_NO_CXX11_VARIADIC_TEMPLATES
#   error "Require C++11 variadic templates."
#endif

namespace boost { namespace phoenix { namespace detail
{
    // C++14 like index_tuple
    template <std::size_t... Indices>
    struct index_tuple
    {
        typedef index_tuple type;
    };

    template <typename Left, typename Right>
    struct _index_tuple_join;

    template <std::size_t... Left, std::size_t... Right>
    struct _index_tuple_join<index_tuple<Left...>, index_tuple<Right...> >
        : index_tuple<Left..., (sizeof...(Left) + Right)...> { };


    template <std::size_t N>
    struct make_index_tuple
        : _index_tuple_join<
              typename make_index_tuple<N / 2>::type
            , typename make_index_tuple<N - N / 2>::type
          > { };

    template <>
    struct make_index_tuple<0> : index_tuple<> { };

    template <>
    struct make_index_tuple<1> : index_tuple<0> { };
}}}

#endif

