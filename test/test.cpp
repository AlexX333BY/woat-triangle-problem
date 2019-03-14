#define BOOST_TEST_MODULE woat_triangle_problem_test
#include <boost/test/unit_test.hpp>
#include "../src/Triangle.h"

BOOST_AUTO_TEST_CASE(equilateral_test)
{
    std::vector<double> sides(3, 3);
    Triangle triangle;
    BOOST_TEST(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsEquilateral());
}
