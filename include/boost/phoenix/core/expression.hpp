
#if !PHOENIX_IS_ITERATING

/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_EXPRESSION_HPP
#define PHOENIX_CORE_EXPRESSION_HPP

#include <boost/phoenix/support/iterate.hpp>
#include <boost/preprocessor/comparison/equal.hpp>

namespace boost { namespace phoenix
{
    template <typename Expr> struct actor;
    
    template <
        template <typename> class Actor
      , typename Tag
      , PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)
      , typename Dummy = void>
    struct expr_ext;

	template <
        typename Tag
      , PHOENIX_typename_A_void(PHOENIX_COMPOSITE_LIMIT)
      , typename Dummy = void
    >
	struct expr : expr_ext<actor, Tag, PHOENIX_A(PHOENIX_COMPOSITE_LIMIT)> {};

    struct default_domain_with_basic_expr
        : proto::domain<proto::use_basic_expr<proto::default_generator> >
    {};

#define PHOENIX_ITERATION_PARAMS                                                \
    (3, (1, PHOENIX_COMPOSITE_LIMIT,                                            \
    <boost/phoenix/core/expression.hpp>))                                       \
/**/
    #include PHOENIX_ITERATE()

}}

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

#else
    template <template <typename> class Actor, typename Tag, PHOENIX_typename_A>
    struct expr_ext<Actor, Tag, PHOENIX_A>
        : proto::transform<expr_ext<Actor, Tag, PHOENIX_A>, int>
    {
        typedef
            typename proto::result_of::make_expr<
                Tag
              , default_domain_with_basic_expr
              , PHOENIX_A
            >::type
            base_type;

        typedef Actor<base_type> type;

        typedef
            typename proto::nary_expr<Tag, PHOENIX_A>::proto_grammar
            proto_grammar;
        
        static type make(PHOENIX_A_a)
        {
            actor<base_type> const e =
                {
                    proto::make_expr<
                        Tag
                      , default_domain_with_basic_expr
                    >(PHOENIX_a)
                };
            return e;
        }

        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::detail::pass_through_impl<expr_ext, Expr, State, Data>
        {};
        
        typedef Tag proto_tag;
    #define BOOST_PHOENIX_ENUM_CHILDREN(_, N, __)                               \
        typedef BOOST_PP_CAT(A, N) BOOST_PP_CAT(proto_child, N);                \
    /**/
        BOOST_PP_REPEAT(PHOENIX_ITERATION, BOOST_PHOENIX_ENUM_CHILDREN, _)
    #undef BOOST_PHOENIX_ENUM_CHILDREN
    };

#endif
