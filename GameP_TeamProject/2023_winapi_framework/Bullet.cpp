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
	// 이미지 불러오기
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bullet", L"Texture\\" + _name + L".bmp");

	// 콜라이더 생성
	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// 방향 초기화
	m_vDir = dir;
	// 이름 초기화
	SetName(_name);
	// 위치 초기화
	SetPos(pos);
	// 크기 초기화
	SetScale(scale);
	// 속도 초기화
	m_fAttackSpeed = 300.f;
	// 공격력 초기화
	m_fDamage = 10.f;
	// 원소 초기화
	m_eElement = ENTITY_ELEMENT_TYPE::FIRE;

	m_fcurTime = 0.f;
	m_fLifeTime = 3.f;

	// 현재 씬 불러오기
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
	m_vDir.Normalize();
	SetPos(m_vPos
		+ Vec2{ m_vDir.x * m_fAttackSpeed * fDT, m_vDir.y * m_fAttackSpeed * fDT });
	//SetPos(m_vDir);
}

void Bullet::Render(HDC _dc)
{
	TransparentBlt(_dc, (int)(m_vPos.x - m_vScale.x / 2)
		, (int)(m_vPos.y - m_vScale.y / 2)
		, m_pTex->GetWidth() * (m_vScale.x / 100)
		, m_pTex->GetHeight() * (m_vScale.y / 100)
		, m_pTex->GetDC(), 0, 0, m_pTex->GetWidth()
		, m_pTex->GetHeight(), RGB(255, 0, 255));

	Component_Render(_dc);
}

void Bullet::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();

	// 총알과 충돌한 것이 적 오브젝트라면
	if (pOtherObj->GetName() == L"Enemy")
	{
		// 상성 효과
		m_fDamage = ElementMgr::GetInst()->Elemenet
		(this->m_eElement, pOtherObj->m_eElement, m_fDamage);

		// 데미지 주기
		pOtherObj->SetDamage(m_fDamage);

		// 파티클 생성
		CreateParticle((PARTICLE_TYPE)m_eElement);

		// 총알 삭제
		EventMgr::GetInst()->DeleteWeapon(this);
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
