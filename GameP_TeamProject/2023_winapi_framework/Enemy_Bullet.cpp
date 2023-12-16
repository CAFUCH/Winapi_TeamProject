#include "pch.h"
#include "Enemy_Bullet.h"
#include "TimeMgr.h"
#include "ResMgr.h"
#include "Texture.h"
#include "ElementMgr.h"
#include "Particle.h"
#include "Collider.h"
#include "Animator.h"
#include "Animation.h"
#include "EventMgr.h"
Enemy_Bullet::Enemy_Bullet(float _damage, float _speed)
	:m_fDir(-1.f)
	, m_vDir(Vec2(0.f, 0.f))
	, m_damage(_damage)
	, m_bulletSpeed(_speed)
	, m_pTex(nullptr)
{

	SetName(L"Enemy_Bullet");

	m_pTex = ResMgr::GetInst()->TexFind(L"Weapon_Bullet");
	//m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bullet", L"Texture\\" + _name + L".bmp");

	CreateCollider();

	CreateAnimator();
	GetAnimator()->CreateAnim(L"Bullet_Attack", m_pTex, Vec2(0.f, 0.f),
		{ 21, 19 }, Vec2(0.f, 0.f), 1, 1.f);
	GetAnimator()->PlayAnim(L"Bullet_Attack", true);
}


Enemy_Bullet::~Enemy_Bullet()
{

}

void Enemy_Bullet::Update()
{
	if (!GetIsDead()) {
		Vec2 vPos = GetPos();
		vPos.x += m_bulletSpeed * fDT * m_vDir.x;
		vPos.y += m_bulletSpeed * fDT * m_vDir.y;
		SetPos(vPos);
	}
}

void Enemy_Bullet::Render(HDC _dc)
{
	if (!GetIsDead()) {
		Component_Render(_dc);
	}
}

void Enemy_Bullet::EnterCollision(Collider* _pOther)
{
	if (!GetIsDead())
	{
		Object* pOtherObj = _pOther->GetObj();
		// 총알과 충돌한 것이 적 오브젝트라면
		if (pOtherObj->GetName() == L"Player")
		{
			// 상성 효과
			m_damage = ElementMgr::GetInst()->Elemenet
			(this->m_eElement, pOtherObj->m_eElement, m_damage);

			// 데미지 주기
			pOtherObj->SetDamage(m_damage);

			EventMgr::GetInst()->DeleteObject(this);
			//SetDead();
		}
	}
}

void Enemy_Bullet::ExitCollision(Collider* _pOther)
{
}

void Enemy_Bullet::StayCollision(Collider* _pOther)
{
}
