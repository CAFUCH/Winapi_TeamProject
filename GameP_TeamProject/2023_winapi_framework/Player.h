#pragma once
#include "Object.h"
class Texture; class Weapon;
class Player :
    public Object
{
public:
    Player();
    ~Player();

public:
    virtual void EnterCollision(Collider* _pOther) override;
    virtual void ExitCollision(Collider* _pOther)  override;
    virtual void StayCollision(Collider* _pOther)  override;

public:
    void Update() override;
    //void Render(HDC _dc) override;
    
    void AutoAim();

private:
    // sprite
    Texture* m_pTex;
    // ���� ����
    wstring m_strDir;
    // ���� ����
    Vec2 m_vAttackDir;
    // ���� ����
    Weapon* m_curWeapon;
    // ���� ����
    vector<Weapon*> m_vecWeapon[3];
};

