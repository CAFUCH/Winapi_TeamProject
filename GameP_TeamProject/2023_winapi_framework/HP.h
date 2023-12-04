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
	// Hp 배경 이미지
	Texture* m_pBackTex;
	// Hp 이미지
	Texture* m_pFillTex;

	std::shared_ptr<Scene> m_pCurScene;
	Object* m_pOwner;
};

