/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_STATIC_CAST_HPP
#define PHOENIX_OBJECT_STATIC_CAST_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/object/detail/target.hpp>
#include <boost/proto/transform/lazy.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION(
        static_cast_
      , (proto::terminal<detail::target<proto::_> >)
        (meta_grammar)
    )
    
    template <typename T>
    struct static_cast_eval
        : proto::callable
    {
        typedef typename T::type result_type;

        template <typename Context, typename U>
        result_type
        operator()(Context& ctx, U const& u) const
        {
            return static_cast<result_type>(eval(u, ctx));
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::static_cast_, Dummy>
        : proto::lazy<
            static_cast_eval<evaluator(proto::_child_c<0>, _context)
        >(_context, proto::_child_c<1>)>
    {};

    template <typename T, typename U>
    typename expression::static_cast_<detail::target<T>, U>::type const
    static_cast_(U const& u)
    {
        return
            expression::
                static_cast_<detail::target<T>, U>::
                    make(detail::target<T>(), u);
    }
    
    template <typename T, typename U>
    typename expression::static_cast_<detail::target<T>, U>::type const
    static_cast_(U & u)
    {
        return
            expression::
                static_cast_<detail::target<T>, U>::
                    make(detail::target<T>(), u);
    }

}}

#endif
