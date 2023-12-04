#include "pch.h"
#include "Object.h"

#include "KeyMgr.h"
#include "TimeMgr.h"
#include "EventMgr.h"

#include "Collider.h"
#include "Animator.h"
#include "Weapon.h"
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
	// �ش� ������Ʈ�� �ִٸ� ������Ʈ�� ������ �Բ� ����
	if (nullptr != m_pCollider)
		delete m_pCollider;
	if (nullptr != m_pAnimator)
		delete m_pAnimator;
	for (Weapon* weapon : m_vecWeapon)
	{
		if (nullptr != weapon)
			delete weapon;
	}

	// Entity�� �Ҹ��ڿ��� �������� �ʴ´�.
	// Entity�� ü�¿� ���� ���� ���ΰ� �����Ǳ� ������ EventMgr���� ������ �������ְ� �մ�.!
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

// ��Ȯ���� weapon�̶�� ������Ʈ�� �����ϴ� ��..
void Object::CreateWeapon()
{
	m_vecWeapon.push_back(new Weapon(this));
	// �Ȱ����� �� ���ʸ� weapon�ʿ��� �����ϵ��� ���ִ�?
}
//void Object::CreateWeapon(Weapon* _weapon)
//{
//	_weapon->m_pOwner = this;
//	m_vecWeapon.push_back(_weapon);
//}
//Weapon* Object::CreateWeapon(Weapon* _weapon)
//{
//	_weapon->m_pOwner = this;
//	return _weapon;
//	//m_vecWeapon.push_back(_weapon);
//}

void Object::Update()
{
}

void Object::FinalUpdate()
{
	// �ݶ��̴��� Update
	if (m_pCollider)
		m_pCollider->FinalUpdate();
	for (Weapon* weapon : m_vecWeapon)
	{
		if (weapon)
			weapon->Update();
	}
}

void Object::Render(HDC _dc)
{
	// �⺻���� Render (���������� �����ϰ� ���� obj�� �ִٸ� �ش� ��ü���� ��������)
	// �ش� Obj�� ���Ե� Scene�� Render���� m_vObj ���Ϳ� ��� ȣ��ȴ�.
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
	// �ش� ������Ʈ�� �ִٸ� ������Ʈ�� Render�� �Բ� ����
	if (nullptr != m_pCollider)
		m_pCollider->Render(_dc);
	if (nullptr != m_pAnimator)
		m_pAnimator->Render(_dc);
	for (Weapon* weapon : m_vecWeapon)
	{
		if (nullptr != weapon)
			weapon->Render(_dc);
	}
}

void Object::SetDamage(float _damage)
{
	//if (m_fHp - _damage <= 0)
	//{
	//	m_fHp = 0;
	//	// PoolMgr�� ����ҰŸ� EventMgr�� �� ���� �Ѵ�
	//	EventMgr::GetInst()->DeleteObject(this);
	//}
	//else
	//	m_fHp -= _damage;
}

