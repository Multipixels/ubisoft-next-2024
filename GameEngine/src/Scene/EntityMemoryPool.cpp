//---------------------------------------------------------------------------------
// EntityMemoryPool.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/EntityMemoryPool.h"

namespace GameEngine
{
	namespace Scene
	{
		EntityMemoryPool::EntityMemoryPool(size_t maxEntities)
		{
			std::vector<CTransform> cTransformVector;
			std::vector<CBoundingBox> cBoundingBoxVector;
			std::vector<CBoundingCircle> cBoundingCircleVector;
			std::vector<CRigidbody> cRigidbodyVector;

			cTransformVector.reserve(maxEntities);
			cBoundingBoxVector.reserve(maxEntities);
			cBoundingCircleVector.reserve(maxEntities);
			cRigidbodyVector.reserve(maxEntities);

			entities = std::make_tuple(
				cTransformVector,
				cBoundingBoxVector,
				cBoundingCircleVector,
				cRigidbodyVector
			);
		}

		size_t EntityMemoryPool::getNextEntityID()
		{
			numOfEntities++;
			return numOfEntities - 1;
		}

		template <typename T>
		bool EntityMemoryPool::hasComponent(size_t entityID)
		{
			T& component = getComponent(entityID);
			return component->exists;
		}

		template <typename T>
		T& EntityMemoryPool::getComponent(size_t entityID)
		{
			return std::get<std::vector<T>>(entities)[entityID];
		}

		template <typename T>
		T& EntityMemoryPool::addComponent(size_t entityID)
		{
			T& component = getComponent(entityID);
			component->exists = true;
		}

		Entity EntityMemoryPool::addEntity()
		{
			size_t entityID = getNextEntityID();

			// ERROR HERE
			std::get<std::vector<CTransform>>(entities)[entityID] = CTransform();
			std::get<std::vector<CBoundingBox>>(entities)[entityID] = CBoundingBox();
			std::get<std::vector<CBoundingCircle>>(entities)[entityID] = CBoundingCircle();
			std::get<std::vector<CRigidbody>>(entities)[entityID] = CRigidbody();

			active[entityID] = true;

			return Entity(entityID);
		}

		void EntityMemoryPool::removeEntity(size_t entityID)
		{
			active[entityID] = false;
		}

	}
}