//---------------------------------------------------------------------------------
// EntityManager.h
//---------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <tuple>
#include <memory>

#include "Scene/Entity.h"

namespace GameEngine 
{
	namespace Scene
	{
		class EntityManager
		{
			std::vector<Entity> entities;
			std::vector<Entity> entitiesToAdd;
			
		public:
			EntityManager();

			Entity createEntity();
			void destroyEntity(size_t entityID);
			
			std::vector<Entity>& getEntities();
		};
	}
}