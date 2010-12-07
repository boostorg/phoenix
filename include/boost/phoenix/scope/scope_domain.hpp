/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_SCOPE_DOMAIN_HPP
#define PHOENIX_SCOPE_SCOPE_DOMAIN_HPP

namespace boost { namespace phoenix
{
    template <typename Expr>
    struct scope_actor;
    
    struct scope_grammar;
    
    struct scope_domain
        : proto::domain<
            proto::pod_generator<scope_actor>
          , scope_grammar
          //, proto::_
          //, proto::default_domain
          , phoenix_domain
        >
    {
        template <typename T>
        struct as_child : as_expr<T>
        {};
    };
}}

#endif
