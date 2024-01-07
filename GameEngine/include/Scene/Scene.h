#pragma once

#include "EntityManager.h"

#include <string>
#include <map>
#include "Actions/Action.h"

namespace GameEngine 
{
	namespace Scene 
	{
		using namespace Actions;

		class Scene 
		{
			EntityManager entities;
			int currentFrame;
			bool paused;

			std::map<int, std::string> actionMap;
		public:
			Scene() = default;

			virtual void update() = 0;
			virtual void sDoAction(Action action) = 0;
			virtual void sRender() = 0;

			std::map<int, std::string> getActionMap();
			void registerAction(int keyID, const std::string actionName);
			void doAction(Action action);
		};
	}
}