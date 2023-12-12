#pragma once
class Object;
class Weapon;

class Collider
{
public:
	Collider();
	Collider(const Collider& _origin);
	~Collider();
	Collider& operator = (Collider& _origin) = delete;
public:
	void FinalUpdate();
	void Render(HDC _dc);
public:
	void EnterCollision(Collider* _pOther);
	void ExitCollision(Collider* _pOther);
	void StayCollision(Collider* _pOther);
public:
	const Vec2& GetScale() const { return m_vScale; }
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	const Vec2& GetOffSetPos() const { return m_vOffsetPos; }
	void SetOffSetPos(Vec2 _vOffsetPos) 
	{ m_vOffsetPos = _vOffsetPos; }

	const Vec2& GetFinalPos() { return m_vFinalPos; }
	void SetFinalPos(Vec2 _vOffsetPos) { m_vOffsetPos = _vOffsetPos; }

	const UINT& GetID() const { return m_ID; }
	Object* GetObj() const { return m_pObjOwner; }
	Weapon* GetWeapon() const { return m_pWeaOwner; }

private:
	UINT m_check;
	Object* m_pObjOwner;
	Weapon* m_pWeaOwner;
	Vec2 m_vOffsetPos; // 오프셋
	Vec2 m_vFinalPos; // 파이널 위치
	Vec2 m_vScale; // 크기

	friend class Object;
	friend class Weapon;

	UINT m_ID; // 충돌체 ID값
	static UINT m_sNextID;
};

