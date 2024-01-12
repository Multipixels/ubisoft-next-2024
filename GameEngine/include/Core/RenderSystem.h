//---------------------------------------------------------------------------------
// RenderSystem.h
//---------------------------------------------------------------------------------
#pragma once

#include <memory>

#include "Scene/AbstractScene.h"

namespace MultipixelEngine
{
	namespace Core
	{
		class RenderSystem
		{
			RenderSystem();

			void renderWireFrames(GameObject& gameObject);
			void renderUI(GameObject& gameObject);
		public:
			static RenderSystem& Instance()
			{
				static RenderSystem renderSystem;
				return renderSystem;
			}

			void render(std::shared_ptr<Scene::AbstractScene> sceneToRender);
		};
	}
}
