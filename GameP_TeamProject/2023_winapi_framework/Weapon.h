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
    // 현재 객체
    Object* m_pOwner;
    friend class Object;

protected:
    // sprite
    Texture* m_pTex;
    // 원소
    ENTITY_ELEMENT_TYPE m_eElementType;

    // 위치
    Vec2 m_vPos;
    // 크기
    Vec2 m_vScale;

    // 콜라이더
    Collider* m_pCollider;
    // 애니메이터
    Animator* m_pAnimator;

    // 공격 거리, 공격 딜레이
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed;

    bool m_setActive;
};

