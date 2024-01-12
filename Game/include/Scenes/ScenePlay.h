//------------------------------------------------------------------------
// ScenePlay.h
//------------------------------------------------------------------------
#pragma once

#include <GameEngine.h>

namespace Game
{
	using namespace MultipixelEngine::Core;
	using namespace MultipixelEngine::Events;
	using namespace MultipixelEngine::Scene;

	class ScenePlay : public AbstractScene
	{
		GameObject inputMessage;

		void init();

		// Game Specific System Definitions
		void sPhysics();
		void sDoAction(Action action);

	public:
		ScenePlay();

		void update();
	};
}