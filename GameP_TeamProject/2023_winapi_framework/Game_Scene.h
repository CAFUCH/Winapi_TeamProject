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
    // ���ӿ� �ʿ��� ��� ���⸦ �����صΰ� �������� ����
    //Weapon* GetWeapon(wstring _name) { return m_mWeapon[_name]; }

private:
    // ��״� ������Ʈ�� �ƴ϶� ��¥ ������
    /*map<wstring, Weapon*> m_mWeapon;*/
    //vector<Weapon*> m_vecWeapon;
};

