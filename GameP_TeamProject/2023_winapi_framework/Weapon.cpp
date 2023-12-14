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
	// �ش� ������Ʈ�� �ִٸ� ������Ʈ�� ������ �Բ� ����
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
	// �ݶ��̴��� Update
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
	// �ش� ������Ʈ�� �ִٸ� ������Ʈ�� Render�� �Բ� ����
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
