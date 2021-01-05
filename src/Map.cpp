#pragma once

#include "Map.h"

#include <vector>

namespace SkyZrath
{
    Map::Map()
    {
        std::cout << "Ctor" << std::endl;
    }

    Map::~Map()
    {
        std::cout << "Dtor" << std::endl;
    }

    Map *Map::getInstance()
    {
        static Map *instance = nullptr;

        if (!instance)
            instance = new Map;

        return instance;
    }

    size_t Map::size() const
    {
        return mTiles.size();
    }

    Hexagonal *Map::getTile(const Point& v) const
    {
        return mTiles.count(v) ? mTiles.at(v) : nullptr;
    }
} // namespace SkyZrath
