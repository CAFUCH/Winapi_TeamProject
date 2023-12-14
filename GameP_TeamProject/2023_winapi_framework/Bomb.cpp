#include "pch.h"
#include "Bomb.h"
#include "Scene.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"
#include "ElementMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Bomb::Bomb()
{
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bomb", L"Texture\\Bomb.bmp");
	m_pBulletTex = ResMgr::GetInst()->TexLoad(L"Bomb_Attack", L"Texture\\Explosion.bmp");

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// �ִϸ����� ����
	CreateAnimator();
	/*Bomb Animation*/ {
		GetAnimator()->CreateAnim(L"Bomb_Attack", m_pBulletTex, Vec2(0.f, 0.f),
			Vec2(280.f, 100.f), Vec2(280.f, 0.f), 7, 0.7f);
	}

	// ���ݷ� �ʱ�ȭ
	m_fDamage = 10.f;
	// ���� �ʱ�ȭ
	m_eElement = ENTITY_ELEMENT_TYPE::FIRE;
	// ��Ÿ� �ʱ�ȭ
	m_fDistance = 1000.f;
	// ������ �ʱ�ȭ
	m_fDelay = 0.3f;
	// ���� �ʱ�ȭ
	isAttack = false;

	m_fcurTime = 0.f;
	m_fWaitTime = 3.f;
	m_fLifeTime = 1.f;

	// ���� �� �ҷ�����
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	if (isWait)
	{
		m_fcurTime += fDT;
		if (m_fcurTime >= m_fWaitTime && isAttack == false)
		{
			isAttack = true;
			m_fcurTime = 0.f;
		}
	}

	if (isAttack == true)
	{
		// ������ ������ �������
		m_fcurTime += fDT;
		if (m_fcurTime >= m_fLifeTime)
		{
			isWait = false;
			isAttack = false;
		}

		GetAnimator()->Update();
	}
	else
		SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });

}

void Bomb::Render(HDC _dc)
{
	if (isAttack == true)
		Component_Render(_dc);
	else
	{
		TransparentBlt(_dc, (int)(m_vPos.x - m_vScale.x / 2)
			, (int)(m_vPos.y - m_vScale.y / 2)
			, m_pTex->GetWidth() * (m_vScale.x / 100)
			, m_pTex->GetHeight() * (m_vScale.y / 100)
			, m_pTex->GetDC(), 0, 0, m_pTex->GetWidth()
			, m_pTex->GetHeight(), RGB(255, 0, 255));
	}
}

void Bomb::EnterCollision(Collider* _pOther)
{
	if (isAttack == true)
	{
		if (_pOther->GetObj()->GetName() == L"Enemy")
		{
			// �� ȿ��
			m_fDamage = ElementMgr::GetInst()->Elemenet
			(this->m_eElement, _pOther->GetObj()->m_eElement, m_fDamage);

			// ������ �ֱ�
			_pOther->GetObj()->SetDamage(m_fDamage);

			// ��ƼŬ ����
			CreateParticle((PARTICLE_TYPE)m_eElement);
		}
	}
}

void Bomb::ExitCollision(Collider* _pOther)
{
}

void Bomb::StayCollision(Collider* _pOther)
{
}

void Bomb::Attack(Vec2 dir)
{
	isWait = true;
	GetAnimator()->PlayAnim(L"Bomb_Attack", false);
}
