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
    virtual void Attack() abstract;

private:
    // 무기 원소
    ELEMENT_TYPE m_eElementType;

private:
    // 공격 사정거리, 공격 딜레이
    float m_fDistance; float m_fDelay;
    // 공격력, 공격 속도, 치명타
    float m_fSpeed; float m_fDamage; float m_fCritical;
};

