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
    virtual void Attack(Vec2 dir) override;
};