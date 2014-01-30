/*=============================================================================
    Copyright (c) 2005-2007 Dan Marsden
    Copyright (c) 2005-2007 Joel de Guzman
    Copyright (c) 2014      John Fletcher
    
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

// Check for Bug5715

#include <boost/phoenix/statement/sequence.hpp>
#include <boost/phoenix/bind.hpp>

#include <boost/detail/lightweight_test.hpp>

namespace test
{
  int  x = 0;

  void f() { ++x; }
  void g() { --x; }

}
int main()
{
    (
     boost::phoenix::bind(test::f),
     boost::phoenix::bind(test::g)
    )();
    BOOST_TEST(test::x == 0);
}
