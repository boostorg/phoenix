/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef BOOST_PHOENIX_THROW_HPP_EAN_2008_05_18
#define BOOST_PHOENIX_THROW_HPP_EAN_2008_05_18

#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{
    namespace detail
    {
        struct throw_fun
        {
            typedef void result_type;

            void operator()() const
            {
                throw;
            }

            template<typename Exception>
            void operator()(Exception const &exception) const
            {
                throw exception;
            }
        };

        typedef actor<proto::terminal<throw_fun>::type> throw_type;
        throw_type const throw_ = {{{}}};
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    actor<proto::function<detail::throw_type>::type> const
    throw_()
    {
        actor<proto::function<detail::throw_type>::type> that = {{detail::throw_}};
        return that;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////
    template<typename Expr>
    typename proto::result_of::make_expr<
        proto::tag::function
      , detail::domain
      , detail::throw_type
      , Expr const &
    >::type const
    throw_(Expr const &expr)
    {
        return proto::implicit_expr(detail::throw_, expr);
    }

}}

#endif
