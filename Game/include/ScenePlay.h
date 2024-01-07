#pragma once

#include <GameEngine.h>

namespace Game
{
	using namespace GameEngine::Scene;

	class ScenePlay : Scene 
	{
		void init();

		// Game Specific System Definitions
		void sCollision();
		void sRender();
		void sDoAction();

	public:
		ScenePlay();

		void update();
	};
}