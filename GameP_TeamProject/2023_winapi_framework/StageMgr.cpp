#include "pch.h"
#include "StageMgr.h"
#include "SceneMgr.h"
#include "Scene.h"

#include "Melee_Enemy.h"
#include "Chase_State.h"
#include "Idle_State.h"

void StageMgr::Init()
{
	curStage = 1;
}

void StageMgr::NextStage()
{
	++curStage;
}

void StageMgr::EnemySpawn(float delay)
{
	for (int i = 1; i <= 30; ++i) {

		Melee_Enemy* enemy = new Melee_Enemy(i % 7 + 1, ENTITY_ELEMENT_TYPE::FIRE);
		enemy->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 500, (int)WINDOW_HEIGHT / 2 + rand() % 400));
		enemy->SetScale(Vec2(64, 64));
		SceneMgr::GetInst()->GetCurScene()->AddObject(enemy, OBJECT_GROUP::MONSTER);

		AI* ai = new AI(enemy);
		ai->AddState(ENEMY_STATE::CHASE, new Chase_State(ai, rand() % 100 + 5));
		ai->InitState(ENEMY_STATE::CHASE);
	}


}
