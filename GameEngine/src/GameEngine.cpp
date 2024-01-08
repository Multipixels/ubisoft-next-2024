//---------------------------------------------------------------------------------
// GameEngine.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "GameEngine.h"

namespace GameEngine 
{
	GameEngine::GameEngine() {
		init();
	}

	void GameEngine::init() 
	{
		sceneMap.reserve(10);
		// TODO: Load assets
	}


	void GameEngine::update(float deltaTime)
	{
		if (currentScene == -1)
		{
			return;
		}

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
		if (currentScene != -1) 
		{
			getCurrentScene()->sRender();
		}
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
}

void Update(float deltaTime) 
{ 
	GameEngine::GameEngine::Instance().update(deltaTime); 
}

void Render() 
{ 
	GameEngine::GameEngine::Instance().render(); 
}

void Shutdown()
{

}