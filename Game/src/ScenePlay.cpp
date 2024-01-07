//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "ScenePlay.h"

using namespace GameEngine::Scene;

namespace Game
{
	void ScenePlay::init()
	{
		registerAction('W', "UP");
		registerAction('S', "DOWN");
		registerAction('A', "LEFT");
		registerAction('D', "RIGHT");
	}

	void ScenePlay::update()
	{

	}

	void ScenePlay::sCollision()
	{

	}

	void ScenePlay::sRender()
	{

	}

	void ScenePlay::sDoAction()
	{

	}
}