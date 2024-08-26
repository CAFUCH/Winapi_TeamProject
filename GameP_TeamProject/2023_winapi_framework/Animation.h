#pragma once
class Texture; class Animator;
struct tAnimFrame
{
	// 애니메이션의 시작값 (left, top)
	Vec2 vLT;
	// 애니메이션 한 프레임 크기
	Vec2 vSlice;
	// 애니메이션 재생 시간
	float fDuration;
	// 애니메이션 오프셋
	Vec2 vOffset;
};

class Animation
{
public:
	Animation();
	~Animation();

public:
	void Update();
	//bool Update();
	void Render(HDC _dc);

public:
	// 애니메이션 생성 (시작 위치, 크기, 크기, 프레임 수, 재생 시간) 
	void Create(Texture* _pTex, Vec2 _vLT, Vec2 _vSliceSize, 
		Vec2 _vStep, int _framecount, float _fDuration);

public:
	const wstring& GetName() const { return m_strName; }
	void SetName(wstring _name) { m_strName = _name; }

	const bool& GetIsAnima() const { return m_isAnim; }

	void SetFrameOffset(int _index, Vec2 _offset) { m_vecAnimFrame[_index].vOffset = _offset; }

	const size_t& GetMaxFrame() { return m_vecAnimFrame.size(); }

	friend class Animator;

private:
	// 애니메이션 이름
	wstring m_strName;
	// 애니메이터
	Animator* m_pAnimator;
	// 애니메이션 프레임
	vector<tAnimFrame> m_vecAnimFrame;

	// 애니메이션 텍스처
	Texture* m_pTex; 
	// 현재 프레임
	UINT m_CurFrame; 
	// 누적 시간
	float m_fAccTime;
	// 반복 횟수
	int m_repeatcnt; 
	// 현재 진행이 끝났는지
	bool m_isAnim;
};

