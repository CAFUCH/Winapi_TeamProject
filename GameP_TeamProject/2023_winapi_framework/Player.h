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
    virtual void ExitCollision(Collider* _pOther)  override;
    virtual void StayCollision(Collider* _pOther)  override;

public:
    void Update() override;
    //void Render(HDC _dc) override;
    
    void AutoAim();

private:
    // sprite
    Texture* m_pTex;
    // 현재 방향
    wstring m_strDir;
    // 공격 방향
    Vec2 m_vAttackDir;
    // 현재 무기
    Weapon* m_curWeapon;
    // 소지 무기 개수
    int m_maxWeaponCnt; int m_curWeaponIdx;
    // 소지 무기
    vector<Weapon*> m_vecWeapon;

    // 현재 씬 
    std::shared_ptr<Scene> m_pCurScene;
    // 현재 씬의 적
    vector<Object*> m_vecEnemy;
};

