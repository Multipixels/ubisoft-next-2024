//------------------------------------------------------------------------
// ScenePlay.h
//------------------------------------------------------------------------
#pragma once

#include <GameEngineManager.h>

namespace Game
{
	using namespace GameEngine::Scene;

	class ScenePlay2 : public Scene 
	{
		void init();

		// Game Specific System Definitions
		void sPhysics();
		void sRender();
		void sDoAction(Action action);

	public:
		ScenePlay2();

		void update();
	};
}