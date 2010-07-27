/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_DETAIL_ACTOR_FUN_EVAL_HPP
#define PHOENIX_CORE_DETAIL_ACTOR_FUN_EVAL_HPP

#include <boost/phoenix/support/iterate.hpp>
#include <boost/preprocessor/repetition/enum_shifted_binary_params.hpp>
#include <boost/preprocessor/punctuation/paren.hpp>

#define PHOENIX_ITERATION_PARAMS                                                \
        (3, (4, PHOENIX_ACTOR_LIMIT,                                            \
        <boost/phoenix/core/detail/actor_fun_eval.hpp>))
#include PHOENIX_ITERATE()

#endif

#else
    template <PHOENIX_typename_A>
    struct actor_fun_eval<PHOENIX_A>
    {
#define EVAL_RESULTS(_, n, __) BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) typename boost::result_of<eval_grammar(A ## n const&, Env&)>::type
        template <typename Env, typename Dummy = void>
        struct basic_environment
            : make_basic_environment<
                BOOST_PP_REPEAT_FROM_TO(
                    1, PHOENIX_ITERATION, EVAL_RESULTS, _)>
        {};

        template <typename Sig>
        struct result;

        template <typename This, typename Env>
        struct result<This(Env&, PHOENIX_A_const_ref)>
        {
            typedef typename boost::result_of<
                eval_grammar(A0 const&, typename basic_environment<Env>::type&)
                >::type
                type;
        };

        template <typename Env>
        typename boost::result_of<
            eval_grammar(A0 const&, typename basic_environment<Env>::type&)
            >::type
        operator()(Env& env, PHOENIX_A_const_ref_a) const
        {
#define EVAL_ARGS(_, n, __) BOOST_PP_COMMA_IF(BOOST_PP_DEC(n)) eval(a ## n , env)
            typename basic_environment<Env>::type args(
                BOOST_PP_REPEAT_FROM_TO(1, PHOENIX_ITERATION, EVAL_ARGS, _));

            return eval(a0, args);
        }
    };

#undef EVAL_ARGS
#undef EVAL_RESULTS

#endif

