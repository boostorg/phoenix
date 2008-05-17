#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_SWITCH_HPP_EAN_2008_05_10
    #define BOOST_PHOENIX_SWITCH_HPP_EAN_2008_05_10

    #include <boost/ref.hpp>
    #include <boost/mpl/int.hpp>
    #include <boost/mpl/assert.hpp>
    #include <boost/mpl/equal_to.hpp>
    #include <boost/mpl/next_prior.hpp>
    #include <boost/preprocessor.hpp>
    #include <boost/proto/proto.hpp>
    #include <boost/phoenix/core/actor.hpp>
    #include <boost/fusion/include/as_vector.hpp>

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
            struct Case
              : proto::switch_<struct CaseCases>
            {};
            
            struct CaseCases
            {
                template<typename Tag>
                struct case_
                  : proto::not_<proto::_>
                {};
                
                template<int Label>
                struct case_<tag::case_<Label> >
                  : proto::unary_expr<proto::_, evaluator>
                {};
            };

            struct Default
              : proto::unary_expr<tag::default_, evaluator>
            {};
            
            struct CasesNoDefault
              : proto::or_<
                    Case
                  , proto::comma<CasesNoDefault, Case>
                >
            {};

            struct CasesWithDefault
              : proto::or_<
                    Default
                  , proto::comma<CasesNoDefault, Default>
                >
            {};

            struct Switch
              : proto::binary_expr<
                    tag::switch_
                  , evaluator
                  , proto::or_<CasesNoDefault, CasesWithDefault>
                >
            {};

            #define BOOST_PP_ITERATION_PARAMS_1 (3, (0, PHOENIX_LIMIT, <boost/phoenix/statement/switch.hpp>))
            #include BOOST_PP_ITERATE()

            ////////////////////////////////////////////////////////////////////////////////////////
            // Proto transform that evaluates switch(condition)[ case_<0>(expr), case_<1>(expr), ... ]
            struct switch_evaluator
              : proto::transform<switch_evaluator>
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
                        detail::do_switch(
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
        template<>
        struct extension<tag::switch_, void>
          : proto::when<
                detail::Switch
              , detail::switch_evaluator
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<int Label>
        struct is_nullary_cases::case_<tag::case_<Label> >
          : proto::otherwise<mpl::false_()>
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<>
        struct is_nullary_cases::case_<tag::default_>
          : proto::otherwise<mpl::false_()>
        {};

    }}

    #ifdef _MSC_VER
    # pragma warning(pop)
    #endif

    #endif

#else

    #define N BOOST_PP_ITERATION()

        #define M0(Z, N, DATA)                                                                      \
            proto::expr<tag::case_<BOOST_PP_CAT(L, N)>, BOOST_PP_CAT(A, N), 1> const &BOOST_PP_CAT(a, N)\
            /**/
        
        #define M1(Z, N, DATA)                                                                      \
            case BOOST_PP_CAT(L, N):                                                                \
                evaluator()(BOOST_PP_CAT(a, N).child0, state, data);                                \
                break;                                                                              \
            /**/
            
        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            typename Expr, typename State, typename Data
          , typename A0
            BOOST_PP_COMMA_IF(N)
            BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_INC(N), typename A)
        >
        void do_switch(
            Expr &expr, State &state, Data &data
          , proto::expr<proto::tag::comma, A0, 2> const &a0
            BOOST_PP_COMMA_IF(N)
            BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(BOOST_PP_INC(N), A, const &a)
        )
        {
            // Fan out the arguments
            detail::do_switch(
                expr, state, data
              , a0.child0.proto_base()
              , a0.child1.proto_base()
                BOOST_PP_COMMA_IF(N)
                BOOST_PP_ENUM_SHIFTED_PARAMS(BOOST_PP_INC(N), a)
            );
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            typename Expr, typename State, typename Data
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
            switch(evaluator()(expr, state, data))
            {
                BOOST_PP_REPEAT(BOOST_PP_INC(N), M1, ~)
                default:;
            }
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            typename Expr, typename State, typename Data
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
            switch(evaluator()(expr, state, data))
            {
                BOOST_PP_REPEAT(N, M1, ~)
                default:
                    evaluator()(BOOST_PP_CAT(a, N).child0, state, data);
                    break;
            }
        }

        #undef M0
        #undef M1
        
    #undef N

#endif
