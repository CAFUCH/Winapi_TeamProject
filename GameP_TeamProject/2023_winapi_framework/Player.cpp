#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "HP.h"
#include "Particle.h"
//#include "Camera.h"

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
	m_fHp = 30;
	m_fHpMax = 30;
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"PlayerT", L"Texture\\Player.bmp");

	// ���� �� �ҷ�����
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();

	// �ʱ�ȭ
	{
		// ���� ���� �ε���
		m_curWeaponIdx = 0;
		// ���� ���� ����
		m_maxWeaponCnt = 3;

		// �̵� �ӵ�
		m_fMoveSpeed = 150.f;
		// ��ġ �ʱ�ȭ
		m_velocity = { 0, 0 };

		// ü�� �ʱ�ȭ
		SetMaxHP(20.f);
		SetHP(GetMaxHP());
	}

	// �ݶ��̴� ������Ʈ ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f)); // ��� �־��ֱ�

	// �ִϸ����� ������Ʈ ����
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

		m_strDir = L"Front";
		GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
	}

	// ���� ������Ʈ ����
	{
		for (int i = 0; i < m_maxWeaponCnt; ++i)
			CreateWeapon();
	}

	// HP ����
	{
		HP* pHP = new HP();
		pHP->SetOwner(this);
		pHP->SetPos({ GetPos().x, GetPos().y - GetScale().y / 2 });
		pHP->SetScale({ 100.f, 100.f });
		pHP->SetMaxHP(GetMaxHP());
		pHP->SetHP(GetHP());
		m_pCurScene->AddObject(pHP, OBJECT_GROUP::UI);
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
			m_strDir = L"Back";
			m_velocity.y = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Back", true);
		}
		if (KEY_UP(KEY_TYPE::S))
		{
			m_strDir = L"Front";
			m_velocity.y = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Front", true);
		}
		if (KEY_UP(KEY_TYPE::A))
		{
			m_strDir = L"Left";
			m_velocity.x = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Left", true);
		}
		if (KEY_UP(KEY_TYPE::D))
		{
			m_strDir = L"Right";
			m_velocity.x = 0;
			GetAnimator()->PlayAnim(L"Player_Idle_Right", true);
		}
	}
	// Player KeyPress(Move)
	{
		if (KEY_PRESS(KEY_TYPE::W))
		{
			m_strDir = L"Back";
			m_velocity.y = -1;
			GetAnimator()->PlayAnim(L"Player_Walk_Back", true);;
		}
		if (KEY_PRESS(KEY_TYPE::S))
		{
			m_strDir = L"Front";
			m_velocity.y = 1;
			GetAnimator()->PlayAnim(L"Player_Walk_Front", true);
		}
		if (KEY_PRESS(KEY_TYPE::A))
		{
			m_strDir = L"Left";
			m_velocity.x = -1;
			GetAnimator()->PlayAnim(L"Player_Walk_Left", true);
		}
		if (KEY_PRESS(KEY_TYPE::D))
		{
			m_strDir = L"Right";
			m_velocity.x = 1;
			GetAnimator()->PlayAnim(L"Player_Walk_Right", true);
		}

		if (m_velocity.x != 0 || m_velocity.y != 0)
		{
			m_velocity.Normalize();
			vPos = vPos + Vec2{ m_velocity.x * m_fMoveSpeed * fDT, m_velocity.y * m_fMoveSpeed * fDT };
		}
	}

	// ���� ���� �׽�Ʈ
	if (KEY_DOWN(KEY_TYPE::N))
	{
		//GetAnimator()->PlayAnim(L"Player_Hit_" + m_strDir, false);
		//if (GetAnimator()->IsAnim())
		//	assert(1 == 0);

		//m_pCurScene->GetWeapon(L"Gun")->SetOwner(this);
		//m_pCurScene->GetWeapon(L"Knife")->SetOwner(this);
		//m_pCurScene->GetWeapon(L"Bomb")->SetOwner(this);
		// 
		//m_pCurScene->GetWeapon(L"Gun")->SetEnable(true);
		//SetWeapon(0, m_pCurScene->GetWeapon(L"Gun"));
		//SetWeapon(1, m_pCurScene->GetWeapon(L"Knife"));
		//SetWeapon(2, m_pCurScene->GetWeapon(L"Bomb"));

		//m_curWeapon = GetWeapon(0);
		//m_curWeapon->SetOwner(this);

		SetWeapon(0, m_pCurScene->GetWeapon(L"Gun"));
		SetWeapon(1, m_pCurScene->GetWeapon(L"Knife"));
		SetWeapon(2, m_pCurScene->GetWeapon(L"Bomb"));
	}

	// ����
	if (KEY_DOWN(KEY_TYPE::SPACE) && m_curWeapon != NULL)
	{		 

		// �ڵ� ����
		AutoAim();

		// ���� ���� ���
		if (m_vAttackDir.x != 0 || m_vAttackDir.y != 0)
			m_curWeapon->Attack(m_vAttackDir);

		// ���� ��ġ �ʱ�ȭ
		m_vAttackDir = { 0, 0 };
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

		m_curWeapon = GetWeapon(m_curWeaponIdx);
		m_curWeapon->SetOwner(this);
	}

	//// ���� ���� (�׽�Ʈ)
	//{
	//	if (KEY_DOWN(KEY_TYPE::K))
	//	{
	//		m_curWeapon = GetWeapon(m_curWeaponIdx);
	//	}
	//}

	if (KEY_DOWN(KEY_TYPE::M))
	{
		SetHP(GetHP() - 1);
		// ��ƼŬ ����
		{
			Particle* m_pParticle = new Particle(PARTICLE_TYPE::HIT);
			m_pParticle->SetOwner(this);
			m_pParticle->SetPos({ GetPos().x, GetPos().y - GetScale().y / 2 });
			m_pParticle->SetScale({ 100.f, 100.f });
			m_pCurScene->AddObject(m_pParticle, OBJECT_GROUP::PARTICLE);
		}
	}

	// �ִϸ��̼� ����
	GetAnimator()->Update();

	// ���� ����
	if (m_curWeapon != nullptr)
		m_curWeapon->Update();

	// ��ġ �����ϱ�
	SetPos(vPos);
}

void Player::Render(HDC _dc)
{
	Component_Render(_dc);

	if (m_curWeapon != nullptr)
		m_curWeapon->Render(_dc);
}

void Player::AutoAim()
{
	// ��ġ �޾ƿ���
	Vec2 vPos = GetPos();
	
	// ������� ���ʹ̸� �����´�.
	m_vecEnemy = m_pCurScene->GetGroupObject(OBJECT_GROUP::MONSTER);

	// ��� ���� �˻�
	for (size_t i = 0; i < m_vecEnemy.size(); ++i)
	{
		// ���� ���� �ۿ� �ִٸ� ���� �ʴ´�.
		if (m_curWeapon->GetDistance() < m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()))
			continue;
		// ���� ���� �ȿ� �ִٸ� ��� �ִ´�.
		else
			m_vecEnemyDist.push_back({ m_vecEnemy[i]->GetPos(), m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()) });
	}

	// �������� ���ķ� �Ÿ��� ���� ���� ���� ������ �д� // ���� ��� �ٲ���! -> �Ǳ���
	std::sort(m_vecEnemyDist.begin(), m_vecEnemyDist.end(), cmp1);

	// ���� ����� ���� ��ġ�� �����Ѵ�.
	if (!m_vecEnemyDist.empty())
		m_vAttackDir = m_vecEnemyDist.front().first;

	// ��ġ�� �Ÿ� �ʱ�ȭ
	m_vecEnemy.clear();
	m_vecEnemyDist.clear();
}

void Player::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();

	// �÷��̾� �浹�� ������Ʈ (��, �� ����, ����߸��� ����(?))
	if (pOtherObj->GetName() == L"Enemy" || pOtherObj->GetName() == L"Enemy_Bullet")
	{
		// ������ �ޱ�
		//SetDamage(pOtherObj->GetDamage());
		//pOtherObj->SetDamage(m_fDamage);
		EventMgr::GetInst()->DeleteObject(_pOther->GetObj());
		// Hit �ִϸ��̼� ����
		GetAnimator()->PlayAnim(L"Player_Hit_" + m_strDir, false);

		// Hit ��ƼŬ ����
		{
			Particle* m_pParticle = new Particle(PARTICLE_TYPE::HIT);
			m_pParticle->SetOwner(this);
			m_pParticle->SetPos({ GetPos().x, GetPos().y - GetScale().y / 2 });
			m_pParticle->SetScale({ 100.f, 100.f });
			m_pCurScene->AddObject(m_pParticle, OBJECT_GROUP::PARTICLE);
		}
	}
}

void Player::StayCollision(Collider* _pOther)
{
	//auto obj = _pOther->GetObj();
	//obj->SetDamage(100);
}

void Player::ExitCollision(Collider* _pOther)
{
	GetAnimator()->PlayAnim(L"Player_Idle_" + m_strDir, false);
}
