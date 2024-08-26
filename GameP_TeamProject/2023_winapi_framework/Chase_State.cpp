#include "pch.h"
#include "Chase_State.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Animation.h"
#include "Animator.h"

#include "Object.h"

Chase_State::Chase_State(AI* _ai, float _speed)
	:ai(_ai)
	, speed(_speed)
{
	owner = ai->GetOnwer();
}

Chase_State::~Chase_State()
{

}

void Chase_State::Update()
{
	Vec2 thisPos = owner->GetPos();
	const Player* pObj = owner->GetPlayer();
	Vec2 pPos = pObj->GetPos(); //ÀÌ°Å ¾È‰Î 

	Vec2 dir = (pPos - thisPos).Normalize();

	if (pPos.Distance(thisPos, pPos) > (double).3f)
		thisPos.x += fDT * speed * dir.x;
	thisPos.y += fDT * speed * dir.y;

	//if (dir.y > 0)
	//	owner->GetAnimator()->PlayAnim(owner->ANIM_FRONT_HASH, true);
	//else if (dir.y < 0)				 
	//	owner->GetAnimator()->PlayAnim(owner->ANIM_BACK_HASH, true);

	if (dir.x > 0) 
		owner->GetAnimator()->PlayAnim(owner->ANIM_RIGHT_HASH, true);
	else if (dir.x < 0)							
		owner->GetAnimator()->PlayAnim(owner->ANIM_LEFT_HASH, true);

	owner->SetPos(thisPos);
}

void Chase_State::EnterState()
{

}

void Chase_State::ExitState()
{

}
