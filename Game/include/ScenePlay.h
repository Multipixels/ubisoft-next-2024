#pragma once

#include <GameEngine.h>

namespace Game
{
	class ScenePlay : Scene 
	{
		void init();

		// Game Specific System Definitions
		void sCollision();
		void sRender();
		void sDoAction();

	public:
		ScenePlay() = default;

		void update();
	};
}