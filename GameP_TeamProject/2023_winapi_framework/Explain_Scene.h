#pragma once
#include "Scene.h"
class Texture;
class Explain_Scene :
    public Scene
{
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render(HDC _dc) override;
    virtual void Release() override;
};