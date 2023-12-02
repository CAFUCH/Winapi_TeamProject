#pragma once
#include "Scene.h"
class Weapon;
class Game_Scene :
    public Scene
{
public:
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;

public:
    // 게임에 필요한 모든 무기를 생성해두고 가져오기 위해
    //Weapon* GetWeapon(wstring _name) { return m_mWeapon[_name]; }

private:
    // 얘네는 컴포넌트가 아니라 진짜 무기임
    /*map<wstring, Weapon*> m_mWeapon;*/
    //vector<Weapon*> m_vecWeapon;
};

