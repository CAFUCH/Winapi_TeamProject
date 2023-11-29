#pragma once
class Object;
class Texture;
class Weapon
{
public:
    Weapon();
    ~Weapon();

public:
    virtual void Update();
    virtual void Render(HDC _dc);

public:
    virtual void Attack(Vec2 dir);

public:
    float GetDistance() const { return m_fDistance; }

protected:
    // ���� ��ü
    Object* m_pOwner;
    friend class Object;

protected:
    // sprite
    Texture* m_pTex;
    // ����
    ENTITY_ELEMENT_TYPE m_eElementType;

    // ���� �Ÿ�, ���� ������
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed;
};

