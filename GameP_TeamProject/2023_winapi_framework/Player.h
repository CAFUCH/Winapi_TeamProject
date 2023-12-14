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
    void Render(HDC _dc) override;
    void AutoAim();

public:
    const Player GetPlayer() const { this; }
    //const std::shared_ptr<Scene> GetCurScene() const { m_pCurScene; }

private:
    // sprite
    Texture* m_pTex;
    // 이동 방향
    Vec2 m_velocity;
    // 현재 방향
    //std::pair<wstring, Vec2> m_strDir;
    wstring m_strDir;
    // 공격 방향
    Vec2 m_vAttackDir;
    // 최대 소지 개수, 현재 무기 인덱스
    int m_maxWeaponCnt; int m_curWeaponIdx;

    // 현재 무기 (이자? 컴포넌트~)
    Weapon* m_curWeapon;
    // 현재 파티클
    //Particle* m_pParticle;

    // 현재 씬 
    std::shared_ptr<Scene> m_pCurScene;
    // 현재 씬의 적
    vector<Object*> m_vecEnemy;
    // 현재 씬의 적과의 거리
    vector<std::pair<Vec2, double>> m_vecEnemyDist;
};

