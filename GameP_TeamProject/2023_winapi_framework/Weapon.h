#pragma once
#include "Object.h"

class Texture; class Scene;
class Weapon :
    public Object
{
public:
    Weapon();
    ~Weapon();

public:
    //virtual void Update() override;
    // ���� �Լ� (�÷��̾� ȣ��)
    virtual void Attack(Vec2 dir) abstract;

protected:
    // ����
    ENTITY_ELEMENT_TYPE m_eElementType;

protected:
    // sprite
    Texture* m_pTex;
};

