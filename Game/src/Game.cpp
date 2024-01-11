//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include <stdafx.h>

#include "Game.h"
#include "Scenes/ScenePlay.h"
#include "Scenes/ScenePlay2.h"

void Init() { Game::Init(); }

namespace Game 
{
	void Init()
	{
		std::shared_ptr<ScenePlay> a = std::make_shared<ScenePlay>();
		std::shared_ptr<ScenePlay2> b = std::make_shared<ScenePlay2>();
		a.reset(new ScenePlay);
		b.reset(new ScenePlay2);

		MultipixelEngine::GameEngine::Instance().addScene(a);
		MultipixelEngine::GameEngine::Instance().addScene(b);
		MultipixelEngine::GameEngine::Instance().changeScene(0);
	}
}