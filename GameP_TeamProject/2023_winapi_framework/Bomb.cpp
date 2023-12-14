#include "pch.h"
#include "Bomb.h"
#include "Scene.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Bomb::Bomb()
{
	// 이미지 불러오기
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bomb", L"Texture\\Bullet.bmp");

	// 콜라이더 생성
	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// 애니메이터 생성
	CreateAnimator();
	/*Bomb Animation*/ {
		GetAnimator()->CreateAnim(L"Bomb_Attack", m_pTex, Vec2(0.f, 0.f),
			Vec2(64.f, 32.f), Vec2(64.f, 0.f), 12, 0.025f);
		GetAnimator()->PlayAnim(L"Bomb_Attack", false);
	}

	m_fDistance = 1000.f;
	m_fDelay = 0.3f;
	isAttack = false;
}

Bomb::~Bomb()
{
}

void Bomb::Update()
{
	if (isAttack == true)
	{
		// 공격 할 것?..
	}
	else
		SetPos({ m_pOwner->GetPos().x - 100, m_pOwner->GetPos().y });

	GetAnimator()->Update();
}

void Bomb::Render(HDC _dc)
{
	Component_Render(_dc);
}

void Bomb::Attack(Vec2 dir)
{
	GetAnimator()->PlayAnim(L"Bomb_Attack", false);

	isAttack = true;
}
