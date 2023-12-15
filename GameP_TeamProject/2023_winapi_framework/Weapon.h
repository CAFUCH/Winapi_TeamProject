#pragma once
class Object;
class Texture;
class Scene;
class Collider;
class Animator;
class Particle;
class Weapon
{
public:
    Weapon();
    ~Weapon();

public:
    virtual void Update();
    virtual void FinalUpdate() final;

    virtual void Render(HDC _dc);

    virtual void EnterCollision(Collider* _pOther);
    virtual void ExitCollision(Collider* _pOther);
    virtual void StayCollision(Collider* _pOther);

    void Component_Render(HDC _dc);

public:
    virtual void Attack(Vec2 dir);

public:
    const Vec2& GetPos() const { return m_vPos; }
    void SetPos(Vec2 _vPos) { m_vPos = _vPos; }

    const Vec2& GetScale() const { return m_vScale; }
    void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

    Collider* GetCollider() const { return m_pCollider; }
    Animator* GetAnimator() { return m_pAnimator; }

public:
    float GetDistance() const { return m_fDistance; }

    void SetOwner(Object* _owner) { m_pOwner = _owner; }

    const wstring& GetName() const { return m_name; }
    void SetName(wstring _name) { m_name = _name; }

    const bool& GetAlive() { return m_IsAlive; }
    void SetDead() { m_IsAlive = false; }

    void SetUpgrade() { m_fDamage * 1.25f; }

public:
    void CreateCollider();
    void CreateAnimator();
    Particle* CreateParticle(PARTICLE_TYPE _eType);

protected:
    // 현재 객체
    Object* m_pOwner;
    friend class Object;

protected:
    // sprite
    Texture* m_pTex;
    //// 원소
    ENTITY_ELEMENT_TYPE m_eElement;

    // 이름
    wstring m_name;
    // 위치
    Vec2 m_vPos;
    // 크기
    Vec2 m_vScale;

    // 콜라이더
    Collider* m_pCollider;
    // 애니메이터
    Animator* m_pAnimator;

    // 현재 씬 
    std::shared_ptr<Scene> m_pCurScene;

    // 공격 거리, 공격 딜레이
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed; float m_fDamage;

    // 생존
    bool m_IsAlive;
};

