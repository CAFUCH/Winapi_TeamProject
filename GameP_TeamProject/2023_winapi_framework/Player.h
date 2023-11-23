#pragma once
#include "Object.h"
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

private:
    // 플레이어 이미지
    Texture* m_pTex;
    // 플레이어 스탯
    Stat m_stat;
    // 플레이어 현재 무기
    Weapon* m_curWeapon;
    // 플레이어 소지 무기
    vector<Weapon*> m_vecWeapon[3];
};

