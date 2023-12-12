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
    virtual void Attack(Vec2 dir) override;

private:
    //std::shared_ptr<Scene> m_pCurScene;
    bool isAttack;
};
