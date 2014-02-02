#include <boost/phoenix.hpp>
#include <boost/range/as_literal.hpp>
#include <boost/detail/lightweight_test.hpp>

using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;
    
int main()
{
    char X('x'), Y ;
    find(boost::as_literal("fox"), 'x')();     // works
#ifndef BOOST_NO_CXX11_DECLTYPE
    Y = find(boost::as_literal("fox"), arg1)('x'); // works for C++11
#else
    Y = find(boost::as_literal("fox"), construct<char>(arg1))('x'); // works
#endif
    BOOST_TEST(X==Y);
}
