#include "pch.h"
#include "Test_Scene.h"
#include "Button.h"
#include "SceneMgr.h"
#include "Enemy.h"
#include "Melee_Enemy.h"
#include "AI.h"
#include "Idle_State.h"
#include "ResMgr.h"
void Test_Scene::Init()
{
	Button* btn = new Button(Vec2(200, 200), Vec2(200, 100));

	btn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"gameStart_btn_on", L"Texture\\GameStart_btn_on.bmp"));
	btn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"gameStart_btn_off", L"Texture\\GameStart_btn_off.bmp"));

	AddObject(btn, OBJECT_GROUP::UI);


	Enemy* meleeEnemy = new Melee_Enemy;
	AI* ai = new AI(meleeEnemy);
	ai->AddState(ENEMY_STATE::IDLE, new Idle_State(ai));

	ai->InitState(ENEMY_STATE::IDLE);
	//btn->onReister = HandleChangedGameScene;
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
