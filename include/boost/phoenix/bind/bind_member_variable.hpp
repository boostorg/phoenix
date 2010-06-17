/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_BIND_BIND_MEMBER_VARIABLE_HPP
#define PHOENIX_BIND_BIND_MEMBER_VARIABLE_HPP

#include <boost/phoenix/core/mem_obj_ptr.hpp>

namespace boost { namespace phoenix
{

    ////////////////////////////////////////////////////////////////////////////
    // Bind - overload for member object pointers
    ////////////////////////////////////////////////////////////////////////////

    template <typename MemPtr, typename Object>
    typename enable_if<
        is_member_object_pointer<MemPtr>
      , typename make_mem_obj_ptr<Object, MemPtr>::type const
      >::type
    bind( MemPtr ptr, Object const& obj)
    {
        return make_mem_obj_ptr<Object, MemPtr>()(obj, ptr);
    }

}}

#endif
