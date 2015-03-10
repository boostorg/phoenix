/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2015      John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/detail/lightweight_test.hpp>

// This a test to see why test fails with BenPope x86_64 Ubuntu 
// clang- linux- 3.6~msan~c14_libc++

// The failure may well be in boost::report_errors();

int
main()
{
    int x = 123;
    //BOOST_TEST(x == 123);  No test
    return boost::report_errors();
}
