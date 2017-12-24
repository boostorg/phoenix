/*=============================================================================
    Copyright (c) 2017 Nikita Kniazev

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#include <boost/phoenix/core.hpp>
#include <boost/phoenix/object.hpp>

#include <boost/array.hpp>
#include <string>

int main()
{
    (void) boost::phoenix::construct<std::string>("str");

    int ints[] = { 1, 2, 3 };
    (void) boost::phoenix::construct<boost::array<int, sizeof(ints)> >(ints);

    return 0;
}
