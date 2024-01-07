//---------------------------------------------------------------------------------
// GameEngine.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "GameEngine.h"

namespace GameEngine 
{
	GameEngine::GameEngine() {
		Init();
	}

	void GameEngine::init() 
	{
		sceneMap.reserve(10);
		// TODO: Load assets
	}


	void GameEngine::update(float deltaTime)
	{
		auto currentScene = getCurrentScene();
		auto sceneActionMap = currentScene->getActionMap();
		for (auto key : sceneActionMap) 
		{
			if (App::IsKeyPressed(key.first))
			{
				// TODO: find some way to differentiate between press and release
				currentScene->doAction(Actions::Action(key.second, Actions::NONE));
			}
		}

		currentScene->update();
	}

	void GameEngine::render()
	{
		getCurrentScene()->sRender();
	}



	void GameEngine::addScene(std::shared_ptr<Scene::Scene> sceneToAdd)
	{
		sceneMap.push_back(sceneToAdd);
	}

	void GameEngine::changeScene(int sceneID) 
	{
		currentScene = sceneID;
	}


	std::shared_ptr<Scene::Scene> GameEngine::getCurrentScene()
	{
		return sceneMap[currentScene];
	}



	
	void Shutdown()
	{

	}
}