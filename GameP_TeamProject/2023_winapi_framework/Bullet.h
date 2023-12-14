#pragma once
#include "Weapon.h"
#include "Scene.h"
class Bullet :
    public Weapon
{
public:
    Bullet() = default;
    Bullet(wstring _name, Vec2 dir, Vec2 pos, Vec2 scale);
    ~Bullet();

public:
    void Update() override;
    void Render(HDC _dc) override;

public:
    virtual void EnterCollision(Collider* _pOther) override;
    virtual void ExitCollision(Collider* _pOther) override;
    virtual void StayCollision(Collider* _pOther) override;

public:
    virtual void Attack(Vec2 dir) override;

public:
    const bool& GetIsErase() { return m_IsErase; }

private:
    Texture* m_pBullet;
    Vec2 m_vDir;
    float m_fcurTime; float m_fLifeTime;
    bool m_IsErase;
};
