#include "pch.h"
#include "Player.h"
#include "Weapon.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Player::Player() 
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\Player.png");

	CreateCollider();
	//GetCollider()->SetScale(Vec2(m_pTex->GetWidth(), m_pTex->GetHeight())); // 상수 넣어주기

	CreateAnimator();
	/*Player Animation*/ {
		// Player Idle Animation
		{
			GetAnimator()->CreateAnim(L"Player_Idle_Front", m_pTex, Vec2(0.f, 0.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Right", m_pTex, Vec2(0.f, 50.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Left", m_pTex, Vec2(0.f, 100.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Back", m_pTex, Vec2(0.f, 150.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
		}
		// Player Walk Animation
		{
			GetAnimator()->CreateAnim(L"Player_Walk_Front", m_pTex, Vec2(0.f, 200.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Right", m_pTex, Vec2(0.f, 250.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Left", m_pTex, Vec2(0.f, 400.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Back", m_pTex, Vec2(0.f, 450.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
		}
		// Player Hit Animation
		{
			GetAnimator()->CreateAnim(L"Player_Hit_Front", m_pTex, Vec2(0.f, 500.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hit_Right", m_pTex, Vec2(0.f, 550.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hit_Left", m_pTex, Vec2(0.f, 600.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hitk_Back", m_pTex, Vec2(0.f, 650.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
		}
		// Player Die Animation
		{
			GetAnimator()->CreateAnim(L"Player_Die_Front", m_pTex, Vec2(0.f, 700.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Right", m_pTex, Vec2(0.f, 750.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Left", m_pTex, Vec2(0.f, 800.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Back", m_pTex, Vec2(0.f, 850.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
		}
	}
}

Player::~Player()
{
}

void Player::Update()
{
	Vec2 vPos = GetPos();
	/*Player KeyUp(Stop)*/ {
		if (KEY_UP(KEY_TYPE::W))
		{
			m_strDir = L"Front";
			GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
		}
		if (KEY_UP(KEY_TYPE::S))
		{
			m_strDir = L"Back";
			GetAnimator()->PlayAnim(L"Player_Idle_Back", true);
		}
		if (KEY_UP(KEY_TYPE::A))
		{
			m_strDir = L"Left";
			GetAnimator()->PlayAnim(L"Player_Idle_Left", true);
		}
		if (KEY_UP(KEY_TYPE::D))
		{
			m_strDir = L"Right";
			GetAnimator()->PlayAnim(L"Player_Idle_Right", true);
		}
	}
	/*Player KeyPress(Move)*/ {
		if (KEY_PRESS(KEY_TYPE::W))
		{
			m_strDir = L"Front";
			GetAnimator()->PlayAnim(L"Player_Walk_Front", true);
			vPos.y -= m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::S))
		{
			m_strDir = L"Back";
			GetAnimator()->PlayAnim(L"Player_Walk_Back", true);
			vPos.y += m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::A))
		{
			m_strDir = L"Left";
			GetAnimator()->PlayAnim(L"Player_Walk_Left", true);
			vPos.x -= m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::D))
		{
			m_strDir = L"Right";
			GetAnimator()->PlayAnim(L"Player_Walk_Right", true);
			vPos.x += m_fMoveSpeed * fDT;
		}
	}

	if (KEY_DOWN(KEY_TYPE::SPACE))
	{
		// 자동 조준
		AutoAim();

		// 현재 무기 사용
		m_curWeapon->Attack(m_vAttackDir);
	}

	SetPos(vPos);
	GetAnimator()->Update();
}

void Player::AutoAim()
{
	// 가장 가까운 적을 찾아 적의 위치를 저장한다...
	// 현재 씬의 에너미를 다 가져오고... 음...
}

void Player::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();

	if (pOtherObj->GetName() == L"Enemy" || pOtherObj->GetName() == L"Enemy_Bullet")
	{
		SetDamage(pOtherObj->GetDamage());
		GetAnimator()->PlayAnim(L"Player_Hit_" + m_strDir, false);
	}
}

void Player::ExitCollision(Collider* _pOther)
{
}

void Player::StayCollision(Collider* _pOther)
{
}
