#include "pch.h"
#include "Bullet.h"
#include "Scene.h"

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

Bullet::Bullet(wstring _name, Vec2 dir, Vec2 pos, Vec2 scale)
{
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bullet", L"Texture\\" + _name + L".bmp");
	// ���� �ʱ�ȭ
	m_vDir = dir;
	// �̸� �ʱ�ȭ
	SetName(_name);
	// ��ġ �ʱ�ȭ
	SetPos(pos);
	// ũ�� �ʱ�ȭ
	SetScale(scale);
	// �ӵ� �ʱ�ȭ
	m_fAttackSpeed = 300.f;

	m_fcurTime = 0.f;
	m_fLifeTime = 3.f;

	// ���� �� �ҷ�����
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	m_fcurTime += fDT;
	if (m_fcurTime >= m_fLifeTime)
		EventMgr::GetInst()->DeleteWeapon(this);

	m_vPos = GetPos();
	//m_vDir.Normalize();
	//SetPos(m_vPos
	//	+ Vec2{ m_vDir.x * m_fAttackSpeed * fDT, m_vDir.y * m_fAttackSpeed * fDT });
	SetPos(m_vDir);
}

void Bullet::Render(HDC _dc)
{
	TransparentBlt(_dc, (int)(m_vPos.x - m_vScale.x / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, m_pTex->GetWidth() * (m_vScale.x / 100)
		, m_pTex->GetHeight() * (m_vScale.y / 100)
		, m_pTex->GetDC(), 0, 0, m_pTex->GetWidth()
		, m_pTex->GetHeight(), RGB(255, 0, 255));
}

void Bullet::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();

	// �Ѿ˰� �浹�� ���� �� ������Ʈ���
	if (pOtherObj->GetName() == L"Enemy")
	{
		// �� ȿ��
		m_fDamage = ElementMgr::GetInst()->Elemenet
		(this->m_eElement, pOtherObj->m_eElement, pOtherObj->GetDamage());

		// ������ �ֱ�
		pOtherObj->SetDamage(m_fDamage);

		// Hit ��ƼŬ ����
		{
			m_pCurScene->AddObject
				(pOtherObj->CreateParticle(PARTICLE_TYPE::HIT)
				, OBJECT_GROUP::PARTICLE);
		}

		delete this;
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
