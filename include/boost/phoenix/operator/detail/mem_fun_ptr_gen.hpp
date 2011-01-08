/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OPERATOR_MEMBER_DETAIL_MEM_FUN_PTR_GEN_HPP
#define PHOENIX_OPERATOR_MEMBER_DETAIL_MEM_FUN_PTR_GEN_HPP

namespace boost { namespace phoenix
{
	namespace tag
	{
		struct mem_fun_ptr;
	}

	namespace detail {
        namespace result_of
        {
            template <typename Object, typename MemPtr,
                PHOENIX_typename_A_void(PHOENIX_MEMBER_LIMIT)
                , typename Dummy = void>
            struct mem_fun_ptr_gen;

            template <typename Object, typename MemPtr>
            struct mem_fun_ptr_gen<Object, MemPtr>
                : proto::result_of::make_expr<
                      tag::mem_fun_ptr
                    , phoenix_domain
                    , Object
                    , MemPtr>
            {};

#define PHOENIX_ITERATE_RESULT_OF 1
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_MEMBER_LIMIT,                                           \
        <boost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>,                    \
        PHOENIX_ITERATE_RESULT_OF))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_RESULT_OF

        }

        template <typename Object, typename MemPtr>
        struct mem_fun_ptr_gen
        {
            mem_fun_ptr_gen(Object const& obj, MemPtr ptr)
              : obj(obj)
              , ptr(ptr)
            {}

            typename result_of::mem_fun_ptr_gen<Object, MemPtr>::type const
            operator()() const
            {
                return proto::make_expr<
                    tag::mem_fun_ptr, phoenix_domain>(obj, ptr);
            }

#define PHOENIX_ITERATE_OPERATOR 2
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_MEMBER_LIMIT,                                           \
        <boost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>,                    \
        PHOENIX_ITERATE_OPERATOR))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_OPERATOR

            Object const& obj;
            MemPtr ptr;

        };

	}
}}

#endif

#else

#if BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_RESULT_OF

            template <typename Object, typename MemPtr, PHOENIX_typename_A>
            struct mem_fun_ptr_gen<Object, MemPtr, PHOENIX_A>
                : proto::result_of::make_expr<
                      tag::mem_fun_ptr
                    , phoenix_domain
                    , Object
                    , MemPtr
                    , PHOENIX_A>
            {};

#elif BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_OPERATOR

            template <PHOENIX_typename_A>
            typename result_of::mem_fun_ptr_gen<
                Object
              , MemPtr
              , PHOENIX_A
            >::type const
            operator()(PHOENIX_A_const_ref_a) const
            {
                return proto::make_expr<
                    tag::mem_fun_ptr, phoenix_domain>(obj, ptr, PHOENIX_a);
            }

            template <PHOENIX_typename_A>
            typename result_of::mem_fun_ptr_gen<
                Object
              , MemPtr
              , PHOENIX_A
            >::type const
            operator()(PHOENIX_A_ref_a) const
            {
                return proto::make_expr<
                    tag::mem_fun_ptr, phoenix_domain>(obj, ptr, PHOENIX_a);
            }

#endif
#endif
