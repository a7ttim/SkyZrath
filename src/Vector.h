#pragma once

#include <vector>
#include <iostream>
#include <set>
#include <string>

namespace SkyZrath
{
    template <typename T>
    struct Vector
    {
    public:
        Vector(T _x, T _y, T _z)
            : x(_x), y(_y), z(_z)
        {
        }

        Vector() = default;

        T x = 0, y = 0, z = 0;

        Vector operator+(const Vector &v) const
        {
            return Vector{x + v.x, y + v.y, z + v.z};
        }

        Vector operator-(const Vector &v) const
        {
            return Vector{x - v.x, y - v.y, z - v.z};
        }

        Vector operator*(const float &f) const
        {
            return Vector{x * f, y * f, z * f};
        }

        Vector operator-() const
        {
            return Vector{-x, -y, -z};
        }

        bool operator==(const Vector<T> &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }

        bool operator!=(const Vector<T> &v) const
        {
            return !(*this == v);
        }

        bool operator<(const Vector<T> &v) const
        {
            return x < v.x || (x == v.x && y < v.y) || (x == v.x && y == v.y && z < v.z);
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector &v)
        {
            os << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ", " << std::to_string(v.z) << ")";
            return os;
        }

        friend std::ostream &operator<<(std::ostream &os, const std::set<Vector> &s)
        {
            for (auto &v : s)
            {
                os << v << std::endl;
            }
            return os;
        }
    };

    template <typename T>
    struct VectorComparator
    {
        bool operator()(const Vector<T> &l, const Vector<T> &r) const
        {
            return l < r;
        }
    };

    template <typename T>
    struct VectorHasher
    {
        std::size_t operator()(const Vector<T> &k) const
        {
            return std::hash<T>()(k.x) ^ std::hash<T>()(k.y) ^ std::hash<T>()(k.z);
        }
    };

    template <typename T>
    struct Vector2D
    {
    public:
        Vector2D(T _x = .0, T _y = .0)
            : x(_x), y(_y)
        {
        }

        T x, y;

        Vector2D operator+(const Vector2D &v) const
        {
            return Vector{x + v.x, y + v.y};
        }

        Vector2D operator-(const Vector2D &v) const
        {
            return Vector{x - v.x, y - v.y};
        }

        Vector2D operator*(const float &f) const
        {
            return Vector{x * f, y * f};
        }

        Vector2D operator-() const
        {
            return Vector{-x, -y};
        }

        bool operator==(const Vector2D &v) const
        {
            return x == v.x && y == v.y;
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector2D &v)
        {
            os << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")" << std::endl;
            return os;
        }
    };

    template <typename T>
    struct Vector2DHasher
    {
        std::size_t operator()(const Vector2D<T> &k) const
        {
            int32_t a32 = k.x, b32 = k.y;

            return ((int64_t)a32 << 32) | b32;
        }
    };
}; // namespace SkyZrath