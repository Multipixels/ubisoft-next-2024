//---------------------------------------------------------------------------------
// GameObject.h
//---------------------------------------------------------------------------------
#pragma once

#include "Core/Components.h"

namespace MultipixelEngine 
{
	namespace Core 
	{
		class GameObject
		{
			friend class GameObjectMemoryPool;

			size_t gameObjectId;
			GameObject(size_t idIn);
		public:
			void destroy();

			template<typename T>
			bool hasComponent()
			{
				return GameObjectMemoryPool::Instance().hasComponent<T>(gameObjectId);
			}

			template<typename T>
			T& getComponent()
			{
				return GameObjectMemoryPool::Instance().getComponent<T>(gameObjectId);
			}

			template<typename T>
			T& addComponent()
			{
				return GameObjectMemoryPool::Instance().addComponent<T>(gameObjectId);
			}
		};
	}
}
