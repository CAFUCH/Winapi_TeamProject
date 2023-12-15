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
    // ���� ��ü
    Object* m_pOwner;
    friend class Object;

protected:
    // sprite
    Texture* m_pTex;
    //// ����
    ENTITY_ELEMENT_TYPE m_eElement;

    // �̸�
    wstring m_name;
    // ��ġ
    Vec2 m_vPos;
    // ũ��
    Vec2 m_vScale;

    // �ݶ��̴�
    Collider* m_pCollider;
    // �ִϸ�����
    Animator* m_pAnimator;

    // ���� �� 
    std::shared_ptr<Scene> m_pCurScene;

    // ���� �Ÿ�, ���� ������
    float m_fDistance; float m_fDelay;
    float m_fAttackSpeed; float m_fDamage;

    // ����
    bool m_IsAlive;
};

