#pragma once

#include <vector>
#include <iostream>
#include <string>

namespace SkyZrath
{
    template <typename T>
    struct Vector
    {
    public:
        Vector(T _x = .0, T _y = .0, T _z = .0)
            : x(_x), y(_y), z(_z)
        {
        }

        T x, y, z;

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

        bool operator==(const Vector &v) const
        {
            return x == v.x && y == v.y && z == v.z;
        }

        friend std::ostream &operator<<(std::ostream &os, const Vector &v)
        {
            os << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ", " << std::to_string(v.z) << ")";
            return os;
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
            os << "(" << std::to_string(v.x) << ", " << std::to_string(v.y) << ")";
            return os;
        }
    };

    template <typename T>
    struct Vector2DHasher
    {
        std::size_t operator()(const Vector2D<T> &k) const
        {
            return std::hash<T>()(k.x) ^ std::hash<T>()(k.y);
        }
    };

}; // namespace SkyZrath