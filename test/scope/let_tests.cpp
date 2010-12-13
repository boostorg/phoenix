/*=============================================================================
    Copyright (c) 2001-2007 Joel de Guzman

    Distributed under the Boost Software License, Version 1.0. (See accompanying 
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

#define PHOENIX_LIMIT 6
#include <boost/detail/lightweight_test.hpp>
#include <boost/phoenix/core.hpp>
#include <boost/phoenix/operator.hpp>
#include <boost/phoenix/function.hpp>
#include <boost/phoenix/fusion.hpp>
#include <boost/phoenix/scope.hpp>
#include <boost/fusion/tuple.hpp>

#include <typeinfo>

namespace fusion = boost::fusion;
namespace mpl = boost::mpl;

template <typename Expr>
void fpp_test(Expr const & expr)
{
    using boost::phoenix::let;
    using boost::phoenix::local_names::_a;
    using boost::phoenix::local_names::_b;
    using boost::phoenix::local_names::_c;
    using boost::phoenix::local_names::_d;
    using boost::phoenix::local_names::_e;
    using boost::phoenix::local_names::_x;
    using boost::phoenix::local_names::_y;
    using boost::phoenix::local_names::_z;
    //std::cout << typeid(typename boost::phoenix::detail::grammar_of<Expr>::type).name() << "\n";
    std::cout << typeid(typename boost::proto::matches<Expr, boost::phoenix::meta_grammar>::type).name() << "\n";
    std::cout << typeid(typename boost::phoenix::is_nullary<Expr>::type).name() << "\n";
    //std::cout << typeid(let(_a = 1, _b = 2, _c = 2, _d = 3, _e = 5)[expr]()).name() << "\n";
    //let(_a = 1/*, _b = 2, _c = 2, _d = 3, _e = 5*/)[expr]();
    //let(_a = 1, _b = 2, _c = 2, _d = 3, _e = 5)[expr]();
    std::cout << "\n";
}

template <typename Expr0, typename Expr1>
void fpp_test(Expr0 const & expr0, Expr1 const & expr1)
{
    fpp_test(expr0);
    fpp_test(expr1);
    fpp_test(expr0 + expr1);
}

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
        int x = 1;
        BOOST_TEST(
            let(_a = _1)
            [
                _a
            ]
            (x) == x
        );
    }

    {
        int x = 1, y = 10;
        BOOST_TEST(
            let(_a = _1, _b = _2)
            [
                _a + _b
            ]
            (x, y) == x + y
        );
    }

    {
        int x = 1, y = 10, z = 13;
        BOOST_TEST(
            let(_x = _1, _y = _2)
            [
                let(_z = _3)
                [
                    _x + _y + _z
                ]
            ]
            (x, y, z) == x + y + z
        );
    }

    {
        int x = 1, y = 10;
        BOOST_TEST(
            let(_x = _1) 
            [
                _x +
                    let(_x = _2)
                    [
                        -_x
                    ]
            ]
            (x, y) == x + -y
        );
    }

    {
        int x = 999;
        BOOST_TEST(
            let(_x = _1) // _x is a reference to x
            [
                _x += 888
            ]
            (x) == 999 + 888
        );
        
        BOOST_TEST(x == 888 + 999);    
    }

    {
        int x = 999;
    /*
        BOOST_TEST(
            let(_x = val(_1)) // _x holds x by value 
            [
                _x += 888
            ]
            (x) == x + 888
        );
        
        BOOST_TEST(x == 999);
    */

        BOOST_TEST(
            let(_x = val(_1)) // _x holds x by value 
            [
                //val(_x += 888)
                val(888 + 999)
            ]
            (x) == x + 888
        );
        
        BOOST_TEST(x == 999);
    }

    {
        BOOST_TEST(
            let(_a = 1, _b = 2, _c = 3, _d = 4, _e = 5)
            [
                _a + _b + _c + _d + _e
            ]
            () == 1 + 2 + 3 + 4 + 5
        );
    }

#ifdef PHOENIX_SHOULD_NOT_COMPILE_TEST
    {
        // disallow this:
        int i;
        (_a + _b)(i);
    }
#endif
 
    {
        // show that we can return a local from an outer scope
        int y = 0;
        int x = (let(_a = 1)[let(_b = _1)[ _a ]])(y);

        BOOST_TEST(x == 1);
    }

    {
        // show that this code returns an lvalue
        int i = 1;
        let(_a = arg1)[ _a ](i)++;
        BOOST_TEST(i == 2);
    }

    {
        // show that what you put in is what you get out
        int i = 1;
        int& j = let(_a = arg1)[_a](i);
        BOOST_TEST(&i == &j);
    }

    {
        using boost::phoenix::at_c;

        boost::fusion::tuple<int, int> t = boost::fusion::make_tuple(0, 1);
        int i = let(_a = at_c<0>(_1))[_a](t);

        BOOST_TEST( i == 0 );
    }

    {
        int i = 0;
        let(_a = _1)[_a = _2](i, 2);
        BOOST_TEST(i == 2);
    }

    return boost::report_errors();
}

