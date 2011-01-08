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

#define PHOENIX_UNPACK_CHOICES                                                  \
    (phoenix::unpack)                                                           \
    (phoenix::unpack())                                                         \
    (phoenix::unpack(Seq))                                                      \
    (phoenix::unpack(Seq, Fun))                                                 \
/**/

#define BOOST_PP_ITERATION_PARAMS_1                                             \
            (3, (1, BOOST_PP_SEQ_SIZE(PHOENIX_UNPACK_CHOICES),                  \
            <boost/phoenix/core/unpack.hpp>))                                   \
/**/
#include BOOST_PP_ITERATE()

#undef PHOENIX_UNPACK_CHOICES

#endif

#else

#if BOOST_PP_ITERATION_DEPTH() == 1

#define PHOENIX_UNPACK_I                                                        \
    BOOST_PP_DEC(BOOST_PP_FRAME_ITERATION(1))                                   \
/**/

#define PHOENIX_UNPACK                                                          \
    BOOST_PP_SEQ_ELEM(PHOENIX_UNPACK_I, PHOENIX_UNPACK_CHOICES)                 \
/**/

#define BOOST_PP_ITERATION_PARAMS_2                                             \
    (3, (1, BOOST_PROTO_MAX_ARITY,                                              \
    <boost/phoenix/core/unpack.hpp>))                                           \
/**/
#include BOOST_PP_ITERATE()

#undef PHOENIX_UNPACK
#undef PHOENIX_UNPACK_I

#elif BOOST_PP_ITERATION_DEPTH() == 2

#define PHOENIX_UNPACK_J                                                        \
    BOOST_PP_FRAME_ITERATION(2)                                                 \
/**/

#define BOOST_PP_ITERATION_PARAMS_3                                             \
    (3, (BOOST_PP_DEC(PHOENIX_UNPACK_J), BOOST_PP_DEC(BOOST_PROTO_MAX_ARITY),   \
    <boost/phoenix/core/unpack.hpp>))                                           \
/**/
#include BOOST_PP_ITERATE()

#undef PHOENIX_UNPACK_J

#elif BOOST_PP_ITERATION_DEPTH() == 3

#define PHOENIX_UNPACK_K                                                        \
    BOOST_PP_FRAME_ITERATION(3)                                                 \
/**/

#define PHOENIX_UNPACK_M0(Z, N, D)                                              \
    , A ## N                                                                    \
/**/

#define PHOENIX_UNPACK_SIG                                                      \
    R(                                                                          \
        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_UNPACK_J), A)                 \
        BOOST_PP_COMMA_IF(BOOST_PP_DEC(PHOENIX_UNPACK_J))                       \
        PHOENIX_UNPACK                                                          \
        BOOST_PP_REPEAT_FROM_TO(                                                \
            BOOST_PP_FRAME_START(3)                                             \
          , PHOENIX_UNPACK_K                                                    \
          , PHOENIX_UNPACK_M0                                                   \
          , _                                                                   \
        )                                                                       \
    )                                                                           \
/**/

#define PHOENIX_UNPACK_M1(Z, N, D)                                              \
    BOOST_PP_COMMA_IF(BOOST_PP_NOT_EQUAL(N, D)) BOOST_PP_CAT(A, N)              \
/**/

#define PHOENIX_UNPACK_M2(Z, N, D)                                              \
    , typename A ## N                                                           \
/**/

#define PHOENIX_UNPACK_TYPENAME_SIG                                             \
    BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_UNPACK_J), typename A)            \
    BOOST_PP_REPEAT_FROM_TO(                                                    \
        BOOST_PP_FRAME_START(3)                                                 \
      , PHOENIX_UNPACK_K                                                        \
      , PHOENIX_UNPACK_M2                                                       \
      , _                                                                       \
    )                                                                           \
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
          BOOST_PP_COMMA_IF(BOOST_PP_DEC(PHOENIX_UNPACK_J))
          PHOENIX_UNPACK_TYPENAME_SIG
        >
        struct unpack_impl<
            Expr
          , State
          , Data
          , Seq
          , Fun
          , PHOENIX_UNPACK_SIG
          , 0
        >
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};

            typedef
                proto::call<
                    R(
                        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_UNPACK_J), A)
                        BOOST_PP_COMMA_IF(
                            BOOST_PP_AND(
                                BOOST_PP_DEC(PHOENIX_UNPACK_J)
                              , BOOST_PP_NOT_EQUAL(
                                    BOOST_PP_FRAME_START(3)
                                  , PHOENIX_UNPACK_K
                                )
                            )
                        )
                        BOOST_PP_REPEAT_FROM_TO(
                            BOOST_PP_FRAME_START(3)
                          , PHOENIX_UNPACK_K
                          , PHOENIX_UNPACK_M1
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
      #if PHOENIX_UNPACK_I > 1
      , typename Seq
      #endif
      #if PHOENIX_UNPACK_I > 2
      , typename Fun
      #endif
      BOOST_PP_COMMA_IF(BOOST_PP_DEC(PHOENIX_UNPACK_J))
      PHOENIX_UNPACK_TYPENAME_SIG
      >
    struct call<PHOENIX_UNPACK_SIG>
        : proto::transform<call<PHOENIX_UNPACK_SIG> >
    {
        template <typename Expr, typename State, typename Data>
        struct impl
            : phoenix::detail::unpack_impl<
                Expr
              , State
              , Data
              #if PHOENIX_UNPACK_I > 1
              , Seq
              #else
              , proto::_
              #endif
              #if PHOENIX_UNPACK_I > 2
              , Fun
              #else
              , proto::_
              #endif
              , PHOENIX_UNPACK_SIG
            >
        {};
    };

}}

#undef PHOENIX_UNPACK_K
#undef PHOENIX_UNPACK_SIG
#undef PHOENIX_UNPACK_TYPENAME_SIG
#undef PHOENIX_UNPACK_M0
#undef PHOENIX_UNPACK_M1
#undef PHOENIX_UNPACK_M2

#else

#define PHOENIX_UNPACK_L BOOST_PP_FRAME_ITERATION(4)

#if PHOENIX_UNPACK_J + PHOENIX_UNPACK_K + PHOENIX_UNPACK_L - 2 > BOOST_PROTO_MAX_ARITY
//PHOENIX_UNPACK_SIG PHOENIX_UNPACK_J PHOENIX_UNPACK_K PHOENIX_UNPACK_L too much ...
#else
    #define PHOENIX_UNPACK_M5(__, N, ___)                                       \
        fun_type(proto::functional::at(Seq, mpl::int_<N>()))                    \
    /**/

        template <
            typename Expr
          , typename State
          , typename Data
          , typename Seq
          , typename Fun
          , typename R
          BOOST_PP_COMMA_IF(BOOST_PP_DEC(PHOENIX_UNPACK_J))
          PHOENIX_UNPACK_TYPENAME_SIG
        >
        struct unpack_impl<
            Expr
          , State
          , Data
          , Seq
          , Fun
          , PHOENIX_UNPACK_SIG
          , PHOENIX_UNPACK_L
        >
            : proto::transform_impl<Expr, State, Data>
        {
            struct fun_type : proto::when<proto::_, Fun> {};

            typedef
                proto::call<
                    R(
                        BOOST_PP_ENUM_PARAMS(BOOST_PP_DEC(PHOENIX_UNPACK_J), A)
                        BOOST_PP_COMMA_IF(
                            BOOST_PP_AND(BOOST_PP_DEC(PHOENIX_UNPACK_J)
                          , PHOENIX_UNPACK_L)
                        )
                        BOOST_PP_ENUM(PHOENIX_UNPACK_L, PHOENIX_UNPACK_M5, _)
                        BOOST_PP_COMMA_IF(
                            BOOST_PP_AND(
                                PHOENIX_UNPACK_L
                              , BOOST_PP_NOT_EQUAL(
                                    BOOST_PP_FRAME_START(3)
                                  , PHOENIX_UNPACK_K
                                )
                            )
                        )
                        BOOST_PP_REPEAT_FROM_TO(
                            BOOST_PP_FRAME_START(3)
                          , PHOENIX_UNPACK_K
                          , PHOENIX_UNPACK_M1
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

    #undef PHOENIX_UNPACK_M5
#endif

#undef PHOENIX_UNPACK_L

#endif

#endif

