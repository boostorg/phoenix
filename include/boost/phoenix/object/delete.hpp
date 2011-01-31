/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_DELETE_HPP
#define PHOENIX_OBJECT_DELETE_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>

namespace boost { namespace phoenix
{
    namespace tag {
        struct delete_ {};
    }

    namespace expression
    {
        template <typename T>
        struct delete_
            : expr<tag::delete_, T>
        {};
    }

    namespace rule
    {
        struct delete_
            : expression::delete_<meta_grammar>
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<tag::delete_, Dummy>
        : proto::when<rule::delete_, proto::external_transform>
    {};

    struct delete_eval
        : proto::callable
    {
        typedef void result_type;

        template <typename Context, typename P>
        result_type
        operator()(Context& ctx, P const& p) const
        {
            delete eval(p, ctx);
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::delete_, Dummy>
        : proto::call<delete_eval(_context, proto::_child_c<0>)>
    {};

    template <typename P>
    typename expression::delete_<P>::type const
    delete_(P const& p)
    {
        return expression::delete_<P>::make(p);
    }

}}

#endif
