#include "pch.h"
#include "Melee_Enemy.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"

Melee_Enemy::Melee_Enemy(int _idx)
	:m_pTex(nullptr)
{
	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(50.f, 50.f)); // 상수 넣어주기

	// 애니메이터 생성
	CreateAnimator();
	/*Melee_Enemy Animation*/ {
		// Melee_Enemy Idle Animation
		{
			GetAnimator()->CreateAnim(L"Melee_Enemy_Idle_Front" + _idx, m_pTex, Vec2(0.f, 0.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Idle_Right" + _idx, m_pTex, Vec2(0.f, 128.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Idle_Left" + _idx, m_pTex, Vec2(0.f, 256.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Idle_Back" + _idx, m_pTex, Vec2(0.f, 384.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		}
		// Melee_Enemy Walk Animation
		{
			GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Front", m_pTex, Vec2(0.f, 512.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Right", m_pTex, Vec2(0.f, 640.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Left", m_pTex, Vec2(0.f, 768.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Back", m_pTex, Vec2(0.f, 896.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		}
		// Melee_Enemy Hit Animation
		{
			GetAnimator()->CreateAnim(L"Melee_Enemy_Hit_Front", m_pTex, Vec2(0.f, 1024.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Hit_Right", m_pTex, Vec2(0.f, 1152.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Hit_Left", m_pTex, Vec2(0.f, 1280.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Hitk_Back", m_pTex, Vec2(0.f, 1408.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
		}
		// Melee_Enemy Die Animationgj 
		{
			GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Front", m_pTex, Vec2(0.f, 1536.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Right", m_pTex, Vec2(0.f, 1664.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Left", m_pTex, Vec2(0.f, 1792.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Back", m_pTex, Vec2(0.f, 1920.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		}

		GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
	}
}

Melee_Enemy::~Melee_Enemy()
{
}

void Melee_Enemy::EnterCollision(Collider* _pOther)
{

}

void Melee_Enemy::StayCollision(Collider* _pOther)
{

}

void Melee_Enemy::ExitCollision(Collider* _pOther)
{
}

void Melee_Enemy::Update()
{

}
