#define BOOST_TEST_MODULE SkyZrathHexagonalTest

#include <boost/test/included/unit_test.hpp>
#include <boost/bind.hpp>

#include "../src/Hexagonal.h"

using namespace SkyZrath;

BOOST_AUTO_TEST_CASE(cubicToPointTest)
/* Compare with void free_test_function() */
{
  const auto testData1 = Vector<int>(2, 0, -2);
  const auto expected1 = Vector2D<int>(1, -2);

  const auto testData2 = Vector<int>(-2, 1, 1);
  const auto expected2 = Vector2D<int>(-2, 1);

  BOOST_TEST(Hexagonal::cubicToPoint(testData1) == expected1);
  BOOST_TEST(Hexagonal::cubicToPoint(testData2) == expected2);
}

BOOST_AUTO_TEST_CASE(pointToCubicTest)
/* Compare with void free_test_function() */
{
  const auto testData1 = Vector2D<int>(1, -2);
  const auto expected1 = Vector<int>(2, 0, -2);

  const auto testData2 = Vector2D<int>(-2, 1);
  const auto expected2 = Vector<int>(-2, 1, 1);
  
  BOOST_TEST(Hexagonal::pointToCubic(testData1) == expected1);
  BOOST_TEST(Hexagonal::pointToCubic(testData2) == expected2);
}
