#pragma once

#include "Map.h"

#include <algorithm>

namespace SkyZrath
{
    Map::Map()
    {
        /// @TODO Remove after check
        std::cout << "Ctor" << std::endl;
    }

    Map::~Map()
    {
        /// @TODO Remove after check
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

    HexagonalPtr Map::getTile(const Point &v) const
    {
        return mTiles.at(v);
    }

    void Map::setRadius(const size_t r)
    {
        mRadius = r;
    }

    void Map::loadWithinRadius(const Vector<int> &v)
    {
        std::set<Vector<int>> tilesToLoad;
        std::set<Vector<int>> tilesToUnload;

        std::set<Vector<int>> newSet = Hexagonal::getWithinRadius(v, (int)mRadius);

        if (!mLoadedTiles.empty())
        {
            std::set_difference(newSet.begin(), newSet.end(), mLoadedTiles.begin(), mLoadedTiles.end(),
                                std::inserter(tilesToLoad, tilesToLoad.begin()));
            std::set_difference(mLoadedTiles.begin(), mLoadedTiles.end(), newSet.begin(), newSet.end(),
                                std::inserter(tilesToUnload, tilesToUnload.begin()));
        }
        else
        {
            tilesToLoad = newSet;
        }

#ifndef DEBUG
        std::cout << "Tiles to load: " << std::endl;
        std::cout << tilesToLoad << std::endl;
#endif // DEBUG

        for (auto &v : tilesToLoad)
        {
            mTiles.insert({Hexagonal::cubicToPoint(v), std::make_shared<Hexagonal>(v)});
        }

#ifndef DEBUG
        std::cout << "Tiles to unload: " << std::endl;
        std::cout << tilesToUnload << std::endl;
#endif // DEBUG

        for (auto &v : tilesToUnload)
        {
            const auto p = Hexagonal::cubicToPoint(v);
            mTiles.erase(p);
        }

        mLoadedTiles = std::move(newSet);
    } // namespace SkyZrath
} // namespace SkyZrath
