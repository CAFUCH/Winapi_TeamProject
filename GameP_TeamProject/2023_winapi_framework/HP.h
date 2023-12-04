#pragma once
#include "UI.h"
#include "Scene.h"
class Texture;
class Object;
class HP :
	public UI
{
public:
	HP();
	~HP();

public:
	virtual void Update() override;
	virtual void Render(HDC _dc) override;

public:
	void SetOwner(Object* _owner) { m_pOwner = _owner; }

private:
	// Hp ��� �̹���
	Texture* m_pBackTex;
	// Hp �̹���
	Texture* m_pFillTex;

	std::shared_ptr<Scene> m_pCurScene;
	Object* m_pOwner;
};

