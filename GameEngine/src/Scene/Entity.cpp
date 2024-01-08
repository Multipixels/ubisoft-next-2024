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
	}
}