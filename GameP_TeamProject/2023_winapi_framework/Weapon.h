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
    // 현재 객체
    Object* m_pOwner;
    friend class Object;

protected:
    // sprite
    Texture* m_pTex;
    // 원소
    ENTITY_ELEMENT_TYPE m_eElementType;

    // 공격 거리, 공격 딜레이
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed;
};

