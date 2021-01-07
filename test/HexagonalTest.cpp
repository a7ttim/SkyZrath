#define BOOST_TEST_MODULE SkyZrathHexagonalTest

#include <boost/test/included/unit_test.hpp>
#include <boost/bind.hpp>

#include "../src/Hexagonal.h"
#include "../src/Vector.h"

using namespace SkyZrath;

BOOST_AUTO_TEST_CASE(cubicToPointTest)
{
  const auto testData1 = Vector<int>(2, 0, -2);
  const auto expected1 = Vector2D<int>(1, -2);

  const auto testData2 = Vector<int>(-2, 1, 1);
  const auto expected2 = Vector2D<int>(-2, 1);

  BOOST_TEST(Hexagonal::cubicToPoint(testData1) == expected1);
  BOOST_TEST(Hexagonal::cubicToPoint(testData2) == expected2);
}

BOOST_AUTO_TEST_CASE(pointToCubicTest)
{
  const auto testData1 = Vector2D<int>(1, -2);
  const auto expected1 = Vector<int>(2, 0, -2);

  const auto testData2 = Vector2D<int>(-2, 1);
  const auto expected2 = Vector<int>(-2, 1, 1);

  BOOST_TEST(Hexagonal::pointToCubic(testData1) == expected1);
  BOOST_TEST(Hexagonal::pointToCubic(testData2) == expected2);
}

BOOST_AUTO_TEST_CASE(getWithinRadius)
{
  const auto testData1_1 = Vector<int>(0, 0, 0);
  const auto testData1_2 = 1;

  const auto testData2_1 = Vector<int>(1, -1, 0);
  const auto testData2_2 = 1;

  const auto testData3_1 = testData1_1;
  const auto testData3_2 = 2;

  const auto testData4_1 = testData2_1;
  const auto testData4_2 = testData3_2;

  const auto expected1 = std::set<Vector<int>>{
      Vector<int>(-1, 0, 1),
      Vector<int>(-1, 1, 0),
      Vector<int>(0, -1, 1),
      Vector<int>(0, 0, 0),
      Vector<int>(0, 1, -1),
      Vector<int>(1, -1, 0),
      Vector<int>(1, 0, -1)};

  const auto expected2 = std::set<Vector<int>>{
      Vector<int>(0, -1, 1),
      Vector<int>(0, 0, 0),
      Vector<int>(1, -2, 1),
      Vector<int>(1, -1, 0),
      Vector<int>(1, 0, -1),
      Vector<int>(2, -2, 0),
      Vector<int>(2, -1, -1)};

  const auto expected3 = std::set<Vector<int>>{
      Vector<int>(-2, 0, 2),
      Vector<int>(-2, 1, 1),
      Vector<int>(-2, 2, 0),
      Vector<int>(-1, -1, 2),
      Vector<int>(-1, 0, 1),
      Vector<int>(-1, 1, 0),
      Vector<int>(-1, 2, -1),
      Vector<int>(0, -2, 2),
      Vector<int>(0, -1, 1),
      Vector<int>(0, 0, 0),
      Vector<int>(0, 1, -1),
      Vector<int>(0, 2, -2),
      Vector<int>(1, -2, 1),
      Vector<int>(1, -1, 0),
      Vector<int>(1, 0, -1),
      Vector<int>(1, 1, -2),
      Vector<int>(2, -2, 0),
      Vector<int>(2, -1, -1),
      Vector<int>(2, 0, -2)};

  const auto expected4 = std::set<Vector<int>>{
      Vector<int>(-2, 0, 2) + testData2_1,
      Vector<int>(-2, 1, 1) + testData2_1,
      Vector<int>(-2, 2, 0) + testData2_1,
      Vector<int>(-1, -1, 2) + testData2_1,
      Vector<int>(-1, 0, 1) + testData2_1,
      Vector<int>(-1, 1, 0) + testData2_1,
      Vector<int>(-1, 2, -1) + testData2_1,
      Vector<int>(0, -2, 2) + testData2_1,
      Vector<int>(0, -1, 1) + testData2_1,
      Vector<int>(0, 0, 0) + testData2_1,
      Vector<int>(0, 1, -1) + testData2_1,
      Vector<int>(0, 2, -2) + testData2_1,
      Vector<int>(1, -2, 1) + testData2_1,
      Vector<int>(1, -1, 0) + testData2_1,
      Vector<int>(1, 0, -1) + testData2_1,
      Vector<int>(1, 1, -2) + testData2_1,
      Vector<int>(2, -2, 0) + testData2_1,
      Vector<int>(2, -1, -1) + testData2_1,
      Vector<int>(2, 0, -2) + testData2_1};

  const auto result1 = Hexagonal::getWithinRadius(testData1_1, testData1_2);
  const auto result2 = Hexagonal::getWithinRadius(testData2_1, testData2_2);
  const auto result3 = Hexagonal::getWithinRadius(testData3_1, testData3_2);
  const auto result4 = Hexagonal::getWithinRadius(testData4_1, testData4_2);

  BOOST_TEST(result1.size() == expected1.size());
  BOOST_TEST(result1 == expected1);
  BOOST_TEST(result2.size() == expected2.size());
  BOOST_TEST(result2 == expected2);
  BOOST_TEST(result3.size() == expected3.size());
  BOOST_TEST(result3 == expected3);
  BOOST_TEST(result4.size() == expected4.size());
  BOOST_TEST(result4 == expected4);
}