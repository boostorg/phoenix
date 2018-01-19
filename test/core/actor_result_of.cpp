/*=============================================================================
    Copyright (c) 2018 Kohei Takahashi

    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <boost/utility/result_of.hpp>
#include <boost/phoenix/core/actor.hpp>
#include <boost/phoenix/core/value.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/type_traits/is_same.hpp>

int main()
{
    using boost::phoenix::actor;
    using boost::phoenix::expression::value;

    BOOST_MPL_ASSERT((boost::is_same<int, boost::result_of<actor<value<int>::type>()>::type>));
    BOOST_MPL_ASSERT((boost::is_same<int, boost::tr1_result_of<actor<value<int>::type>()>::type>));

    BOOST_MPL_ASSERT_NOT((boost::is_same<void, boost::result_of<actor<value<int>::type>()>::type>));
    BOOST_MPL_ASSERT_NOT((boost::is_same<void, boost::tr1_result_of<actor<value<int>::type>()>::type>));

    // TODO: Add non nullary tests...
}
