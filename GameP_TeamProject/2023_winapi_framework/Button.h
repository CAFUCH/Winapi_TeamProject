#pragma once
#include "UI.h"
class Texture;
class Button :
	public UI
{
public:
	Button();
	~Button();
public:
	virtual void Init();
	virtual void Update();
	virtual void Render(HDC _dc);
private:
	Texture* texture;
};

