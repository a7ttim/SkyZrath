#pragma once

#include "Hexagonal.h"

#include <unordered_map>

namespace SkyZrath
{
    using Point = Vector2D<int>;
    using PointHasher = Vector2DHasher<int>;

    class Map
    {
    public:
        static Map *Map::getInstance();

        ~Map();

        size_t size() const;
        Hexagonal* getTile(const Point&) const;

        Map();

    private:
        std::unordered_map<Point, Hexagonal*, PointHasher> mTiles;
    };
} // namespace SkyZrath