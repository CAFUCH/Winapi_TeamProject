#include "pch.h"
#include "Object.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "EventMgr.h"

#include "Collider.h"
#include "Animator.h"
Object::Object()
	: m_pCollider(nullptr)
	, m_vPos{}
	, m_vScale{}
	, m_IsAlive(true)
	, m_pAnimator(nullptr)
{
}

Object::~Object()
{
	// 해당 컴포넌트가 있다면 컴포넌트의 삭제도 함께 실행
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;

	// Entity는 소멸자에서 삭제하지 않는다.
	// Entity는 체력에 따라 생존 여부가 결정되기 때문에 EventMgr에서 삭제를 지원해주고 잇다.!
}

void Object::CreateCollider()
{
	m_pCollider = new Collider;
	m_pCollider->m_pOwner = this;
}

void Object::CreateAnimator()
{
	m_pAnimator = new Animator;
	m_pAnimator->m_pOwner = this;
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
	// 기본적인 Render (독립적으로 렌더하고 싶은 obj가 있다면 해당 객체에서 렌더하자)
	// 해당 Obj가 포함된 Scene의 Render에서 m_vObj 백터에 담겨 호출된다.
	//RECT_RENDER(m_vPos.x, m_vPos.y, m_vScale.x, m_vScale.y, _dc);
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

