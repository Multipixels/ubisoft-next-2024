//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include <stdafx.h>

#include "Game.h"
#include "ScenePlay.h"

void Init() { Game::Init(); }

namespace Game 
{
	void Init()
	{
		std::shared_ptr<ScenePlay> a;
		a.reset(new ScenePlay);

		GameEngine::GameEngine::Instance().addScene(a);
		GameEngine::GameEngine::Instance().changeScene(0);
	}
}