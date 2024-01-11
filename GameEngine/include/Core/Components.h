//---------------------------------------------------------------------------------
// Components.h
//---------------------------------------------------------------------------------
#pragma once

#include "Core/Vector2.h"

namespace MultipixelEngine 
{
	namespace Core 
	{
		struct Component 
		{
		public:
			bool exists = false;
		};

		struct CTransform : Component 
		{
		public:
			Vector2 position = Vector2();
			Vector2 previousPosition = Vector2();
			Vector2 scale = Vector2(1, 1);

			CTransform() {};
		};

		struct CBoundingBox : Component
		{
		public:
			Vector2 size = Vector2();

			CBoundingBox() = default;
		};

		struct CBoundingCircle : Component
		{
		public:
			float radius = 0;

			CBoundingCircle() = default;
		};

		struct CRigidbody : Component
		{
			bool isKinematic = false;
			bool useGravity = false;

			Vector2 velocity = Vector2();
		};
	}
}