#pragma once
#include "UI.h"
#include "Scene.h"
class Texture;
class Object;
class HP :
	public UI
{
public:
	HP() = default;
	HP(Object* _owner);
	~HP();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

public:
	//const Vec2& GetPos() const { return m_vPos; }
	//void SetPos(Vec2 _vPos) { m_vPos = _vPos; }

	//const Vec2& GetScale() const { return m_vScale; }
	//void SetScale(Vec2 _vScale) { m_vScale = _vScale; }

	void SetMaxHP(float _fMaxHp) { m_fMaxHP = _fMaxHp; }
	void SetHP(float _fHp) { m_fCurHP = _fHp; }

private:
	// Hp ��� �̹���
	Texture* m_pBackTex;
	// Hp �̹���
	Texture* m_pFillTex;

	//// ��ġ
	//Vec2 m_vPos;
	//// ũ��
	//Vec2 m_vScale;

	//
	float m_fHPValue;
	// ���� ü��
	float m_fCurHP;
	// �ִ� ü��
	float m_fMaxHP;

	std::shared_ptr<Scene> m_pCurScene;
	//vector<Object*> m_pOwner;
	Object* m_pOwner;
};

