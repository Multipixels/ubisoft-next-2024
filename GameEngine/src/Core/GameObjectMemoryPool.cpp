//---------------------------------------------------------------------------------
// GameObjectMemoryPool.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Core/GameObjectMemoryPool.h"

namespace MultipixelEngine
{
	namespace Core
	{
		GameObjectMemoryPool::GameObjectMemoryPool(size_t maxGameObjects)
		{
			std::vector<CTransform> cTransformVector(maxGameObjects);
			std::vector<CBoundingBox> cBoundingBoxVector(maxGameObjects);
			std::vector<CBoundingCircle> cBoundingCircleVector(maxGameObjects);
			std::vector<CRigidbody> cRigidbodyVector(maxGameObjects);
			std::vector<UIText> uiTextVector(maxGameObjects);

			/*cTransformVector.reserve(maxGameObjects);
			cBoundingBoxVector.reserve(maxGameObjects);
			cBoundingCircleVector.reserve(maxGameObjects);
			cRigidbodyVector.reserve(maxGameObjects);
			uiText.reserve(maxGameObjects);*/

			gameObjects = std::make_tuple(
				cTransformVector,
				cBoundingBoxVector,
				cBoundingCircleVector,
				cRigidbodyVector,
				uiTextVector
			);

			activeGameObjects = std::vector<bool>(maxGameObjects);
		}

		size_t GameObjectMemoryPool::getNextGameObjectId()
		{
			numOfGameObjects++;
			return numOfGameObjects - 1;
		}

		GameObject GameObjectMemoryPool::addGameObject()
		{
			size_t gameObjectId = getNextGameObjectId();

			std::get<std::vector<CTransform>>(gameObjects).insert(std::get<std::vector<CTransform>>(gameObjects).begin(), gameObjectId, CTransform());
			std::get<std::vector<CBoundingBox>>(gameObjects).insert(std::get<std::vector<CBoundingBox>>(gameObjects).begin(), gameObjectId, CBoundingBox());
			std::get<std::vector<CBoundingCircle>>(gameObjects).insert(std::get<std::vector<CBoundingCircle>>(gameObjects).begin(), gameObjectId, CBoundingCircle());
			std::get<std::vector<CRigidbody>>(gameObjects).insert(std::get<std::vector<CRigidbody>>(gameObjects).begin(), gameObjectId, CRigidbody());
			std::get<std::vector<UIText>>(gameObjects).insert(std::get<std::vector<UIText>>(gameObjects).begin(), gameObjectId, UIText());

			activeGameObjects[gameObjectId] = true;

			return GameObject(gameObjectId);
		}

		void GameObjectMemoryPool::removeGameObject(size_t gameObjectId)
		{
			activeGameObjects[gameObjectId] = false;
		}

	}
}