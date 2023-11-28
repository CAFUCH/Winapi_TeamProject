#pragma once
#include "Object.h"
#include "Scene.h"
class Texture; class Weapon;
class Player :
    public Object
{
public:
    Player();
    ~Player();

public:
    virtual void EnterCollision(Collider* _pOther) override;
    virtual void StayCollision(Collider* _pOther)  override;
    virtual void ExitCollision(Collider* _pOther)  override;

public:
    void Update() override;
    //void Render(HDC _dc) override;
    void AutoAim();

public:
    const Player GetPlayer() const { this; }

private:
    // sprite
    Texture* m_pTex;
    // �̵� ����
    Vec2 m_velocity;
    // ���� ����
    std::pair<wstring, Vec2> m_strDir;
    // ���� ����
    Vec2 m_vAttackDir;
    // �ִ� ���� ����, ���� ���� �ε���
    int m_maxWeaponCnt; int m_curWeaponIdx;
    // ���� ����
    Object* m_curWeapon;
    // ���� ����
    vector<Object*> m_vecWeapon;
    //// ���� ����
    //Weapon* m_curWeapon;
    //// ���� ����
    //vector<Weapon*> m_vecWeapon;

    // ���� �� 
    std::shared_ptr<Scene> m_pCurScene;
    // ���� ���� ��
    vector<Object*> m_vecEnemy;
};

