/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_SCOPE_SCOPE_GRAMMAR_HPP
#define PHOENIX_SCOPE_SCOPE_GRAMMAR_HPP

namespace boost { namespace phoenix
{
    struct scope_grammar
        : proto::switch_<scope_grammar>
    {
        template <typename Tag, typename Dummy = void>
        struct case_
            : meta_grammar::case_<Tag, Dummy>
        {};
    };
}}

#endif
