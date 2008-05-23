#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman
        Copyright (c) 2008 Eric Niebler

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_SCOPE_LET_HPP_EAN_2008_05_21
    #define BOOST_PHOENIX_SCOPE_LET_HPP_EAN_2008_05_21

    #include <boost/preprocessor.hpp>
    #include <boost/fusion/include/map.hpp>
    #include <boost/fusion/include/fold.hpp>
    #include <boost/phoenix/scope/local_variable.hpp>

    namespace boost { namespace phoenix
    {
        namespace tag
        {
            struct let_ {};
        }

        namespace detail
        {
            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Map>
            struct let_generator
            {
                typedef typename proto::terminal<Map>::type map_type;

                explicit let_generator(Map const &map)
                  : map(map_type::make(map))
                {}

                template<typename Body>
                typename proto::result_of::make_expr<
                    tag::let_
                  , domain
                  , map_type const &
                  , Body const &
                >::type const
                operator [](Body const &body) const
                {
                    return proto::implicit_expr(this->map, body);
                }

            private:
                typename proto::terminal<Map>::type map;
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Map, typename State>
            struct scope
            {
                scope(Map const &map, State const &state)
                  : map(map)
                  , state(state)
                {}

                typedef Map const map_type;
                typedef State const state_type;

                Map const &map;        // local variables map
                State const &state;    // outer state
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            struct is_let_init_nullary
            {
                template<typename Sig>
                struct result;

                template<typename This, typename Elem, typename State>
                struct result<This(Elem &, State &)>
                  : mpl::and_<
                        State
                      , typename result_of<is_nullary(typename fusion::result_of::second<Elem>::type)>::type
                    >
                {};
            };
        }

        ////////////////////////////////////////////////////////////////////////////////////////////
        // Evaluate a let() expression by evaluating the body with a state that contains
        // a map of the local variables and a reference to the enclosing scope.
        template<>
        struct extension<tag::let_, void>
          : proto::when<
                proto::binary_expr<tag::let_, proto::terminal<proto::_>, evaluator>
              , evaluator(
                    proto::_right
                  , proto::make<
                        detail::scope<proto::_value(proto::_left), proto::_state>(
                            proto::_value(proto::_left)
                          , proto::_state
                        )
                    >
                  , proto::_data
                )
            >
        {};

        ////////////////////////////////////////////////////////////////////////////////////////////
        // BUGBUG this isn't quite right. It gets the answer wrong for
        // let(_a = 1)[ _a += arg1 ]
        template<>
        struct is_nullary_cases::case_<tag::let_>
          : proto::otherwise<
                fusion::result_of::fold<
                    proto::_value(proto::_left)
                  , mpl::true_()
                  , detail::is_let_init_nullary()
                >()
            >
        {};

        #define BOOST_PP_ITERATION_PARAMS_1 (3, (1, PHOENIX_LIMIT, <boost/phoenix/scope/let.hpp>))
        #include BOOST_PP_ITERATE()

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
                        actor<local_variable<BOOST_PP_CAT(T, N)> > const &                          \
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
        detail::let_generator<fusion::map<BOOST_PP_ENUM(N, M1, ~)> > const
        let(BOOST_PP_ENUM(N, M0, ~))
        {
            typedef fusion::map<BOOST_PP_ENUM(N, M1, ~)> map_type;
            return detail::let_generator<map_type>(map_type(BOOST_PP_ENUM(N, M2, ~)));
        }

        #undef M0
        #undef M1
        #undef M2

    #undef N

#endif
