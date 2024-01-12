//---------------------------------------------------------------------------------
// GameEngine.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "GameEngine.h"

namespace MultipixelEngine 
{
	GameEngine::GameEngine() 
		: sceneManager(SceneManager::Instance())
	{
		init();
	}

	void GameEngine::init()
	{
		// TODO: Load assets

		// Reverts option set in main.cpp,
		// Fixes a bug with the assert macro in which it will return to the code that would have caused an exception.
		glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_EXIT);
	}
	
	void GameEngine::update(float deltaTime)
	{
		if (crashed)
		{
			crashScene->update();
			return;
		}

		if (sceneManager.getCurrentSceneIndex() == -1)
		{
			return;
		}

		auto currentSceneObject = sceneManager.getCurrentScene();
		auto sceneActionMap = currentSceneObject->getActionMap();

		// For every desired key, check if it's pressed
		// Trigger an Action if state of key press changes.
		for (auto key : sceneActionMap) 
		{
			if (App::IsKeyPressed(key.first))
			{
				if (previousKeyStates[key.first] != Events::PRESS)
				{
					currentSceneObject->doAction(Events::Action(key.second, Events::PRESS));
					previousKeyStates[key.first] = Events::PRESS;
				}
			}
			else {
				// Prevent release event from occuring on first frame
				if (previousKeyStates[key.first] == Events::NONE)
				{
					continue;
				}

				if (previousKeyStates[key.first] != Events::RELEASE)
				{
					currentSceneObject->doAction(Events::Action(key.second, Events::RELEASE));
					previousKeyStates[key.first] = Events::RELEASE;
				}
			}
		}

		currentSceneObject->update();
	}

	void GameEngine::render()
	{
		if (crashed)
		{
			crashScene->sRender();
			return;
		}
		sceneManager.getCurrentScene()->sRender();
	}

	void GameEngine::crash(std::string message)
	{
		if (crashed) return;

		crashed = true;
		crashScene = std::make_shared<ErrorScene>(message);
		crashScene->sRender();
		glutMainLoop();
	}

	void GameEngine::crash()
	{
		crashed = true;
		crashScene = std::make_shared<ErrorScene>("");
	}

	void GameEngine::registerAction(int actionKey)
	{
		previousKeyStates[actionKey] = Events::NONE;
	}
}

void Update(float deltaTime) 
{ 
	MultipixelEngine::GameEngine::Instance().update(deltaTime);
}

void Render() 
{ 
	MultipixelEngine::GameEngine::Instance().render();
}

void Shutdown()
{

}