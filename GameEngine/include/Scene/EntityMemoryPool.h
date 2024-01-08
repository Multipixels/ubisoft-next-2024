//---------------------------------------------------------------------------------
// EntityMemoryPool.h
//---------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <tuple>
#include <memory>

#include "Scene/Entity.h"
#include "Scene/Components.h"

#define MAX_ENTITIES 1000

namespace GameEngine
{
	namespace Scene
	{
		typedef std::tuple<
			std::vector<CTransform>,
			std::vector<CBoundingBox>,
			std::vector<CBoundingCircle>,
			std::vector<CRigidbody>
		> ComponentContainer;

		class EntityMemoryPool
		{
			size_t numOfEntities = 0;
			ComponentContainer entities;
			std::vector<bool> active;

			EntityMemoryPool(size_t maxEntities);

			size_t getNextEntityID();
		public:
			static EntityMemoryPool& Instance() 
			{
				static EntityMemoryPool entityMemoryPool(MAX_ENTITIES);
				return entityMemoryPool;
			}

			template <typename T>
			bool hasComponent(size_t entityID)
			{
				T& component = getComponent<T>(entityID);
				return component.exists;
			}

			template <typename T>
			T& getComponent(size_t entityID)
			{
				return std::get<std::vector<T>>(entities)[entityID];
			}

			template <typename T>
			T& addComponent(size_t entityID)
			{
				T& component = getComponent<T>(entityID);
				component.exists = true;
				return component;
			}

			Entity addEntity();
			void removeEntity(size_t entityID);
		};
	}
}