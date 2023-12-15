#include "pch.h"
#include "Bullet.h"
#include "Scene.h"
#include "Gun.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "ElementMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Particle.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Bullet::Bullet(wstring _name, Vec2 dir, Vec2 pos, Vec2 scale, Vec2 texSize, int test, Gun* owner)
{
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bullet", L"Texture\\" + _name + L".bmp");

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// �ִϸ����� ����
	/*Bomb Animation*/ {
		CreateAnimator();
		GetAnimator()->CreateAnim(L"Bullet_Attack", m_pTex, Vec2(0.f, 0.f),
			texSize, Vec2(0.f, 0.f), 1, 1.f);
		GetAnimator()->PlayAnim(L"Bullet_Attack", true);
	}

	// ���� �ʱ�ȭ
	m_vDir = dir;
	// �̸� �ʱ�ȭ
	SetName(_name);
	// ��ġ �ʱ�ȭ
	SetPos(pos);
	// ũ�� �ʱ�ȭ
	SetScale(scale);
	// �ӵ� �ʱ�ȭ
	m_fAttackSpeed = 500.f;
	// ���ݷ� �ʱ�ȭ
	m_fDamage = 10.f;
	// ���� �ʱ�ȭ
	m_eElement = ENTITY_ELEMENT_TYPE::FIRE;

	m_fcurTime = 0.f;
	m_fLifeTime = 1.5f;

	// ���� �� �ҷ�����
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();

	this->test = test;
	m_pOwner = owner;

	m_IsAlive = true;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (GetAlive())
	{
		// �ð��� ������ ����
		m_fcurTime += fDT;
		if (m_fcurTime >= m_fLifeTime)
			SetDead();
		//EventMgr::GetInst()->DeleteWeapon(this);

		m_vPos = GetPos();
		//m_vDir.Normalize();

		Vec2 dir = (m_vDir - m_vPos).Normalize();
		m_vPos.x += dir.x * m_fAttackSpeed * fDT;
		m_vPos.y += dir.y * m_fAttackSpeed * fDT;

		SetPos(m_vPos);

		//SetPos(m_vPos
		//	+ Vec2{ m_vDir.x * m_fAttackSpeed * fDT, m_vDir.y * m_fAttackSpeed * fDT });
	}
}

void Bullet::Render(HDC _dc)
{
	if (GetAlive())
		Component_Render(_dc);
}

void Bullet::EnterCollision(Collider* _pOther)
{
	if (GetAlive())
	{
		Object* pOtherObj = _pOther->GetObj();

		// �Ѿ˰� �浹�� ���� �� ������Ʈ���
		if (pOtherObj->GetName() == L"Enemy")
		{
			// �� ȿ��
			m_fDamage = ElementMgr::GetInst()->Elemenet
			(this->m_eElement, pOtherObj->m_eElement, m_fDamage);

			// ������ �ֱ�
			pOtherObj->SetDamage(m_fDamage);

			// ��ƼŬ ����
			CreateParticle((PARTICLE_TYPE)m_eElement);

			// �Ѿ� ����
			//EventMgr::GetInst()->DeleteWeapon(this);
			//m_pOwner->bullets.erase(test);
			SetDead();
		}
	}
}

void Bullet::ExitCollision(Collider* _pOther)
{
}

void Bullet::StayCollision(Collider* _pOther)
{
}

void Bullet::Attack(Vec2 dir)
{
}
