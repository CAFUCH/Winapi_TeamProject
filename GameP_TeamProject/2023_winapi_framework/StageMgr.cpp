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
	enemyCountInWave = 100; //�ӽ÷� ������
	isUpdate = true;
}

void StageMgr::Update()
{
	if (isUpdate) {
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
				((myFuncDef)action)(); //void �����ʹ� �̷��� ����
				allDead = true;
			}
			if (curStage >= 2) { //10���������� �Ǹ� Ŭ���������
				SceneMgr::GetInst()->LoadScene(L"Clear_Scene");
			}
		}
	}
}

void StageMgr::Setting()
{
	enemyCountInWave = 100;
	isUpdate = true;
	curTime = 0;
	spawnDelay = 0;

	curStage = 0;
	spawnCount = 0;
	enemyCount = 0;
	isStageStart = true;
	allDead = false;
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
		int random = rand() % 2;

		if (curStage >= 2 && random == 1) {

			Range_Enemy* enemy2 = new Range_Enemy(i % 2 + 1, ENTITY_ELEMENT_TYPE::FIRE, 20, 10.f, 3.f);

			enemy2->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 1000 - 500, (int)WINDOW_HEIGHT / 2 + rand() % 1000 - 500));
			enemy2->SetScale(Vec2(64, 64));
			SceneMgr::GetInst()->GetCurScene()->AddObject(enemy2, OBJECT_GROUP::MONSTER);

			AI* ai2 = new AI(enemy2);
			ai2->AddState(ENEMY_STATE::CHASE, new Chase_State_Range(ai2, rand() % 100 + 5));
			ai2->AddState(ENEMY_STATE::IDLE, new Idle_State(ai2, 2.f));
			ai2->AddState(ENEMY_STATE::ATTACK, new Attack_State_Range(ai2)); //����, ��ٸ��� �ð�
			ai2->InitState(ENEMY_STATE::CHASE);
		}
		else {
			Melee_Enemy* enemy = new Melee_Enemy(i % 7 + 1, ENTITY_ELEMENT_TYPE::FIRE
				, 20, 5.f, .5f);

			enemy->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 1000 - 500, (int)WINDOW_HEIGHT / 2 + rand() % 1000 - 500));
			enemy->SetScale(Vec2(64, 64));
			SceneMgr::GetInst()->GetCurScene()->AddObject(enemy, OBJECT_GROUP::MONSTER);

			AI* ai = new AI(enemy);
			ai->AddState(ENEMY_STATE::CHASE, new Chase_State_Melee(ai, rand() % 100 + 20));
			ai->InitState(ENEMY_STATE::CHASE);
		}
	}
}
