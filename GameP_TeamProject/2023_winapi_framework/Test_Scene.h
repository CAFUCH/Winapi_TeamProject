#pragma once
#include "Scene.h"
class Test_Scene :
	public Scene
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC _dc) override;
	virtual void Release() override;
public:
	void HandleChangedGameScene();
	void HandleChangedEXPScene();
};

