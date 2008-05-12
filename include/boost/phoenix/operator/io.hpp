/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OPERATOR_IO_HPP
#define PHOENIX_OPERATOR_IO_HPP

#include <iosfwd>
#include <boost/phoenix/core/actor.hpp>
#include <boost/proto/proto.hpp>

namespace boost { namespace phoenix
{

    namespace actorns_
    {

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        actor<
            typename proto::shift_left<
                actor<Expr> const &
              , proto::terminal<std::ostream &(*)(std::ostream &)>::type
            >::type
        > const
        operator<<(actor<Expr> const &expr, std::ostream &(*omanip)(std::ostream &))
        {
            actor<
                typename proto::shift_left<
                    actor<Expr> const &
                  , proto::terminal<std::ostream &(*)(std::ostream &)>::type
                >::type
            > that = {{expr, {omanip}}};
            return that;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        actor<
            typename proto::shift_left<
                actor<Expr> const &
              , proto::terminal<std::ios_base &(*)(std::ios_base &)>::type
            >::type
        > const
        operator<<(actor<Expr> const &expr, std::ios_base &(*iomanip)(std::ios_base &))
        {
            actor<
                typename proto::shift_left<
                    actor<Expr> const &
                  , proto::terminal<std::ios_base &(*)(std::ios_base &)>::type
                >::type
            > that = {{expr, {iomanip}}};
            return that;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        actor<
            typename proto::shift_right<
                actor<Expr> const &
              , proto::terminal<std::istream &(*)(std::istream &)>::type
            >::type
        > const
        operator>>(actor<Expr> const &expr, std::istream &(*imanip)(std::istream &))
        {
            actor<
                typename proto::shift_right<
                    actor<Expr> const &
                  , proto::terminal<std::istream &(*)(std::istream &)>::type
                >::type
            > that = {{expr, {imanip}}};
            return that;
        }

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        actor<
            typename proto::shift_right<
                actor<Expr> const &
              , proto::terminal<std::ios_base &(*)(std::ios_base &)>::type
            >::type
        > const
        operator>>(actor<Expr> const &expr, std::ios_base &(*iomanip)(std::ios_base &))
        {
            actor<
                typename proto::shift_right<
                    actor<Expr> const &
                  , proto::terminal<std::ios_base &(*)(std::ios_base &)>::type
                >::type
            > that = {{expr, {iomanip}}};
            return that;
        }
    } // actorns_

}}

#endif
