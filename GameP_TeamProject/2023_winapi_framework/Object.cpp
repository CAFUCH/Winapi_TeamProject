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
	// 해당 컴포넌트가 있다면 컴포넌트의 삭제도 함께 실행
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
	/*for (Weapon* weapon : m_vecWeapon)
	{
		if (nullptr != weapon)
			delete weapon;
	}*/

	// Entity는 소멸자에서 삭제하지 않는다.
	// Entity는 체력에 따라 생존 여부가 결정되기 때문에 EventMgr에서 삭제를 지원해주고 잇다.!
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
	// 콜라이더의 Update
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
	// 해당 컴포넌트가 있다면 컴포넌트의 Render도 함께 실행
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
		// PoolMgr를 사용할거면 EventMgr를 손 봐야 한다
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

