
#if !PHOENIX_IS_ITERATING

/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_EXPRESSION_HPP
#define PHOENIX_CORE_EXPRESSION_HPP

#include <boost/phoenix/support/iterate.hpp>

namespace boost { namespace phoenix
{
    template <typename Expr> struct actor;
    
    template <
        template <typename> class Actor
      , typename Tag
      , PHOENIX_typename_A_void(PHOENIX_LIMIT)
      , typename Dummy = void>
    struct expr_ext;

	template <typename Tag, PHOENIX_typename_A_void(PHOENIX_LIMIT), typename Dummy = void>
	struct expr : expr_ext<actor, Tag, PHOENIX_A(PHOENIX_LIMIT)> {};

    struct default_domain_with_basic_expr
        : proto::domain<proto::use_basic_expr<proto::default_generator> >
    {};

    #define PHOENIX_ITERATION_PARAMS                                            \
        (3, (1, PHOENIX_ACTOR_LIMIT,                                            \
        <boost/phoenix/core/expression.hpp>))
    #include PHOENIX_ITERATE()

}}

#endif

#else
    template <template <typename> class Actor, typename Tag, PHOENIX_typename_A>
    struct expr_ext<Actor, Tag, PHOENIX_A>
        : proto::transform<expr_ext<Actor, Tag, PHOENIX_A>, int>
    {
        typedef typename proto::result_of::make_expr<Tag, default_domain_with_basic_expr, PHOENIX_A>::type base_type;
        typedef Actor<base_type> type;
        typedef typename proto::nary_expr<Tag, PHOENIX_A>::proto_grammar proto_grammar;
        
        static type const make(PHOENIX_A_a)
        {
            type const e = {PHOENIX_a};
            return e;
        }

        template<typename Expr, typename State, typename Data>
        struct impl
          : proto::detail::pass_through_impl<expr_ext, Expr, State, Data>
        {};
        
        typedef Tag proto_tag;
        #define BOOST_PHOENIX_ENUM_CHILDREN(_, N, __) typedef BOOST_PP_CAT(A, N) BOOST_PP_CAT(proto_child, N);
        BOOST_PP_REPEAT(PHOENIX_ITERATION, BOOST_PHOENIX_ENUM_CHILDREN, _)
        #undef BOOST_PHOENIX_ENUM_CHILDREN
    };

#endif
