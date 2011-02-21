/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_CORE_ARGUMENT_HPP
#define BOOST_PHOENIX_CORE_ARGUMENT_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/terminal.hpp>
#include <boost/mpl/int.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    //
    //  argument
    //
    //      function for evaluating argument placeholders like: _1
    //
    ////////////////////////////////////////////////////////////////////////////
    
    namespace detail
    {
        template <int I>
        struct argument
            : mpl::int_<I>
        {
            bool operator==(argument) const
            {
                return true;
            }

            template <int I2>
            bool operator==(argument<I2>) const
            {
                return false;
            }
        };
    }

}}

namespace boost {
    template <int I>
    struct is_placeholder<phoenix::detail::argument<I> >
        : mpl::int_<I>
    {};
}

namespace boost { namespace phoenix
{
    namespace expression
    {
        template <int I>
        struct argument
            : expression::terminal<detail::argument<I> >
        {
            typedef typename expression::terminal<detail::argument<I> >::type type;
            static const type make()
            {
                type const e = {};
                return e;
            }
        };
    }

    #define BOOST_PHOENIX_ARGUMENT_N(_, N, name)                                \
    expression::argument<BOOST_PP_INC(N)>::type const                           \
        BOOST_PP_CAT(name, BOOST_PP_INC(N)) = {};                               \
    /**/

    namespace placeholders
    {
        BOOST_PP_REPEAT(BOOST_PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, arg)
        BOOST_PP_REPEAT(BOOST_PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, _)
    }

    namespace arg_names
    {
        BOOST_PP_REPEAT(BOOST_PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, arg)
        BOOST_PP_REPEAT(BOOST_PHOENIX_ARG_LIMIT, BOOST_PHOENIX_ARGUMENT_N, _)
    }

    #undef BOOST_PHOENIX_ARGUMENT_N
}}

#endif
