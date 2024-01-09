//------------------------------------------------------------------------
// Game.cpp
//------------------------------------------------------------------------
#include <stdafx.h>

#include "Game.h"
#include "ScenePlay.h"
#include "ScenePlay2.h"

void Init() { Game::Init(); }

namespace Game 
{
	void Init()
	{
		std::shared_ptr<ScenePlay> a = std::make_shared<ScenePlay>();
		std::shared_ptr<ScenePlay2> b = std::make_shared<ScenePlay2>();
		//a.reset(new ScenePlay);
		//b.reset(new ScenePlay2);

		//GameEngine::GameEngineManager::Instance().addScene(a);
		//GameEngine::GameEngineManager::Instance().addScene(b);
		GameEngine::GameEngineManager::Instance().changeScene(0);
	}
}