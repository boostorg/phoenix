/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OPERATOR_DETAIL_MEM_FUN_PTR_EVAL_RESULT_OF_HPP
#define PHOENIX_OPERATOR_DETAIL_MEM_FUN_PTR_EVAL_RESULT_OF_HPP

#define PHOENIX_MEM_FUN_PTR_EVAL_RESULT_OF_CHILD(Z, N, D)                       \
            typedef                                                             \
                typename                                                        \
                evaluator::impl<                                                \
                    BOOST_PP_CAT(A, N)                                          \
                  , Context                                                     \
                  , int                                                         \
                >::result_type                                                  \
                BOOST_PP_CAT(child, N);                                         \
        /**/

        #define PHOENIX_ITERATION_PARAMS                                        \
            (3, (2, PHOENIX_LIMIT,                                              \
                 <boost/phoenix/operator/detail/mem_fun_ptr_eval_result_of.hpp>))
        #include PHOENIX_ITERATE()

#undef PHOENIX_MEM_FUN_PTR_EVAL_RESULT_OF_CHILD

#endif

#else

        template <typename Context, PHOENIX_typename_A>
        struct mem_fun_ptr_eval<Context, PHOENIX_A>
        {
            BOOST_PP_REPEAT(PHOENIX_ITERATION, PHOENIX_MEM_FUN_PTR_EVAL_RESULT_OF_CHILD, _)

            typedef
                typename boost::result_of<
                    child1(
                        BOOST_PP_ENUM_SHIFTED_PARAMS(PHOENIX_ITERATION, child)
                    )
                >::type
                type;
        };

#endif
