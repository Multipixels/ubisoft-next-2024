//---------------------------------------------------------------------------------
// AbstractScene.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Scene/AbstractScene.h"
#include "GameEngine.h"

namespace MultipixelEngine
{
	namespace Scene
	{
		AbstractScene::AbstractScene()
			: gameObjectManager(GameObjectManager())
		{
		}

		std::vector<GameObject>& AbstractScene::getSceneGameObjects()
		{
			return gameObjectManager.getGameObjects();
		};

		std::map<int, std::string> AbstractScene::getActionMap()
		{
			return actionMap;
		}

		void AbstractScene::registerAction(int keyId, const std::string actionName)
		{
			actionMap[keyId] = actionName;
			GameEngine::Instance();
		}

		void AbstractScene::doAction(Action action)
		{
			sDoAction(action);
		}
	}
}