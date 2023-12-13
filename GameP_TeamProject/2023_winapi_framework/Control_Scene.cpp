#include "pch.h"
#include "Control_Scene.h"
#include "Core.h"
#include "Button.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Panel.h"

void HandleSceneChangedIntroScene() {
	SceneMgr::GetInst()->LoadScene(L"Intro_Scene");
}
void HandleSceneChangedNextScene() {
	SceneMgr::GetInst()->LoadScene(L"Explain_Scene");
}

void Control_Scene::Init()
{
	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"Control_Panel", L"Texture\\Control_Panel.bmp"));

	AddObject(bg, OBJECT_GROUP::Panel);

	Button* backBtn = new Button(Vec2(200, 100),
		Vec2(350, 120));
	backBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_on", L"Texture\\BackBtn_hover.bmp"));
	backBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_off", L"Texture\\BackBtn.bmp"));
	backBtn->onReister = HandleSceneChangedIntroScene;
	AddObject(backBtn, OBJECT_GROUP::UI);

	Button* nextBtn = new Button(Vec2((int)WINDOW_WIDTH - 200, 100),
		Vec2(350, 120));
	nextBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"NextBtn_on", L"Texture\\NextBtn_hover.bmp"));
	nextBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"NextBtn_off", L"Texture\\NextBtn.bmp"));
	nextBtn->onReister = HandleSceneChangedNextScene;
	AddObject(nextBtn, OBJECT_GROUP::UI);
}

void Control_Scene::Update()
{
	Scene::Update();
}

void Control_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Control_Scene::Release()
{
	Scene::Release();
}
