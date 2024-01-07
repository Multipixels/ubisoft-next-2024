//---------------------------------------------------------------------------------
// Entity.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/Entity.h"
#include "Scene/EntityMemoryPool.h"

namespace GameEngine
{
	namespace Scene
	{
		Entity::Entity(size_t idIn) 
			: entityID(idIn)
		{

		}

		void Entity::destroy() 
		{
			EntityMemoryPool::Instance().removeEntity(entityID);
		}

		template<typename T>
		bool Entity::hasComponent() 
		{
			return EntityMemoryPool::Instance().hasComponent<T>(entityID);
		}

		template<typename T>
		T& getComponent() 
		{
			return EntityMemoryPool::Instance().getComponent<T>(entityID);
		}

		template<typename T>
		void addComponent() 
		{
			return EntityMemoryPool::Instance().addComponent<T>(entityID);
		}

	}
}