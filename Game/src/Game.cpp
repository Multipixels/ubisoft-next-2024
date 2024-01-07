//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include <stdafx.h>

#include "Game.h"
#include "ScenePlay.h"


namespace Game 
{
	void Init()
	{
		ScenePlay defaultScene();

		GameEngine::GameEngine::Instance().addScene(*defaultScene));
		GameEngine::GameEngine::Instance().changeScene(0);
	}
}