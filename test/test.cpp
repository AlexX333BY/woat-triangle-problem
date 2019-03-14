#define BOOST_TEST_MODULE woat_triangle_problem_test
#include <boost/test/unit_test.hpp>
#include "../src/Triangle.h"
#include <float.h>

BOOST_AUTO_TEST_CASE(equilateral_test)
{
    std::vector<double> sides(3, 3);
    Triangle triangle;
    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsEquilateral());
}

BOOST_AUTO_TEST_CASE(ordinary_test)
{
    std::vector<double> sides;
    sides.push_back(2);
    sides.push_back(3);
    sides.push_back(4);
    Triangle triangle;
    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(!triangle.IsEquilateral());
    BOOST_TEST(!triangle.IsIsosceles());
}

BOOST_AUTO_TEST_CASE(isosceles_test)
{
    std::vector<double> sides(3);
    Triangle triangle;

    sides[0] = 2;
    sides[1] = 2;
    sides[2] = 3;

    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsIsosceles());

    sides[0] = 2;
    sides[1] = 3;
    sides[2] = 2;

    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsIsosceles());

    sides[0] = 3;
    sides[1] = 2;
    sides[2] = 2;

    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsIsosceles());
}
