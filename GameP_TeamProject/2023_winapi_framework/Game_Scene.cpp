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

void Game_Scene::Init()
{
	// 플레이어 생성 및 초기화
	Object* pPlayer = new Player;
	pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayer, OBJECT_GROUP::PLAYER);

	// 무기 생성 및 초기화
	{
		Object* pGun = new Gun;
		pGun->SetPos((Vec2({ pPlayer->GetPos() })));
		pGun->SetScale(Vec2(50.f, 50.f));
		AddObject(pGun, OBJECT_GROUP::WEAPON);
	}

	// 적 생성 및 초기화 (테스트 버전)
	{
		Object* ptEnemy1 = new Player;
		ptEnemy1->SetPos((Vec2({ 100.f, 100.f })));
		ptEnemy1->SetScale(Vec2(100.f, 100.f));
		AddObject(ptEnemy1, OBJECT_GROUP::MONSTER);

		Object* ptEnemy2 = new Player;
		ptEnemy2->SetPos((Vec2({ 300.f, 100.f })));
		ptEnemy2->SetScale(Vec2(100.f, 100.f));
		AddObject(ptEnemy2, OBJECT_GROUP::MONSTER);

		Object* ptEnemy3 = new Player;
		ptEnemy3->SetPos((Vec2({ 500.f, 100.f })));
		ptEnemy3->SetScale(Vec2(100.f, 100.f));
		AddObject(ptEnemy3, OBJECT_GROUP::MONSTER);
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
