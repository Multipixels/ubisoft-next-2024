//---------------------------------------------------------------------------------
// RenderSystem.cpp
//---------------------------------------------------------------------------------
#include "stdafx.h"

#include "Core/RenderSystem.h"
#include "App/app.h"

namespace MultipixelEngine
{
	namespace Core
	{
		RenderSystem::RenderSystem()
		{
			
		}

		void RenderSystem::render(std::shared_ptr<Scene::AbstractScene> sceneToRender)
		{
			for (auto gameObject : sceneToRender->getSceneGameObjects())
			{
				if (gameObject.hasComponent<CTransform>())
				{
					if (gameObject.hasComponent<CBoundingBox>()) renderWireFrames(gameObject);
					if (gameObject.hasComponent<UIText>()) renderUI(gameObject);
				}
			}
		}

		void RenderSystem::renderWireFrames(GameObject& gameObject)
		{
			auto& cTransform = gameObject.getComponent<CTransform>();
			auto& cBB = gameObject.getComponent<CBoundingBox>();

			App::DrawLine(
				cTransform.position.x - cBB.size.x / 2, cTransform.position.y - cBB.size.y / 2,
				cTransform.position.x - cBB.size.x / 2, cTransform.position.y + cBB.size.y / 2,
				1, 1, 1);

			App::DrawLine(
				cTransform.position.x - cBB.size.x / 2, cTransform.position.y - cBB.size.y / 2,
				cTransform.position.x + cBB.size.x / 2, cTransform.position.y - cBB.size.y / 2,
				1, 1, 1);

			App::DrawLine(
				cTransform.position.x + cBB.size.x / 2, cTransform.position.y + cBB.size.y / 2,
				cTransform.position.x - cBB.size.x / 2, cTransform.position.y + cBB.size.y / 2,
				1, 1, 1);

			App::DrawLine(
				cTransform.position.x + cBB.size.x / 2, cTransform.position.y + cBB.size.y / 2,
				cTransform.position.x + cBB.size.x / 2, cTransform.position.y - cBB.size.y / 2,
				1, 1, 1);
		}

		void RenderSystem::renderUI(GameObject& gameObject)
		{
			auto& cTransform = gameObject.getComponent<CTransform>();
			auto& uiText = gameObject.getComponent<UIText>();

			App::Print(cTransform.position.x, cTransform.position.y, uiText.text.c_str());
		}
	}
}