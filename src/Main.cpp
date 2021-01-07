#include <iostream>
#include "Map.h"

int main(int argc, char **argv)
{
	using namespace SkyZrath;

	auto* map = Map::getInstance();

	std::string in;

	std::cout << map->size() << std::endl;
	std::cin;

	const auto result1 = Hexagonal::getWithinRadius(Vector<int>(0, 0, 0), 1);

	map->~Map();
	return 0;
}