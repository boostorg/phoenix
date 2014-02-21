/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#include <boost/phoenix/core/limits.hpp>

#include <boost/detail/lightweight_test.hpp>
#include <boost/fusion/tuple.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/function.hpp>
#include <boost/phoenix/fusion.hpp>
#include <boost/phoenix/scope.hpp>

#include <typeinfo>

namespace fusion = boost::fusion;
namespace mpl = boost::mpl;

int
main()
{
    using boost::phoenix::let;
    using boost::phoenix::val;
    using boost::phoenix::arg_names::_1;
    using boost::phoenix::arg_names::_2;
    using boost::phoenix::arg_names::_3;
    using boost::phoenix::local_names::_a;
    using boost::phoenix::local_names::_b;
    using boost::phoenix::local_names::_c;
    using boost::phoenix::local_names::_d;
    using boost::phoenix::local_names::_e;
    using boost::phoenix::local_names::_x;
    using boost::phoenix::local_names::_y;
    using boost::phoenix::local_names::_z;
    using boost::phoenix::placeholders::arg1;

    {
        // show that we can return a local from an outer scope
        int y = 0;
        int x = (let(_a = 1)[let(_b = _1)[ _a ]])(y);

        BOOST_TEST(x == 1);
    }
    {
        // show that we can return a local from an inner scope
        int y = 1;
        int x = (let(_a = 0)[let(_b = _1)[ _b ]])(y);

        BOOST_TEST(x == 1);
    }
    {
        // show that we can return a local from an outer scope
        //int y = 0;
        int x = (let(_a = 1)[let(_b = _a)[ _a ]])();

        BOOST_TEST(x == 1);
    }
    {
        // show that we can return a local from an inner scope
        //int y = 0;
        int x = (let(_a = 1)[let(_b = _a)[ _b ]])();

        BOOST_TEST(x == 1);
    }
    {
        // show that we can return a local from an outer scope
        int y = 1;
        int x = (let(_a = _1)[let(_b = _a)[ _a ]])(y);

        BOOST_TEST(x == 1);
    }
    {
        // show that we can return a local from an inner scope
        int y = 1;
        int x = (let(_a = _1)[let(_b = _a)[ _b ]])(y);

        BOOST_TEST(x == 1);
    }

    
    return boost::report_errors();
}

