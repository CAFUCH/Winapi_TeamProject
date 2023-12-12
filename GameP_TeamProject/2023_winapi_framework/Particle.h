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
    void Render(HDC _dc) override;
    
public:
    void SetOwner(Object* _owner) { m_pOwner = _owner; }

private:
    Texture* m_pTex;
    PARTICLE_TYPE m_eType;
    Object* m_pOwner;
    wstring m_animName;
    float curTime, lifeTime;

    friend Object;
};

