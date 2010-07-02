/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#if !PHOENIX_IS_ITERATING

#ifndef PHOENIX_FUNCTION_FUNCTION_HPP
#define PHOENIX_FUNCTION_FUNCTION_HPP

#include <boost/phoenix/core/domain.hpp>
#include <boost/phoenix/core/limits.hpp>
#include <boost/phoenix/support/iterate.hpp>
#include <boost/fusion/sequence/intrinsic/at_c.hpp>
#include <boost/proto/make_expr.hpp>
#include <boost/proto/tags.hpp>
#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
    ////////////////////////////////////////////////////////////////////////////
    // Functions
    ////////////////////////////////////////////////////////////////////////////
    
    namespace result_of
    {
        template <typename F,
            PHOENIX_typename_A_void(PHOENIX_ACTOR_LIMIT),
            typename Dummy = void>
        struct function;

        template <typename F>
        struct function<F>
          : proto::result_of::make_expr<
                proto::tag::function
              , phoenix_domain
              , F>
        {};

#define PHOENIX_ITERATE_RESULT_OF 1
#define PHOENIX_ITERATION_PARAMS                                                \
    (4, (1, PHOENIX_ACTOR_LIMIT,                                                \
    <boost/phoenix/function/function.hpp>, PHOENIX_ITERATE_RESULT_OF))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_RESULT_OF

    }

    // functor which returns our lazy function call extension
    template<typename F>
    struct function
    {
        function() {}

        function(F f)
          : f(f)
        {}

        template<typename Sig>
        struct result;

        template<typename This>
        struct result<This()>
            : result_of::function<F>
        {};

        typename result_of::function<F>::type const
        operator()() const
        {
            return proto::make_expr<proto::tag::function, phoenix_domain>(f);
        }

#define PHOENIX_ITERATE_OPERATOR 2
#define PHOENIX_ITERATION_PARAMS                                                \
        (4, (1, PHOENIX_ACTOR_LIMIT,                                            \
        <boost/phoenix/function/function.hpp>, PHOENIX_ITERATE_OPERATOR))
#include PHOENIX_ITERATE()
#undef PHOENIX_ITERATE_OPERATOR

        F f;
    };

}

    template<typename F>
    struct result_of<phoenix::function<F>()>
      : phoenix::result_of::function<F>
    {};

}

#endif

#else

#if BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_RESULT_OF
        
        template <typename F, PHOENIX_typename_A>
        struct function<F, PHOENIX_A>
          : proto::result_of::make_expr<
                proto::tag::function
              , phoenix_domain
              , F
              , PHOENIX_A>
        {};

#elif BOOST_PP_ITERATION_FLAGS() == PHOENIX_ITERATE_OPERATOR

        template<typename This, PHOENIX_typename_A>
        struct result<This(PHOENIX_A_const_ref)>
            : result_of::function<F, PHOENIX_A>
        {};

        template< PHOENIX_typename_A>
        typename result_of::function<F, PHOENIX_A>::type const
        operator()(PHOENIX_A_const_ref_a) const
        {
            return proto::make_expr<
                proto::tag::function, phoenix_domain>(f, PHOENIX_a);
        }

#endif

#endif
