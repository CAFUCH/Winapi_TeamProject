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
#include"Particle.h"
#include"SceneMgr.h"

const  float SliceSize = 32.f;

Melee_Enemy::Melee_Enemy(int _idx, ENTITY_ELEMENT_TYPE _type, int _hp, float _damage, float _atkDelay)
	:m_pTex(nullptr)
	, type(_type)
	, atkDelay(_atkDelay)
{
	SetMaxHP(_hp);
	SetHP(GetMaxHP());

	SetName(L"Enemy");

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
	/*Melee_Enemy Animation*/ {
		// Melee_Enemy Idle Animation
		{
			ANIM_RIGHT_HASH = L"Melee_Enemy_Right" + _idx;
			ANIM_LEFT_HASH = L"Melee_Enemy_Left" + _idx;
			ANIM_RIGHT_HIT_HASH = L"Melee_Enemy_Right_Hit" + _idx;
			ANIM_LEFT_HIT_HASH = L"Melee_Enemy_Left_Hit" + _idx;

			GetAnimator()->CreateAnim(ANIM_RIGHT_HASH, m_pTex, Vec2(0.f, 0.f), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_LEFT_HASH, m_pTex, Vec2(0.f, SliceSize * 1), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_RIGHT_HIT_HASH, m_pTex, Vec2(0.f, SliceSize * 2), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(ANIM_LEFT_HIT_HASH, m_pTex, Vec2(0.f, SliceSize * 3), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
		}

		GetAnimator()->PlayAnim(ANIM_RIGHT_HASH, true);
	}
}

Melee_Enemy::~Melee_Enemy()
{

}

void Melee_Enemy::EnterCollision(Collider* _pOther)
{
	curTime = atkDelay;

	Particle* m_pParticle = new Particle(PARTICLE_TYPE::HIT);
	m_pParticle->SetOwner(this);
	m_pParticle->SetPos({ GetPos().x, GetPos().y - GetScale().y / 2 });
	m_pParticle->SetScale({ 100.f, 100.f });
	SceneMgr::GetInst()->GetCurScene()->AddObject(m_pParticle, OBJECT_GROUP::PARTICLE);
}

void Melee_Enemy::StayCollision(Collider* _pOther)
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

void Melee_Enemy::ExitCollision(Collider* _pOther)
{

}

void Melee_Enemy::Update()
{
	GetAnimator()->Update();

	_ai->UpdateState();




}

