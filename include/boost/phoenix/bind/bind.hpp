#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman
        Copyright (c) 2008 Eric Niebler

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_BIND_BIND_HPP_EAN_2008_05_21
    #define BOOST_PHOENIX_BIND_BIND_HPP_EAN_2008_05_21

    #include <boost/preprocessor/arithmetic/sub.hpp>
    #include <boost/preprocessor/arithmetic/dec.hpp>
    #include <boost/preprocessor/iteration/iterate.hpp>
    #include <boost/preprocessor/facilities/intercept.hpp>
    #include <boost/preprocessor/punctuation/comma_if.hpp>
    #include <boost/preprocessor/repetition/enum_shifted_params.hpp>
    #include <boost/preprocessor/repetition/enum_trailing_params.hpp>
    #include <boost/preprocessor/repetition/enum_shifted_binary_params.hpp>
    #include <boost/mpl/if.hpp>
    #include <boost/mpl/and.hpp>
    #include <boost/mpl/not.hpp>
    #include <boost/proto/proto.hpp>
    #include <boost/phoenix/core/actor.hpp>
    #include <boost/phoenix/core/reference.hpp>
    #include <boost/type_traits/is_member_pointer.hpp>

    namespace boost { namespace phoenix
    {
        namespace detail
        {
            template<typename Fun, typename T>
            struct by_ref
              : mpl::and_<
                    is_member_pointer<Fun>
                  , mpl::not_<proto::is_expr<T> >
                >
            {};
        }

        template<typename Fun>
        typename proto::result_of::make_expr<
            proto::tag::function
          , detail::domain
          , Fun const &
        >::type const
        bind(Fun const &fun)
        {
            return proto::implicit_expr(fun);
        }

        #define BOOST_PP_ITERATION_PARAMS_1                                             \
            (3, (1, BOOST_PP_SUB(PHOENIX_LIMIT, 2), <boost/phoenix/bind/bind.hpp>))
        #include BOOST_PP_ITERATE()

    }}

    #endif

#else

    #define N BOOST_PP_ITERATION()

        template<
            typename Fun
          , typename A0
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(N))
            BOOST_PP_ENUM_SHIFTED_PARAMS(N, typename A)
        >
        typename proto::result_of::make_expr<
            proto::tag::function
          , detail::domain
          , Fun const &
          , typename mpl::if_<
                detail::by_ref<Fun, A0>
              , actor<typename proto::terminal<A0 &>::type>
              , A0 &
            >::type
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(N))
            BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(N, A, const & BOOST_PP_INTERCEPT)
        >::type const
        bind(
            Fun const &fun
          , A0 &a0
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(N))
            BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(N, A, const &a)
        )
        {
            return proto::implicit_expr(fun BOOST_PP_ENUM_TRAILING_PARAMS(N, a));
        }

        template<
            typename Fun
          , typename A0
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(N))
            BOOST_PP_ENUM_SHIFTED_PARAMS(N, typename A)
        >
        typename proto::result_of::make_expr<
            proto::tag::function
          , detail::domain
          , Fun const &
          , typename mpl::if_<
                detail::by_ref<Fun, A0>
              , actor<typename proto::terminal<A0 const &>::type>
              , A0 const &
            >::type
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(N))
            BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(N, A, const & BOOST_PP_INTERCEPT)
        >::type const
        bind(
            Fun const &fun
          , A0 const &a0
            BOOST_PP_COMMA_IF(BOOST_PP_DEC(N))
            BOOST_PP_ENUM_SHIFTED_BINARY_PARAMS(N, A, const &a)
        )
        {
            return proto::implicit_expr(fun BOOST_PP_ENUM_TRAILING_PARAMS(N, a));
        }

    #undef N

#endif
