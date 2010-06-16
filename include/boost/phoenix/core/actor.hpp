/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_CORE_ACTOR_HPP
#define PHOENIX_CORE_ACTOR_HPP

#include <boost/fusion/container/vector/vector10.hpp>
#include <boost/mpl/identity.hpp>
#include <boost/mpl/eval_if.hpp>
#include <boost/phoenix/core/arity.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/environment.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/comparison/less.hpp>
#include <boost/preprocessor/control/if.hpp>
#include <boost/preprocessor/facilities/expand.hpp>
#include <boost/preprocessor/facilities/intercept.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/fold_right.hpp>
#include <boost/preprocessor/seq/for_each_i.hpp>
#include <boost/preprocessor/seq/for_each_product.hpp>
#include <boost/preprocessor/tuple/rem.hpp>
#include <boost/proto/extends.hpp>
#include <boost/proto/debug.hpp>
#include <boost/utility/result_of.hpp>

#include <boost/mpl/void.hpp>
namespace boost { namespace phoenix
{
    template <typename Expr>
    struct actor;

    namespace detail
    {
        struct error_expecting_arguments
        {
            template <typename T>
            error_expecting_arguments(T const&) {}
        };
    }

    namespace result_of
    {
        template <typename Expr
            , PHOENIX_typename_A_void(PHOENIX_ACTOR_LIMIT)
            , typename Dummy = void>
        struct actor;

        template <typename Expr>
        struct actor<Expr>
        {
            static const int arity = result_of::arity<Expr>::type::value;

            typedef typename
                mpl::eval_if_c<
                    arity == 0 // avoid calling result_of::actor when this is true
                  , boost::result_of<eval_grammar(Expr const&, 
                        typename make_basic_environment<>::type&)>
                  , mpl::identity<detail::error_expecting_arguments>
                >::type
            type;
        };

#define PHOENIX_ITERATE_RESULT_OF 1
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_ACTOR_LIMIT,                                            \
        <boost/phoenix/core/actor.hpp>,                                         \
        PHOENIX_ITERATE_RESULT_OF))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_RESULT_OF

    }

    ////////////////////////////////////////////////////////////////////////////
    //
    //  actor
    //
    //      The actor class. The main thing! In phoenix, everything is an actor
    //      This class is responsible for full function evaluation. Partial
    //      function evaluation involves creating a hierarchy of actor objects.
    //
    ////////////////////////////////////////////////////////////////////////////
    template <typename Expr>
    struct actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, actor<Expr>, phoenix_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

        template <typename Sig>
        struct result;

        template <typename This>
        struct result<This()>
            : result_of::actor<Expr>
        {};

        typename result_of::actor<Expr>::type
        operator()() const
        {
            BOOST_PROTO_ASSERT_MATCHES( *this, eval_grammar );
            typename make_basic_environment<>::type args;

            return eval(this->proto_base(), args);
        }

#define PHOENIX_ITERATE_OPERATOR 2
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_ACTOR_LIMIT,                                            \
        <boost/phoenix/core/actor.hpp>,                                         \
        PHOENIX_ITERATE_OPERATOR))

#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_OPERATOR

    };
}

    // specialize boost::result_of to return the proper result type
    template<typename Expr>
    struct result_of<phoenix::actor<Expr>() >
      : phoenix::result_of::actor<Expr>
    {};

}

#endif

#else

#define PHOENIX_ENV( A ) typename make_basic_environment<A>::type

#if BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_RESULT_OF
        
        template <typename Expr, PHOENIX_typename_A>
        struct actor<Expr, BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, A)>
            : boost::result_of<eval_grammar(
                ::boost::phoenix::actor<Expr> const &,
                    PHOENIX_ENV(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, A))&)>
        {};

#elif BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_OPERATOR

        template <typename This, PHOENIX_typename_A>
        struct result<This(BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, A))>
            : result_of::actor<Expr, BOOST_PP_ENUM_PARAMS(PHOENIX_ITERATION, A)>
        {};

#if PHOENIX_ITERATION >= PHOENIX_PERFECT_FORWARD_LIMIT

        template <PHOENIX_typename_A>
        typename result_of::actor<Expr, PHOENIX_A_ref>::type
        operator()(PHOENIX_A_ref_a) const
        {
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);
            PHOENIX_ENV(PHOENIX_A_ref) args( PHOENIX_a);

            return eval(*this, args);
        }

        template <PHOENIX_typename_A>
        typename result_of::actor<Expr, PHOENIX_A_const_ref>::type
        operator()(PHOENIX_A_const_ref_a) const
        {
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);
            PHOENIX_ENV(PHOENIX_A_const_ref) args( PHOENIX_a);

            return eval(*this, args);
        }

#else

// We need to define operator() for all permutations of reference types.
// For PHOENIX_ITERATION <= PHOENIX_LIMIT_PREFECT_FORWARD
// 2^PHOENIX_ITERATION overloads are created
// For compile time reasons,
// if PHOENIX_ITERATION > PHOENIX_LIMIT_PERFECT_FORWARD
// only operator()(A const &...a) and operator()(A &...a) are generated
// this is all handled by the PP mumbo jumbo above
#define PHOENIX_ACTOR_OPERATOR(_, I, __)                                       \
        template <PHOENIX_typename_A>                                          \
        typename result_of::actor<Expr, PHOENIX_PERM_A(I)>::type               \
        operator()(PHOENIX_PERM_A_a(I)) const                                  \
        {                                                                      \
            BOOST_PROTO_ASSERT_MATCHES(*this, eval_grammar);                   \
            PHOENIX_ENV(PHOENIX_PERM_A(I)) args(PHOENIX_a);                    \
                                                                               \
            return eval(*this, args);                                          \
        }

        BOOST_PP_REPEAT( PHOENIX_PERM_SIZE, PHOENIX_ACTOR_OPERATOR, _)

#undef PHOENIX_ACTOR_OPERATOR

#endif

#endif

#undef PHOENIX_ENV

#endif

