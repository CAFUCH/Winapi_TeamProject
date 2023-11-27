#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "Scene.h"

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
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"PlayerT", L"Texture\\test1.bmp");
	//m_pTex = ResMgr::GetInst()->TexLoad(L"Player", L"Texture\\jiwoo.bmp");
	
	// ���� �� �ҷ�����
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(32.f, 32.f)); // ��� �־��ֱ�

	// �ִϸ����� ����
	CreateAnimator();
	/*Player Animation*/ {
		// Player Idle Animation
		{
			GetAnimator()->CreateAnim(L"Player_Idle_Front", m_pTex, Vec2(0.f, 0.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Right", m_pTex, Vec2(0.f, 32.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Left", m_pTex, Vec2(0.f, 64.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Back", m_pTex, Vec2(0.f, 96.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
		}
		// Player Walk Animation
		{
			GetAnimator()->CreateAnim(L"Player_Walk_Front", m_pTex, Vec2(0.f, 128.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Right", m_pTex, Vec2(0.f, 160.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Left", m_pTex, Vec2(0.f, 192.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Back", m_pTex, Vec2(0.f, 224.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
		}
		// Player Hit Animation
		{
			GetAnimator()->CreateAnim(L"Player_Hit_Front", m_pTex, Vec2(0.f, 256.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hit_Right", m_pTex, Vec2(0.f, 288.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hit_Left", m_pTex, Vec2(0.f, 320.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hitk_Back", m_pTex, Vec2(0.f, 352.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 2, 0.2f);
		}
		// Player Die Animation
		{
			GetAnimator()->CreateAnim(L"Player_Die_Front", m_pTex, Vec2(0.f, 384.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Right", m_pTex, Vec2(0.f, 416.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Left", m_pTex, Vec2(0.f, 448.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Back", m_pTex, Vec2(0.f, 480.f),
				Vec2(32.f, 32.f), Vec2(32.f, 0.f), 4, 0.2f);
		}

		m_strDir = L"Front";
		GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
	}

	// Weapon �ʱⰪ
	{
		m_curWeaponIdx = 0;
		m_maxWeaponCnt = 3;
		m_vecWeapon.resize(m_maxWeaponCnt);
	}

	m_fMoveSpeed = 50.f;
}

Player::~Player()
{
}

void Player::Update()
{
	// ��ġ ��������
	Vec2 vPos = GetPos();

	// Player KeyUp(Stop)
	{
		if (KEY_UP(KEY_TYPE::W))
		{
			m_strDir = L"Back";
			GetAnimator()->PlayAnim(L"Player_Idle_Back", true);
		}
		if (KEY_UP(KEY_TYPE::S))
		{
			m_strDir = L"Front";
			GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
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
	// Player KeyPress(Move)
	{
		if (KEY_PRESS(KEY_TYPE::W))
		{
			m_strDir = L"Back";
			GetAnimator()->PlayAnim(L"Player_Walk_Back", true);
			vPos.y -= m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::S))
		{
			m_strDir = L"Front";
			GetAnimator()->PlayAnim(L"Player_Walk_Front", true);
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

	// ����
	if (KEY_DOWN(KEY_TYPE::SPACE))
	{
		// �ڵ� ����
		AutoAim();

		// ���� ���� ���
		m_curWeapon->Attack(m_vAttackDir);

		// ���� ��ġ �ʱ�ȭ
		m_vAttackDir = {0, 0};
	}

	// ���� ��ü
	{
		if (KEY_DOWN(KEY_TYPE::Q))
			--m_curWeaponIdx;
		if (KEY_DOWN(KEY_TYPE::E))
			++m_curWeaponIdx;

		if (m_curWeaponIdx < 0)
			m_curWeaponIdx = m_maxWeaponCnt;
		else if (m_curWeaponIdx > m_maxWeaponCnt)
			m_curWeaponIdx = 0;

		m_curWeapon = m_vecWeapon[m_curWeaponIdx];
	}

	// ������� ���ʹ̸� �����´�.
	m_vecEnemy = m_pCurScene->GetGroupObject(OBJECT_GROUP::MONSTER);

	// ��ġ �����ϱ�
	SetPos(vPos);
	// �ִϸ��̼� ����
	GetAnimator()->Update();
}

bool cmp1(std::pair<Vec2, double>& left, std::pair<Vec2, double>& right)
{
	return left.second > right.second;
}

void Player::AutoAim()
{
	// ��� ���ʹ� �˻��ϸ� player.pos - enemy.pos�� ���밪�� ���� ���� ���� ã��... zz...

	// ��ġ �޾ƿ���
	Vec2 vPos = GetPos();
	// *���ʹ��� ��ġ�� �Ÿ�
	vector<std::pair<Vec2, double>> testDist;

	for (size_t i = 0; i < m_vecEnemy.size(); ++i)
	{
		// ���� ���� �ۿ� �ִٸ� �˻����� �ʴ´�
		if (m_curWeapon->GetDistance() > m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()))
			continue;
		// ���� ����� �� ã��
		else
			testDist.push_back({ m_vecEnemy[i]->GetPos(), m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()) });
	}

	// �������� ���ķ� �Ÿ��� ���� ���� ���� ������ �д�
	//std::sort(testDist.begin()->second, testDist.end()->second);
	std::sort(testDist.begin(), testDist.end(), cmp1);
	// ���� ù ���� enemy ��ġ�� �ѱ��.
	m_vAttackDir = testDist[0].first;

	// ��ġ�� �Ÿ� �ʱ�ȭ
	testDist.clear();
}

void Player::EnterCollision(Collider* _pOther)
{
	const Object* pOtherObj = _pOther->GetObj();

	// �÷��̾� �浹�� ������Ʈ (��, �� ����, ����߸��� ����(?))
	if (pOtherObj->GetName() == L"Enemy" || pOtherObj->GetName() == L"Enemy_Bullet")
	{
		// ������ �ޱ�
		SetDamage(pOtherObj->GetDamage());
		// Hit �ִϸ��̼� ����
		GetAnimator()->PlayAnim(L"Player_Hit_" + m_strDir, false);
	}
}

void Player::ExitCollision(Collider* _pOther)
{
}

void Player::StayCollision(Collider* _pOther)
{
}
