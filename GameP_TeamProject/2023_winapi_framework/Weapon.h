#pragma once
#include "Object.h"
class Texture;
class Weapon :
    public Object
{
public:
    Weapon();
    ~Weapon();

public:
    // ���� �Լ� (�÷��̾� ȣ��)
    virtual void Attack(Vec2 dir) abstract;

protected:
    // ����
    ENTITY_ELEMENT_TYPE m_eElementType;

protected:
    // sprite
    Texture* m_pTex;
};

