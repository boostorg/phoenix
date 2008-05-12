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
    #include <boost/config.hpp>
    #include <boost/mpl/if.hpp>
    #include <boost/mpl/or.hpp>
    #include <boost/mpl/and.hpp>
    #include <boost/mpl/bool.hpp>
    #include <boost/mpl/void.hpp>
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
        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag, typename Void = void>
        struct extension;

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Value, typename Void = void>
        struct terminal_extension
          : proto::_expr
        {
            typedef void phoenix_terminal_extension_not_specialized_;
        };

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Value, typename Void = void>
        struct is_terminal_extended
          : mpl::true_
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Value>
        struct is_terminal_extended<Value, typename terminal_extension<Value>::phoenix_terminal_extension_not_specialized_>
          : mpl::false_
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Value, typename Void = void>
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

        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            struct evaluator;
        }
        
        using detail::evaluator;

        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            // True when a lambda expression can be applied with no arguments and
            // without an active exception object
            struct is_nullary
              : proto::or_<
                    proto::when<
                        proto::terminal<proto::_>
                      , is_terminal_nullary<proto::_value>()
                    >
                  , proto::when<
                        proto::_
                      , proto::fold<proto::_, mpl::true_(), mpl::and_<proto::_state, is_nullary>()>
                    >
                >
            {};

            struct evaluator;

            ////////////////////////////////////////////////////////////////////////////////////////
            struct cases
            {
                template<typename Tag>
                struct case_
                  : phoenix::extension<Tag>
                {};
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            struct evaluator
              : proto::switch_<cases>
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
                    typedef actor<Expr> type;
                };

                template<typename This, typename T>
                struct result<This(proto::expr<proto::tag::terminal, proto::term<T &> >)>
                {
                    typedef
                        actor<
                            proto::expr<
                                proto::tag::terminal
                              , proto::term<typename storage<T>::type>
                            >
                        >
                    type;
                };

                template<typename Expr>
                actor<Expr> operator()(Expr const &expr) const
                {
                    actor<Expr> that = {expr};
                    return that;
                }

                template<typename T>
                actor<
                    proto::expr<
                        proto::tag::terminal
                      , proto::term<typename storage<T>::type>
                    >
                >
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

            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Sig>
            struct result;

            template<typename This>
            struct result<This()>
              : mpl::if_c<
                    result_of<is_nullary(This &)>::type::value
                  , result_of<evaluator(This &, mpl::void_ const &, fusion::vector0 &)>
                  , mpl::identity<void>
                >::type
            {};

            #define M0(Z, N, DATA)                                                                      \
            template<typename This BOOST_PP_ENUM_TRAILING_PARAMS_Z(Z, N, typename A)>                   \
            struct result<This(BOOST_PP_ENUM_PARAMS_Z(Z, N, A))>                                        \
              : result_of<                                                                              \
                    evaluator(                                                                          \
                        This &                                                                          \
                      , mpl::void_ const &                                                              \
                      , BOOST_PP_CAT(fusion::vector, N)<BOOST_PP_ENUM_PARAMS_Z(Z, N, A)> &              \
                    )                                                                                   \
                >                                                                                       \
            {};                                                                                         \
            /**/
            BOOST_PP_REPEAT_FROM_TO(1, BOOST_PP_INC(PHOENIX_LIMIT), M0, ~)
            #undef M0
        }
        
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
                    BOOST_MPL_ASSERT((proto::matches<Expr, evaluator>));
                    fusion::vector0 args;
                    return evaluator()(*this, mpl::void_(), args);
                }

                #define M0(Z, N, _) ((0))
                
                #define M1(Z, N, _) ((0)(1))

                #define M2(R, PRODUCT) M3(R, BOOST_PP_SEQ_SIZE(PRODUCT), PRODUCT)

                #define M3(R, SIZE, PRODUCT)                                                                    \
                    template<BOOST_PP_ENUM_PARAMS(SIZE, typename A)>                                            \
                    typename result<Expr const(BOOST_PP_SEQ_FOR_EACH_I_R(R, M5, ~, PRODUCT))>::type             \
                    operator ()(BOOST_PP_SEQ_FOR_EACH_I_R(R, M4, ~, PRODUCT)) const                             \
                    {                                                                                           \
                        BOOST_MPL_ASSERT((proto::matches<Expr, evaluator>));                                    \
                        BOOST_PP_CAT(fusion::vector, SIZE)<BOOST_PP_SEQ_FOR_EACH_I_R(R, M5, ~, PRODUCT)> args   \
                            (BOOST_PP_SEQ_FOR_EACH_I_R(R, M6, ~, PRODUCT));                                     \
                        return evaluator()(*this, mpl::void_(), args);                                          \
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
            };

        } // namespace actorns_

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename Tag, typename Void>
        struct extension
          : proto::when<
                proto::nary_expr<proto::_, proto::vararg<evaluator> >
              , proto::_default<evaluator>
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<>
        struct extension<proto::tag::terminal, void>
          : proto::or_<
                // If the handling of a particular terminal type has been
                // overridden, invoke the specified handler.
                proto::when<
                    proto::if_<is_terminal_extended<proto::_value>()>
                  , proto::lazy<terminal_extension<proto::_value> >
                >
                // Otherwise, just return the value of the terminal.
              , proto::otherwise<proto::_value>
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
