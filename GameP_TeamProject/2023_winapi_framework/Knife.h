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
    bool m_IsAtking;
    Vec2 m_vDir;
    float m_fCurTime; float m_fAtkTime;
};