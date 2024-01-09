//---------------------------------------------------------------------------------
// AbstractScene.h
//---------------------------------------------------------------------------------
#pragma once

#include <string>
#include <map>

#include "Scene/EntityManager.h"
#include "Actions/Action.h"

namespace GameEngine 
{
	namespace Scene 
	{
		using namespace Actions;

		class AbstractScene
		{
			int currentFrame = 0;
			bool paused = false;

			std::map<int, std::string> actionMap;
		protected:
			EntityManager entityManager;
		public:
			AbstractScene();

			virtual void init() = 0;
			virtual void update() = 0;
			virtual void sDoAction(Action action) = 0;
			virtual void sRender() = 0;

			std::map<int, std::string> getActionMap();
			void registerAction(int keyID, const std::string actionName);
			void doAction(Action action);
		};
	}
}