//---------------------------------------------------------------------------------
// GameEngine.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "GameEngine.h"

namespace MultipixelEngine 
{
	GameEngine::GameEngine() 
		: sceneManager(SceneManager::Instance()),
		  eventManager(EventManager::Instance())
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

		EventManager::Instance().detectEvent();

		sceneManager.getCurrentScene()->update();
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