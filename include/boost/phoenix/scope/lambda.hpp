#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman
        Copyright (c) 2008 Eric Niebler

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_SCOPE_LAMBDA_HPP_EAN_2008_05_29
    #define BOOST_PHOENIX_SCOPE_LAMBDA_HPP_EAN_2008_05_29

    #include <boost/preprocessor.hpp>
    #include <boost/fusion/include/map.hpp>
    #include <boost/fusion/include/fold.hpp>
    #include <boost/fusion/include/pair.hpp>
    #include <boost/fusion/include/as_map.hpp>
    #include <boost/fusion/include/at_key.hpp>
    #include <boost/fusion/include/transform.hpp>
    #include <boost/phoenix/scope/let.hpp>

    namespace boost { namespace phoenix
    {
        namespace tag
        {
            struct lambda_ {};
            struct with_state {};
        }

        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Map>
            struct lambda_generator
              : let_generator<Map>
            {
                typedef typename let_generator<Map>::map_type map_type;
                
                explicit lambda_generator(Map const &map)
                  : let_generator<Map>(map)
                {}

                template<typename Body>
                typename proto::result_of::make_expr<
                    tag::let_
                  , domain
                  , map_type const &
                  , typename proto::result_of::make_expr<
                        tag::lambda_
                      , domain
                      , Body const &
                    >::type const
                >::type const
                operator [](Body const &body) const
                {
                    return proto::make_expr<tag::let_, domain>(
                        boost::ref(this->map)
                      , proto::make_expr<tag::lambda_, domain>(boost::ref(body))
                    );
                }
            };
            
            ////////////////////////////////////////////////////////////////////////////////////////
            struct LocalVariable
              : proto::when<
                    proto::terminal<local_variable<proto::_> >
                  , local_variable_evaluator
                >
            {};

            ////////////////////////////////////////////////////////////////////////////////////////
            struct lambda_placeholder
            {
                template<typename Body>
                typename proto::result_of::make_expr<
                    tag::let_
                  , domain
                  , fusion::map<> const
                  , typename proto::result_of::make_expr<
                        tag::lambda_
                      , domain
                      , Body const &
                    >::type const
                >::type const
                operator [](Body const &body) const
                {
                    return proto::make_expr<tag::let_, domain>(
                        fusion::map<>()
                      , proto::make_expr<tag::lambda_, domain>(boost::ref(body))
                    );
                }

                #define BOOST_PP_ITERATION_PARAMS_1 (3, (1, PHOENIX_LIMIT, <boost/phoenix/scope/lambda.hpp>))
                #include BOOST_PP_ITERATE()
            };
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        // Evaluate a lambda() expression by simply returning the child let() expression.
        template<typename SubGrammar>
        struct extension<tag::lambda_, SubGrammar>
          : proto::when<
                proto::unary_expr<tag::lambda_, evaluator<SubGrammar> >
              , proto::_make_expr<tag::with_state, detail::domain>(
                    proto::call<proto::_make_expr<proto::tag::terminal, detail::domain>(proto::_byval(proto::_state))>
                  , proto::_child
                )
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename SubGrammar>
        struct extension<tag::with_state, SubGrammar>
          : proto::otherwise<
                evaluator<proto::or_<detail::LocalVariable, SubGrammar> >(
                    proto::_right
                  , proto::_value(proto::_left)
                  , proto::_data
                )
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<typename SubGrammar>
        struct is_nullary_extension<tag::lambda_, SubGrammar>
          : proto::_
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        detail::lambda_placeholder const lambda = {};
    }}

    #endif

#else

    #define N BOOST_PP_ITERATION()

        ////////////////////////////////////////////////////////////////////////////////////////////
        #define M0(Z, N, DATA)                                                                      \
            actor<                                                                                  \
                proto::expr<                                                                        \
                    proto::tag::assign                                                              \
                  , proto::list2<                                                                   \
                        actor<phoenix::local_variable<BOOST_PP_CAT(T, N)> >                         \
                      , BOOST_PP_CAT(A, N)                                                          \
                    >                                                                               \
                >                                                                                   \
            > const & BOOST_PP_CAT(a, N)                                                            \
            /**/

        ////////////////////////////////////////////////////////////////////////////////////////////
        #define M1(Z, N, DATA)                                                                      \
            fusion::pair<BOOST_PP_CAT(T, N), BOOST_PP_CAT(A, N)>                                    \
            /**/

        ////////////////////////////////////////////////////////////////////////////////////////////
        #define M2(Z, N, DATA)                                                                      \
            fusion::make_pair<BOOST_PP_CAT(T, N)>(BOOST_PP_CAT(a, N).proto_base().child1)           \
            /**/

        ////////////////////////////////////////////////////////////////////////////////////////////
        template<
            BOOST_PP_ENUM_PARAMS(N, typename T)
            BOOST_PP_ENUM_TRAILING_PARAMS(N, typename A)
        >
        detail::lambda_generator<fusion::map<BOOST_PP_ENUM(N, M1, ~)> > const
        operator()(BOOST_PP_ENUM(N, M0, ~)) const
        {
            typedef fusion::map<BOOST_PP_ENUM(N, M1, ~)> map_type;
            return detail::lambda_generator<map_type>(map_type(BOOST_PP_ENUM(N, M2, ~)));
        }

        #undef M0
        #undef M1
        #undef M2

    #undef N

#endif
