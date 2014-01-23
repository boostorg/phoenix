#include <boost/phoenix.hpp>
#include <boost/range/as_literal.hpp>

using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;
    
int main()
{
    find(boost::as_literal("fox"), 'x')();                      // works
    find(boost::as_literal("fox"), construct<char>(arg1))('x'); // works
    find(boost::as_literal("fox"), arg1)('x');                  // compilation error
}
