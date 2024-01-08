//---------------------------------------------------------------------------------
// Entity.h
//---------------------------------------------------------------------------------
#pragma once

#include "Scene/Components.h"

namespace GameEngine 
{
	namespace Scene 
	{
		class Entity 
		{
			friend class EntityMemoryPool;

			size_t entityID;
			Entity(size_t idIn);
		public:
			void destroy();

			template<typename T>
			bool hasComponent()
			{
				return EntityMemoryPool::Instance().hasComponent<T>(entityID);
			}

			template<typename T>
			T& getComponent()
			{
				return EntityMemoryPool::Instance().getComponent<T>(entityID);
			}

			template<typename T>
			T& addComponent()
			{
				return EntityMemoryPool::Instance().addComponent<T>(entityID);
			}
		};
	}
}
