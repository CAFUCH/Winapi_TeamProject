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
    // �̵� ����
    Vec2 m_velocity;
    // ���� ����
    //std::pair<wstring, Vec2> m_strDir;
    wstring m_strDir;
    // ���� Ÿ��
    Object* m_pTarget;/* Object* m_pPerTarget;*/
    // ���� ����
    Vec2 m_vAttackDir;
    // �ִ� ���� ����, ���� ���� �ε���, ���� ���� �ε���
    int m_maxWeaponCnt; int m_curWeaponIdx; int m_preWeaponIdx;

    // ���� ���� (����? ������Ʈ~)
    Weapon* m_curWeapon;
    //���� ��ƼŬ
    Particle* m_pParticle;

    //// ���� �� 
    //std::shared_ptr<Scene> m_pCurScene;
    // ���� ���� ��
    vector<Object*> m_vecEnemy;
    // ���� ���� ������ �Ÿ�
    vector<std::pair<Object*, double>> m_vecEnemyDist;
};

