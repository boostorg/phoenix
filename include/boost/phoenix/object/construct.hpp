#ifndef BOOST_PP_IS_ITERATING
    /*=============================================================================
        Copyright (c) 2001-2007 Joel de Guzman
        Copyright (c) 2008 Eric Niebler

        Distributed under the Boost Software License, Version 1.0. (See accompanying
        file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
    ==============================================================================*/
    #ifndef BOOST_PHOENIX_OBJECT_CONSTRUCT_HPP_EAN_2008_05_21
    #define BOOST_PHOENIX_OBJECT_CONSTRUCT_HPP_EAN_2008_05_21

    #include <boost/preprocessor/iteration/iterate.hpp>
    #include <boost/preprocessor/repetition/enum_params.hpp>
    #include <boost/preprocessor/repetition/enum_binary_params.hpp>
    #include <boost/proto/proto.hpp>
    #include <boost/phoenix/core/actor.hpp>

    namespace boost { namespace phoenix
    {

        namespace detail
        {
            template<typename T>
            struct construct
            {
                typedef T result_type;

                T operator()() const
                {
                    return T();
                }

                #define BOOST_PP_ITERATION_PARAMS_1                                             \
                    (3, (1, PHOENIX_LIMIT, <boost/phoenix/object/construct.hpp>))
                #include BOOST_PP_ITERATE()
            };
        }

        BOOST_PROTO_DEFINE_VARARG_FUNCTION_TEMPLATE(
            construct
          , detail::domain
          , (proto::tag::function)
          , ((detail::construct)(typename))
        )

    }}

    #endif

#else

    #define N BOOST_PP_ITERATION()

        template<BOOST_PP_ENUM_PARAMS(N, typename A)>
        T operator()(BOOST_PP_ENUM_BINARY_PARAMS(N, A, const &a)) const
        {
            return T(BOOST_PP_ENUM_PARAMS(N, a));
        }

    #undef N

#endif
