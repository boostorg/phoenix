// Check for Bug5715

#include <boost/phoenix/statement/sequence.hpp>
#include <boost/phoenix/bind.hpp>

#include <boost/detail/lightweight_test.hpp>

namespace test
{
  int x = 0;
  int y = 0;
  int z = 0;

  void f() { ++x; ++y; }
  void g() { --x; ++z; }

}
int main()
{
    (
     boost::phoenix::bind(test::f),
     boost::phoenix::bind(test::g)
    )();
    BOOST_TEST(test::x == 0);
    BOOST_TEST(test::y == 1);
    BOOST_TEST(test::z == 1);
}
