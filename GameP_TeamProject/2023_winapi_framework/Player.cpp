#include "pch.h"
#include "Player.h"
#include "Weapon.h"
#include "HP.h"
#include "Particle.h"

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

bool cmp1(std::pair<Object*, double>& left, std::pair<Object*, double>& right)
{
	return left.second < right.second;
}

Player::Player()
	: m_pTex(nullptr)
{
	m_fHp = 30;
	m_fHpMax = 30;
	// 이미지 불러오기
	m_pTex = ResMgr::GetInst()->TexLoad(L"PlayerT", L"Texture\\Player.bmp");

	// 현재 씬 불러오기
	m_pCurScene = SceneMgr::GetInst()->GetCurScene();

	// 초기화
	{
		// 현재 무기 인덱스
		m_curWeaponIdx = 0;
		// 이전 무기 인덱스
		m_preWeaponIdx = 0;
		// 소지 무기 개수
		m_maxWeaponCnt = 3;

		// 이동 속도
		m_fMoveSpeed = 150.f;
		// 위치 초기화
		m_velocity = { 0, 0 };

		// 체력 초기화
		SetMaxHP(20.f);
		SetHP(GetMaxHP());
	}

	// 콜라이더 컴포넌트 생성
	CreateCollider();
	// 콜라이더 사이즈 초기화
	GetCollider()->SetScale(Vec2(50.f, 50.f)); // 상수 넣어주기

	// 애니메이터 컴포넌트 생성
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

	// 무기 컴포넌트 생성
	{
		for (int i = 0; i < m_maxWeaponCnt; ++i)
			CreateWeapon();
	}

	// HP 생성
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
	// 위치 가져오기
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

	// 전체 무기 얻기 (테스트용)
	if (KEY_DOWN(KEY_TYPE::N))
	{
		SetWeapon(0, m_pCurScene->GetWeapon(L"Gun"));
		SetWeapon(1, m_pCurScene->GetWeapon(L"Knife"));
		SetWeapon(2, m_pCurScene->GetWeapon(L"Bomb"));
	}

	// 자동 조준
	AutoAim();

	// 공격
	if (KEY_DOWN(KEY_TYPE::SPACE) && m_curWeapon != NULL)
	{		 
		// 현재 무기 사용
		if (m_vAttackDir.x != 0 || m_vAttackDir.y != 0)
			m_curWeapon->Attack(m_vAttackDir);

		// 현재 위치 초기화
		m_vAttackDir = { 0, 0 };
	}

	// 무기 교체
	{
		if (KEY_DOWN(KEY_TYPE::Q))
		{
			m_preWeaponIdx = m_curWeaponIdx;
			--m_curWeaponIdx;
		}
		if (KEY_DOWN(KEY_TYPE::E))
		{
			m_preWeaponIdx = m_curWeaponIdx;
			++m_curWeaponIdx;
		}

		if (m_curWeaponIdx < 0)
			m_curWeaponIdx = m_maxWeaponCnt - 1;
		else if (m_curWeaponIdx >= m_maxWeaponCnt)
			m_curWeaponIdx = 0;

		//if (GetWeapon(m_curWeaponIdx)->GetOwner() == nullptr)
		//	m_curWeaponIdx = m_preWeaponIdx;

		m_curWeapon = GetWeapon(m_curWeaponIdx);
		m_curWeapon->SetOwner(this);
	}

	if (KEY_DOWN(KEY_TYPE::M))
	{
		SetHP(GetHP() - 1);
		// 파티클 생성
		{
			CreateParticle(PARTICLE_TYPE::ELECT_ELEM, this);
		}
	}

	// 애니메이션 실행
	GetAnimator()->Update();

	// 무기 실행
	if (m_curWeapon != nullptr)
		m_curWeapon->Update();

	// 위치 저장하기
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
	// 위치 받아오기
	Vec2 vPos = GetPos();
	
	// 현재씬의 에너미를 가져온다.
	m_vecEnemy = m_pCurScene->GetGroupObject(OBJECT_GROUP::MONSTER);

	// 모든 적을 검사
	for (size_t i = 0; i < m_vecEnemy.size(); ++i)
	{
		// 공격 범위 밖에 있다면 넣지 않는다.
		if (m_curWeapon->GetDistance() < m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()))
			continue;
		// 공격 범위 안에 있다면 대상에 넣는다.
		else
			m_vecEnemyDist.push_back({ m_vecEnemy[i], m_vPos.Distance(GetPos(), m_vecEnemy[i]->GetPos()) });
	}

	// 오름차순 정렬로 거리가 가장 작은 것을 앞으로 둔다 // 정렬 방법 바꾸자! -> 되긴함
	std::sort(m_vecEnemyDist.begin(), m_vecEnemyDist.end(), cmp1);

	// 가장 가까운 적의 위치를 저장한다.
	if (!m_vecEnemyDist.empty())
	{
		m_vAttackDir = m_vecEnemyDist.front().first->GetPos();
		//m_pPerTarget = m_pTarget;
		m_pTarget = m_vecEnemyDist.front().first;
	}

	// 에임 표시
	if (m_pParticle)
		m_pParticle->OnStop();
	if (m_pTarget)
		m_pParticle = CreateParticle(PARTICLE_TYPE::AIM, m_pTarget);

	// 위치와 거리 초기화
	m_vecEnemy.clear();
	m_vecEnemyDist.clear();
}

void Player::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();

	// 플레이어 충돌한 적
	if (pOtherObj->GetName() == L"Enemy" || pOtherObj->GetName() == L"Enemy_Bullet")
	{
		// 충돌한 적 삭제
		EventMgr::GetInst()->DeleteObject(_pOther->GetObj());
		// Hit 애니메이션 실행
		GetAnimator()->PlayAnim(L"Player_Hit_" + m_strDir, false);
		// Hit 파티클 생성
		CreateParticle(PARTICLE_TYPE::HIT, this);
	}
}

void Player::StayCollision(Collider* _pOther)
{
}

void Player::ExitCollision(Collider* _pOther)
{
	GetAnimator()->PlayAnim(L"Player_Idle_" + m_strDir, false);
}
