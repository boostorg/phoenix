/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2011 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_CALL_HPP
#define PHOENIX_CORE_CALL_HPP

namespace boost { namespace phoenix
{
    namespace detail
    {
        template <typename Fun, typename Expr, typename State, typename Data, long Arity = proto::arity_of<Expr>::value>
        struct call_impl;
    }

    template <typename Fun>
    struct call
        : proto::transform<call<Fun> >
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : detail::call_impl<Fun, Expr, State, Data>
        {};
    };

    #include <boost/phoenix/core/detail/call.hpp>

}

    namespace proto
    {
        template <typename Fun>
        struct is_callable<phoenix::call<Fun> > : mpl::true_ {};
    }

}



#endif
