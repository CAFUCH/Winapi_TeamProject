#include "pch.h"
#include "Test_Scene.h"
#include "Button.h"
#include "SceneMgr.h"
#include "Enemy.h"
#include "Melee_Enemy.h"
#include "AI.h"
#include "Idle_State.h"
#include "ResMgr.h"
#include "Chase_State.h"
#include "Core.h"

void HandleSceneChangedGameScene() {
	SceneMgr::GetInst()->LoadScene(L"Game_Scene");
}
void Test_Scene::Init()
{
	//SetBkMode(Core::GetInst()->GetMainDC(), 0);

	Button* btn = new Button(Vec2(200, 200), Vec2(200, 100));
	btn->onReister = HandleSceneChangedGameScene;

	btn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_on", L"Texture\\PlayBtn_on.bmp"));
	btn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"PlayBtn_off", L"Texture\\PlayBtn_off.bmp"));

	AddObject(btn, OBJECT_GROUP::UI);


	Enemy* meleeEnemy = new Melee_Enemy;
	AI* ai = new AI(meleeEnemy);
	//ai->AddState(ENEMY_STATE::IDLE, std::make_shared<Idle_State>(ai));
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
