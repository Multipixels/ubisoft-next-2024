//------------------------------------------------------------------------
// ScenePlay.h
//------------------------------------------------------------------------
#pragma once

#include <GameEngine.h>

namespace Game
{
	using namespace MultipixelEngine::Events;
	using namespace MultipixelEngine::Scene;

	class ScenePlay : public AbstractScene
	{
		void init();

		// Game Specific System Definitions
		void sPhysics();
		void sRender();
		void sDoAction(Action action);

	public:
		ScenePlay();

		void update();
	};
}