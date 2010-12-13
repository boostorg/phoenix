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
    template <typename Expr>
    struct is_nullary;

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
            : //proto::lazy<is_nullary<custom_terminal<proto::_value> >(proto::_, _env)>
            proto::make<mpl::true_()>
		{};

		template <typename Dummy>
		struct is_nullary_::when<rule::terminal, Dummy>
			: proto::make<mpl::true_()>
		{};
	}

	template <typename Expr>
	struct is_nullary
		: boost::result_of<evaluator(Expr const&, fusion::vector2<fusion::vector0<>&, detail::is_nullary_>&)>
	{};

    template <typename T>
    struct is_nullary<custom_terminal<T> >
        : proto::make<mpl::true_()>
    {};

    template <typename T>
    struct is_nullary<T & >
        : is_nullary<T>
    {};

    template <typename T>
    struct is_nullary<T const & >
        : is_nullary<T>
    {};

    template <typename T>
    struct is_nullary<T const >
        : is_nullary<T>
    {};

}}

#endif

