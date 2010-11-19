/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/detail/lightweight_test.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/object.hpp>
#include <boost/phoenix/operator.hpp>

int n = 0;

using std::cout;
using std::endl;

struct X
{
    X(int, int, int) { cout << "new X(int, int, int)" << endl; ++n; }
    X() { cout << "new X" << endl; ++n; }
    ~X() { cout << "delete X" << endl; --n; }
};

int
main()
{
    using boost::phoenix::arg_names::arg1;
    using boost::phoenix::construct;
    using boost::phoenix::delete_;
    using boost::phoenix::new_;

    using std::for_each;
    using std::vector;

    {
        vector<X*> v(10);

        for_each(v.begin(), v.end(), arg1 = new_<X>());
        for_each(v.begin(), v.end(), delete_(arg1));

        for_each(v.begin(), v.end(), arg1 = new_<X>(1, 2, 3));
        for_each(v.begin(), v.end(), delete_(arg1));
    }

    {
        using boost::shared_ptr;
        vector<shared_ptr<X> > v(10);
        for_each(v.begin(), v.end(),
            arg1 = construct<shared_ptr<X> >(new_<X>())
        );
    }

    BOOST_TEST(n == 0);
    return boost::report_errors();
}
//PHOENIX_DEFINE_EXPRESSION_VARARG(new_, (proto::terminal<detail::target<proto::_> >)(meta_grammar), PHOENIX_LIMIT)

/*
#include <boost/preprocessor/comparison/equal.hpp>


#define SEQ (h)

BOOST_PP_SEQ_ELEM(BOOST_PP_DEC(BOOST_PP_SEQ_SIZE(SEQ)), SEQ)

BOOST_PP_IF(BOOST_PP_EQUAL(1, BOOST_PP_SEQ_SIZE(SEQ)), BOOST_PP_EMPTY(), BOOST_PP_SEQ_ENUM(BOOST_PP_SEQ_POP_BACK(SEQ)))
*/
