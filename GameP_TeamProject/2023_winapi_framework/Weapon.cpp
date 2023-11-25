#include "pch.h"
#include "Weapon.h"
//#include "Scene.h"

#include "SceneMgr.h"

Weapon::Weapon()
	: m_pTex(nullptr)
{
	//m_pCurScene = SceneMgr::GetInst()->GetCurScene();
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{
	// 현재씬의 에너미를 가져온다.
	//m_pCurScene->GetGroupObject(OBJECT_GROUP::MONSTER);
}
