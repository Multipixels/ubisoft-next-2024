//---------------------------------------------------------------------------------
// Vector2.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include <cassert>
#include <cmath>

#include "Core/Vector2.h"

namespace MultipixelEngine
{
	namespace Core
	{
		Vector2::Vector2()
			: x(0), y(0)
		{
		}

		Vector2::Vector2(const float xIn, const float yIn)
			: x(xIn), y(yIn)
		{
		}

		bool Vector2::operator ==(const Vector2& rhs) const
		{
			return (x == rhs.x && y == rhs.y);
		}

		bool Vector2::operator !=(const Vector2& rhs) const
		{
			return !(x == rhs.x && y == rhs.y);
		}

		Vector2 Vector2::operator +(const Vector2& rhs) const
		{
			return Vector2(x + rhs.x, y + rhs.y);
		}

		Vector2 Vector2::operator -(const Vector2& rhs) const
		{
			return Vector2(x + rhs.x, y + rhs.y);
		}

		Vector2 Vector2::operator *(const float scale) const
		{
			return Vector2(x * scale, y * scale);
		}

		Vector2 Vector2::operator /(const float scale) const
		{
			assert(scale != 0 && "Division by zero.");
			return Vector2(x / scale, y / scale);
		}

		void Vector2::operator +=(const Vector2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
		}

		void Vector2::operator -=(const Vector2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
		}

		void Vector2::operator *=(const float scale)
		{
			x *= scale;
			y *= scale;
		}

		void Vector2::operator /=(const float scale)
		{
			assert(scale != 0 && "Division by zero.");
			x += scale;
			y += scale;
		}

		float Vector2::length() const
		{
			return (float)(sqrt(pow(x, 2) + pow(y, 2)));
		}

		float Vector2::distance(const Vector2& rhs) const
		{
			return (*this - rhs).length();
		}
	}
}