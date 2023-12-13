#include "pch.h"
#include "Clear_Scene.h"
#include "Panel.h"
#include "Button.h"
#include "ResMgr.h"
#include "SceneMgr.h"

void GoIntroScene1() {
	SceneMgr::GetInst()->LoadScene(L"Intro_Scene");
}
void Clear_Scene::Init()
{
	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"Clear_Panel", L"Texture\\Clear_Panel.bmp"));

	AddObject(bg, OBJECT_GROUP::Panel);

	Button* backBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT - 200),
		Vec2(350, 120));
	backBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_on", L"Texture\\BackBtn_hover.bmp"));
	backBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_off", L"Texture\\BackBtn.bmp"));
	backBtn->onReister = GoIntroScene1;
	AddObject(backBtn, OBJECT_GROUP::UI);
}

void Clear_Scene::Update()
{
	Scene::Update();
}

void Clear_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Clear_Scene::Release()
{
	Scene::Release();
}
