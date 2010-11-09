/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_IS_NULLARY_HPP
#define PHOENIX_CORE_IS_NULLARY_HPP

#include <boost/proto/proto.hpp>
#include <boost/phoenix/core/environment.hpp>
#include <boost/phoenix/core/meta_grammar.hpp>
#include <boost/phoenix/core/terminal.hpp>

namespace boost { namespace phoenix
{
	namespace detail
	{
		struct is_nullary_
		{
			template <typename Rule, typename Dummy = void>
			struct when
				: proto::fold<
				    proto::_
				  , mpl::true_()
				  , mpl::and_<
				      proto::_state
				    , evaluator(proto::_, _env)
				    >()
				>
			{};
		};

		template <typename Dummy>
		struct is_nullary_::when<rule::argument, Dummy>
			: proto::make<mpl::false_()>
		{};

		template <typename Dummy>
		struct is_nullary_::when<rule::custom_terminal, Dummy>
			: proto::make<mpl::true_()>
		{};

		template <typename Dummy>
		struct is_nullary_::when<rule::terminal, Dummy>
			: proto::make<mpl::true_()>
		{};
	}

	template <typename Expr>
	struct is_nullary
		: boost::result_of<evaluator(Expr const&, make_basic_environment<detail::is_nullary_>::type&)>
	{};

}}

#endif

