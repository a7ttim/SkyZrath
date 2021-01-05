#include "Object.h"

namespace SkyZrath
{
	Object::Object()
	{
	}

	void Object::setPosition(const Vector<float> &p)
	{
		mPosition = p;
	}

	void Object::setScale(const Vector<float> &s)
	{
		mScale = s;
	}

	void Object::setRotation(const Vector<float> &r)
	{
		mRotation = std::move(r);
	}
} // namespace SkyZrath