// Check for Bug5715

#include <boost/phoenix/statement/sequence.hpp>
#include <boost/phoenix/bind.hpp>


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
    BOOST_TEST(x == 0);
}
