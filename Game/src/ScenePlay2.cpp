//------------------------------------------------------------------------
// ScenePlay.cpp
//------------------------------------------------------------------------
#include "stdafx.h"

#include "ScenePlay2.h"

using namespace GameEngine::Core;
using namespace GameEngine::Scene;
using namespace GameEngine::Actions;

namespace Game
{
	std::string b = "";

	ScenePlay2::ScenePlay2()
	{
		init();
	}

	void ScenePlay2::init()
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

	void ScenePlay2::update()
	{
	
	}

	void ScenePlay2::sPhysics()
	{

	}

	void ScenePlay2::sRender()
	{
		App::Print(500, 500, b.c_str(), 0.5f, 0.5f, 0.5f);
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

	void ScenePlay2::sDoAction(Action action)
	{
		if (action.name() == "UP" && action.type() == PRESS)
		{
			GameEngine::GameEngineManager::Instance().changeScene(1);
		}
	}
}