/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OPERATOR_HPP
#define PHOENIX_OPERATOR_HPP

#define PHOENIX_UNARY_RULE(_, __, name)                                         \
        template <typename Grammar>                                             \
        struct name                                                             \
            : proto::unary_expr<proto::tag::name, Grammar>                      \
        {};                                                                     \
    /**/

#define PHOENIX_BINARY_RULE(_, __, name)                                        \
        template <typename Grammar>                                             \
        struct name                                                             \
            : proto::binary_expr<proto::tag::name, Grammar, Grammar>            \
        {};                                                                     \
    /**/

#define PHOENIX_GRAMMAR(_, __, name)                                            \
    template <typename Grammar>                                                 \
    struct meta_grammar::case_<proto::tag::name, Grammar>                       \
        : proto::when<rule::name<Grammar>, proto::external_transform>           \
    {};                                                                         \
    /**/

#define PHOENIX_UNARY_OPERATORS(ops)                                            \
    namespace rule {                                                            \
        BOOST_PP_SEQ_FOR_EACH(PHOENIX_UNARY_RULE, _, ops)                       \
    }                                                                           \
    BOOST_PP_SEQ_FOR_EACH(PHOENIX_GRAMMAR, _, ops)                              \
    /**/

#define PHOENIX_BINARY_OPERATORS(ops)                                           \
    namespace rule {                                                            \
        BOOST_PP_SEQ_FOR_EACH(PHOENIX_BINARY_RULE, _, ops)                      \
    }                                                                           \
    BOOST_PP_SEQ_FOR_EACH(PHOENIX_GRAMMAR, _, ops)                              \
    /**/

#include <boost/phoenix/version.hpp>
#include <boost/phoenix/operator/arithmetic.hpp>
#include <boost/phoenix/operator/bitwise.hpp>
#include <boost/phoenix/operator/comparision.hpp>
#include <boost/phoenix/operator/if_else.hpp>
#include <boost/phoenix/operator/self.hpp>
#include <boost/phoenix/operator/logical.hpp>
#include <boost/phoenix/operator/io.hpp>
#include <boost/phoenix/operator/member.hpp>

#undef PHOENIX_UNARY_RULE
#undef PHOENIX_BINARY_RULE
#undef PHOENIX_GRAMMAR
#undef PHOENIX_UNARY_OPERATORS
#undef PHOENIX_BINARY_OPERATORS

#endif
