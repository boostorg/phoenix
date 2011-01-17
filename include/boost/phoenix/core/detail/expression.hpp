/*=============================================================================
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef PHOENIX_CORE_DETAIL_EXPRESSION_HPP
#define PHOENIX_CORE_DETAIL_EXPRESSION_HPP

#include <boost/preprocessor/empty.hpp>
#include <boost/preprocessor/arithmetic/add.hpp>
#include <boost/preprocessor/arithmetic/dec.hpp>
#include <boost/preprocessor/comma_if.hpp>
#include <boost/preprocessor/comparison/equal.hpp>
#include <boost/preprocessor/seq/size.hpp>
#include <boost/preprocessor/seq/enum.hpp>
#include <boost/preprocessor/seq/pop_back.hpp>
#include <boost/preprocessor/tuple/elem.hpp>
#include <boost/preprocessor/enum_params.hpp>
#include <boost/preprocessor/repeat_from_to.hpp>

#define PHOENIX_DEFINE_EXPRESSION(NAME, SEQ)                                    \
    namespace tag {                                                             \
        struct NAME {};                                                         \
    }                                                                           \
                                                                                \
    namespace expression                                                        \
    {                                                                           \
        template <BOOST_PP_ENUM_PARAMS(BOOST_PP_SEQ_SIZE(SEQ), typename A)>     \
        struct NAME                                                             \
            : expr<tag:: NAME, BOOST_PP_ENUM_PARAMS(BOOST_PP_SEQ_SIZE(SEQ), A)> \
        {};                                                                     \
    }                                                                           \
                                                                                \
    namespace rule {                                                            \
        struct NAME                                                             \
            : expression:: NAME <BOOST_PP_SEQ_ENUM(SEQ)>                        \
        {};                                                                     \
    }                                                                           \
                                                                                \
    template <typename Dummy>                                                   \
    struct meta_grammar::case_<tag:: NAME, Dummy>                               \
        : proto::when<rule:: NAME, proto::external_transform>                   \
    {};                                                                         \
    /**/

#define PHOENIX_DEFINE_EXPRESSION_VARARG_R(_, N, NAME)                          \
    template <                                                                  \
        PHOENIX_typename_A(                                                     \
            BOOST_PP_ADD(                                                       \
                N                                                               \
              , BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(2, 1, NAME))              \
            )                                                                   \
        )                                                                       \
    >                                                                           \
    struct BOOST_PP_TUPLE_ELEM(2, 0, NAME)<                                     \
        PHOENIX_A(                                                              \
            BOOST_PP_ADD(N, BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(2, 1, NAME))) \
        )                                                                       \
    >                                                                           \
        : expr<                                                                 \
            tag:: BOOST_PP_TUPLE_ELEM(2, 0, NAME)                               \
          , PHOENIX_A(                                                          \
                BOOST_PP_ADD(                                                   \
                    N                                                           \
                  , BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(2, 1, NAME))          \
                )                                                               \
            )                                                                   \
        >                                                                       \
    {};                                                                         \
/**/

#define PHOENIX_DEFINE_EXPRESSION_VARARG(NAME, GRAMMAR, LIMIT)                  \
    namespace tag {                                                             \
        struct NAME {};                                                         \
    }                                                                           \
                                                                                \
    namespace expression                                                        \
    {                                                                           \
        template <                                                              \
            PHOENIX_typename_A_void(                                            \
                BOOST_PP_ADD(LIMIT, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR)))   \
            )                                                                   \
          , typename Dummy = void                                               \
        >                                                                       \
        struct NAME;                                                            \
                                                                                \
        BOOST_PP_REPEAT_FROM_TO(                                                \
            1                                                                   \
          , BOOST_PP_ADD(LIMIT, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR)))       \
          , PHOENIX_DEFINE_EXPRESSION_VARARG_R                                  \
          , (NAME, BOOST_PP_SEQ_POP_BACK(GRAMMAR))                              \
        )                                                                       \
    }                                                                           \
                                                                                \
    namespace rule {                                                            \
        struct NAME                                                             \
            : expression:: NAME <                                               \
                BOOST_PP_IF(                                                    \
                    BOOST_PP_EQUAL(1, BOOST_PP_SEQ_SIZE(GRAMMAR))               \
                  , BOOST_PP_EMPTY()                                            \
                  , BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_BACK(GRAMMAR))           \
                )                                                               \
                BOOST_PP_COMMA_IF(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR)))     \
                proto::vararg<                                                  \
                    BOOST_PP_SEQ_ELEM(                                          \
                        BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR))                \
                      , GRAMMAR                                                 \
                    )                                                           \
                >                                                               \
            >                                                                   \
        {};                                                                     \
    }                                                                           \
                                                                                \
    template <typename Dummy>                                                   \
    struct meta_grammar::case_<tag:: NAME, Dummy>                               \
        : proto::when<rule:: NAME, proto::external_transform>                   \
    {};                                                                         \
/**/

#define PHOENIX_DEFINE_EXPRESSION_EXT(ACTOR, NAME, SEQ)                         \
    namespace tag {                                                             \
        struct NAME {};                                                         \
    }                                                                           \
                                                                                \
    namespace expression                                                        \
    {                                                                           \
        template <BOOST_PP_ENUM_PARAMS(BOOST_PP_SEQ_SIZE(SEQ), typename A)>     \
        struct NAME                                                             \
            : expr_ext<                                                         \
                ACTOR                                                           \
              , tag:: NAME, BOOST_PP_ENUM_PARAMS(BOOST_PP_SEQ_SIZE(SEQ), A)>    \
        {};                                                                     \
    }                                                                           \
                                                                                \
    namespace rule {                                                            \
        struct NAME                                                             \
            : expression:: NAME <BOOST_PP_SEQ_ENUM(SEQ)>                        \
        {};                                                                     \
    }                                                                           \
                                                                                \
    template <typename Dummy>                                                   \
    struct meta_grammar::case_<tag:: NAME, Dummy>                               \
        : proto::when<rule:: NAME, proto::external_transform>                   \
    {};                                                                         \
/**/

#define PHOENIX_DEFINE_EXPRESSION_EXT_VARARG_R(_, N, NAME)                      \
    template <                                                                  \
        PHOENIX_typename_A(                                                     \
            BOOST_PP_ADD(                                                       \
                N                                                               \
              , BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(3, 1, NAME))              \
            )                                                                   \
        )                                                                       \
    >                                                                           \
    struct BOOST_PP_TUPLE_ELEM(3, 0, NAME)<                                     \
        PHOENIX_A(                                                              \
            BOOST_PP_ADD(N, BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(3, 1, NAME))) \
        )                                                                       \
    >                                                                           \
        : expr_ext<                                                             \
            BOOST_PP_TUPLE_ELEM(3, 2, NAME)                                     \
          , tag:: BOOST_PP_TUPLE_ELEM(3, 0, NAME)                               \
          , PHOENIX_A(                                                          \
                BOOST_PP_ADD(                                                   \
                    N                                                           \
                  , BOOST_PP_SEQ_SIZE(BOOST_PP_TUPLE_ELEM(3, 1, NAME))          \
                )                                                               \
            )                                                                   \
        >                                                                       \
    {};                                                                         \

#define PHOENIX_DEFINE_EXPRESSION_EXT_VARARG(ACTOR, NAME, GRAMMAR, LIMIT)       \
    namespace tag {                                                             \
        struct NAME {};                                                         \
    }                                                                           \
                                                                                \
    namespace expression                                                        \
    {                                                                           \
        template <                                                              \
            PHOENIX_typename_A_void(                                            \
                BOOST_PP_ADD(LIMIT, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR)))   \
            )                                                                   \
          , typename Dummy = void                                               \
        >                                                                       \
        struct NAME;                                                            \
                                                                                \
        BOOST_PP_REPEAT_FROM_TO(                                                \
            1                                                                   \
          , BOOST_PP_ADD(LIMIT, BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR)))       \
          , PHOENIX_DEFINE_EXPRESSION_EXT_VARARG_R                              \
          , (NAME, BOOST_PP_SEQ_POP_BACK(GRAMMAR), ACTOR)                       \
        )                                                                       \
    }                                                                           \
                                                                                \
    namespace rule {                                                            \
        struct NAME                                                             \
            : expression:: NAME <                                               \
                BOOST_PP_IF(                                                    \
                    BOOST_PP_EQUAL(1, BOOST_PP_SEQ_SIZE(GRAMMAR))               \
                  , BOOST_PP_EMPTY()                                            \
                  , BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_BACK(GRAMMAR))           \
                )                                                               \
                BOOST_PP_COMMA_IF(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR)))     \
                proto::vararg<                                                  \
                    BOOST_PP_SEQ_ELEM(                                          \
                        BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(GRAMMAR))                \
                      , GRAMMAR                                                 \
                    )                                                           \
                >                                                               \
            >                                                                   \
        {};                                                                     \
    }                                                                           \
                                                                                \
    template <typename Dummy>                                                   \
    struct meta_grammar::case_<tag:: NAME, Dummy>                               \
        : proto::when<rule:: NAME, proto::external_transform>                   \
    {};                                                                         \
/**/

#endif
