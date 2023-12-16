#include "pch.h"
#include "Knife.h"

#include "ResMgr.h"
#include "SceneMgr.h"
#include "TimeMgr.h"

#include "Object.h"
#include "Texture.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"

Knife::Knife()
{
	// �̹��� �ҷ�����
	m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Knife", L"Texture\\Knife.bmp");

	// �ݶ��̴� ����
	CreateCollider();
	// �ݶ��̴� ������ �ʱ�ȭ
	GetCollider()->SetScale(Vec2(50.f, 50.f));

	// �ִϸ����� ����
	CreateAnimator();
	/*Gun Animation*/ {
		GetAnimator()->CreateAnim(L"Knife_Attack", m_pTex, Vec2(0.f, 0.f),
			Vec2(64.f, 64.f), Vec2(0.f, 0.f), 1, 1.f);
		GetAnimator()->PlayAnim(L"Knife_Attack", true);
	}

	m_fDistance = 250.f;
	m_fDelay = 0.3f;

	m_fCurTime = 0.f;
	m_fAtkTime = 1.f;
}

Knife::~Knife()
{
}

void Knife::Update()
{
	Vec2 pPos = GetPos();


	if (m_IsAtking) {

		m_fCurTime += fDT;

		if (m_fCurTime >= m_fAtkTime) {
			m_fCurTime = 0.f;
			m_IsAtking = false;
		}
		else {
			if ((float)pPos.Distance(pPos, m_vDir) > .05f) {

				Vec2 dir = (m_vDir - pPos).Normalize();
				pPos.x += dir.x * m_fCurTime;
				pPos.y += dir.y * m_fCurTime;

				SetPos(pPos);
			}
		}
	}
	else
	{
		SetPos({ m_pOwner->GetPos().x + 30, m_pOwner->GetPos().y });
	}
}

void Knife::Render(HDC _dc)
{
	//TransparentBlt(_dc, (int)(m_vPos.x - m_vScale.x / 2)
	//	, (int)(m_vPos.y - m_vScale.y / 2)
	//	, m_pTex->GetWidth() * (m_vScale.x / 100)
	//	, m_pTex->GetHeight() * (m_vScale.y / 100)
	//	, m_pTex->GetDC(), 0, 0, m_pTex->GetWidth()
	//	, m_pTex->GetHeight(), RGB(255, 0, 255));

	Component_Render(_dc);
}

void Knife::EnterCollision(Collider* _pOther)
{
	Object* pOtherObj = _pOther->GetObj();
}

void Knife::ExitCollision(Collider* _pOther)
{
}

void Knife::StayCollision(Collider* _pOther)
{
}

void Knife::Attack(Vec2 dir)
{
	m_IsAtking = true;
	m_vDir = dir;
	//GetAnimator()->PlayAnim(L"Knife_Attack", false);

	// if (���� ��Ÿ���� �����ٸ�)
	// m_texture �̵� (���� �Ÿ���ŭ ���� �ӵ���)


	//Vec2 vPos = GetPos();
	//// �⺻������ ������ �������� ������ ���� �̵��Ѵ�... (�Ѿ��̶�� �����Ͽ� �ۼ���)
	//vPos.x += dir.x * m_fAttackSpeed * fDT;
}
