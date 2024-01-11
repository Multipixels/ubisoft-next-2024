//---------------------------------------------------------------------------------
// GameObjectMemoryPool.h
//---------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <tuple>

#include "Core/GameObject.h"
#include "Core/Components.h"

#define MAX_GAMEOBJECTS 1000

namespace MultipixelEngine
{
	namespace Core
	{
		typedef std::tuple<
			std::vector<CTransform>,
			std::vector<CBoundingBox>,
			std::vector<CBoundingCircle>,
			std::vector<CRigidbody>
		> ComponentContainer;

		class GameObjectMemoryPool
		{
			size_t numOfGameObjects = 0;
			ComponentContainer gameObjects;
			std::vector<bool> activeGameObjects;

			GameObjectMemoryPool(size_t maxGameObjects);

			size_t getNextGameObjectId();
		public:
			static GameObjectMemoryPool& Instance()
			{
				static GameObjectMemoryPool gameObjectMemoryPool(MAX_GAMEOBJECTS);
				return gameObjectMemoryPool;
			}

			template <typename T>
			bool hasComponent(size_t gameObjectId)
			{
				T& component = getComponent<T>(gameObjectId);
				return component.exists;
			}

			template <typename T>
			T& getComponent(size_t gameObjectId)
			{
				return std::get<std::vector<T>>(gameObjects)[gameObjectId];
			}

			template <typename T>
			T& addComponent(size_t gameObjectId)
			{
				T& component = getComponent<T>(gameObjectId);
				component.exists = true;
				return component;
			}

			GameObject addGameObject();
			void removeGameObject(size_t gameObjectId);
		};
	}
}