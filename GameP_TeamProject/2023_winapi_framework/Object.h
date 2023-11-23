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

public:
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }

	const Vec2& GetPos() const { return m_vPos; }
	void SetPos(Vec2 _vPos) { m_vPos = _vPos; }

	const Vec2& GetScale() const { return m_vScale; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	bool GetIsDead() const { return !m_IsAlive; }

	Collider* GetCollider() const { return m_pCollider; }
	Animator* GetAnimator() { return m_pAnimator; }

private:
	void SetDead() { m_IsAlive = false; }
	friend class EventMgr;

public:
	void CreateCollider();
	void CreateAnimator();

private:
	// �̸�.
	wstring m_strName; 
	// ��ġ
	Vec2 m_vPos; 
	// ũ��
	Vec2 m_vScale; 
	// ���� ����
	bool m_IsAlive;
	// �ݶ��̴�
	Collider* m_pCollider;
	// �ִϸ�����
	Animator* m_pAnimator;
};

