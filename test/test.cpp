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

BOOST_AUTO_TEST_CASE(zero_side_test)
{
    std::vector<double> sides(3);
    Triangle triangle;

    sides[0] = 0;
    sides[1] = 1;
    sides[2] = 1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = 0;
    sides[2] = 1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = 1;
    sides[2] = 0;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 0;
    sides[1] = 0;
    sides[2] = 1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 0;
    sides[1] = 1;
    sides[2] = 0;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = 0;
    sides[2] = 0;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 0;
    sides[1] = 0;
    sides[2] = 0;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);
}

BOOST_AUTO_TEST_CASE(negative_side_test)
{
    std::vector<double> sides(3);
    Triangle triangle;

    sides[0] = -1;
    sides[1] = 1;
    sides[2] = 1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = -1;
    sides[2] = 1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = 1;
    sides[2] = -1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = -1;
    sides[1] = -1;
    sides[2] = 1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = -1;
    sides[1] = 1;
    sides[2] = -1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = -1;
    sides[2] = -1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = -1;
    sides[1] = -1;
    sides[2] = -1;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);
}

BOOST_AUTO_TEST_CASE(sum_of_two_equals_third_test)
{
    std::vector<double> sides(3);
    Triangle triangle;

    sides[0] = 1;
    sides[1] = 3;
    sides[2] = 2;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 3;
    sides[1] = 1;
    sides[2] = 2;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = 2;
    sides[2] = 3;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);
}

BOOST_AUTO_TEST_CASE(sum_of_two_less_than_third_test)
{
    std::vector<double> sides(3);
    Triangle triangle;

    sides[0] = 1;
    sides[1] = 4;
    sides[2] = 2;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 4;
    sides[1] = 1;
    sides[2] = 2;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides[0] = 1;
    sides[1] = 2;
    sides[2] = 4;

    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);
}

BOOST_AUTO_TEST_CASE(wrong_sides_count_test)
{
    std::vector<double> sides;
    Triangle triangle;

    sides.push_back(1);
    sides.push_back(1);
    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);

    sides.push_back(1);
    sides.push_back(1);
    BOOST_TEST(triangle.Initialize(sides) == NOT_A_TRIANGLE);
}
