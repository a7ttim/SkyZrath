#include "Hexagonal.h"

#include "Map.h"
#include <cassert>
#include "Vector.h"

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

    Hexagonal *Hexagonal::getNeighbor(Direction direction) const
    {
        return Map::getInstance()->getTile(cubicToPoint(mPosition + directions.at(static_cast<int>(direction))));
    }

    const Vector<int> Hexagonal::pointToCubic(const Vector2D<int> &p)
    {
        const auto x = p.x - (p.y - (p.y & 1)) / 2;
        const auto z = p.y;
        const auto y = -x - z;
        return {x, y, z};
    }

    const Vector2D<int> Hexagonal::cubicToPoint(const Vector<int> &v)
    {
        return {v.x + (v.z - (v.z & 1)) / 2, v.z};
    }
} // namespace SkyZrath