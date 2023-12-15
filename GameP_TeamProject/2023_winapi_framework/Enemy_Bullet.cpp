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
Enemy_Bullet::Enemy_Bullet(float _damage, float _speed)
	:m_fDir(-1.f)
	, m_vDir(Vec2(0.f, 0.f))
	, m_damage(_damage)
	, m_bulletSpeed(_speed)
	, m_pTex(nullptr)
{
	m_pTex = ResMgr::GetInst()->TexFind(L"Weapon_Bullet");
	//m_pTex = ResMgr::GetInst()->TexLoad(L"Weapon_Bullet", L"Texture\\" + _name + L".bmp");

	CreateCollider();

	CreateAnimator();
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
		Vec2 vPos = GetPos();
		Vec2 vScale = GetScale();

		int Width = m_pTex->GetWidth();
		int Height = m_pTex->GetHeight();

		TransparentBlt(_dc
			, (int)(vPos.x - vScale.x / 2)
			, (int)(vPos.y - vScale.y / 2)
			, Width, Height, m_pTex->GetDC()
			, 0, 0, Width, Height, RGB(255, 0, 255));
	}


	Component_Render(_dc);
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
			m_fDamage = ElementMgr::GetInst()->Elemenet
			(this->m_eElement, pOtherObj->m_eElement, m_fDamage);

			// 데미지 주기
			pOtherObj->SetDamage(m_fDamage);

			// 파티클 생성
			CreateParticle((PARTICLE_TYPE)m_eElement, this);
			SetDead();
		}
	}
}

void Enemy_Bullet::ExitCollision(Collider* _pOther)
{
}

void Enemy_Bullet::StayCollision(Collider* _pOther)
{
}
