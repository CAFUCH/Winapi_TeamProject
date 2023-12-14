#include "pch.h"
#include "GameOver_Scene.h"
#include "Panel.h"
#include "Button.h"
#include "ResMgr.h"
#include "SceneMgr.h"

void GoIntroScene() {
	SceneMgr::GetInst()->LoadScene(L"Intro_Scene");
}	

void GameOver_Scene::Init()
{
	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"GameOver_Panel", L"Texture\\GameOver_Panel.bmp"));

	AddObject(bg, OBJECT_GROUP::Panel);

	Button* backBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT - 200),
		Vec2(350, 120));
	backBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_on", L"Texture\\BackBtn_hover.bmp"));
	backBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_off", L"Texture\\BackBtn.bmp"));
	backBtn->onReister = GoIntroScene;
	AddObject(backBtn, OBJECT_GROUP::UI);
}

void GameOver_Scene::Update()
{
	Scene::Update();
}

void GameOver_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void GameOver_Scene::Release()
{
	Scene::Release();
}
