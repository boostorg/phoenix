////////////////////////////////////////////////////////////////////////////
// lazy_list3_tests.cpp
//
// more tests on list<T>
//
////////////////////////////////////////////////////////////////////////////
/*=============================================================================
    Copyright (c) 2000-2003 Brian McNamara and Yannis Smaragdakis
    Copyright (c) 2001-2007 Joel de Guzman
    Copyright (c) 2015 John Fletcher

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/phoenix/core/limits.hpp>

#include <boost/detail/lightweight_test.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/function/lazy_prelude.hpp>


int main()
{
    namespace phx = boost::phoenix;
    //using boost::phoenix::arg_names::arg1;
    //using boost::phoenix::arg_names::arg2;
    using namespace phx;

    list<int> l    = enum_from(2);
    list<int> ll   = take(4,l);
    list<int> lll  = take(12,l);
    list<int> l2   = enum_from_to(2,10);
    list<int> ll2  = take(4,l2);
    list<int> lll2 = take(12,l2);
    list<int> evens = filter(even,l);
    list<int> even4 = take(4,evens)();
    
    BOOST_TEST(last(ll)()   == 5);
    BOOST_TEST(last(lll)()  == 13);
    BOOST_TEST(last(ll2)()  == 5);
    BOOST_TEST(last(lll2)() == 10);
    BOOST_TEST(length(lll2)() == 9);
    BOOST_TEST(at(even4,3)() == 8);

    return boost::report_errors();
}
