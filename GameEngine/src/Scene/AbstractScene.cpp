//---------------------------------------------------------------------------------
// AbstractScene.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/AbstractScene.h"
#include "GameEngineManager.h"

namespace GameEngine
{
	namespace Scene
	{
		AbstractScene::AbstractScene()
			: entityManager(EntityManager())
		{
		}

		std::map<int, std::string> AbstractScene::getActionMap()
		{
			return actionMap;
		}

		void AbstractScene::registerAction(int keyID, const std::string actionName)
		{
			actionMap[keyID] = actionName;
			GameEngineManager::Instance();
		}

		void AbstractScene::doAction(Action action)
		{
			sDoAction(action);
		}
	}
}