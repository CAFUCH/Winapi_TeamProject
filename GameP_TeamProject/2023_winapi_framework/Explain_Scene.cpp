#include "pch.h"
#include "Core.h"
#include "Explain_Scene.h"
#include "Button.h"
#include "Texture.h"
#include "SceneMgr.h"
#include "ResMgr.h"
#include "Panel.h"

void HandleSceneChangedControlScene2() {
	SceneMgr::GetInst()->LoadScene(L"Control_Scene");
}
void HandleSceneChangedIntroScene2() {
	SceneMgr::GetInst()->LoadScene(L"Intro_Scene");
}
void Explain_Scene::Init()
{
	Panel* bg = new Panel();
	bg->SetTexture(ResMgr::GetInst()->TexLoad(L"Explain_Panel", L"Texture\\Explain_Panel.bmp"));
	AddObject(bg, OBJECT_GROUP::Panel);

	Button* backBtn = new Button(Vec2(200, 100),
		Vec2(350, 120));
	backBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_on", L"Texture\\BackBtn_hover.bmp"));
	backBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"BackBtn_off", L"Texture\\BackBtn.bmp"));
	backBtn->onReister = HandleSceneChangedIntroScene2;
	AddObject(backBtn, OBJECT_GROUP::UI);

	Button* nextBtn = new Button(Vec2((int)WINDOW_WIDTH - 200, 100),
		Vec2(350, 120));
	nextBtn->SetOnTexture(ResMgr::GetInst()->TexLoad(L"PrevBtn_on", L"Texture\\PrevBtn_hover.bmp"));
	nextBtn->SetOffTexture(ResMgr::GetInst()->TexLoad(L"PrevBtn_off", L"Texture\\PrevBtn.bmp"));
	nextBtn->onReister = HandleSceneChangedControlScene2;
	AddObject(nextBtn, OBJECT_GROUP::UI);

}

void Explain_Scene::Update()
{
	Scene::Update();
}

void Explain_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Explain_Scene::Release()
{
	Scene::Release();
}
