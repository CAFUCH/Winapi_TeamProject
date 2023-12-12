#include "pch.h"
#include "Range_Enemy.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Core.h"

#include "HP.h"
#include "Enemy.h"

#include "TimeMgr.h"

const  float SliceSize = 32.f;

Range_Enemy::Range_Enemy(int _idx, ENTITY_ELEMENT_TYPE _type, int _hp, float _damage, float _atkDelay)
	:m_pTex(nullptr)
	, type(_type)
	, atkDelay(_atkDelay)
{
	m_fDamage = _damage;

	SetBkMode(Core::GetInst()->GetMainDC(), 0);

	string pathname = "Texture\\pigeon.bmp";
	pathname.insert(14, to_string(_idx));
	wstring w_pathname;
	w_pathname.assign(pathname.begin(), pathname.end());

	m_pTex = ResMgr::GetInst()->TexLoad(L"Range_Enemy" + _idx, w_pathname);

	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(SliceSize, SliceSize)); // 상수 넣어주기

	// 애니메이터 생성
	CreateAnimator();
	/*Melee_Enemy Animation*/ {
		// Melee_Enemy Idle Animation
		{
			ANIM_RIGHT_HASH = L"Range_Enemy_Right" + _idx;
			ANIM_LEFT_HASH = L"Range_Enemy_Left" + _idx;
			ANIM_RIGHT_HIT_HASH = L"Range_Enemy_Right_Hit" + _idx;
			ANIM_LEFT_HIT_HASH = L"Range_Enemy_Left_Hit" + _idx;

			GetAnimator()->CreateAnim(ANIM_RIGHT_HASH, m_pTex, Vec2(0.f, 0.f), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_LEFT_HASH, m_pTex, Vec2(0.f, SliceSize * 1), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_RIGHT_HIT_HASH, m_pTex, Vec2(0.f, SliceSize * 2), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_LEFT_HIT_HASH, m_pTex, Vec2(0.f, SliceSize * 3), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
		}

		GetAnimator()->PlayAnim(ANIM_RIGHT_HASH, true);
	}

}

Range_Enemy::~Range_Enemy()
{

}

void Range_Enemy::EnterCollision(Collider* _pOther)
{
	curTime = atkDelay;

	Object* obj = _pOther->GetObj();
	obj->SetDamage(m_fDamage);
	Vec2 thisPos = GetPos();
	Vec2 pPos = obj->GetPos();
	Vec2 dir = (pPos - thisPos).Normalize();

	if (dir.x > 0)
		GetAnimator()->PlayAnim(ANIM_RIGHT_HIT_HASH, true);
	else if (dir.x < 0)
		GetAnimator()->PlayAnim(ANIM_LEFT_HIT_HASH, true);
}

void Range_Enemy::StayCollision(Collider* _pOther)
{
	curTime += fDT;

	if (curTime >= atkDelay) {
		Object* obj = _pOther->GetObj();
		obj->SetDamage(m_fDamage);

		Vec2 thisPos = GetPos();
		Vec2 pPos = obj->GetPos();
		Vec2 dir = (pPos - thisPos).Normalize();

		if (dir.x > 0)
			GetAnimator()->PlayAnim(ANIM_RIGHT_HIT_HASH, true);
		else if (dir.x < 0)
			GetAnimator()->PlayAnim(ANIM_LEFT_HIT_HASH, true);

		curTime = 0;
	}
}

void Range_Enemy::ExitCollision(Collider* _pOther)
{
}

void Range_Enemy::Update()
{
	GetAnimator()->Update();

	_ai->UpdateState();
}
