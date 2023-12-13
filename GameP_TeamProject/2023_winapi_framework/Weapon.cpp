#include "pch.h"
#include "Weapon.h"
#include "Texture.h"

#include "Collider.h"
#include "Animator.h"

Weapon::Weapon()
	: m_pTex(nullptr)
	, m_eElement(ENTITY_ELEMENT_TYPE::END)
	, m_pCollider(nullptr)
	, m_pAnimator(nullptr)
{
}

Weapon::~Weapon()
{
	// 해당 컴포넌트가 있다면 컴포넌트의 삭제도 함께 실행
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
}

void Weapon::Update()
{
}

void Weapon::FinalUpdate()
{
	// 콜라이더의 Update
	if (m_pCollider)
		m_pCollider->FinalUpdate();
}

void Weapon::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Weapon::EnterCollision(Collider* _pOther)
{
}

void Weapon::ExitCollision(Collider* _pOther)
{
}

void Weapon::StayCollision(Collider* _pOther)
{
}

void Weapon::Component_Render(HDC _dc)
{
	// 해당 컴포넌트가 있다면 컴포넌트의 Render도 함께 실행
	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc);
	if (nullptr != m_pAnimator)
		m_pAnimator->Render(_dc);
}

void Weapon::Attack(Vec2 dir)
{
}

void Weapon::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pWeaOwner = this;
}

void Weapon::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pWeaOwner = this;
}
