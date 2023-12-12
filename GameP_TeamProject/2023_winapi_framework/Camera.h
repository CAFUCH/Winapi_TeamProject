#pragma once
class Object;
class Camera
{
	SINGLE(Camera);

public:
	void Update();

public:
	// 카메라 위치 설정
	void SetLook(Vec2 _look) { m_vLookAt = _look; }
	// 카메라 타겟 설정
	void SetTarget(Object* _target) { m_pTarget = _target; }

	// 둘이 서로 World와 Local 값으로 변환해주는
	const Vec2& GetRenderPos(Vec2 _vObjectPos) 
		const {return _vObjectPos - m_vDiff; }
	const Vec2& GetRealPos(Vec2 _vRenderPos) 
		const {return _vRenderPos + m_vDiff; }

private:
	// 차이 계산
	void CalDiff();

private:
	// 현재 카메라 위치
	Vec2 m_vLookAt;
	// 이전 카메라 위치
	Vec2 m_vPrevLookAt;
	// 이전과 현재 사이의 카메라 위치
	Vec2 m_vCurLookAt;

	// 타겟 오브젝트
	Object* m_pTarget;
	// 해상도 중심값과 타겟의 차이값
	Vec2 m_vDiff;

private:
	// 타겟 따라가는데 걸리는 시간
	float m_fTime = 2.f; 
	// 타겟 따라가는 속도
	float m_fSpeed = 0.f; 
	// 누적시간
	float m_fAccTime = 0.f; 
};

