/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_DOMAIN_HPP
#define PHOENIX_CORE_DOMAIN_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/proto/proto_fwd.hpp>
#include <boost/proto/domain.hpp>
#include <boost/proto/generate.hpp>
#include <boost/proto/matches.hpp>

namespace boost { namespace phoenix
{
    template <typename Expr>
    struct actor;
    
    struct meta_grammar;
    
    struct phoenix_domain
        : proto::domain<
            proto::pod_generator<actor>
          , meta_grammar
          , proto::default_domain
        >
    {
        template <typename T>
        struct as_child
            : as_expr<T>
        {};
    };
}}

#endif
