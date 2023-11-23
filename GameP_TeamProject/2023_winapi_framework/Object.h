#pragma once
class Collider;
class Animator;
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

	void SetDamage(float _damage);

public:
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }

	const Vec2& GetPos() const { return m_vPos; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }

	const Vec2& GetScale() const { return m_vScale; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	bool GetIsDead() const { return !m_IsAlive; }

	float GetDamage() const { return m_fAttackPower; }

	Collider* GetCollider() const { return m_pCollider; }
	Animator* GetAnimator() { return m_pAnimator; }

private:
	void SetDead() { m_IsAlive = false; }
	friend class EventMgr;

public:
	void CreateCollider();
	void CreateAnimator();

protected:
	// 이름
	wstring m_strName; 
	// 위치
	Vec2 m_vPos; 
	// 크기
	Vec2 m_vScale; 
	// 콜라이더
	Collider* m_pCollider;
	// 애니메이터
	Animator* m_pAnimator;

	// 생존
	bool m_IsAlive;
	// 체력, 최대 체력
	float m_fHp; float m_fHpMax;
	// 공속, 이속
	float m_fAttackSpeed; float m_fMoveSpeed;
	// 공격력, 회복력, 방어력
	float m_fAttackPower; float m_fRecoverPower; float m_fDefensePower;
};

