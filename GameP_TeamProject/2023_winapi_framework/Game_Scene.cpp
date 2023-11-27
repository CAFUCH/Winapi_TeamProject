#include "pch.h"
#include "Game_Scene.h"
#include "Core.h"

#include "Object.h"

#include "Player.h"
#include "Knife.h"

#include "KeyMgr.h"
#include "ResMgr.h"
#include "CollisionMgr.h"

void Game_Scene::Init()
{
	// �÷��̾� ���� �� �ʱ�ȭ
	Object* pObj = new Player;
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::PLAYER);

	// ���� ����
	//ResMgr::GetInst()->Play(L"BGM");

	//�⵿ ����
	CollisionMgr::GetInst()->CheckGroup(OBJECT_GROUP::MONSTER, OBJECT_GROUP::PLAYER);
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
