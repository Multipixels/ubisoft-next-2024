//---------------------------------------------------------------------------------
// GameObjectManager.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Core/GameObjectManager.h"
#include "Core/GameObjectMemoryPool.h"

namespace MultipixelEngine
{
	namespace Core
	{
		GameObjectManager::GameObjectManager()
		{
			gameObjects.reserve(MAX_GAMEOBJECTS);
			gameObjectsToAdd.reserve(MAX_GAMEOBJECTS);
		}

		GameObject GameObjectManager::createGameObject()
		{
			GameObject e = GameObjectMemoryPool::Instance().addGameObject();
			//TODO: entity buffer
			//entitiesToAdd.push_back(e);
			gameObjects.push_back(e);
			return e;
		}

		void GameObjectManager::destroyEntity(size_t entityID)
		{
			GameObjectMemoryPool::Instance().removeGameObject(entityID);
		}

		std::vector<GameObject>& GameObjectManager::getGameObjects() {
			return gameObjects;
		}
	}
}