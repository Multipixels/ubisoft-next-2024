//------------------------------------------------------------------------
// ErrorScene.h
//------------------------------------------------------------------------
#pragma once

#include "Scene/AbstractScene.h"

namespace MultipixelEngine
{
	using namespace Scene;

	class ErrorScene : public AbstractScene
	{
		std::string errorMessage;
	public:
		ErrorScene(std::string message);

		void init();
		void sDoAction(Action action);
		void update();
	};
}