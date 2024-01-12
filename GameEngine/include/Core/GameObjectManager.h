//---------------------------------------------------------------------------------
// GameObjectManager.h
//---------------------------------------------------------------------------------
#pragma once

#include <vector>

#include "Core/GameObject.h"
#include "Core/GameObjectMemoryPool.h"

namespace MultipixelEngine 
{
	namespace Core
	{
		class GameObjectManager
		{
			std::vector<GameObject> gameObjects;
			std::vector<GameObject> gameObjectsToAdd;
			
		public:
			GameObjectManager();

			GameObject createGameObject();
			void destroyEntity(size_t gameObjectId);
			
			std::vector<GameObject>& getGameObjects();
		};
	}
}