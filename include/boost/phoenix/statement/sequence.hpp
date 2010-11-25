/*==============================================================================
    Copyright (c) 2001-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef PHOENIX_STATEMENT_SEQUENCE_HPP
#define PHOENIX_STATEMENT_SEQUENCE_HPP

#include <boost/config.hpp>
#include <boost/phoenix/core/expression.hpp>
#include <boost/phoenix/core/actor.hpp>

namespace boost { namespace phoenix
{
	namespace rule
	{
		struct sequence
		  : proto::binary_expr<
		    proto::tag::comma
		  , meta_grammar
		  , meta_grammar>
		{};
	}

	template <typename Dummy>
	struct meta_grammar::case_<proto::tag::comma, Dummy>
		: proto::when<rule::sequence, proto::external_transform>
	{};

}}

#endif
