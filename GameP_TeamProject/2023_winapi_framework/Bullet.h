#pragma once
#include "Weapon.h"
#include "Scene.h"
class Texture;
class Bullet :
    public Weapon
{
public:
    Bullet();
    ~Bullet();

public:
    void Update() override;
    void Render(HDC _dc) override;

public:
    virtual void Attack(Vec2 dir) override;

private:
    Texture* m_pBullet;
};

