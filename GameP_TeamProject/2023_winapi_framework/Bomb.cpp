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
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bomb", L"Texture\\bomb.bmp");
	m_pBulletTex = ResMgr::GetInst()->TexLoad(L"Bomb_Attack", L"Texture\\Explosion.bmp");

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(200.f, 50.f));

	// �ִϸ����� ����
	CreateAnimator();
	/*Bomb Animation*/ {
		GetAnimator()->CreateAnim(L"Bomb_Idle", m_pTex, Vec2(0.f, 0.f),
			Vec2(32.f, 32.f), Vec2(0.f, 0.f), 1, 1.f);
		GetAnimator()->CreateAnim(L"Bomb_Attack", m_pBulletTex, Vec2(0.f, 0.f),
			Vec2(280.f, 100.f), Vec2(280.f, 0.f), 7, 0.7f);
		GetAnimator()->PlayAnim(L"Bomb_Idle", true);
	}

	// ���ݷ� �ʱ�ȭ
	m_fDamage = 10.f;
	// ���� �ʱ�ȭ
	m_eElement = ENTITY_ELEMENT_TYPE::FIRE;
	// ��Ÿ� �ʱ�ȭ
	m_fDistance = 1000.f;
	// ������ �ʱ�ȭ
	m_fDelay = 0.3f;
	// eorl chrlghk
	isWait = false;
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
		if (m_fcurTime >= m_fWaitTime)
		{
			isAttack = true;
			m_fcurTime = 0.f;
			GetAnimator()->PlayAnim(L"Bomb_Attack", false);
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
			GetAnimator()->PlayAnim(L"Bomb_Idle", true);
		}
	}
	
	if (isWait == false && isAttack == false)
		SetPos({ m_pOwner->GetPos().x, m_pOwner->GetPos().y + 15 });

	GetAnimator()->Update();
}

void Bomb::Render(HDC _dc)
{
 	Component_Render(_dc);
	//if (isAttack == true)
	//else
	//{
	//	TransparentBlt(_dc, (int)(m_vPos.x - m_vScale.x / 2)
	//		, (int)(m_vPos.y - m_vScale.y / 2)
	//		, m_pTex->GetWidth() * (m_vScale.x / 100)
	//		, m_pTex->GetHeight() * (m_vScale.y / 100)
	//		, m_pTex->GetDC(), 0, 0, m_pTex->GetWidth()
	//		, m_pTex->GetHeight(), RGB(255, 0, 255));
	//}
}

void Bomb::EnterCollision(Collider* _pOther)
{
	int a = 0;
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
}
