#pragma once

namespace GameEngine 
{
	namespace Scene 
	{
		class Entity 
		{
			friend class EntityMemoryPool;

			size_t entityID;
			Entity(size_t idIn);
		public:
			void destroy();

			template<typename T>
			bool hasComponent();

			template<typename T>
			T& getComponent();

			template<typename T>
			void addComponent();
		};
	}
}