#include "pch.h"
#include "Weapon.h"

#include "SceneMgr.h"

Weapon::Weapon()
	: m_pTex(nullptr)
{
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{
	//m_pCurScene.
}
