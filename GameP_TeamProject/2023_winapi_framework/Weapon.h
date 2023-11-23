#pragma once
#include "Object.h"
class Weapon :
    public Object
{
public:
    Weapon();
    ~Weapon();

public:
    // 공격 함수 (플레이어 호출)
    virtual void Attack(Vec2 dir);

private:
    // 원소
    ENTITY_ELEMENT_TYPE m_eElementType;

private:
    // sprite
    Texture* m_pTex;
    // 공격 거리, 공격 딜레이
    float m_fDistance; float m_fDelay;
    // 공격력, 공격 속도, 치명타
    float m_fSpeed; float m_fDamage; float m_fCritical;
};

