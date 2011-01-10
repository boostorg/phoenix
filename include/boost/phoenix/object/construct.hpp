/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_CONSTRUCT_HPP
#define PHOENIX_OBJECT_CONSTRUCT_HPP

#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/fusion.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION_VARARG(
        construct
      , (proto::terminal<detail::target<proto::_> >)
        (meta_grammar)
      , PHOENIX_COMPOSITE_LIMIT
    )

    template <typename T>
    struct construct_eval
    {
        typedef typename T::type result_type;

        template <typename Env>
        result_type
        operator()(Env& env) const
        {
            return result_type();
        }

        // Bring in the rest
        #include <boost/phoenix/object/detail/construct_eval.hpp>

    };

#define PHOENIX_CONSTRUCT_CHILD(Z, N, D) proto::_child_c<N>
#define PHOENIX_CONSTRUCT_CALL(Z, N, D)                                         \
            proto::when<                                                        \
                expression::construct<                                          \
                    proto::terminal<proto::_>                                   \
                  , BOOST_PP_ENUM_PARAMS(N, meta_grammar BOOST_PP_INTERCEPT)    \
                >                                                               \
              , proto::lazy<                                                    \
                    construct_eval<proto::_value(proto::_child_c<0>)>(          \
                        _env                                                    \
                      , BOOST_PP_ENUM_SHIFTED(                                  \
                            BOOST_PP_INC(N)                                     \
                          , PHOENIX_CONSTRUCT_CHILD                             \
                          , _                                                   \
                        )                                                       \
                    )                                                           \
                >                                                               \
            >                                                                   \
        /**/

    template <typename Dummy>
    struct default_actions::when<rule::construct, Dummy>
        : proto::or_<
            proto::when<
                expression::construct<proto::terminal<proto::_> >
              , proto::lazy<
                    construct_eval<
                        proto::_value(proto::_child_c<0>)
                    >(_env)
                >
            >
          , BOOST_PP_ENUM_SHIFTED(PHOENIX_LIMIT, PHOENIX_CONSTRUCT_CALL, _)
        >

    {};
#undef PHOENIX_CONSTRUCT_CHILD
#undef PHOENIX_CONSTRUCT_CALL

    template <typename T>
    typename expression::construct<detail::target<T> >::type const
    construct()
    {
        return
            expression::
                construct<detail::target<T> >::
                    make(detail::target<T>());
    }

    // Bring in the rest
    #include <boost/phoenix/object/detail/construct.hpp>

}}

#endif

