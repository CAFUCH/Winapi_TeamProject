#include "pch.h"
#include "Melee_Enemy.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Core.h"

#include "HP.h"
#include "Enemy.h"

#include "TimeMgr.h"

const float SliceSize = 32.f;

Melee_Enemy::Melee_Enemy(int _idx, ENTITY_ELEMENT_TYPE _type, int _hp, float _damage, float _atkDelay)
	:m_pTex(nullptr)
	, type(_type)
	, atkDelay(_atkDelay)
{
	m_fDamage = _damage;

	SetBkMode(Core::GetInst()->GetMainDC(), 0);

	string pathname = "Texture\\snake.bmp";
	pathname.insert(13, to_string(_idx));
	wstring w_pathname;
	w_pathname.assign(pathname.begin(), pathname.end());

	m_pTex = ResMgr::GetInst()->TexLoad(L"Melee_Enemy" + _idx, w_pathname);

	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(SliceSize, SliceSize)); // 상수 넣어주기

	// 애니메이터 생성
	CreateAnimator();
	//m_pTex = (ResMgr::GetInst()->TexLoad(L"Melee_Enemy_1", L"Texture\\snake1.bmp"));
	/*Melee_Enemy Animation*/ {
		// Melee_Enemy Idle Animation
		{
			ANIM_RIGHT_HASH = L"Melee_Enemy_Right" + _idx;
			ANIM_LEFT_HASH = L"Melee_Enemy_Left" + _idx;
			ANIM_RIGHT_HIT_HASH = L"Melee_Enemy_Right_Hit" + _idx;
			ANIM_LEFT_HIT_HASH = L"Melee_Enemy_Left_Hit" + _idx;

			GetAnimator()->CreateAnim(ANIM_RIGHT_HASH, m_pTex, Vec2(0.f, 0.f), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_LEFT_HIT_HASH, m_pTex, Vec2(0.f, SliceSize * 1), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_RIGHT_HIT_HASH, m_pTex, Vec2(0.f, SliceSize * 2), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_LEFT_HASH, m_pTex, Vec2(0.f, SliceSize * 3), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
		}

		GetAnimator()->PlayAnim(L"Melee_Enemy_Front" + _idx, true);
	}
}

Melee_Enemy::~Melee_Enemy()
{

}

void Melee_Enemy::EnterCollision(Collider* _pOther)
{
	curTime = atkDelay;
}

void Melee_Enemy::StayCollision(Collider* _pOther)
{
	curTime += fDT;

	if (curTime >= atkDelay) {
		Object* obj = _pOther->GetObj();
		obj->SetDamage(m_fDamage);

		curTime = 0;
	}
}

void Melee_Enemy::ExitCollision(Collider* _pOther)
{
}

void Melee_Enemy::Update()
{
	GetAnimator()->Update();

	_ai->UpdateState();




}

