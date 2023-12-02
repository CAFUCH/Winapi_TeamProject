#include "pch.h"
#include "Melee_Enemy.h"
#include "Animation.h"
#include "Animator.h"
#include "Collider.h"
#include "ResMgr.h"
#include "Core.h"

const float SliceSize = 32.f;

Melee_Enemy::Melee_Enemy(int _idx)
	:m_pTex(nullptr)
{

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
			GetAnimator()->CreateAnim(L"Melee_Enemy_Right" + _idx, m_pTex, Vec2(0.f, 0.f), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Front" + _idx, m_pTex, Vec2(0.f, SliceSize * 1), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Back" + _idx, m_pTex, Vec2(0.f, SliceSize * 2), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
			GetAnimator()->CreateAnim(L"Melee_Enemy_Left" + _idx, m_pTex, Vec2(0.f, SliceSize * 3), Vec2(SliceSize, SliceSize), Vec2(SliceSize, 0.f), 8, 0.2f);
		}
		//// Melee_Enemy Walk Animation
		//{
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Front", m_pTex, Vec2(0.f, 512.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Right", m_pTex, Vec2(0.f, 640.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Left", m_pTex, Vec2(0.f, 768.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Walk_Back", m_pTex, Vec2(0.f, 896.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//}
		//// Melee_Enemy Hit Animation
		//{
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Hit_Front", m_pTex, Vec2(0.f, 1024.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Hit_Right", m_pTex, Vec2(0.f, 1152.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Hit_Left", m_pTex, Vec2(0.f, 1280.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Hitk_Back", m_pTex, Vec2(0.f, 1408.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
		//}
		//// Melee_Enemy Die Animationgj 
		//{
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Front", m_pTex, Vec2(0.f, 1536.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Right", m_pTex, Vec2(0.f, 1664.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Left", m_pTex, Vec2(0.f, 1792.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//	GetAnimator()->CreateAnim(L"Melee_Enemy_Die_Back", m_pTex, Vec2(0.f, 1920.f), Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		//}

		GetAnimator()->PlayAnim(L"Melee_Enemy_Front" + _idx, true);
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
	GetAnimator()->Update();

	_ai->UpdateState();



	
}

