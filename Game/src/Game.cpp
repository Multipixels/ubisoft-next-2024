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
		std::shared_ptr<ScenePlay> a;// = std::make_shared<ScenePlay>();
		std::shared_ptr<ScenePlay> b;// = std::make_shared<ScenePlay>();
		a.reset(new ScenePlay);

		GameEngine::GameEngineManager::Instance().addScene(a);
		//GameEngine::GameEngineManager::Instance().addScene(b);
		GameEngine::GameEngineManager::Instance().changeScene(0);
	}
}