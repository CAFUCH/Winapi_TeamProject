#include "pch.h"
#include "Weapon.h"
#include "Texture.h"

#include "Collider.h"
#include "Animator.h"

Weapon::Weapon()
	: m_pTex(nullptr)
	, m_eElementType(ENTITY_ELEMENT_TYPE::NONE)
{
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{
}

void Weapon::Render(HDC _dc)
{
	//TransparentBlt(_dc
	//	, (int)(m_vPos.x - m_vScale.x / 2)
	//	, (int)(m_vPos.y - m_vScale.y / 2)
	//	, m_pTex->GetWidth(), m_pTex->GetHeight()
	//	, m_pTex->GetDC()
	//	, 0, 0, m_pTex->GetWidth(), m_pTex->GetHeight()
	//	, RGB(255, 0, 255));

	//BitBlt(_dc
	//	, (int)(m_vPos.x - m_vScale.x / 2)
	//	, (int)(m_vPos.y - m_vScale.y / 2)
	//	, m_pTex->GetWidth(), m_pTex->GetHeight()
	//	, m_pTex->GetDC()
	//	, 0, 0, SRCCOPY);
}

void Weapon::Attack(Vec2 dir)
{
}

void Weapon::CreateCollider()
{
	m_pCollider = new Collider;
	//m_pCollider->m_pOwner = this;
}

void Weapon::CreateAnimator()
{
	m_pAnimator = new Animator;
	//m_pAnimator->m_pOwner = this;
}
