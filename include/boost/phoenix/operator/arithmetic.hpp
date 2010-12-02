/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#ifndef PHOENIX_OPERATOR_ARITHMETIC_HPP
#define PHOENIX_OPERATOR_ARITHMETIC_HPP

#include <boost/phoenix/core/meta_grammar.hpp>

namespace boost { namespace phoenix
{
	PHOENIX_UNARY_OPERATORS(
		(negate)
		(unary_plus)
		(pre_inc)
		(pre_dec)
		(post_inc)
		(post_dec)
	)
	
	PHOENIX_BINARY_OPERATORS(
		(plus_assign)
		(minus_assign)
		(multiplies_assign)
		(divides_assign)
		(modulus_assign)
		(plus)
		(minus)
		(multiplies)
		(divides)
		(modulus)
	)

    /*
    struct blubb
        : proto::callable
    {
        typedef int result_type;

        template <typename Env, typename Lhs, typename Rhs>
        result_type
        operator()(Env& env, Lhs const& lhs, Rhs const& rhs) const
        {
            std::cout << "ok ....\n";
            return 5;
        }
    };

    template <typename Dummy>
    struct default_actions::when<rule::plus_assign, Dummy>
        : proto::call<blubb(_env, proto::_child_c<0>, proto::_child_c<0>)>
    {};
    */
}}

#endif
