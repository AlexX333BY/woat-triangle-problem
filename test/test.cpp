#define BOOST_TEST_MODULE woat_triangle_problem_test
#include <boost/test/unit_test.hpp>
#include "../src/Triangle.h"

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
    std::vector<double> sides;
    Triangle triangle;

    sides.push_back(2);
    sides.push_back(2);
    sides.push_back(3);

    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsIsosceles());

    sides.clear();
    sides.push_back(2);
    sides.push_back(3);
    sides.push_back(2);

    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsIsosceles());

    sides.clear();
    sides.push_back(3);
    sides.push_back(2);
    sides.push_back(2);

    BOOST_TEST_REQUIRE(triangle.Initialize(sides) == SUCCESS);
    BOOST_TEST(triangle.IsIsosceles());
}
