/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OBJECT_NEW_HPP
#define PHOENIX_OBJECT_NEW_HPP

#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/object/detail/target.hpp>
#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    PHOENIX_DEFINE_EXPRESSION_VARARG(
        new_
      , (proto::terminal<detail::target<proto::_> >)
        (meta_grammar)
      , PHOENIX_COMPOSITE_LIMIT
    )

    template <typename T>
    struct new_eval
        : proto::callable
    {
        typedef typename T::type construct_type;
        typedef typename T::type* result_type;

        template <typename Context>
        result_type
        operator()(Context&) const
        {
            return new construct_type;
        }

        // Bring in the rest
        #include <boost/phoenix/object/detail/new_eval.hpp>
    };

#define PHOENIX_NEW_CHILD(Z, N, D) proto::_child_c<N>
#define PHOENIX_NEW_CALL(Z, N, D)                                               \
            proto::when<                                                        \
                expression::new_<                                               \
                    proto::terminal<proto::_>                                   \
                  , BOOST_PP_ENUM_PARAMS(N, meta_grammar BOOST_PP_INTERCEPT)    \
                >                                                               \
              , proto::lazy<                                                    \
                    new_eval<proto::_value(proto::_child_c<0>)>(                \
                        _context                                                  \
                      , BOOST_PP_ENUM_SHIFTED(                                  \
                            BOOST_PP_INC(N)                                     \
                          , PHOENIX_NEW_CHILD                                   \
                          , _                                                   \
                        )                                                       \
                    )                                                           \
                >                                                               \
            >                                                                   \
        /**/

    template <typename Dummy>
    struct default_actions::when<rule::new_, Dummy>
        : proto::or_<
            proto::when<
                expression::new_<proto::terminal<proto::_> >
              , proto::lazy<
                    new_eval<
                        proto::_value(proto::_child_c<0>)
                    >(_context)
                >
            >
          , BOOST_PP_ENUM_SHIFTED(PHOENIX_COMPOSITE_LIMIT, PHOENIX_NEW_CALL, _)
        >

    {};
#undef PHOENIX_NEW_CHILD
#undef PHOENIX_NEW_CALL

    template <typename T>
    typename expression::new_<detail::target<T> >::type const
    new_()
    {
        return
            expression::
                new_<detail::target<T> >::
                    make(detail::target<T>());
    }

    // Bring in the rest
    #include <boost/phoenix/object/detail/new.hpp>
}}

#endif

