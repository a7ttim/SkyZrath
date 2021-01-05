#include <iostream>
#include "Map.h"

int main(int argc, char **argv)
{
	using namespace SkyZrath;

	auto* map = new Map();

	std::string in;

	//SkyZrath::Vector<float> vector1{5., 6., 7.};

	std::cout << map->size() << std::endl;
	std::cin;

	map->~Map();
	return 0;
}