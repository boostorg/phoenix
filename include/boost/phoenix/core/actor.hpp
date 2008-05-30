#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_ACTOR_HPP_EAN_2008_05_09
    #define BOOST_PHOENIX_ACTOR_HPP_EAN_2008_05_09

    #include <iosfwd>
    #include <boost/phoenix/core/limits.hpp>
    #include <boost/assert.hpp>
    #include <boost/config.hpp>
    #include <boost/mpl/if.hpp>
    #include <boost/mpl/or.hpp>
    #include <boost/mpl/and.hpp>
    #include <boost/mpl/bool.hpp>
    #include <boost/mpl/void.hpp>
    #include <boost/mpl/assert.hpp>
    #include <boost/mpl/identity.hpp>
    #include <boost/proto/proto.hpp>
    #include <boost/type_traits/is_abstract.hpp>
    #include <boost/type_traits/is_function.hpp>
    #include <boost/type_traits/is_base_of.hpp>
    #include <boost/type_traits/add_reference.hpp>
    #include <boost/type_traits/remove_const.hpp>
    #include <boost/preprocessor.hpp>
    #include <boost/utility/result_of.hpp>
    #include <boost/fusion/include/vector.hpp>

    namespace boost { namespace phoenix
    {
        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            typedef proto::not_<proto::_> no_sub_grammar;

            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename SubGrammar = no_sub_grammar, typename X = proto::callable>
            struct evaluator;
        }

        using detail::evaluator;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag, typename SubGrammar>
        struct extension;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Value, typename SubGrammar>
        struct terminal_extension
          : proto::otherwise<proto::_value>
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Value, typename SubGrammar>
        struct is_terminal_nullary
          : mpl::true_
        {};

        namespace actorns_
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Expr>
            struct actor;
        }

        using actorns_::actor;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename SubGrammar = detail::no_sub_grammar>
        struct is_nullary_cases;

        ////////////////////////////////////////////////////////////////////////////////////////
        // True when a lambda expression can be applied with no arguments and
        // without an active exception object
        template<typename SubGrammar = detail::no_sub_grammar, typename X = proto::callable>
        struct is_nullary
          : proto::or_<
                SubGrammar
              , proto::switch_<is_nullary_cases<SubGrammar> >
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////
        template<>
        struct is_nullary<>
          : proto::switch_<is_nullary_cases<> >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag, typename SubGrammar>
        struct is_nullary_extension
          : proto::nary_expr<Tag, proto::vararg<is_nullary<SubGrammar> > >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////
        template<typename SubGrammar>
        struct is_nullary_cases
        {
        private:
            template<typename T>
            struct is_terminal_nullary_local
              : is_terminal_nullary<T, SubGrammar>
            {};

        public:
            template<typename Tag, typename X = void>
            struct case_
              : is_nullary_extension<Tag, SubGrammar>
            {};

            template<typename X>
            struct case_<proto::tag::terminal, X>
              : proto::if_<is_terminal_nullary_local<proto::_value>()>
            {};
        };

        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename SubGrammar = detail::no_sub_grammar>
            struct evaluator_cases
            {
            private:
                template<typename Value>
                struct terminal_extension_local
                  : terminal_extension<Value, SubGrammar>
                {};

            public:
                template<typename Tag, typename X = void>
                struct case_
                  : phoenix::extension<Tag, SubGrammar>
                {};

                template<typename X>
                struct case_<proto::tag::terminal, X>
                  : proto::when<
                        proto::if_<
                            proto::matches<proto::_, terminal_extension_local<proto::_value>()>()
                        >
                      , proto::lazy<terminal_extension_local<proto::_value> >
                    >
                {};
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename SubGrammar, typename Callable>
            struct evaluator
              : proto::or_<
                    SubGrammar
                  , proto::switch_<evaluator_cases<SubGrammar> >
                >
            {};

            ////////////////////////////////////////////////////////////////////////////////////////
            template<>
            struct evaluator<>
              : proto::switch_<evaluator_cases<> >
            {};

            ////////////////////////////////////////////////////////////////////////////////////////
            // These terminal types are always stored by reference
            template<typename Value>
            struct storage
            {
                typedef
                    typename mpl::eval_if_c<
                        mpl::or_<
                            is_abstract<Value>
                          , is_function<Value>
                          , is_base_of<std::ios_base, Value>
                        >::type::value
                      , add_reference<Value>
                      , remove_const<Value>
                    >::type
                type;
            };

            template<typename T, std::size_t N>
            struct storage<T[N]>
            {
                typedef T (&type)[N];
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            // Store terminals by value, unless they are streams, arrays, functions or abstract types.
            struct generator
            {
                template<typename Sig>
                struct result;

                template<typename This, typename Expr>
                struct result<This(Expr)>
                {
                    typedef actor<typename proto::by_value_generator::result<void(Expr)>::type> type;
                };

                template<typename This, typename T>
                struct result<This(proto::expr<proto::tag::terminal, proto::term<T &> >)>
                {
                    typedef
                        actor<
                            proto::expr<proto::tag::terminal, proto::term<typename storage<T>::type> >
                        >
                    type;
                };

                template<typename Expr>
                actor<typename proto::by_value_generator::result<void(Expr)>::type> const
                operator()(Expr const &expr) const
                {
                    actor<typename proto::by_value_generator::result<void(Expr)>::type> that 
                        = {proto::by_value_generator()(expr)};
                    return that;
                }

                template<typename T>
                actor<
                    proto::expr<proto::tag::terminal, proto::term<typename storage<T>::type> >
                > const
                operator()(proto::expr<proto::tag::terminal, proto::term<T &> > const &expr) const
                {
                    actor<
                        proto::expr<
                            proto::tag::terminal
                          , proto::term<typename storage<T>::type>
                        >
                    > that = {{expr.child0}};
                    return that;
                }
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            struct domain
              : proto::domain<generator>
            {};

            typedef mpl::void_ const &initial_state_type;
            
            typedef proto::detail::any any;

            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Sig>
            struct result;

            template<typename This>
            struct result<This()>
              : mpl::if_c<
                    proto::matches<This, proto::and_<evaluator<>, is_nullary<> > >::type::value
                  , result_of<evaluator<>(This &, initial_state_type, fusion::vector0 &)>
                  , mpl::identity<void>
                >::type
            {};

            #define M0(Z, N, DATA)                                                                      \
            template<typename This BOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, N, typename A)>                   \
            struct result<This(BOOST_PP_ENUM_PARAMS_Z(Z, N, A))>                                        \
              : mpl::if_c<                                                                              \
                    proto::matches<This, evaluator<> >::type::value                                     \
                  , result_of<                                                                          \
                        evaluator<>(                                                                    \
                            This &                                                                      \
                          , initial_state_type                                                          \
                          , BOOST_PP_CAT(fusion::vector, N)<BOOST_PP_ENUM_PARAMS_Z(Z, N, A)> &          \
                        )                                                                               \
                    >                                                                                   \
                  , mpl::identity<any>                                                                  \
                >::type                                                                                 \
            {};                                                                                         \
            /**/
            BOOST_PP_REPEAT_FROM_TO(1, BOOST_PP_INC(PHOENIX_LIMIT), M0, ~)
            #undef M0
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        struct INVALID_LAMBDA_EXPRESSION
          : mpl::false_
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        struct VALID_LAMBDA_EXPRESSION
          : mpl::true_
        {};

        namespace actorns_
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Expr>
            struct actor
            {
                BOOST_PROTO_BASIC_EXTENDS(Expr, actor<Expr>, detail::domain)
                BOOST_PROTO_EXTENDS_ASSIGN()
                BOOST_PROTO_EXTENDS_SUBSCRIPT()

                template<typename Sig>
                struct result
                  : detail::result<Sig>
                {};

                typename result<Expr const()>::type
                operator()() const
                {
                    typedef typename result<Expr const()>::type result_type;
                    fusion::vector0 args;
                    return this->evaluate<result_type>(args);
                }

                #define M0(Z, N, _) ((0))

                #define M1(Z, N, _) ((0)(1))

                #define M2(R, PRODUCT) M3(R, BOOST_PP_SEQ_SIZE(PRODUCT), PRODUCT)

                #define M3(R, SIZE, PRODUCT)                                                                    \
                    template<BOOST_PP_ENUM_PARAMS(SIZE, typename A)>                                            \
                    typename result<Expr const(BOOST_PP_SEQ_FOR_EACH_I_R(R, M5, ~, PRODUCT))>::type             \
                    operator ()(BOOST_PP_SEQ_FOR_EACH_I_R(R, M4, ~, PRODUCT)) const                             \
                    {                                                                                           \
                        typedef typename                                                                        \
                            result<Expr const(BOOST_PP_SEQ_FOR_EACH_I_R(R, M5, ~, PRODUCT))>::type              \
                        result_type;                                                                            \
                        BOOST_PP_CAT(fusion::vector, SIZE)<BOOST_PP_SEQ_FOR_EACH_I_R(R, M5, ~, PRODUCT)> args   \
                            (BOOST_PP_SEQ_FOR_EACH_I_R(R, M6, ~, PRODUCT));                                     \
                        return this->evaluate<result_type>(args);                                               \
                    }                                                                                           \
                    /**/

                #define M4(R, _, I, ELEM)                                                                       \
                    BOOST_PP_COMMA_IF(I) BOOST_PP_CAT(A, I) BOOST_PP_CAT(C, ELEM) &BOOST_PP_CAT(a, I)           \
                    /**/

                #define M5(R, _, I, ELEM)                                                                       \
                    BOOST_PP_COMMA_IF(I) BOOST_PP_CAT(A, I) BOOST_PP_CAT(C, ELEM)&                              \
                    /**/

                #define M6(R, _, I, ELEM)                                                                       \
                    BOOST_PP_COMMA_IF(I) BOOST_PP_CAT(a, I)                                                     \
                    /**/

                #define C0

                #define C1 const

                #define BOOST_PP_ITERATION_PARAMS_1 (3, (1, PHOENIX_LIMIT, <boost/phoenix/core/actor.hpp>))
                #include BOOST_PP_ITERATE()

                #undef C0
                #undef C1
                #undef M0
                #undef M1
                #undef M2
                #undef M3
                #undef M4
                #undef M5
                #undef M6

            private:
                template<typename Result, typename Args>
                Result evaluate(Args &args) const
                {
                    typedef typename
                        mpl::if_<
                            proto::matches<Expr, evaluator<> >
                          , VALID_LAMBDA_EXPRESSION
                          , INVALID_LAMBDA_EXPRESSION
                        >::type
                    IS_VALID_LAMBDA_EXPRESSION;

                    // If your compile breaks here, your lambda expression doesn't validate against
                    // the Phoenix lambda grammar. Go back and check your expression for well-formedness.
                    BOOST_MPL_ASSERT((IS_VALID_LAMBDA_EXPRESSION));

                    return this->evaluate<Result>(args, IS_VALID_LAMBDA_EXPRESSION());
                }

                template<typename Result, typename Args>
                Result evaluate(Args &args, mpl::true_) const
                {
                    return evaluator<>()(this->proto_base(), mpl::void_(), args);
                }

                template<typename Result, typename Args>
                Result evaluate(Args &args, mpl::false_) const
                {
                    BOOST_ASSERT(false);
                    throw "never called";
                }
            };

        } // namespace actorns_

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag, typename SubGrammar>
        struct extension
          : proto::when<
                proto::nary_expr<proto::_, proto::vararg<evaluator<SubGrammar> > >
              , proto::_default<evaluator<SubGrammar> >
            >
        {};

    }}

    #endif

#else

    #if BOOST_PP_ITERATION() <= PHOENIX_PERFECT_FORWARD_LIMIT

        BOOST_PP_SEQ_FOR_EACH_PRODUCT(
            M2,
            BOOST_PP_REPEAT(BOOST_PP_ITERATION(), M1, ~)
        )

    #else

        BOOST_PP_SEQ_FOR_EACH_PRODUCT(
            M2,
            BOOST_PP_REPEAT(PHOENIX_PERFECT_FORWARD_LIMIT, M1, ~)
            BOOST_PP_REPEAT(BOOST_PP_SUB(BOOST_PP_ITERATION(), PHOENIX_PERFECT_FORWARD_LIMIT), M0, ~)
        )

    #endif

#endif
