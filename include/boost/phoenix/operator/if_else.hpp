/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OPERATOR_IF_ELSE_HPP
#define PHOENIX_OPERATOR_IF_ELSE_HPP

//#include <boost/phoenix/core/compose.hpp>
//#include <boost/utility/result_of.hpp>

namespace boost { namespace phoenix
{
	namespace rule
	{
		struct if_else
		  : proto::nary_expr<
		    proto::tag::if_else_
		  , meta_grammar
		  , meta_grammar
		  , meta_grammar>
		{};
	}

	template <typename Dummy>
	struct meta_grammar::case_<proto::tag::if_else_, Dummy>
		: proto::when<rule::if_else, proto::external_transform>
	{};

	using proto::if_else;
}}

#endif
