#pragma once
#include "Weapon.h"
#include "Scene.h"
class Texture;
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
    //std::shared_ptr<Scene> m_pCurScene;
};
