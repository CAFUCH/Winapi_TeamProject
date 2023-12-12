#pragma once
class Object;
class Texture;
class Collider;
class Animator;
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

    Collider* GetCollider() const { return m_pCollider; }
    Animator* GetAnimator() { return m_pAnimator; }

    const bool& GetEnable() const { return m_setActive; }
    void SetEnable(bool _value) { m_setActive = _value; }

public:
    float GetDistance() const { return m_fDistance; }
    void SetOwner(Object* _owner) { m_pOwner = _owner; }

public:
    void CreateCollider();
    void CreateAnimator();

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

    // �ݶ��̴�
    Collider* m_pCollider;
    // �ִϸ�����
    Animator* m_pAnimator;

    // ���� �Ÿ�, ���� ������
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed;

    bool m_setActive;
};

