#include "pch.h"
#include "StageMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Core.h"

#include "Melee_Enemy.h"
#include "Chase_State.h"
#include "Idle_State.h"

#include "HP.h"
#include "TimeMgr.h"


void StageMgr::Init()
{
	curStage = 0;
}

void StageMgr::Update()
{
	if (isStageStart) {
		curTime += fDT;
		if (curTime >= spawnDelay) {
			EnemySpawn(3);
			curTime = 0;
			--spawnCount;
		}
	}
	if (spawnCount <= 0) {
		isStageStart = false;
		allDead = true;
	}
	//TextOut(Core::GetInst()->GetMainDC(), 100, 100, (LPCWSTR)enemycount, 1);
}

void StageMgr::NextStage(int _spawnCount, float _spawnDelay)
{
	++curStage;
	spawnCount = _spawnCount;
	spawnDelay = _spawnDelay;

	allDead = false;
	isStageStart = true;
}

void StageMgr::EnemySpawn(int eCount)
{
	for (int i = 1; i <= eCount; ++i) {

		Melee_Enemy* enemy = new Melee_Enemy(i % 7 + 1, ENTITY_ELEMENT_TYPE::FIRE
			, 100, 3, .3f);

		enemy->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 500, (int)WINDOW_HEIGHT / 2 + rand() % 400));
		enemy->SetScale(Vec2(64, 64));
		SceneMgr::GetInst()->GetCurScene()->AddObject(enemy, OBJECT_GROUP::MONSTER);

		AI* ai = new AI(enemy);
		ai->AddState(ENEMY_STATE::CHASE, new Chase_State(ai, rand() % 100 + 5));
		ai->InitState(ENEMY_STATE::CHASE);


		HP* pHP = new HP();
		pHP->SetOwner(enemy);
		pHP->SetPos({ enemy->GetPos().x, enemy->GetPos().y - enemy->GetScale().y / 2 });
		pHP->SetScale({ 100.f, 100.f });
		pHP->SetMaxHP(20.f);
		pHP->SetHP(pHP->GetMaxHP());
		SceneMgr::GetInst()->GetCurScene()->AddObject(pHP, OBJECT_GROUP::UI);
	}


}
