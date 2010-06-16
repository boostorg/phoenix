/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OPERATOR_MEMBER_HPP
#define PHOENIX_OPERATOR_MEMBER_HPP

#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/make_expr.hpp>
#include <boost/proto/tags.hpp>
#include <boost/type_traits/is_member_function_pointer.hpp>

namespace boost { namespace phoenix
{
    namespace detail
    {
        namespace result_of
        {
            template <typename Object, typename MemPtr,
                PHOENIX_typename_A_void(PHOENIX_MEMBER_LIMIT)
                , typename Dummy = void>
            struct mem_ptr;

            template <typename Object, typename MemPtr>
            struct mem_ptr<Object, MemPtr>
                : proto::result_of::make_expr<
                      proto::tag::function
                    , phoenix_domain
                    , MemPtr
                    , Object>
            {};

#define PHOENIX_ITERATE_RESULT_OF 1
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_MEMBER_LIMIT,                                           \
        <boost/phoenix/operator/member.hpp>,                                    \
        PHOENIX_ITERATE_RESULT_OF))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_RESULT_OF

        }

        template <typename Object, typename MemPtr>
        struct mem_ptr
        {
            mem_ptr(Object const& obj, MemPtr ptr)
              : obj(obj)
              , ptr(ptr)
            {}

            typename result_of::mem_ptr<Object, MemPtr>::type const
            operator()() const
            {
                return proto::make_expr<
                    proto::tag::function, phoenix_domain>(ptr, obj);
            }

#define PHOENIX_ITERATE_OPERATOR 2
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_MEMBER_LIMIT,                                           \
        <boost/phoenix/operator/member.hpp>,                                    \
        PHOENIX_ITERATE_OPERATOR))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_OPERATOR

            Object const& obj;
            MemPtr ptr;

        };
    }

    ////////////////////////////////////////////////////////////////////////////
    //
    // This operator overload is preferred to Proto's when the second parameter
    // is a member function pointer. If it is a member object pointer, Proto's
    // default handling will do the right thing.
    // 
    ////////////////////////////////////////////////////////////////////////////
    template <typename Object, typename MemPtr>
    typename enable_if<
        is_member_function_pointer<MemPtr>
      , detail::mem_ptr<actor<Object>, MemPtr> const
      >::type
    operator->*(actor<Object> const& obj, MemPtr ptr)
    {
        return detail::mem_ptr<actor<Object>, MemPtr>(obj, ptr);
    }

}}

#endif

#else

#if BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_RESULT_OF

            template <typename Object, typename MemPtr, PHOENIX_typename_A>
            struct mem_ptr<Object, MemPtr, PHOENIX_A>
                : proto::result_of::make_expr<
                      proto::tag::function
                    , phoenix_domain
                    , MemPtr
                    , Object
                    , PHOENIX_A>
            {};

#elif BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_OPERATOR

            template <PHOENIX_typename_A>
            typename result_of::mem_ptr<Object, MemPtr, PHOENIX_A>::type const
            operator()(PHOENIX_A_const_ref_a) const
            {
                return proto::make_expr<
                    proto::tag::function, phoenix_domain>(ptr, obj, PHOENIX_a);
            }

#endif
#endif
