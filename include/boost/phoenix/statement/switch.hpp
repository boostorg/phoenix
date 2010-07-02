/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_STATEMENT_SWITCH_HPP
#define PHOENIX_STATEMENT_SWITCH_HPP

#include <boost/fusion/sequence/intrinsic/at.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/domain.hpp>

#include <boost/proto/extends.hpp>
#include <boost/proto/make_expr.hpp>

namespace boost { namespace phoenix
{
    struct switch_case_tag {};

    template <typename Expr>
    struct switch_actor;

    struct switch_domain
        : proto::domain<
          proto::pod_generator<switch_actor>,
          proto::_, proto::default_domain>
    {
        template <typename T>
        struct as_child : as_expr<T>
        {};
    };

    struct test
    {
        typedef void result_type;

        test() { std::cout << "hmmmm\n";}

        template <typename A0, typename A1>
        result_type
        operator()( A0 const& a0, A1 const& a1) const
        {
            std::cout << "ok ..\n";
        }
    };

    struct switch_grammar
        : proto::or_<
            proto::when<
                proto::comma<switch_grammar, switch_grammar>
              , proto::_default<switch_grammar>
            >
          /* proto::when<
                proto::binary_expr<
                    switch_case_tag
                  , proto::_
                  , proto::_
                >
              //, proto::_child1(proto::_child0)
              //, proto::_default<switch_grammar>
              , proto::_child1()
            >
          ,*/
          , proto::when<
                proto::binary_expr<switch_case_tag, proto::_, eval_grammar>
              , proto::_default<eval_grammar>
            >
        >
    {};

    switch_grammar const switch_eval = switch_grammar();

    template <typename Expr>
    struct switch_actor
    {
        BOOST_PROTO_BASIC_EXTENDS(Expr, switch_actor<Expr>, switch_domain)
        BOOST_PROTO_EXTENDS_ASSIGN()
        BOOST_PROTO_EXTENDS_SUBSCRIPT()

        typedef void result_type;

        result_type
        operator()() const
        {
            switch_eval(*this);
            std::cout << "blubb0\n";
            std::cout << typeid(Expr).name() << "\n";
        }

        template <typename A0>
        result_type
        operator()(A0 const& a0) const
        {
            std::cout << "blubb1\n";
            switch_eval(*this);
        }

        template <typename A0, typename A1>
        result_type
        operator()(A0 const& a0, A1 const& a1) const
        {
            std::cout << "blubb2\n";
            switch_eval(*this);
        }

        template <typename A0, typename A1, typename A2>
        result_type
        operator()(A0 const& a0, A1 const& a1, A1 const& a2) const
        {
            std::cout << "blubb3\n";
            switch_eval(*this);
        }
    };
    
    template <int N, typename A0>
    switch_actor<
        typename proto::result_of::make_expr<
            switch_case_tag
          , default_domain_with_basic_expr
          , int
          , A0
        >::type
    >const
    case_(A0 const& a0)
    {
        typedef typename
            proto::result_of::make_expr<
                switch_case_tag
              , default_domain_with_basic_expr
              , int
              , A0
            >::type
            expr_type;

        switch_actor<expr_type> const e = {{N, a0}};
        return e;
    }

/*
    template <typename Cond>
    switch_gen<Cond>
    switch_(Cond const& cond)
    {
        return switch_gen<Cond>(cond);
    };

    template <int N, typename A0>
    switch_case<A0, int
    */

}}

#endif
