#pragma once
class Object;
class Camera
{
	SINGLE(Camera);

public:
	void Update();

public:
	// ī�޶� ��ġ ����
	void SetLook(Vec2 _look) { m_vLookAt = _look; }
	// ī�޶� Ÿ�� ����
	void SetTarget(Object* _target) { m_pTarget = _target; }

	// ���� ���� World�� Local ������ ��ȯ���ִ�
	const Vec2& GetRenderPos(Vec2 _vObjectPos) 
		const {return _vObjectPos - m_vDiff; }
	const Vec2& GetRealPos(Vec2 _vRenderPos) 
		const {return _vRenderPos + m_vDiff; }

private:
	// ���� ���
	void CalDiff();

private:
	// ���� ī�޶� ��ġ
	Vec2 m_vLookAt;
	// ���� ī�޶� ��ġ
	Vec2 m_vPrevLookAt;
	// ������ ���� ������ ī�޶� ��ġ
	Vec2 m_vCurLookAt;

	// Ÿ�� ������Ʈ
	Object* m_pTarget;
	// �ػ� �߽ɰ��� Ÿ���� ���̰�
	Vec2 m_vDiff;

private:
	// Ÿ�� ���󰡴µ� �ɸ��� �ð�
	float m_fTime = 2.f; 
	// Ÿ�� ���󰡴� �ӵ�
	float m_fSpeed = 0.f; 
	// �����ð�
	float m_fAccTime = 0.f; 
};

