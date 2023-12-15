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
	// 이미지 불러오기
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bullet", L"Texture\\" + _name + L".bmp");

	// 콜라이더 생성
	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// 애니메이터 생성
	/*Bomb Animation*/ {
		CreateAnimator();
		GetAnimator()->CreateAnim(L"Bullet_Attack", m_pTex, Vec2(0.f, 0.f),
			texSize, Vec2(0.f, 0.f), 1, 1.f);
		GetAnimator()->PlayAnim(L"Bullet_Attack", true);
	}

	// 방향 초기화
	m_vDir = dir;
	// 이름 초기화
	SetName(_name);
	// 위치 초기화
	SetPos(pos);
	// 크기 초기화
	SetScale(scale);
	// 속도 초기화
	m_fAttackSpeed = 500.f;
	// 공격력 초기화
	m_fDamage = 10.f;
	// 원소 초기화
	m_eElement = ENTITY_ELEMENT_TYPE::FIRE;

	m_fcurTime = 0.f;
	m_fLifeTime = 1.5f;

	// 현재 씬 불러오기
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
		// 시간이 지나면 삭제
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
