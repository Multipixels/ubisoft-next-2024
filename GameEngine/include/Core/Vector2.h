//---------------------------------------------------------------------------------
// Vector2.h
//---------------------------------------------------------------------------------
#pragma once
namespace MultipixelEngine 
{
	namespace Core 
	{
		class Vector2
		{
		public:
			float x;
			float y;

			Vector2();
			Vector2(float x_in, float y_in);

			bool operator == (const Vector2& rhs) const;
			bool operator != (const Vector2& rhs) const;

			Vector2 operator + (const Vector2& rhs) const;
			Vector2 operator - (const Vector2& rhs) const;
			Vector2 operator * (const float scale) const;
			Vector2 operator / (const float scale) const;

			void operator += (const Vector2& rhs);
			void operator -= (const Vector2& rhs);
			void operator *= (const float scale);
			void operator /= (const float scale);

			float length() const;
			float distance(const Vector2& rhs) const;
		};
	}
}