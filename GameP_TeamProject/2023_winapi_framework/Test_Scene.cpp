#include "pch.h"
#include "Test_Scene.h"
#include "Button.h"
#include "SceneMgr.h"
#include "Enemy.h"
#include "Melee_Enemy.h"
#include "AI.h"
#include "Idle_State.h"
#include "ResMgr.h"
#include "Chase_State_Melee.h"
#include "Core.h"

void Test_Scene::Init()
{
	//SetBkMode(Core::GetInst()->GetMainDC(), 0);

	/*Button* playBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2),
		Vec2(200, 100));
	playBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_on", L"Texture\\PlayBtn_on.bmp"));
	playBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_off", L"Texture\\PlayBtn_off.bmp"));
	playBtn->onReister = HandleSceneChangedGameScene;
	AddObject(playBtn, OBJECT_GROUP::UI);*/

	/*
	Button* expBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2),
		Vec2(200, 100));
	expBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_on", L"Texture\\PlayBtn_on.bmp"));
	expBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_off", L"Texture\\PlayBtn_off.bmp"));
	expBtn->onReister = HandleSceneChangedGameScene;
	AddObject(expBtn, OBJECT_GROUP::UI);

	Button* exit = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2),
		Vec2(200, 100));
	exit->SetOnTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_on", L"Texture\\PlayBtn_on.bmp"));
	exit->SetOffTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_off", L"Texture\\PlayBtn_off.bmp"));
	exit->onReister = HandleSceneChangedGameScene;
	AddObject(exit, OBJECT_GROUP::UI);*/

	//meleeEnemy->SetTexure(ResMgr::GetInst()->TexLoad(L"Melee_Enemy_1", L"Texture\\snake1.bmp"));

	/*Melee_Enemy* meleeEnemy = new Melee_Enemy(7);
	meleeEnemy->SetPos(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2));
	meleeEnemy->SetScale(Vec2(64, 64));
	AddObject(meleeEnemy, OBJECT_GROUP::MONSTER);

	AI* ai = new AI(meleeEnemy);*/



	//ai->AddState(ENEMY_STATE::IDLE, new Idle_State(ai));
	//ai->AddState(ENEMY_STATE::CHASE, new Chase_State(ai, 3));

	//ai->InitState(ENEMY_STATE::CHASE);

}


void Test_Scene::Update()
{
	Scene::Update();
}

void Test_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Test_Scene::Release()
{
	Scene::Release();
}
