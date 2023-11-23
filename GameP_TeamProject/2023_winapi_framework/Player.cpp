#include "pch.h"
#include "Player.h"
#include "Texture.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Player::Player() 
	: m_pTex(nullptr)
{
	ResMgr::GetInst()->TexLoad(L"Player", L"");
}

Player::~Player()
{
}

void Player::Update()
{
	Vec2 vPos = GetPos();

	if (KEY_PRESS(KEY_TYPE::LEFT))
	{
		// �ִϸ��̼�
		// ����
		vPos.x -= m_stat.m_fMoveSpeed * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::RIGHT))
	{

		vPos.x += m_stat.m_fMoveSpeed * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::UP))
	{

		vPos.y -= m_stat.m_fMoveSpeed * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::DOWN))
	{

		vPos.y += m_stat.m_fMoveSpeed * fDT;
	}
	if (KEY_PRESS(KEY_TYPE::SPACE))
	{
		// �ڵ� ����
		// ���� ���� ���
	}
}

//void Player::Render(HDC _dc)
//{
//}
