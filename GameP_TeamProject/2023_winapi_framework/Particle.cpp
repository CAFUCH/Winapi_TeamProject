#include "pch.h"
#include "Particle.h"

#include "ResMgr.h"
#include "Animator.h"
#include "Animation.h"

Particle::Particle(PARTICLE_TYPE _type)
	: m_eType(_type)
{
	CreateAnimator();

	switch (m_eType)
	{
	case PARTICLE_TYPE::ATTACK:
		m_pTex = ResMgr::GetInst()->TexLoad(L"PlayerT", L"Texture\\Player.bmp");
		m_animName = L"Player_Idle_Front";
		GetAnimator()->CreateAnim(L"Player_Idle_Front", m_pTex, Vec2(0.f, 0.f),
			Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		break;
	case PARTICLE_TYPE::HIT:
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
	default:
		break;
	}
}

Particle::~Particle()
{
}

void Particle::Update()
{
	GetAnimator()->PlayAnim(m_animName, false);
}
