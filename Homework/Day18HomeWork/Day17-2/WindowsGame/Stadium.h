#pragma once
class Stadium
{
	public:
		void Init();
		void Render(HDC hdc);
		void Update();
		void Release();

	public:
		CenterRect GetBody() { return _stadiumBody; }
		void SetBody(CenterRect body) { _stadiumBody = body; }
	private:
		CenterRect _stadiumBody;
};

