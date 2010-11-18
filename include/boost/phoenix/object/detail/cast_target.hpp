/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_DETAIL_CAST_TARGET_HPP
#define PHOENIX_OBJECT_DETAIL_CAST_TARGET_HPP

namespace boost { namespace phoenix
{
    namespace detail
    {
        template <typename T>
        struct cast_target
        {
            typedef T type;
        };
    }
}}

#endif
