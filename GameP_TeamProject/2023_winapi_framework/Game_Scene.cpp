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
	// �÷��̾� ���� �� �ʱ�ȭ
	Object* pPlayer = new Player;
	pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pPlayer->SetScale(Vec2(100.f, 100.f));
	AddObject(pPlayer, OBJECT_GROUP::PLAYER);

	// ���� ���� �� �ʱ�ȭ
	{
		Object* pGun = new Gun;
		pGun->SetPos((Vec2({ pPlayer->GetPos() })));
		pGun->SetScale(Vec2(50.f, 50.f));
		AddObject(pGun, OBJECT_GROUP::WEAPON);
	}

	// ���� ����
	//ResMgr::GetInst()->Play(L"BGM");

	//�⵿ ����
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
