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
		m_animName = L"Effect_DieBlood";
		m_pTex = ResMgr::GetInst()->TexLoad(L"Effect_Hit", L"Texture\\Effect_DieBlood.bmp");
		GetAnimator()->CreateAnim(L"Effect_DieBlood", m_pTex, Vec2(0.f, 0.f),
			Vec2(200.f, 200.f), Vec2(200.f, 0.f), 24, 0.035f);
		lifeTime = 0.84f;
		m_x = 5;
		m_y = 7.5f;
		break;
	case PARTICLE_TYPE::WATHER_ELEM:
		break;
	case PARTICLE_TYPE::FIRE_ELEM:
		break;
	case PARTICLE_TYPE::ELECT_ELEM:
		break;
	case PARTICLE_TYPE::END:
		assert(m_eType == PARTICLE_TYPE::END);
		break;
	}
	
	// ������ �ִϸ��̼� ȣ��
	GetAnimator()->PlayAnim(m_animName, false);
}

Particle::~Particle()
{
}

void Particle::Update()
{
	// ��ƼŬ�� ������ ����ٴѴ�.
	SetPos({ m_pOwner->GetPos().x + m_x, m_pOwner->GetPos().y + m_y });

	// �ð��� ������ �����ȴ�.
	curTime += fDT;
	if (curTime >= lifeTime)
		EventMgr::GetInst()->DeleteObject(this);

	// �ִϸ��̼� ����
	GetAnimator()->Update();
}

void Particle::Render(HDC _dc)
{
	Component_Render(_dc);
}
