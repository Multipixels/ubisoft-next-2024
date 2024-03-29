//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include <stdafx.h>

#include "Game.h"
#include "Scenes/ScenePlay.h"
#include "Scenes/ScenePlay2.h"

void Init() { Game::Init(); }

using namespace MultipixelEngine::Scene;

namespace Game 
{
	void Init()
	{
		std::shared_ptr<ScenePlay> a = std::make_shared<ScenePlay>();
		std::shared_ptr<ScenePlay2> b = std::make_shared<ScenePlay2>();
		a.reset(new ScenePlay);
		b.reset(new ScenePlay2);

		SceneManager::Instance().addScene(a);
		SceneManager::Instance().addScene(b);
		SceneManager::Instance().changeScene(0);
	}
}