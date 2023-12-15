#pragma once
#include "Weapon.h"
class Texture;
class Knife :
	public Weapon
{
public:
	Knife();
	~Knife();

public:
	void Update() override;
	void Render(HDC _dc) override;
public:
	virtual void EnterCollision(Collider* _pOther) override;
	virtual void ExitCollision(Collider* _pOther) override;
	virtual void StayCollision(Collider* _pOther) override;
public:
	virtual void Attack(Vec2 dir) override;

private:
	Vec2 m_vDir;
	bool m_IsAtking;
	float m_fAtkTime;
	float m_fCurTime;
};