
#if !defined(PHOENIX_DONT_USE_PREPROCESSED_FILES)
#ifndef PHOENIX_OPERATOR_MEMBER_HPP
#define PHOENIX_OPERATOR_MEMBER_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/get_pointer.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/type_traits/is_member_function_pointer.hpp>

#include <boost/phoenix/operator/preprocessed/member.hpp>

#endif
#else

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_OPERATOR_MEMBER_HPP
#define PHOENIX_OPERATOR_MEMBER_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/get_pointer.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/operator/detail/mem_fun_ptr_gen.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/type_traits/is_member_function_pointer.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 2, line: 0, output: "preprocessed/member_" PHOENIX_LIMIT_STR ".hpp")
#endif

/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(preserve: 1)
#endif

#include <boost/phoenix/operator/detail/define_operator.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_BINARY_OPERATORS(
        (mem_ptr)
    )

    PHOENIX_DEFINE_EXPRESSION_VARARG(mem_fun_ptr, (meta_grammar), PHOENIX_LIMIT)

    template <typename Object, typename MemPtr>
    typename enable_if<
        is_member_function_pointer<MemPtr>
      , detail::mem_fun_ptr_gen<actor<Object>, MemPtr> const
      >::type
    operator->*(actor<Object> const& obj, MemPtr ptr)
    {
        return detail::mem_fun_ptr_gen<actor<Object>, MemPtr>(obj, ptr);
    }

    namespace result_of
    {
        template <
            typename Context
          , typename Expr
          , long Arity = proto::arity_of<Expr>::value
        >
        struct mem_fun_ptr_eval;

        #include <boost/phoenix/operator/detail/mem_fun_ptr_eval_result_of.hpp>
    }

    struct mem_fun_ptr_eval
        : proto::callable
    {
        template<typename Sig>
        struct result;
        
        template <typename This, typename Context, typename Expr>
        struct result<This(Context, Expr const &)>
            : result<This(Context const &, Expr const &)>
        {};

        template <typename This, typename Context, typename Expr>
        struct result<This(Context &, Expr const &)>
            : result_of::mem_fun_ptr_eval<Context, Expr>
        {};

        template <typename Context, typename Expr>
        typename result_of::mem_fun_ptr_eval<Context, Expr>::type
        operator()(Context & ctx, Expr const & expr) const
        {
            return
                this->evaluate(
                    ctx
                  , expr
                  , typename proto::arity_of<Expr>::type()
                );
        }

    #define PHOENIX_MEMBER_EVAL(Z, N, D)                                        \
        BOOST_PP_COMMA_IF(BOOST_PP_NOT(BOOST_PP_EQUAL(N, 2)))                   \
        eval(proto::child_c< N >(expr), ctx)                                    \
    /**/
        private:
    #define PHOENIX_ITERATION_PARAMS                                            \
        (4, (2, PHOENIX_LIMIT,                                                  \
        <boost/phoenix/operator/member.hpp>,                                    \
        PHOENIX_ITERATE_OPERATOR))                                              \
    /**/
        #include PHOENIX_ITERATE()
    #undef PHOENIX_MEMBER_EVAL
    };

    template <typename Dummy>
    struct default_actions::when<rule::mem_fun_ptr, Dummy>
        : proto::call<mem_fun_ptr_eval(_context, proto::_)>
    {};
}}

#include <boost/phoenix/operator/detail/undef_operator.hpp>

#if defined(__WAVE__) && defined(PHOENIX_CREATE_PREPROCESSED_FILES)
#pragma wave option(output: null)
#endif

#endif

#else // PHOENIX_IS_ITERATING
            
        template <typename Context, typename Expr>
        typename result_of::mem_fun_ptr_eval<Context, Expr>::type
        evaluate(
            Context & ctx
          , Expr const & expr
          , mpl::long_<PHOENIX_ITERATION>
        ) const
        {
            return
                (
                    get_pointer(eval(proto::child_c<0>(expr), ctx))
                    ->*eval(proto::child_c<1>(expr), ctx)
                )(
                    BOOST_PP_REPEAT_FROM_TO(
                        2
                      , PHOENIX_ITERATION
                      , PHOENIX_MEMBER_EVAL
                      , PHOENIX_ITERATION
                    )
                );
        }
        

#endif

#endif // PHOENIX_DONT_USE_PREPROCESSED_FILES
