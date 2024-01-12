//---------------------------------------------------------------------------------
// AbstractScene.h
//---------------------------------------------------------------------------------
#pragma once

#include <string>
#include <map>

#include "Core/GameObjectManager.h"
#include "Events/Action.h"

namespace MultipixelEngine 
{
	using namespace Core;
	using namespace Events;

	namespace Scene 
	{
		class AbstractScene
		{
			int currentFrame = 0;
			bool paused = false;

			std::map<int, std::string> actionMap;
		protected:
			GameObjectManager gameObjectManager;
		public:
			AbstractScene();

			virtual void init() = 0;
			virtual void update() = 0;
			virtual void sDoAction(Action action) = 0;

			std::vector<GameObject>& getSceneGameObjects();

			std::map<int, std::string> getActionMap();
			void registerAction(int keyId, const std::string actionName);
			void doAction(Action action);
		};
	}
}