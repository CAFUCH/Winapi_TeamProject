#include "pch.h"
#include "Core.h"
#include "Intro_Scene.h"
#include "Button.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Panel.h"

void HandleSceneChangedGameScene() {
	SceneMgr::GetInst()->LoadScene(L"Game_Scene");
}
void HandleSceneChangedExplainScene() {
	SceneMgr::GetInst()->LoadScene(L"Control_Scene");
}
void HandleSceneChangedExit() {
	exit(0);
}
void Intro_Scene::Init()
{

	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"Intro_Panel", L"Texture\\Intro_Panel.bmp"));

	AddObject(bg, OBJECT_GROUP::Panel);

	Button* playBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2 - 50),
		Vec2(350, 120));
	playBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"StartBtn_on", L"Texture\\StartBtn_hover.bmp"));
	playBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"StartBtn_off", L"Texture\\StartBtn.bmp"));
	playBtn->onReister = HandleSceneChangedGameScene;
	AddObject(playBtn, OBJECT_GROUP::UI);

	Button* explainBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2 + 100),
		Vec2(350, 120));
	explainBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"SettingBtn_on", L"Texture\\SettingBtn_hover.bmp"));
	explainBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"SettingBtn_off", L"Texture\\SettingBtn.bmp"));
	explainBtn->onReister = HandleSceneChangedExplainScene;
	AddObject(explainBtn, OBJECT_GROUP::UI);


	Button* exitBtn = new Button(Vec2((int)WINDOW_WIDTH / 2 - 30, (int)WINDOW_HEIGHT / 2 + 250),
		Vec2(350, 120));
	exitBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_on", L"Texture\\ExitBtn_hover.bmp"));
	exitBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_off", L"Texture\\ExitBtn.bmp"));
	exitBtn->onReister = HandleSceneChangedExit;
	AddObject(exitBtn, OBJECT_GROUP::UI);

}

void Intro_Scene::Update()
{
	Scene::Update();
}

void Intro_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Intro_Scene::Release()
{
	Scene::Release();
}
