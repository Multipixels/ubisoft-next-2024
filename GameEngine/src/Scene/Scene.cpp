//---------------------------------------------------------------------------------
// EntityMemoryPool.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/Scene.h"

namespace GameEngine
{
	namespace Scene
	{
		std::map<int, std::string> Scene::getActionMap()
		{
			return actionMap;
		}

		void Scene::registerAction(int keyID, const std::string actionName)
		{
			actionMap[keyID] = actionName;
		}

		void Scene::doAction(Action action)
		{
			sDoAction(action);
		}
	}
}