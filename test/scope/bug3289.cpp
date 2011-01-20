/*==============================================================================
    Copyright (c) 2005-2010 Joel de Guzman
    Copyright (c) 2010 Thomas Heller

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <algorithm>
#include <vector>

#include <boost/detail/lightweight_test.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/scope.hpp>
#include <boost/phoenix/stl.hpp>

using namespace boost::phoenix;
using namespace boost::phoenix::arg_names;
using namespace boost::phoenix::local_names;

int main()
{
    std::vector<double> u(11,1.0);
    std::vector<double> w(11,2.0);
    std::vector<double>::const_iterator it=w.begin();

    boost::phoenix::generate(ref(u), lambda(_a=*ref(it)++)[_a*2.0])();

    BOOST_TEST(std::accumulate(u.begin(), u.end(), 0.0) == 44.0);

    BOOST_TEST(lambda(_a=*ref(it)++)[_a*2.0]()() == 4.0);
    
    return boost::report_errors();
}


