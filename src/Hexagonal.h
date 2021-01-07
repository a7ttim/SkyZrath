#pragma once

#include "Vector.h"

#include <set>

namespace SkyZrath
{
	/// odd-r realization
	class Hexagonal
	{
		using This = Hexagonal;

		using HexagonalPtr = std::shared_ptr<Hexagonal>;

		enum class Direction : int
		{
			NorthEast = 0,
			East,
			SouthEast,
			SouthWest,
			West,
			NorthWest = 5
		};

	public:
		Hexagonal(const Vector<int> &);
		~Hexagonal();

		//Point position2D() const;
		//Cube position() const;

		HexagonalPtr getNeighbor(Direction) const;

		const static Vector<int> pointToCubic(const Vector2D<int> &);
		const static Vector2D<int> cubicToPoint(const Vector<int> &);

		const static std::set<Vector<int>> getWithinRadius(const Vector<int> &v, const int r);

	public:
		//bool addNeighbor(Direction, Building&);

	private:
		Vector<int> mPosition;
		Direction mRotation;
	};

} // namespace SkyZrath