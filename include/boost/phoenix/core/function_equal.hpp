/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_FUNCTION_EQUAL_HPP
#define PHOENIX_CORE_FUNCTION_EQUAL_HPP

namespace boost { namespace phoenix
{
    // FIXME: need some binary visitation to compare runtime information, needed for bind tests
    template <typename Expr1, typename Expr2>
    bool function_equal_impl(actor<Expr1> const&, actor<Expr2> const&)
    {
        return true;//typeid(actor<Expr1>) == typeid(actor<Expr2>);
    }

    template <typename Expr1, typename Expr2>
    bool function_equal(actor<Expr1> const& a1, actor<Expr2> const& a2)
    {
        return function_equal_impl(a1, a2);
    }

}}

#endif

