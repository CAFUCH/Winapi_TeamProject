#pragma once
#include "Object.h"
class Texture;
class Particle :
    public Object
{
public:
    Particle() = default;
    Particle(PARTICLE_TYPE _type);
    ~Particle();

public:
    void Update() override;

private:
    Texture* m_pTex;
    PARTICLE_TYPE m_eType;
    wstring m_animName;
};

