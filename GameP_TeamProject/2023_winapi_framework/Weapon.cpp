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
	// ������� ���ʹ̸� �����´�.
	//m_pCurScene->GetGroupObject(OBJECT_GROUP::MONSTER);
}
