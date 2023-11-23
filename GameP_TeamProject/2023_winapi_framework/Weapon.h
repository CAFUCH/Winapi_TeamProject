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
    virtual void Attack() abstract;

private:
    // ���� ����
    ELEMENT_TYPE m_eElementType;

private:
    // ���� �����Ÿ�, ���� ������
    float m_fDistance; float m_fDelay;
    // ���ݷ�, ���� �ӵ�, ġ��Ÿ
    float m_fSpeed; float m_fDamage; float m_fCritical;
};

