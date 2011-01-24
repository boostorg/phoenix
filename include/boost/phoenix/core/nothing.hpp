/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_NOTHING_HPP
#define PHOENIX_CORE_NOTHING_HPP

#include <boost/mpl/void.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/expression.hpp>

namespace boost { namespace phoenix
{
    /////////////////////////////////////////////////////////////////////////////
    //
    //  null_actor
    //
    //      An actor that does nothing (a "bum", if you will :-).
    //
    /////////////////////////////////////////////////////////////////////////////
    
    PHOENIX_DEFINE_EXPRESSION(null, (proto::terminal<mpl::void_>::type))
	 namespace tag
	 {
	     struct nothing {};
	 }

	 namespace expression
	 {
	     struct nothing
			  : expr<tag::nothing, proto::terminal<mpl::void_> >
		  {
		      typedef actor<
				    typename proto::result_of::make_expr<
						 tag::nothing
					  , default_domain_with_basic_expr
					  , mpl::void_
					>::type
					>
					type;
        
				typedef
                typename proto::unnary_expr<tag::nothing, proto::_>::proto_grammar
                proto_grammar;

				static type const make()
				{
					type const e = {{}};
					return e;
				}
		  };
	 }

	 namespace rule
	 {
	     struct null : expression::null {};
	 }
    
    struct null_eval
    {
        BOOST_PROTO_CALLABLE()

        typedef void result_type;

        void operator()() const
        {}
    };

    template <typename Dummy>
    struct default_actions::when<rule::null, Dummy>
        : proto::call<null_eval()>
    {};

    expression::null::type const nothing = {};
}}

#endif
