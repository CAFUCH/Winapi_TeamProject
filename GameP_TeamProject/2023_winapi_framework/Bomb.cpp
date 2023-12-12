#include "pch.h"
#include "Bomb.h"
#include "Scene.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Bomb::Bomb()
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bomb", L"Texture\\jiwoo.bmp");
	isAttack = false;
	m_fDistance = 1000.f;
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	if (isAttack == false)
		SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });
}

void Bomb::Render(HDC _dc)
{
	BitBlt(_dc
		, (int)(GetPos().x - m_vScale.x / 2)
		, (int)(GetPos().y - m_vScale.y / 2)
		, m_pTex->GetWidth(), m_pTex->GetHeight()
		, m_pTex->GetDC()
		, 0, 0, SRCCOPY);
}

void Bomb::Attack(Vec2 dir)
{
	isAttack = true;
}
