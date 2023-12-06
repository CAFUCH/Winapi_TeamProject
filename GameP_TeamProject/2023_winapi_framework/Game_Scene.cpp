#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"

#include "Player.h"

#include "Knife.h"
#include "Gun.h"

#include "Object.h"

#include "KeyMgr.h"
#include "ResMgr.h"
#include "CollisionMgr.h"

#include "Melee_Enemy.h"
#include "Chase_State.h"
#include "Idle_State.h"

#include "StageMgr.h"

void Game_Scene::Init()
{
	// 플레이어 생성 및 초기화
	{
		Object* pPlayer = new Player;
		pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
		pPlayer->SetScale(Vec2(100.f, 100.f));
		AddObject(pPlayer, OBJECT_GROUP::PLAYER);
	}

	// 무기 생성 및 초기화
	{
		Weapon* pGun = new Gun;
		pGun->SetPos((Vec2({ 0, 0 })));
		pGun->SetScale(Vec2(50.f, 50.f));
		m_mWeapon.insert({ L"Gun", pGun });

		Weapon* pKnife = new Knife;
		pKnife->SetPos((Vec2({ 0, 0 })));
		pKnife->SetScale(Vec2(50.f, 50.f));
		m_mWeapon.insert({ L"Knife", pKnife });
	}

	// 적 생성 및 초기화 (테스트 버전)
	{

		StageMgr::GetInst()->NextStage(3, 3.f);
		/*for (int i = 1; i <= 30; ++i) {
			Melee_Enemy* enemy = new Melee_Enemy(i % 7 + 1, ENTITY_ELEMENT_TYPE::FIRE);
			enemy->SetPos(Vec2((int)WINDOW_WIDTH / 2 + rand() % 500, (int)WINDOW_HEIGHT / 2 + rand() % 400));
			enemy->SetScale(Vec2(64, 64));
			AddObject(enemy, OBJECT_GROUP::MONSTER);

			AI* ai = new AI(enemy);
			ai->AddState(ENEMY_STATE::CHASE, new Chase_State(ai, rand() % 100 + 5));
			ai->InitState(ENEMY_STATE::CHASE);
		}*/
	}

	// 사운드 세팅
	//ResMgr::GetInst()->Play(L"BGM");

	//출동 세팅
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::PLAYER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::WEAPON, OBJECT_GROUP::MONSTER);
}

void Game_Scene::Update()
{
	Scene::Update();
}

void Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Game_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
