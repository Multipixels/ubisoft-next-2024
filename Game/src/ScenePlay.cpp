//------------------------------------------------------------------------
// ScenePlay.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "ScenePlay.h"

using namespace GameEngine::Core;
using namespace GameEngine::Scene;
using namespace GameEngine::Actions;

namespace Game
{
	ScenePlay::ScenePlay()
	{
		init();
	}

	void ScenePlay::init()
	{
		registerAction('W', "UP");
		registerAction('S', "DOWN");
		registerAction('A', "LEFT");
		registerAction('D', "RIGHT");

		Entity e = entityManager.createEntity();
		e.hasComponent<CTransform>();
		e.addComponent<CTransform>();
		e.addComponent<CBoundingBox>();
		e.getComponent<CBoundingBox>().size = Vector2(100, 100);
		e.getComponent<CTransform>().position = Vector2(500, 500);
	}

	void ScenePlay::update()
	{

	}

	void ScenePlay::sCollision()
	{

	}

	void ScenePlay::sRender()
	{
		App::Print(500, 500, "hi", 0.5f, 0.5f, 0.5f);
		for (auto entity : entityManager.getEntities())
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

	void ScenePlay::sDoAction(Action action)
	{

	}
}