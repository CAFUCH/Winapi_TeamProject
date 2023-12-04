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
    virtual void Attack(Vec2 dir) override;
};