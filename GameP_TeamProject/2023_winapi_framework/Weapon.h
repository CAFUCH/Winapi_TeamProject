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
    const Vec2& GetPos() const { return m_vPos; }
    void SetPos(Vec2 _vPos) { m_vPos = _vPos; }

    const Vec2& GetScale() const { return m_vScale; }
    void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

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

    // ��ġ
    Vec2 m_vPos;
    // ũ��
    Vec2 m_vScale;

    // ���� �Ÿ�, ���� ������
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed;
};

