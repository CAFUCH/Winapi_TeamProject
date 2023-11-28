#include "pch.h"
#include "Test_Scene.h"
#include "Button.h"
#include "SceneMgr.h"

void HandleChangedGameScene();
void Test_Scene::Init()
{
	Button* btn = new Button(Vec2(200, 200), Vec2(200, 100));
	AddObject(btn, OBJECT_GROUP::UI);

	//btn->onReister = HandleChangedGameScene;
}

void HandleChangedGameScene() {
	SceneMgr::GetInst()->LoadScene(L"Game_Scene");
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
