
#ifndef BOOST_PP_IS_ITERATING

/*=============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Eric Niebler
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_CORE_IS_NULLARY_HPP
#define PHOENIX_CORE_IS_NULLARY_HPP

namespace boost { namespace phoenix
{
	template <typename Expr> struct actor;

	template <
		template <typename> Actor
	 , PHOENIX_A_void(PHOENIX_LIMIT)
	 , typename Dummy = void>
	struct expr_ext;

	template <PHOENIX_A_void(PHOENIX_LIMIT)>
	struct expr : expr_ext<actor, PHOENIX_A(PHOENIX_LIMIT)> {};

}}

#endif

#else
	
template <
struct 

#endif
