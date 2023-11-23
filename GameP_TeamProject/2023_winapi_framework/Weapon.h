#pragma once
#include "Object.h"
class Weapon :
    public Object
{
public:
    Weapon();
    ~Weapon();

public:
    // ���� �Լ� (�÷��̾� ȣ��)
    virtual void Attack(Vec2 dir);

private:
    // ����
    ENTITY_ELEMENT_TYPE m_eElementType;

private:
    // sprite
    Texture* m_pTex;
    // ���� �Ÿ�, ���� ������
    float m_fDistance; float m_fDelay;
    // ���ݷ�, ���� �ӵ�, ġ��Ÿ
    float m_fSpeed; float m_fDamage; float m_fCritical;
};

