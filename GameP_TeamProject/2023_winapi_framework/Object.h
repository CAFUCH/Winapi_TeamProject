#pragma once
class Collider;
class Animator;
class Weapon;
class Particle;
class Object
{
public:
	Object();
	virtual ~Object();

public:
	virtual void Update();
	virtual void FinalUpdate() final;

	virtual void Render(HDC _dc);

	virtual void EnterCollision(Collider* _pOther);
	virtual void ExitCollision(Collider* _pOther);
	virtual void StayCollision(Collider* _pOther);

	void Component_Render(HDC _dc);

public:
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }

	const Vec2& GetPos() const { return m_vPos; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }

	const Vec2& GetScale() const { return m_vScale; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	float GetMaxHP() { return m_fHpMax; }
	float GetHP() { return m_fHp; }
	void SetMaxHP(float _fMaxHp) { m_fHpMax = _fMaxHp; }
	void SetHP(float _fHp) { m_fHp = _fHp; }

	bool GetIsDead() const { return !m_IsAlive; }

	float GetDamage() const { return m_fDamage; }
	void SetDamage(float _damage);
	//float GetDistance() const { return m_fDistance; }

	Collider* GetCollider() const { return m_pCollider; }
	Animator* GetAnimator() { return m_pAnimator; }
	Weapon* GetWeapon(int _idx) { return m_vecWeapon[_idx]; }
	void SetWeapon(int _idx, Weapon* _weapon) 
	{ m_vecWeapon[_idx] = _weapon; }

private:
	void SetDead() { m_IsAlive = false; }
	friend class EventMgr;

public:
	void CreateCollider();
	void CreateAnimator();
	void CreateWeapon();
	Particle* CreateParticle(PARTICLE_TYPE _eType);
	ENTITY_ELEMENT_TYPE m_eElement;

protected:
	// �⺻ ����
	// �̸�
	wstring m_strName; 
	// ��ġ
	Vec2 m_vPos; 
	// ũ��
	Vec2 m_vScale; 
	// ����

	// ��״� ������Ʈ��!!!
	// �ݶ��̴�
	Collider* m_pCollider;
	// �ִϸ�����
	Animator* m_pAnimator;
	// ���� (��Ȯ���� obj���� �޸� weapon�� ������Ʈ�� �����ϰ� ��� ��)
	vector<Weapon*> m_vecWeapon;
	// ���� ��ƼŬ��
	Particle* m_pParticle;

	// ��ƼƼ ����
	// ����
	bool m_IsAlive;
	// ü��, �ִ� ü��
	float m_fHp; float m_fHpMax;
	// ����, �̼�
	float m_fMoveSpeed;
	// ���ݷ�, ȸ����, ����
	float m_fDamage; float m_fRecoverPower; float m_fDefensePower; float m_fCritical;
};

