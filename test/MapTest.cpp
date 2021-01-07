#define BOOST_TEST_MODULE SkyZrathMapTest

#include <boost/test/included/unit_test.hpp>
#include <boost/bind.hpp>

#include "../src/Map.h"

using namespace SkyZrath;

BOOST_AUTO_TEST_CASE(loadWithinRadius)
{
  auto *map = Map::getInstance();

  const auto testDataRadius1 = 1;
  const auto testDataRadius2 = 2;
  const auto testData1 = Vector<int>(0, 0, 0);
  const auto testData2 = Vector<int>(3, -3, 0);
  
  const auto expected1 = 7;
  const auto expected2 = 19;

  map->setRadius(testDataRadius1);
  map->loadWithinRadius(testData1);
  const auto result1 = map->size();

  map->setRadius(testDataRadius2);
  map->loadWithinRadius(testData2);
  const auto result2 = map->size();
  
  BOOST_TEST(result1 == expected1);
  BOOST_TEST(result2 == expected2);
}