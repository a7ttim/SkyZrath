#pragma once

#include "Vector.h"

namespace SkyZrath
{
	class Object
	{
	public:
		Object();

		const Vector<float> &position() const;
		void setPosition(const Vector<float> &p);
		const Vector<float> &scale() const;
		void setScale(const Vector<float> &s);
		const Vector<float> &rotation() const;
		void setRotation(const Vector<float> &r);

	private:
		Vector<float> mPosition;
		Vector<float> mScale;
		Vector<float> mRotation;
	};
}; // namespace SkyZrath
