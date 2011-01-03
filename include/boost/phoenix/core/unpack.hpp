#if !BOOST_PP_IS_ITERATING

/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef PHOENIX_CORE_UNPACK_HPP
#define PHOENIX_CORE_UNPACK_HPP

#include <boost/fusion/include/size.hpp>
#include <boost/preprocessor/comparison/not_equal.hpp>
#include <boost/preprocessor/iteration/iterate.hpp>
#include <boost/preprocessor/punctuation/comma_if.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/enum_trailing.hpp>
#include <boost/preprocessor/repetition/repeat_from_to.hpp>
#include <boost/preprocessor/seq/elem.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/proto/proto.hpp>
#include <boost/proto/functional.hpp>

#define UNPACK_CHOICES \
    (phoenix::unpack) \
    (phoenix::unpack()) \
    (phoenix::unpack(Seq)) \
    (phoenix::unpack(Seq, Fun))

namespace boost { namespace phoenix
{
    struct unpack {};
        
    namespace detail
    {
        template <
            typename Expr
          , typename State
          , typename Data
          , typename Seq
          , typename Fun
          , typename R
          , long Arity = fusion::result_of::size<
                typename proto::detail::uncvref<
                    typename proto::when<proto::_, Seq>::
                        template impl<Expr, State, Data>::result_type
                    >::type
            >::value
        >
        struct unpack_impl;
    }
}}

#define BOOST_PP_ITERATION_PARAMS_1                                             \
            (3, (1, BOOST_PP_SEQ_SIZE(UNPACK_CHOICES),                          \
            <boost/phoenix/core/unpack.hpp>))                                   \
/**/
#include BOOST_PP_ITERATE()

#undef M0
#undef M1
#undef M2
#undef M3
#undef M4
#undef M5
#undef I
#undef J
#undef K
#undef L
#undef UNPACK_CHOICES

#endif

#else

#if BOOST_PP_ITERATION_DEPTH() == 1

#define I                                                                       \
    BOOST_PP_DEC(BOOST_PP_FRAME_ITERATION(1))                                   \
/**/

#define UNPACK                                                                  \
    BOOST_PP_SEQ_ELEM(I, UNPACK_CHOICES)                                        \
/**/

#define BOOST_PP_ITERATION_PARAMS_2                                             \
    (3, (1, BOOST_PROTO_MAX_ARITY,                                              \
    <boost/phoenix/core/unpack.hpp>))                                           \
/**/
#include BOOST_PP_ITERATE()
#undef UNPACK

#elif BOOST_PP_ITERATION_DEPTH() == 2

#define J                                                                       \
    BOOST_PP_FRAME_ITERATION(2)                                                 \
/**/

#define BOOST_PP_ITERATION_PARAMS_3                                             \
    (3, (BOOST_PP_DEC(J), BOOST_PP_DEC(BOOST_PROTO_MAX_ARITY),                  \
    <boost/phoenix/core/unpack.hpp>))                                           \
/**/
#include BOOST_PP_ITERATE()

#elif BOOST_PP_ITERATION_DEPTH() == 3

#define K                                                                       \
    BOOST_PP_FRAME_ITERATION(3)                                                 \
/**/

#define M0(Z, N, D)                                                             \
    , A ## N                                                                    \
/**/

#define SIG                                                                     \
    R(                                                                          \
        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(J), A)                                \
        BOOST_PP_COMMA_IF(BOOST_PP_DEC(J))                                      \
        UNPACK                                                                  \
        BOOST_PP_REPEAT_FROM_TO(BOOST_PP_FRAME_START(3), K, M0, _)              \
    )                                                                           \
/**/

#define M1(Z, N, D)                                                             \
    BOOST_PP_COMMA_IF(BOOST_PP_NOT_EQUAL(N, D)) BOOST_PP_CAT(A, N)              \
/**/

#define M2(Z, N, D)                                                             \
    , typename A ## N                                                           \
/**/

#define TYPENAME_SIG                                                            \
    BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(J), typename A)                           \
    BOOST_PP_REPEAT_FROM_TO(BOOST_PP_FRAME_START(3), K, M2, _)                  \
/**/
    
namespace boost { namespace phoenix
{
    namespace detail
    {
        template <
            typename Expr
          , typename State
          , typename Data
          , typename Seq
          , typename Fun
          , typename R
          BOOST_PP_COMMA_IF(BOOST_PP_DEC(J)) TYPENAME_SIG
        >
        struct unpack_impl<
            Expr
          , State
          , Data
          , Seq
          , Fun
          , SIG
          , 0
        >
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};

            typedef
                proto::call<
                    R(
                        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(J), A)
                        BOOST_PP_COMMA_IF(
                            BOOST_PP_AND(
                                BOOST_PP_DEC(J)
                              , BOOST_PP_NOT_EQUAL(BOOST_PP_FRAME_START(3), K)
                            )
                        )
                        BOOST_PP_REPEAT_FROM_TO(
                            BOOST_PP_FRAME_START(3)
                          , K
                          , M1
                          , BOOST_PP_FRAME_START(3)
                        )
                    )
                >
                which;

            typedef
                typename which::template impl<Expr, State, Data>::result_type
                result_type;

            result_type
            operator()(
                typename unpack_impl::expr_param e
              , typename unpack_impl::state_param s
              , typename unpack_impl::data_param d
            ) const
            {
                return
                    typename which::
                        template impl<Expr, State, Data>()(e, s, d);
            }

        };

    #define BOOST_PP_ITERATION_PARAMS_4                                         \
        (3, (1, BOOST_PROTO_MAX_ARITY,                                          \
        <boost/phoenix/core/unpack.hpp>))

        #include BOOST_PP_ITERATE()
    }
}}

namespace boost { namespace proto {
    template <
        typename R
      #if I > 1
      , typename Seq
      #endif
      #if I > 2
      , typename Fun
      #endif
      BOOST_PP_COMMA_IF(BOOST_PP_DEC(J)) TYPENAME_SIG
      >
    struct call<SIG>
        : proto::transform<call<SIG> >
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : phoenix::detail::unpack_impl<
                Expr
              , State
              , Data
              #if I > 1
              , Seq
              #else
              , proto::_
              #endif
              #if I > 2
              , Fun
              #else
              , proto::_
              #endif
              , SIG
            >
        {};
    };

}}

#else

#define L BOOST_PP_FRAME_ITERATION(4)

//BOOST_PP_SUB(BOOST_PP_ADD(BOOST_PP_ADD(J, K), L), 2)
#if J + K + L - 2 > BOOST_PROTO_MAX_ARITY
//SIG J K L too much ...
#else
    #undef M5
    #define M5(__, N, ___)                                                      \
        fun_type(proto::functional::at(Seq, mpl::int_<N>()))                    \
    /**/

        template <
            typename Expr
          , typename State
          , typename Data
          , typename Seq
          , typename Fun
          , typename R
          BOOST_PP_COMMA_IF(BOOST_PP_DEC(J)) TYPENAME_SIG
        >
        struct unpack_impl<
            Expr
          , State
          , Data
          , Seq
          , Fun
          , SIG
          , L
        >
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};

            typedef
                proto::call<
                    R(
                        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(J), A)
                        BOOST_PP_COMMA_IF(BOOST_PP_AND(BOOST_PP_DEC(J), L))
                        BOOST_PP_ENUM(L, M5, _)
                        BOOST_PP_COMMA_IF(
                            BOOST_PP_AND(
                                L
                              , BOOST_PP_NOT_EQUAL(BOOST_PP_FRAME_START(3), K)
                            )
                        )
                        BOOST_PP_REPEAT_FROM_TO(
                            BOOST_PP_FRAME_START(3)
                          , K
                          , M1
                          , BOOST_PP_FRAME_START(3)
                        )
                    )
                >
                which;

            typedef
                typename which::template impl<Expr, State, Data>::result_type
                result_type;

            result_type
            operator()(
                typename unpack_impl::expr_param e
              , typename unpack_impl::state_param s
              , typename unpack_impl::data_param d
            ) const
            {
                return
                    typename which::
                        template impl<Expr, State, Data>()(e, s, d);
            }

        };

#endif

#endif

#endif

