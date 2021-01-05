#pragma once

#include "Vector.h"

namespace SkyZrath
{
	/// odd-r realization
	class Hexagonal
	{
		using This = Hexagonal;

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

		//Point position2D() const;
		//Cube position() const;

		Hexagonal *getNeighbor(Direction) const;

		const static Vector<int> pointToCubic(const Vector2D<int> &);
		const static Vector2D<int> cubicToPoint(const Vector<int> &);

	public:
		//bool addNeighbor(Direction, Building&);

	private:
		Vector<int> mPosition;
		Direction mRotation;
	};

} // namespace SkyZrath