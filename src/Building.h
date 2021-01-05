#pragma once

#include "Object.h"

#include <vector>
#include <memory>

namespace SkyZrath
{
	class Building : public Object
	{
		using BuildingUnq = std::unique_ptr<Building>;

		using Base = Object;
		
	public:
		Building();

	private:
		std::vector<BuildingUnq> mNeighbors[6];
	};
}; // namespace SkyZrath
