#include "pch.h"
#include "Core.h"
#include "Intro_Scene.h"
#include "Button.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "ResMgr.h"


void HandleSceneChangedGameScene() {
	//페이드하면 좋을듯
	SceneMgr::GetInst()->LoadScene(L"Game_Scene");
}
void Intro_Scene::Init()
{
	intro_tex = ResMgr::GetInst()->TexLoad(L"Intro_Panel", L"Texture\\Intro_Panel.bmp");

	Button* playBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2),
		Vec2(350, 120));
	playBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"StartBtn_on", L"Texture\\StartBtn_hover.bmp"));
	playBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"StartBtn_off", L"Texture\\StartBtn.bmp"));
	playBtn->onReister = HandleSceneChangedGameScene;
	AddObject(playBtn, OBJECT_GROUP::UI);

	Button* settingBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2 + 120),
		Vec2(350, 120));
	settingBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"SettingBtn_on", L"Texture\\SettingBtn_hover.bmp"));
	settingBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"SettingBtn_off", L"Texture\\SettingBtn.bmp"));
	settingBtn->onReister = HandleSceneChangedGameScene;
	AddObject(settingBtn, OBJECT_GROUP::UI);

	Button* exitBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2 + 240),
		Vec2(350, 120));
	exitBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_on", L"Texture\\ExitBtn_hover.bmp"));
	exitBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_off", L"Texture\\ExitBtn.bmp"));
	exitBtn->onReister = HandleSceneChangedGameScene;
	AddObject(exitBtn, OBJECT_GROUP::UI);
}

void Intro_Scene::Update()
{
	Scene::Update();
}

void Intro_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);

	float Width = intro_tex->GetWidth();
	float Height = intro_tex->GetHeight();

	BitBlt(_dc, 0, 0, (int)Width, (int)Height, intro_tex->GetDC(),0,0, SRCCOPY);
}

void Intro_Scene::Release()
{
	Scene::Release();
}
