#include "pch.h"
#include "Object.h"
#include "Scene.h"
#include "Particle.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "EventMgr.h"
#include "SceneMgr.h"

#include "Collider.h"
#include "Animator.h"
#include "Weapon.h"
Object::Object()
	: m_pCollider(nullptr)
	, m_pAnimator(nullptr)
	, m_vPos{}
	, m_vScale{}
	, m_IsAlive(true)
{
}

Object::~Object()
{
	// �ش� ������Ʈ�� �ִٸ� ������Ʈ�� ������ �Բ� ����
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
	/*for (Weapon* weapon : m_vecWeapon)
	{
		if (nullptr != weapon)
			delete weapon;
	}*/

	// Entity�� �Ҹ��ڿ��� �������� �ʴ´�.
	// Entity�� ü�¿� ���� ���� ���ΰ� �����Ǳ� ������ EventMgr���� ������ �������ְ� �մ�.!
}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pObjOwner = this;
}

void Object::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pObjOwner = this;
}

void Object::CreateWeapon()
{
	Weapon* weapon = new Weapon;
	m_vecWeapon.push_back(weapon);
}

void Object::Update()
{
}

void Object::FinalUpdate()
{
	// �ݶ��̴��� Update
	if (m_pCollider)
		m_pCollider->FinalUpdate();
}

void Object::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Object::EnterCollision(Collider* _pOther)
{
}

void Object::ExitCollision(Collider* _pOther)
{
}

void Object::StayCollision(Collider* _pOther)
{
}

void Object::Component_Render(HDC _dc)
{
	// �ش� ������Ʈ�� �ִٸ� ������Ʈ�� Render�� �Բ� ����
	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc);
	if (nullptr != m_pAnimator)
		m_pAnimator->Render(_dc);
}

void Object::SetDamage(float _damage)
{
	if (m_fHp - _damage <= 0)
	{
		m_fHp = 0;
		// PoolMgr�� ����ҰŸ� EventMgr�� �� ���� �Ѵ�
		EventMgr::GetInst()->DeleteObject(this);

	}
	else
		m_fHp -= _damage;
}

Particle* Object::CreateParticle(PARTICLE_TYPE _type, Object* _owner)
{
	Particle* m_pParticle = new Particle(_type);
	m_pParticle->SetOwner(_owner);
	m_pParticle->SetPos({ GetPos().x, GetPos().y - GetScale().y / 2 });
	m_pParticle->SetScale({ 100.f, 100.f });
	m_pCurScene->AddObject(m_pParticle, OBJECT_GROUP::PARTICLE);
	return m_pParticle;
}

