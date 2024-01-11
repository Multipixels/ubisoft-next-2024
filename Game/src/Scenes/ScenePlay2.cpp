//------------------------------------------------------------------------
// ScenePlay.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "Scenes/ScenePlay2.h"

using namespace MultipixelEngine::Core;
using namespace MultipixelEngine::Events;
using namespace MultipixelEngine::Scene;

namespace Game
{
	std::string b = "";

	ScenePlay2::ScenePlay2()
	{
	}

	void ScenePlay2::init()
	{
		registerAction('W', "UP");
		registerAction('S', "DOWN");
		registerAction('A', "LEFT");
		registerAction('D', "RIGHT");

		GameObject e = gameObjectManager.createGameObject();
		e.addComponent<CTransform>();
		e.addComponent<CBoundingBox>();
		e.getComponent<CBoundingBox>().size = Vector2(100, 100);
		e.getComponent<CTransform>().position = Vector2(700, 500);
	}

	void ScenePlay2::update()
	{
	
	}

	void ScenePlay2::sPhysics()
	{

	}

	void ScenePlay2::sRender()
	{
		App::Print(500, 500, b.c_str(), 0.5f, 0.5f, 0.5f);

		for (auto entity : gameObjectManager.getGameObjects())
		{
			if (entity.hasComponent<CTransform>() && entity.hasComponent<CBoundingBox>())
			{
				auto& transform = entity.getComponent<CTransform>();
				auto& bb = entity.getComponent<CBoundingBox>();

				App::DrawLine(
					transform.position.x - bb.size.x / 2, transform.position.y - bb.size.y / 2,
					transform.position.x - bb.size.x / 2, transform.position.y + bb.size.y / 2,
					1, 1, 1);

				App::DrawLine(
					transform.position.x - bb.size.x / 2, transform.position.y - bb.size.y / 2,
					transform.position.x + bb.size.x / 2, transform.position.y - bb.size.y / 2,
					1, 1, 1);

				App::DrawLine(
					transform.position.x + bb.size.x / 2, transform.position.y + bb.size.y / 2,
					transform.position.x - bb.size.x / 2, transform.position.y + bb.size.y / 2,
					1, 1, 1);

				App::DrawLine(
					transform.position.x + bb.size.x / 2, transform.position.y + bb.size.y / 2,
					transform.position.x + bb.size.x / 2, transform.position.y - bb.size.y / 2,
					1, 1, 1);
			}
		}
	}

	void ScenePlay2::sDoAction(Action action)
	{
		b = action.toString();
		if (action.name() == "UP" && action.type() == PRESS)
		{
			MultipixelEngine::GameEngine::Instance().changeScene(0);
		}
	}
}