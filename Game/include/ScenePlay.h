//------------------------------------------------------------------------
// ScenePlay.h
//------------------------------------------------------------------------
#pragma once

#include <GameEngine.h>

namespace Game
{
	using namespace GameEngine::Scene;

	class ScenePlay : public Scene 
	{
		void init();

		// Game Specific System Definitions
		void sCollision();
		void sRender();
		void sDoAction(Action action);

	public:
		ScenePlay();

		void update();
	};
}