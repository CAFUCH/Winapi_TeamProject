#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "HP.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"
#include "KeyMgr.h"
#include "EventMgr.h"

#include "UI.h"
#include "Scene.h"
#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

bool cmp1(std::pair<Vec2, double>& left, std::pair<Vec2, double>& right)
{
	return left.second < right.second;
}

Player::Player() 
	: m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"PlayerT", L"Texture\\lastPlayer.bmp");
	
	// ���� �� �ҷ�����
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f)); // ��� �־��ֱ�

	// �ִϸ����� ����
	CreateAnimator();
	/*Player Animation*/ {
		// Player Idle Animation
		{
			GetAnimator()->CreateAnim(L"Player_Idle_Front", m_pTex, Vec2(0.f, 0.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Right", m_pTex, Vec2(0.f, 128.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Left", m_pTex, Vec2(0.f, 256.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Idle_Back", m_pTex, Vec2(0.f, 384.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		}
		// Player Walk Animation
		{
			GetAnimator()->CreateAnim(L"Player_Walk_Front", m_pTex, Vec2(0.f, 512.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Right", m_pTex, Vec2(0.f, 640.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Left", m_pTex, Vec2(0.f, 768.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Walk_Back", m_pTex, Vec2(0.f, 896.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		}
		// Player Hit Animation
		{
			GetAnimator()->CreateAnim(L"Player_Hit_Front", m_pTex, Vec2(0.f, 1024.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hit_Right", m_pTex, Vec2(0.f, 1152.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hit_Left", m_pTex, Vec2(0.f, 1280.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Hitk_Back", m_pTex, Vec2(0.f, 1408.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 2, 0.2f);
		}
		// Player Die Animation
		{
			GetAnimator()->CreateAnim(L"Player_Die_Front", m_pTex, Vec2(0.f, 1536.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Right", m_pTex, Vec2(0.f, 1664.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Left", m_pTex, Vec2(0.f, 1792.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
			GetAnimator()->CreateAnim(L"Player_Die_Back", m_pTex, Vec2(0.f, 1920.f),
				Vec2(128.f, 128.f), Vec2(128.f, 0.f), 4, 0.2f);
		}

		m_strDir = {L"Front", Vec2(0, 1)};
		GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
	}

	// ���� ����
	{
		for (int i = 0; i < m_maxWeaponCnt; ++i)
			CreateWeapon(new Weapon());
	}

	// �ʱ�ȭ
	{
		m_fHpMax = 30.f;
		m_fHp = m_fHp;

		m_curWeaponIdx = 0;
		m_maxWeaponCnt = 3;
		m_vecWeapon.resize(m_maxWeaponCnt);

		m_fMoveSpeed = 150.f;		
	}

	// HP ����
	{
		//Object* pHP = new HP;
		//pHP->SetPos({ GetPos().x, GetPos().y - GetScale().y / 2 });
		//pHP->SetScale({ 100.f, 100.f });
		//m_pCurScene->AddObject(pHP, OBJECT_GROUP::UI);
	}
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
			//m_strDir = L"Back";
			m_velocity.y = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Back", true);
		}
		if (KEY_UP(KEY_TYPE::S))
		{
			//m_strDir = L"Front";
			m_velocity.y = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
		}
		if (KEY_UP(KEY_TYPE::A))
		{
			//m_strDir = L"Left";
			m_velocity.x = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Left", true);
		}
		if (KEY_UP(KEY_TYPE::D))
		{
			//m_strDir = L"Right";
			m_velocity.x = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Right", true);
		}
	}
	// Player KeyPress(Move)
	{
		if (KEY_PRESS(KEY_TYPE::W))
		{
			m_strDir = { L"Back", Vec2(2, 1)};
			//vPos.Normalize();
			GetAnimator()->PlayAnim(L"Player_Walk_Back", true);
			m_velocity.y = -m_fMoveSpeed;
			m_velocity.Normalize();
			//vPos.y -= m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::S))
		{
			m_strDir = { L"Front", Vec2(1, 2)};
			//vPos.Normalize();
			GetAnimator()->PlayAnim(L"Player_Walk_Front", true);
			m_velocity.y = m_fMoveSpeed;
			m_velocity.Normalize();
			//vPos.y += m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::A))
		{
			m_strDir = { L"Left", Vec2(1, 2)};
			//vPos.Normalize();
			GetAnimator()->PlayAnim(L"Player_Walk_Left", true);
			m_velocity.x = -m_fMoveSpeed;
			m_velocity.Normalize();
			//vPos.x -= m_fMoveSpeed * fDT;
		}
		if (KEY_PRESS(KEY_TYPE::D))
		{
			m_strDir = { L"Right", Vec2(2, 1)};
			//vPos.Normalize();
			GetAnimator()->PlayAnim(L"Player_Walk_Right", true);
			m_velocity.x = m_fMoveSpeed;
			m_velocity.Normalize();
			//vPos.x += m_fMoveSpeed * fDT;
		}

		//m_velocity.Normalize();

		vPos = m_velocity * fDT;
;	}

	// ����
	if (KEY_DOWN(KEY_TYPE::SPACE))
	{
		m_curWeapon = m_vecWeapon[0];
		//m_curWeapon = m_vecWeapon[m_curWeaponIdx];

		// �ڵ� ����
		AutoAim();

		// ���� ���� ���
		//m_curWeapon->Attack(m_vAttackDir);// �̰� ��ī��

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
			m_curWeaponIdx = m_maxWeaponCnt - 1;
		else if (m_curWeaponIdx >= m_maxWeaponCnt)
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

void Player::AutoAim()
{
	// ��ġ �޾ƿ���
	Vec2 vPos = GetPos();
	// *���ʹ��� ��ġ�� �Ÿ�
	vector<std::pair<Vec2, double>> testDist;

	for (size_t i = 0; i < m_vecEnemy.size(); ++i)
	{
		// ���� ���� �ۿ� �ִٸ� �˻����� �ʴ´�
		if (m_curWeapon->GetDistance() < m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()))
			continue;
		// ���� ����� �� ã��
		else
			testDist.push_back({ m_vecEnemy[i]->GetPos(), m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()) });
	}

	// �������� ���ķ� �Ÿ��� ���� ���� ���� ������ �д� // ���� ��� �ٲ���! -> �Ǳ���
	std::sort(testDist.begin(), testDist.end(), cmp1);
	// ���� ù ���� enemy ��ġ�� �ѱ��.
	m_vAttackDir = testDist[0].first;

	// ��ġ�� �Ÿ� �ʱ�ȭ
	//testDist.clear();
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
		GetAnimator()->PlayAnim(L"Player_Hit_" + m_strDir.first, false);
	}
}

void Player::StayCollision(Collider* _pOther)
{
}

void Player::ExitCollision(Collider* _pOther)
{
	GetAnimator()->PlayAnim(L"Player_Idle_" + m_strDir.first, false);
}
