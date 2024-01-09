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
		sceneMap.reserve(10);
	}
	
	void GameEngineManager::update(float deltaTime)
	{
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
		if (currentSceneIndex != -1)
		{
			getCurrentScene()->sRender();
		}
	}

	void GameEngineManager::addScene(std::shared_ptr<Scene::Scene> sceneToAdd)
	{
		sceneMap.push_back(sceneToAdd);
	}

	void GameEngineManager::changeScene(int sceneID)
	{
		currentSceneIndex = sceneID;
	}

	std::shared_ptr<Scene::Scene> GameEngineManager::getCurrentScene()
	{
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