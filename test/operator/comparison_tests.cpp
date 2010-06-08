/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>

using namespace boost::phoenix;
using namespace std;

int
main()
{
    {
        BOOST_TEST(!(val(123) == 456)(0));
        BOOST_TEST((val(123) != 456)(0));
        BOOST_TEST(!(val(123) > 456)(0));
        BOOST_TEST((val(123) < 456)(0));
        BOOST_TEST(!(val(123) > 456)(0));
        BOOST_TEST((val(123) <= 123)(0));
        BOOST_TEST((val(123) >= 123)(0));
    }

    return boost::report_errors();
}
