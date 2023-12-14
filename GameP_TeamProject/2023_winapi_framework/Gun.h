#pragma once
#include "Weapon.h"
#include "Scene.h"
class Texture;
class Bullet;
class Gun :
    public Weapon
{
public:
    Gun();
    ~Gun();

public:
    void Update() override;
    void Render(HDC _dc) override;

public:
    virtual void Attack(Vec2 dir) override;

private:
    Texture* m_pBullet;
    std::vector<Bullet*> bullets;
};
