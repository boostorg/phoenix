/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_FUNCTION_FUNCTION_HPP
#define PHOENIX_FUNCTION_FUNCTION_HPP

#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/proto/make_expr.hpp>
#include <boost/proto/tags.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    // Functions
    /////////////////////////////////////////////////////////////////////////////

    namespace tag
    {
        typedef proto::tag::function function;
    }

    namespace expression
    {

        template <
            typename F
          , PHOENIX_typename_A_void(PHOENIX_LIMIT)
          , typename Dummy = void
        >
        struct function;

    #define PHOENIX_DEFINE_FUNCTION_EXPRESSION(_, N, __)                            \
        template <typename F, PHOENIX_typename_A(N)>                                \
        struct function<F, PHOENIX_A(N)>                                            \
            : expr<tag::function, F, PHOENIX_A(N)>                                     \
        {};                                                                         \

        BOOST_PP_REPEAT_FROM_TO(
            1
          , PHOENIX_LIMIT
          , PHOENIX_DEFINE_FUNCTION_EXPRESSION
          , _
        )
    }

    namespace rule
    {
        struct function
            : proto::nary_expr<
                proto::tag::function
              , proto::vararg<meta_grammar>
            >
        {};
    }

    template <typename Dummy>
    struct meta_grammar::case_<proto::tag::function, Dummy>
        : proto::when<rule::function, proto::external_transform>
    {};

    // functor which returns our lazy function call extension
    template<typename F>
    struct function
    {
        function() {}

        function(F f)
          : f(f)
        {}

        template <typename Sig>
        struct result;

        typename expression::function<F>::type const
        operator()() const
        {
            return expression::function<F>::make(f);
            //return proto::make_expr<proto::tag::function, phoenix_domain>(f);
        }

        // Bring in the rest
        #include <boost/phoenix/function/detail/function_operator.hpp>

        F f;
    };

}

    template<typename F>
    struct result_of<phoenix::function<F>()>
      : phoenix::expression::function<F>
    {};

}

#endif

