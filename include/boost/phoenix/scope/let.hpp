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
    #include <boost/fusion/include/pair.hpp>
    #include <boost/fusion/include/as_map.hpp>
    #include <boost/fusion/include/at_key.hpp>
    #include <boost/fusion/include/transform.hpp>
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
            template<typename State, typename Data>
            struct initialize_locals
            {
                explicit initialize_locals(State state, Data data)
                  : state(state)
                  , data(data)
                {}

                template<typename Sig>
                struct result;

                template<typename This, typename That>
                struct result<This(That &)>
                  : result<This(That)>
                {};

                template<typename This, typename First, typename Second>
                struct result<This(fusion::pair<First, Second>)>
                {
                    typedef
                        fusion::pair<
                            First
                          , typename boost::result_of<evaluator(Second, State, Data)>::type
                        >
                    type;
                };

                template<typename First, typename Second>
                fusion::pair<
                    First
                  , typename boost::result_of<evaluator(Second, State, Data)>::type
                > const
                operator()(fusion::pair<First, Second> const &p) const
                {
                    typedef
                        fusion::pair<
                            First
                          , typename boost::result_of<evaluator(Second, State, Data)>::type
                        >
                    pair_type;
                    return pair_type(evaluator()(p.second, this->state, this->data));
                }

            private:
                State state;
                Data data;
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            template<typename Map, typename State, typename Data>
            struct scope
            {
                typedef typename remove_reference<State>::type state_type;

                typedef typename
                    fusion::result_of::as_map<typename
                        fusion::result_of::transform<
                            typename remove_reference<Map>::type
                          , initialize_locals<State, Data>
                        >::type
                    >::type
                locals_type;

                scope(Map map, State state, Data data)
                  : state(state)
                  , data(data)
                  , locals(fusion::as_map(fusion::transform(map, initialize_locals<State, Data>(state, data))))
                {}

                State state;                // outer state
                Data data;                  // outer data
                mutable locals_type locals; // Local variables
            };

            ////////////////////////////////////////////////////////////////////////////////////////
            struct make_scope
              : proto::transform<make_scope>
            {
                template<typename Expr, typename State, typename Data>
                struct impl
                  : proto::transform_impl<Expr, State, Data>
                {
                    typedef typename proto::result_of::value<Expr>::type map_type;
                    typedef scope<map_type, typename impl::state_param, Data> result_type;

                    result_type operator()(
                        typename impl::expr_param expr
                      , typename impl::state_param state
                      , typename impl::data_param data
                    ) const
                    {
                        return result_type(proto::value(expr), state, data);
                    }
                };
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
              , evaluator(proto::_right, detail::make_scope(proto::_left), proto::_data)
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
