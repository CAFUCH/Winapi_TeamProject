#pragma once
class Texture; class Animator;
struct tAnimFrame
{
	// �ִϸ��̼��� ���۰� (left, top)
	Vec2 vLT;
	// �ִϸ��̼� �� ������ ũ��
	Vec2 vSlice;
	// �ִϸ��̼� ��� �ð�
	float fDuration;
	// �ִϸ��̼� ������ (���� ��Ȯ�� �𸣰���)
	Vec2 vOffset;
};

class Animation
{
public:
	Animation();
	~Animation();

public:
	void Update();
	void Render(HDC _dc);

public:
	// �ִϸ��̼� ���� (���� ��ġ, ũ��, ũ��, ������ ��, ��� �ð�) 
	void Create(Texture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, 
		Vec2 _vStep, int _framecount, float _fDuration);

public:
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }

	void SetFrameOffset(int _index, Vec2 _offset) { m_vecAnimFrame[_index].vOffset = _offset; }

	const size_t& GetMaxFrame() { return m_vecAnimFrame.size(); }

	friend class Animator;

private:
	// �ִϸ��̼� �̸�
	wstring m_strName;
	// �ִϸ�����
	Animator* m_pAnimator;
	// �ִϸ��̼� ������
	vector<tAnimFrame> m_vecAnimFrame;

	// �ִϸ��̼� �ؽ�ó
	Texture* m_pTex; 
	// ���� ������
	UINT m_CurFrame; 
	// ���� �ð�
	float m_fAccTime;
	// �ݺ� Ƚ��
	int m_repeatcnt; 
};

