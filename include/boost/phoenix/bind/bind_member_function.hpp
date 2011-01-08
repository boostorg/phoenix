/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_BIND_BIND_MEMBER_FUNCTION_HPP
#define PHOENIX_BIND_BIND_MEMBER_FUNCTION_HPP

#include <boost/phoenix/function.hpp>
#include <boost/phoenix/core/reference.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    template <typename RT, typename ClassT, typename ClassA>
    typename result_of::function<
        RT(ClassT::*)()
      , ClassA
    >::type
    bind(RT(ClassT::*f)(), ClassA obj)
    {
        return function<RT(ClassT::*)()>(f)(obj);
    }

    template <typename RT, typename ClassT, typename ClassA>
    typename result_of::function<
        RT(ClassT::*)() const
      , ClassA
    >::type
    bind(RT(ClassT::*f)() const, ClassA obj)
    {
        return function<RT(ClassT::*)() const>(f)(obj);
    }

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_ARG_LIMIT,                                                  \
    <boost/phoenix/bind/bind_member_function.hpp>))
#include PHOENIX_ITERATE()

}}

#endif

#else
    
    template <
        typename RT
      , typename ClassT
      , BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename T)
      , typename ClassA
      , PHOENIX_typename_A
    >
    typename result_of::function<
        RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T))
      , ClassA const&
      , PHOENIX_A_const_ref
    >::type
    bind(
        RT(ClassT::*f)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T))
      , ClassA const& obj
      , PHOENIX_A_const_ref_a
    )
    {
        return function<
            RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T))>(f)(
                obj, PHOENIX_a);
    }

    template <
        typename RT
      , typename ClassT
      , BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename T)
      , typename ClassA
      , PHOENIX_typename_A
    >
    typename result_of::function<
        RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T)) const
      , ClassA const&
      , PHOENIX_A_const_ref
    >::type
    bind(
        RT(ClassT::*f)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T)) const
      , ClassA const& obj
      , PHOENIX_A_const_ref_a
    )
    {
        return function<
            RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T)) const>(f)(
                obj, PHOENIX_a);
    }

    template <
        typename RT
      , typename ClassT
      , BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename T)
      , PHOENIX_typename_A
    >
    typename result_of::function<
        RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T))
      , typename make_reference<ClassT>::type const
      , PHOENIX_A_const_ref
    >::type
    bind(
        RT(ClassT::*f)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T))
      , ClassT& obj
      , PHOENIX_A_const_ref_a
    )
    {
        return function<
            RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T))>(f)(
                ref(obj), PHOENIX_a);
    }

    template <
        typename RT
      , typename ClassT
      , BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, typename T)
      , PHOENIX_typename_A
    >
    typename result_of::function<
        RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T)) const
      , typename make_reference<ClassT>::type const
      , PHOENIX_A_const_ref
    >::type
    bind(
        RT(ClassT::*f)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T)) const
      , ClassT& obj
      , PHOENIX_A_const_ref_a)
    {
        return function<
            RT(ClassT::*)(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, T)) const>(f)(
                ref(obj), PHOENIX_a);
    }

#endif
