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
    

    template <typename RT, typename ClassT, typename ClassA>
    /*typename enable_if<
        is_actor<ClassA>
      ,*/ typename result_of::function<
            RT ClassT::* //detail::member_variable<RT, RT ClassT::*>
          , ClassA //const &
        >::type
    //>::type
    bind(RT ClassT::*mp, ClassA /*const&*/ obj)
    {
        /*typedef detail::member_variable<RT, RT ClassT::*> mp_type;
        return function<mp_type>(mp_type(mp))(obj);*/
        return function<RT ClassT::*>(mp)(obj);
    }
    /*
    template <typename RT, typename ClassT, typename ClassA>
    typename disable_if<
        is_actor<ClassA>
      , typename result_of::function<
            detail::member_variable<RT, RT ClassT::*>
          , typename make_reference<ClassA const>::type const
        >::type
    >::type
    bind(RT ClassT::*mp, ClassA const& obj)
    {
        typedef detail::member_variable<RT, RT ClassT::*> mp_type;
        return function<mp_type>(mp_type(mp))(cref(obj));
    }
    
    template <typename RT, typename ClassT>
    typename result_of::function<
        detail::member_variable<RT, RT ClassT::*>
      , typename make_reference<ClassT>::type const
    >::type
    bind(RT ClassT::*mp, ClassT & obj)
    {
        typedef detail::member_variable<RT, RT ClassT::*> mp_type;
        return function<mp_type>(mp_type(mp))(ref(obj));
    }*/
}}

#endif
