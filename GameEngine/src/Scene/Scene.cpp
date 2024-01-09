//---------------------------------------------------------------------------------
// Scene.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/Scene.h"
#include "GameEngineManager.h"

namespace GameEngine
{
	namespace Scene
	{
		Scene::Scene()
			: entityManager(EntityManager())
		{
		}

		std::map<int, std::string> Scene::getActionMap()
		{
			return actionMap;
		}

		void Scene::registerAction(int keyID, const std::string actionName)
		{
			actionMap[keyID] = actionName;
			GameEngineManager::Instance();
		}

		void Scene::doAction(Action action)
		{
			sDoAction(action);
		}
	}
}