//---------------------------------------------------------------------------------
// EntityManager.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/EntityManager.h"
#include "Scene/EntityMemoryPool.h"

namespace GameEngine
{
	namespace Scene
	{
		EntityManager::EntityManager()
		{
			entities.reserve(MAX_ENTITIES);
			entitiesToAdd.reserve(MAX_ENTITIES);
		}

		Entity EntityManager::createEntity()
		{
			Entity e = EntityMemoryPool::Instance().addEntity();
			//TODO: entity buffer
			//entitiesToAdd.push_back(e);
			entities.push_back(e);
			return e;
		}

		void EntityManager::destroyEntity(size_t entityID)
		{
			EntityMemoryPool::Instance().removeEntity(entityID);
		}

		std::vector<Entity>& EntityManager::getEntities() {
			return entities;
		}

	}
}