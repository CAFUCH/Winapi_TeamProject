#pragma once
#include "Object.h"
class Texture;
class Enemy_Bullet :
	public Object
{
public:
	Enemy_Bullet(float _damage, float _speed);
	~Enemy_Bullet();
public:
	void Update() override;
	void Render(HDC _dc) override;
public:
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther) override;
	virtual void StayCollision(Collider* _pOther) override;
public:
	void SetDir(Vec2 _v) {
		m_vDir = _v;
		//m_vDir.Normalize();
	}
private:
	float m_fDir;
	float m_damage;
	float m_bulletSpeed;
	Vec2 m_vDir;
	Texture* m_pTex;
};

