#include "pch.h"
#include "StageMgr.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Core.h"

#include "Melee_Enemy.h"
#include "Chase_State_Melee.h"

#include "Range_Enemy.h"
#include "Chase_State_Range.h"
#include "Attack_State_Range.h"
#include "Idle_State.h"

#include "HP.h"
#include "TimeMgr.h"

typedef void(*myFuncDef)(void);

void StageMgr::Init()
{
	curStage = 0;
	enemyCountInWave = 10; //임시로 정해줌
}

void StageMgr::Update()
{
	if (isStageStart) {
		curTime += fDT;
		if (curTime >= spawnDelay) {
			EnemySpawn(enemyCount);
			curTime = 0;
			--spawnCount;
		}
	}
	if (spawnCount <= 0) {
		isStageStart = false;
	}

	if (enemyCountInWave <= 0) {
		if (!allDead) {
			((myFuncDef)action)(); //void 포인터는 이렇게 실행
			allDead = true;
		}
	}
	wstring ws = to_wstring(enemyCountInWave);
	TextOut(Core::GetInst()->GetMainDC(), 100, 100, ws.c_str(), ws.length());
}

void StageMgr::NextStage(int _enemyCount, int _spawnCount, float _spawnDelay, void* (_action))
{
	++curStage;

	enemyCount = _enemyCount;
	spawnCount = _spawnCount;
	enemyCountInWave = enemyCount * spawnCount;
	spawnDelay = _spawnDelay;

	action = _action;

	allDead = false;
	isStageStart = true;

}

void StageMgr::EnemySpawn(int eCount)
{
	for (int i = 1; i <= eCount; ++i)
	{

		Melee_Enemy* enemy = new Melee_Enemy(i % 7 + 1, ENTITY_ELEMENT_TYPE::FIRE
			, 100, .01f, 3.f);

		enemy->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 500, (int)WINDOW_HEIGHT / 2 + rand() % 400));
		enemy->SetScale(Vec2(64, 64));
		SceneMgr::GetInst()->GetCurScene()->AddObject(enemy, OBJECT_GROUP::MONSTER);

		AI* ai = new AI(enemy);
		ai->AddState(ENEMY_STATE::CHASE, new Chase_State_Melee(ai, rand() % 100 + 5));
		ai->InitState(ENEMY_STATE::CHASE);


		HP* pHP = new HP();
		pHP->SetOwner(enemy);
		pHP->SetPos({ enemy->GetPos().x, enemy->GetPos().y - enemy->GetScale().y / 2 });
		pHP->SetScale({ 100.f, 100.f });
		pHP->SetMaxHP(20.f);
		pHP->SetHP(pHP->GetMaxHP());
		SceneMgr::GetInst()->GetCurScene()->AddObject(pHP, OBJECT_GROUP::UI);

		//원거리-------------------------------------------------------------------------------------
		if (curStage >= 3) {
			++i;

			Range_Enemy* enemy2 = new Range_Enemy(i % 2 + 1, ENTITY_ELEMENT_TYPE::FIRE, 100, .01f, 3.f);

			enemy2->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 500, (int)WINDOW_HEIGHT / 2 + rand() % 400));
			enemy2->SetScale(Vec2(64, 64));
			SceneMgr::GetInst()->GetCurScene()->AddObject(enemy2, OBJECT_GROUP::MONSTER);

			AI* ai2 = new AI(enemy2);
			ai2->AddState(ENEMY_STATE::CHASE, new Chase_State_Range(ai2, rand() % 100 + 5));
			ai2->AddState(ENEMY_STATE::IDLE, new Idle_State(ai2, 2.f));
			ai2->AddState(ENEMY_STATE::ATTACK, new Attack_State_Range(ai2)); //댐지, 기다리는 시간
			ai2->InitState(ENEMY_STATE::CHASE);


			HP* pHP2 = new HP();
			pHP2->SetOwner(enemy2);
			pHP2->SetPos({ enemy2->GetPos().x, enemy2->GetPos().y - enemy2->GetScale().y / 2 });
			pHP2->SetScale({ 100.f, 100.f });
			pHP2->SetMaxHP(20.f);
			pHP2->SetHP(pHP2->GetMaxHP());
			SceneMgr::GetInst()->GetCurScene()->AddObject(pHP2, OBJECT_GROUP::UI);
		}
	}
}
