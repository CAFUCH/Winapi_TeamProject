#include "pch.h"
#include "Enemy.h"
#include "AI.h"
#include "Idle_State.h"

Idle_State::Idle_State(AI* _ai)
	: ai(_ai)
{

}

Idle_State::~Idle_State()
{
}

void Idle_State::Update()
{
	AI* pAI = GetAI();

	//Enemy* enemy = GetAI()->GetEnemy();

  /*  Vector2f curpos = enemy->GetSprite().getPosition();
	curpos.x += 500.f * _dt * m_dir.x;
	float fDist = abs(m_centerpos.x - curpos.x) - m_fMaxDis;
	if (fDist > 0.f)
	{
		m_dir.x *= -1.f;
		curpos.x += fDist * m_dir.x;
	}
	enemy->GetSprite().setPosition(curpos);*/
}

void Idle_State::EnterState()
{
}

void Idle_State::ExitState()
{
}