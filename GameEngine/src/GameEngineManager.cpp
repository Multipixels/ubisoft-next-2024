//---------------------------------------------------------------------------------
// GameEngine.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "GameEngineManager.h"

namespace GameEngine 
{
	GameEngineManager::GameEngineManager() {
		init();
	}

	void GameEngineManager::init()
	{
		// TODO: Load assets



		// Reverts option set in main.cpp,
		// Fixes a bug with the assert macro in which it will return to the code that would have caused an exception.
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_EXIT);
	}
	
	void GameEngineManager::update(float deltaTime)
	{
		if (crashed)
		{
			crashScene->update();
			return;
		}

		if (currentSceneIndex == -1)
		{
			return;
		}

		auto currentSceneObject = getCurrentScene();
		auto sceneActionMap = currentSceneObject->getActionMap();

		// For every desired key, check if it's pressed
		// Trigger an Action if state of key press changes.
		for (auto key : sceneActionMap) 
		{
			if (App::IsKeyPressed(key.first))
			{
				if (previousKeyStates[key.first] != Actions::PRESS)
				{
					currentSceneObject->doAction(Actions::Action(key.second, Actions::PRESS));
					previousKeyStates[key.first] = Actions::PRESS;
				}
			}
			else {
				// Prevent release event from occuring on first frame
				if (previousKeyStates[key.first] == Actions::NONE)
				{
					continue;
				}

				if (previousKeyStates[key.first] != Actions::RELEASE)
				{
					currentSceneObject->doAction(Actions::Action(key.second, Actions::RELEASE));
					previousKeyStates[key.first] = Actions::RELEASE;
				}
			}
		}

		currentSceneObject->update();
	}

	void GameEngineManager::render()
	{
		if (crashed)
		{
			crashScene->sRender();
			return;
		}
		getCurrentScene()->sRender();
	}

	void GameEngineManager::crash(std::string message)
	{
		if (crashed) return;

		crashed = true;
		crashScene = std::make_shared<ErrorScene>(message);
		crashScene->sRender();
		glutMainLoop();
	}

	void GameEngineManager::crash()
	{
		crashed = true;
		crashScene = std::make_shared<ErrorScene>("");
	}

	void GameEngineManager::addScene(std::shared_ptr<Scene::AbstractScene> sceneToAdd)
	{
		// TODO: GET NEW KEY
		sceneMap[0] = (sceneToAdd);
	}

	void GameEngineManager::changeScene(int sceneID)
	{
		currentSceneIndex = sceneID;
		getCurrentScene()->init();
	}

	std::shared_ptr<Scene::AbstractScene> GameEngineManager::getCurrentScene()
	{
		ASSERT(sceneMap.count(currentSceneIndex), "Could not get current scene");
		return sceneMap[currentSceneIndex];
	}

	void GameEngineManager::registerAction(int actionKey) 
	{
		previousKeyStates[actionKey] = Actions::NONE;
	}
}

void Update(float deltaTime) 
{ 
	GameEngine::GameEngineManager::Instance().update(deltaTime);
}

void Render() 
{ 
	GameEngine::GameEngineManager::Instance().render();
}

void Shutdown()
{

}