/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <iostream>
#include <cmath>
#include <boost/detail/lightweight_test.hpp>
#include <boost/noncopyable.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/bind.hpp>

using namespace boost::phoenix;
using namespace boost::phoenix::arg_names;
using namespace std;
namespace phx = boost::phoenix;

namespace test
{
    struct x : boost::noncopyable // test non-copyable (hold this by reference)
    {
        void
        test() const
        {
            cout << "Test binding member functions...\n";
        }
    };

    struct y : boost::noncopyable // test non-copyable (hold this by reference)
    {
        int
        negate(int n) const
        {
            return -n;
        }
    };

    struct z : boost::noncopyable // test non-copyable (hold this by reference)
    {
        int
        plus(int a, int b) const
        {
            return a + b;
        }
    };

    struct zz : boost::noncopyable // test non-copyable (hold this by reference)
    {
        int
        plus3(int a, int b, int c)
        {
            return a + b + c;
        }
    };
}

int
main()
{
    int a = 123;
    int b = 256;
    test::x x_;
    test::y y_;
    test::z z_;
    test::zz zz_;

    //bind(&test::x::test, x_)(0); // <- original test, fails due to attempt of copying
    bind(&test::x::test, ref(x_))();
    //BOOST_TEST(bind(&test::y::negate, y_, arg1)(a) == -a); // same as above
    BOOST_TEST(bind(&test::y::negate, ref(y_), arg1)(a) == -a);
    //BOOST_TEST(bind(&test::z::plus, arg1, arg2, arg3)(z_, a, b) == a+b);
    //BOOST_TEST(bind(&test::zz::plus3, zz_, arg1, arg2, arg3)(a, b, a) == a+b+a);
    BOOST_TEST(bind(&test::y::negate, &y_, 777)(a) == -777);

    return boost::report_errors();
}
