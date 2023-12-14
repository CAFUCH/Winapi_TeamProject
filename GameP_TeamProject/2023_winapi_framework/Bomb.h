#pragma once
#include "Weapon.h"
#include "Scene.h"
class Texture;
class Bomb :
    public Weapon
{
public:
    Bomb();
    ~Bomb();

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
    Texture* m_pBulletTex;
    float m_fcurTime; float m_fWaitTime; float m_fLifeTime;
    bool isWait; bool isAttack;
};
