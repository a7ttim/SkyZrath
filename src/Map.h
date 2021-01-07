#pragma once

#include "Hexagonal.h"

#include <unordered_map>
#include <memory>

namespace SkyZrath
{
    using Point = Vector2D<int>;
    using PointHasher = Vector2DHasher<int>;

    using HexagonalPtr = std::shared_ptr<Hexagonal>;

    namespace {
        constexpr auto DefaultRadius = 3;
    } // anon

    class Map
    {
    public:
        static Map *Map::getInstance();

        ~Map();

        size_t size() const;
        HexagonalPtr getTile(const Point &) const;
        void setRadius(const size_t);
        void loadWithinRadius(const Vector<int> &);

    private:
        Map();

    private:
        size_t mRadius = DefaultRadius;
        Vector<int> mPosition = Vector<int>(0, 0, 0);
        std::set<Vector<int>> mLoadedTiles;
        std::unordered_map<Point, HexagonalPtr, PointHasher> mTiles;
    };
} // namespace SkyZrath