#pragma once
#include "Object.h"
#include "enums.h"

#include <wtypes.h> // pch에서 해주고 있지 않나??
class Texture; class Weapon;
class Player :
    public Object
{
public:
    Player();
    ~Player();

public:
    void Update() override;
    void Render(HDC _dc) override;

public:
    //void 

private:
    Texture* m_pTex;
    ELEMENT_TYPE m_eElementTy;
    Stat m_stat;
    Weapon* m_curWeapon;
    //vector<Weapon*> m_vecWeapon;
};

