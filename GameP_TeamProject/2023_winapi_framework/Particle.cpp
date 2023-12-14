#include "pch.h"
#include "Particle.h"
#include "Core.h"

#include "Animator.h"
#include "Animation.h"

#include "ResMgr.h"
#include "TimeMgr.h"
#include "EventMgr.h"
#include "KeyMgr.h"

Particle::Particle(PARTICLE_TYPE _type)
	: m_eType(_type)
{
	curTime = 0.f;
	CreateAnimator();

	switch (m_eType)
	{
	case PARTICLE_TYPE::ATTACK:
		break;
	case PARTICLE_TYPE::HIT:
		m_animName = L"Effect_Hit";
		m_pTex = ResMgr::GetInst()->TexLoad(L"Effect_Hit", L"Texture\\Effect_DieBlood.bmp");
		GetAnimator()->CreateAnim(L"Effect_Hit", m_pTex, Vec2(0.f, 0.f),
			Vec2(200.f, 200.f), Vec2(200.f, 0.f), 24, 0.02f);
		lifeTime = 0.48f;
		m_x = 5;
		m_y = 7.5f;
		break;
	case PARTICLE_TYPE::WATHER_ELEM:
		m_animName = L"Effect_Water";
		m_pTex = ResMgr::GetInst()->TexLoad(L"Effect_Water", L"Texture\\Effect_Water.bmp");
		GetAnimator()->CreateAnim(L"Effect_Water", m_pTex, Vec2(0.f, 0.f),
			Vec2(106.f, 44.f), Vec2(106.f, 0.f), 10, 0.075f);
		lifeTime = 0.75f;
		m_x = 5;
		m_y = 7.5f;
		break;
	case PARTICLE_TYPE::FIRE_ELEM:
		m_animName = L"Effect_Fire";
		m_pTex = ResMgr::GetInst()->TexLoad(L"Effect_Fire", L"Texture\\Effect_Fire.bmp");
		GetAnimator()->CreateAnim(L"Effect_Fire", m_pTex, Vec2(0.f, 0.f),
			Vec2(218.f, 76.f), Vec2(218.f, 0.f), 12, 0.075f);
		lifeTime = 0.75f;
		m_x = 5;
		m_y = 7.5f;
		break;
	case PARTICLE_TYPE::ELECT_ELEM:
		m_animName = L"Effect_Elect";
		m_pTex = ResMgr::GetInst()->TexLoad(L"Effect_Elect", L"Texture\\Effect_Elect.bmp");
		GetAnimator()->CreateAnim(L"Effect_Elect", m_pTex, Vec2(0.f, 0.f),
			Vec2(128.f, 128.f), Vec2(128.f, 0.f), 7, 0.05f);
		lifeTime = 0.35f;
		m_x = 5;
		m_y = 7.5f;
		break;
	case PARTICLE_TYPE::END:
		assert(m_eType == PARTICLE_TYPE::END);
		break;
	}
	
	// 실행할 애니메이션 호출
	GetAnimator()->PlayAnim(m_animName, false);
}

Particle::~Particle()
{
}

void Particle::Update()
{
	// 파티클의 주인을 따라다닌다.
	if (m_pOwner != nullptr)
		SetPos({ m_pOwner->GetPos().x + m_x, m_pOwner->GetPos().y + m_y });

	// 시간이 지나면 삭제된다.
	curTime += fDT;
	if (curTime >= lifeTime)
		EventMgr::GetInst()->DeleteObject(this);

	// 애니메이션 실행
	GetAnimator()->Update();
}

void Particle::Render(HDC _dc)
{
	Component_Render(_dc);
}
