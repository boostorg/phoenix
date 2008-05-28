#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_SWITCH_HPP_EAN_2008_05_10
    #define BOOST_PHOENIX_SWITCH_HPP_EAN_2008_05_10

    #include <boost/preprocessor.hpp>
    #include <boost/proto/proto.hpp>
    #include <boost/phoenix/core/actor.hpp>

    #ifdef _MSC_VER
    # pragma warning(push)
    # pragma warning(disable: 4065) // switch statement contains 'default' but no 'case' labels
    #endif

    namespace boost { namespace phoenix
    {
        ////////////////////////////////////////////////////////////////////////////////////////////
        namespace tag
        {
            struct switch_ {};
            struct default_ {};
            template<int Label>
            struct case_ { BOOST_STATIC_CONSTANT(int, label = Label); };
        }

        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Cond>
            struct switch_generator
            {
                explicit switch_generator(Cond const &c)
                  : cond(c)
                {}

                template<typename Body>
                typename proto::result_of::make_expr<
                    tag::switch_
                  , domain
                  , Cond const &
                  , Body const &
                >::type const
                operator[](Body const &body) const
                {
                    return proto::implicit_expr(this->cond, body);
                }

            private:
                switch_generator &operator =(switch_generator const &);
                Cond const &cond;
            };

            // Define the grammar for valid switch statements
            template<typename SubGrammar>
            struct CaseCases;

            template<typename SubGrammar>
            struct Case
              : proto::switch_<CaseCases<SubGrammar> >
            {};

            template<typename SubGrammar>
            struct CaseCases
            {
                template<typename Tag>
                struct case_
                  : proto::not_<proto::_>
                {};

                template<int Label>
                struct case_<tag::case_<Label> >
                  : proto::unary_expr<proto::_, evaluator<SubGrammar> >
                {};
            };

            template<typename SubGrammar>
            struct Default
              : proto::unary_expr<tag::default_, evaluator<SubGrammar> >
            {};

            template<typename SubGrammar>
            struct CasesNoDefault
              : proto::or_<
                    Case<SubGrammar>
                  , proto::comma<CasesNoDefault<SubGrammar>, Case<SubGrammar> >
                >
            {};

            template<typename SubGrammar>
            struct CasesWithDefault
              : proto::or_<
                    Default<SubGrammar>
                  , proto::comma<CasesNoDefault<SubGrammar>, Default<SubGrammar> >
                >
            {};

            template<typename SubGrammar>
            struct Switch
              : proto::binary_expr<
                    tag::switch_
                  , evaluator<SubGrammar>
                  , proto::or_<CasesNoDefault<SubGrammar>, CasesWithDefault<SubGrammar> >
                >
            {};

            #define BOOST_PP_ITERATION_PARAMS_1 (3, (0, PHOENIX_LIMIT, <boost/phoenix/statement/switch.hpp>))
            #include BOOST_PP_ITERATE()

            ////////////////////////////////////////////////////////////////////////////////////////
            // Proto transform that evaluates switch(condition)[ case_<0>(expr), case_<1>(expr), ... ]
            template<typename SubGrammar, typename X = proto::callable>
            struct switch_evaluator
              : proto::transform<switch_evaluator<SubGrammar> >
            {
                template<typename Expr, typename State, typename Data>
                struct impl
                  : proto::transform_impl<Expr, State, Data>
                {
                    typedef void result_type;

                    void operator()(
                        typename impl::expr_param expr
                      , typename impl::state_param state
                      , typename impl::data_param data
                    ) const
                    {
                        detail::do_switch<SubGrammar>(
                            expr.proto_base().child0, state, data
                          , expr.proto_base().child1.proto_base()
                        );
                    }
                };
            };
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Expr>
        detail::switch_generator<Expr> const
        switch_(Expr const &expr)
        {
            return detail::switch_generator<Expr>(expr);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<int Label, typename Expr>
        typename proto::result_of::make_expr<
            tag::case_<Label>
          , detail::domain
          , Expr const &
        >::type const
        case_(Expr const &expr)
        {
            return proto::implicit_expr(expr);
        }

        template<typename Expr>
        typename proto::result_of::make_expr<
            tag::default_
          , detail::domain
          , Expr const &
        >::type const
        default_(Expr const &expr)
        {
            return proto::implicit_expr(expr);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename SubGrammar>
        struct extension<tag::switch_, SubGrammar>
          : proto::when<
                detail::Switch<SubGrammar>
              , detail::switch_evaluator<SubGrammar>
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        // case_<N>(x) expressions are not valid lambdas outside of a switch_
        template<int Label, typename SubGrammar>
        struct extension<tag::case_<Label>, SubGrammar>
          : proto::not_<proto::_>
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        // default_(x) expressions are not valid lambdas outside of a switch_
        template<typename SubGrammar>
        struct extension<tag::default_, SubGrammar>
          : proto::not_<proto::_>
        {};

    }}

    #ifdef _MSC_VER
    # pragma warning(pop)
    #endif

    #endif

#else

    #define N BOOST_PP_SUB(PHOENIX_LIMIT, BOOST_PP_ITERATION())

        #define M0(Z, N, DATA)                                                                      \
            proto::expr<tag::case_<BOOST_PP_CAT(L, N)>, BOOST_PP_CAT(A, N), 1> const &BOOST_PP_CAT(a, N)\
            /**/

        #define M1(Z, N, DATA)                                                                      \
            case BOOST_PP_CAT(L, N):                                                                \
                evaluator<SubGrammar>()(BOOST_PP_CAT(a, N).child0, state, data);                    \
                break;                                                                              \
            /**/

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            typename SubGrammar
          , typename Expr, typename State, typename Data
          , typename Args
            BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
        >
        void do_switch(
            Expr &expr, State &state, Data &data
          , proto::expr<proto::tag::comma, Args, 2> const &cases
            BOOST_PP_ENUM_TRAILING_BINARY_PARAMS(N, A, const &a)
        )
        {
            // Fan out the arguments
            detail::do_switch<SubGrammar>(
                expr, state, data
              , cases.child0.proto_base()
              , cases.child1.proto_base()
                BOOST_PP_ENUM_TRAILING_PARAMS(N, a)
            );
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            typename SubGrammar
          , typename Expr, typename State, typename Data
            BOOST_PP_ENUM_TRAILING_PARAMS(N, int L)
            BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
          , int BOOST_PP_CAT(L, N), typename BOOST_PP_CAT(A, N)
        >
        void do_switch(
            Expr &expr, State &state, Data &data
            BOOST_PP_ENUM_TRAILING(N, M0, ~)
          , proto::expr<tag::case_<BOOST_PP_CAT(L, N)>, BOOST_PP_CAT(A, N), 1> const &BOOST_PP_CAT(a, N)
        )
        {
            switch(evaluator<SubGrammar>()(expr, state, data))
            {
                BOOST_PP_REPEAT(BOOST_PP_INC(N), M1, ~)
                default:;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            typename SubGrammar
          , typename Expr, typename State, typename Data
            BOOST_PP_ENUM_TRAILING_PARAMS(N, int L)
            BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
          , typename BOOST_PP_CAT(A, N)
        >
        void do_switch(
            Expr &expr, State &state, Data &data
            BOOST_PP_ENUM_TRAILING(N, M0, ~)
          , proto::expr<tag::default_, BOOST_PP_CAT(A, N), 1> const &BOOST_PP_CAT(a, N)
        )
        {
            switch(evaluator<SubGrammar>()(expr, state, data))
            {
                BOOST_PP_REPEAT(N, M1, ~)
                default:
                    evaluator<SubGrammar>()(BOOST_PP_CAT(a, N).child0, state, data);
                    break;
            }
        }

        #undef M0
        #undef M1

    #undef N

#endif
