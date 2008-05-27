/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_FUNCTION_FUNCTION_HPP
#define PHOENIX_FUNCTION_FUNCTION_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/proto/proto.hpp>

namespace boost { namespace phoenix
{

    template<typename Fun>
    struct function
    {
        typedef typename proto::terminal<Fun>::type base_type;
        BOOST_PROTO_EXTENDS(base_type, function<Fun>, detail::domain)
    };

}}

#endif
