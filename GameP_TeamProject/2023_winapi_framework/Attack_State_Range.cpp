#include "pch.h"
#include "Attack_State_Range.h"
#include "AI.h"
#include "Enemy.h"
#include "Player.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Animation.h"
#include "Animator.h"

#include "Object.h"
#include "Core.h"

Attack_State_Range::Attack_State_Range(AI* _ai)
	:ai(_ai)
{
	owner = ai->GetOnwer();
}

Attack_State_Range::~Attack_State_Range()
{

}

void Attack_State_Range::Update()
{
	curTime += fDT;
	if (curTime >= waitTime) {
		//°ø°Ý¤¡¤¡
		owner->GetDamage();

		ai->ChangeState(ENEMY_STATE::CHASE);
		//Vec2 thisPos = owner->GetPos();
		//const Player* pObj = owner->GetPlayer();
		//Vec2 pPos = pObj->GetPos();

		//Vec2 dir = (pPos - thisPos).Normalize();

		//if (pPos.Distance(thisPos, pPos) > 300.f) {
		//	
		//}
		//else
		//{
		//	ai->ChangeState(ENEMY_STATE::IDLE);
		//}
	}
}

void Attack_State_Range::EnterState()
{
	curTime = 0;
}

void Attack_State_Range::ExitState()
{
}
