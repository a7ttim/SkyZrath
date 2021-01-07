#include "Hexagonal.h"

#include "Map.h"
#include "Vector.h"

#include <cassert>

namespace SkyZrath
{
    namespace
    {
        static const std::vector<Vector<int>> directions = {
            Vector<int>(1, 0, -1), // NorthEast
            Vector<int>(1, -1, 0), // East
            Vector<int>(0, -1, 1), // SouthEast
            Vector<int>(-1, 0, 1), // SouthWest
            Vector<int>(-1, 1, 0), // West
            Vector<int>(0, 1, -1), // NorthWest
        };
    }

    Hexagonal::Hexagonal(const Vector<int> &v)
        : mPosition(v)
    {
        assert(v.x + v.y + v.z == 0);
    }

    Hexagonal::~Hexagonal()
    {
#ifndef DEBUG
        std::cout << "Tile removed on " << mPosition << std::endl;
#endif // DEBUG
    }

    HexagonalPtr Hexagonal::getNeighbor(Direction direction) const
    {
        return Map::getInstance()->getTile(cubicToPoint(mPosition + directions.at(static_cast<int>(direction))));
    }

    const Vector<int> Hexagonal::pointToCubic(const Vector2D<int> &p)
    {
        const auto x = p.x - (p.y - (p.y & 1)) / 2;

        assert(x + -x - p.y + p.y == 0);

        return {x, -x - p.y, p.y};
    }

    const Vector2D<int> Hexagonal::cubicToPoint(const Vector<int> &v)
    {
        assert(v.x + v.y + v.z == 0);

        return {v.x + (v.z - (v.z & 1)) / 2, v.z};
    }

    const std::set<Vector<int>> Hexagonal::getWithinRadius(const Vector<int> &v, const int r)
    {
#ifdef DEBUG
        std::cout << "vector " << v << ", radius " << r << std::endl;
#endif // DEBUG

        assert(v.x + v.y + v.z == 0);
        assert(r);

        std::set<Vector<int>> result;

        for (int x = -r; x <= r; ++x)
        {
            for (int y = std::max(-r, -x - r); y <= std::min(r, -x + r); ++y)
            {
#ifdef DEBUG
                std::cout << "(" << x + v.x << "," << y + v.y << "," << v.z - x - y << ")" << std::endl;
#endif // DEBUG
                result.insert({v.x + x, v.y + y, v.z - x - y});
            }
        }

        return result;
    }
} // namespace SkyZrath