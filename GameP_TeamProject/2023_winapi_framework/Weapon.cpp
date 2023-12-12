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
}

void Weapon::Attack(Vec2 dir)
{
}

void Weapon::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->SetFinalPos(GetPos());
}

void Weapon::CreateAnimator()
{
	m_pAnimator = new Animator;
	//m_pAnimator->m_pOwner = this;
}
