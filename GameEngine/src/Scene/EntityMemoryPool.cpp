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
			std::vector<CTransform> cTransformVector(maxEntities);
			std::vector<CBoundingBox> cBoundingBoxVector(maxEntities);
			std::vector<CBoundingCircle> cBoundingCircleVector(maxEntities);
			std::vector<CRigidbody> cRigidbodyVector(maxEntities);


			/*CTransformVector.reserve(maxEntities);
			cBoundingBoxVector.reserve(maxEntities);
			cBoundingCircleVector.reserve(maxEntities);
			cRigidbodyVector.reserve(maxEntities);*/

			entities = std::make_tuple(
				cTransformVector,
				cBoundingBoxVector,
				cBoundingCircleVector,
				cRigidbodyVector
			);

			active = std::vector<bool>(maxEntities);
		}

		size_t EntityMemoryPool::getNextEntityID()
		{
			numOfEntities++;
			return numOfEntities - 1;
		}

		Entity EntityMemoryPool::addEntity()
		{
			size_t entityID = getNextEntityID();

			// ERROR HERE
			std::get<std::vector<CTransform>>(entities).insert(std::get<std::vector<CTransform>>(entities).begin(), entityID, CTransform());
			std::get<std::vector<CBoundingBox>>(entities).insert(std::get<std::vector<CBoundingBox>>(entities).begin(), entityID, CBoundingBox());
			std::get<std::vector<CBoundingCircle>>(entities).insert(std::get<std::vector<CBoundingCircle>>(entities).begin(), entityID, CBoundingCircle());
			std::get<std::vector<CRigidbody>>(entities).insert(std::get<std::vector<CRigidbody>>(entities).begin(), entityID, CRigidbody());

			active[entityID] = true;

			return Entity(entityID);
		}

		void EntityMemoryPool::removeEntity(size_t entityID)
		{
			active[entityID] = false;
		}

	}
}