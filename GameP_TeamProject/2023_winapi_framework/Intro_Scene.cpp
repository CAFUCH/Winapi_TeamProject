#include "pch.h"
#include "Core.h"
#include "Intro_Scene.h"
#include "Button.h"
void Intro_Scene::Init()
{
	//Button* btn = new Button;
	//btn->SetPos(Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 }));
	//btn->SetScale(Vec2(100.f, 100.f));
	//AddObject(btn,  OBJECT_GROUP::UI);
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
