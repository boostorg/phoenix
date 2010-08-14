/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <iostream>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/function.hpp>

#include <boost/detail/lightweight_test.hpp>

using boost::phoenix::arg_names::arg1;
using boost::phoenix::arg_names::arg2;
using boost::phoenix::arg_names::arg3;

int main()
{
	/*
	auto square = arg1 * arg1;
	auto cube = arg1 * arg1 * arg1;
	auto square_cube = square(cube(arg1));
	*/

	BOOST_TEST(((arg1 * arg1)(arg1 * arg1 * arg1))(2) == 64);
	BOOST_TEST(((arg1 * arg1)(arg1 * arg2 * arg1))(2, 2) == 64);
	BOOST_TEST(((arg1 * arg1)(arg1 * arg2 * arg3))(2, 2, 2) == 64);
	
	BOOST_TEST((arg1)(arg1)(8) == 8);
	BOOST_TEST((arg1)(arg1 + arg2)(8, 9) == 17);

	BOOST_TEST((arg1 + arg2)(arg1, arg1)(8) == 16);

    double mean = 8.0;
    (arg1 + arg2 * (arg1 * arg1)( boost::phoenix::val(1.0) - mean ))(1.0, 2.0);

	return boost::report_errors();
}
