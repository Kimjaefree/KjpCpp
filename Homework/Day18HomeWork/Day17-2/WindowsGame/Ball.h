#pragma once
class Ball
{

public:
	void Init();
	void Render(HDC hdc);
	void Update();
	void Release();

public:
	CenterRect GetBody() { return _ballBody; }
	void SetBody(CenterRect body) { _ballBody = body; }
private:
	CenterRect _ballBody;
};

