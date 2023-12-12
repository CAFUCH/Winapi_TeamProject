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
#include "Chase_State_Melee.h"
#include "Idle_State.h"

#include "StageMgr.h"


void ddd();
void Game_Scene::Init()
{
	// �÷��̾� ���� �� �ʱ�ȭ
	{
		Object* pPlayer = new Player;
		pPlayer->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
		pPlayer->SetScale(Vec2(100.f, 100.f));
		AddObject(pPlayer, OBJECT_GROUP::PLAYER);
	}

	// ���� ���� �� �ʱ�ȭ
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

	// �� ���� �� �ʱ�ȭ (�׽�Ʈ ����)
	{
		StageMgr::GetInst()->NextStage(5, 3, 3.f, ddd);
	}
	// ���� ����
	//ResMgr::GetInst()->Play(L"BGM");

	//�⵿ ����
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::PLAYER, OBJECT_GROUP::MONSTER);
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::WEAPON, OBJECT_GROUP::MONSTER);
}
void ddd() { 
	//�ϴ� ����
	StageMgr::GetInst()->NextStage(5, 3, 3.f, ddd);
	/*wstring ws = to_wstring(10);
	TextOut(Core::GetInst()->GetMainDC(), 400, 100, ws.c_str(), ws.length());*/
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
