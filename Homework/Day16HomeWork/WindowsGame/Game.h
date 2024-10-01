#pragma once
class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hWnd);
	void Update();
	void Render();

private:
	HWND _hwnd = {};
	HDC _hdc;      // 유저에게 보여줄 화면

private: // 더블버퍼링 변수
	HDC _hdcBack = {};      // backbuffer, 유저에게 보이지 않는 화면
	RECT _rect = {};      // 화면 크기
	HBITMAP _bmpBack = {};   // 화면에 그릴 물감

private:
	InputManager _input;
	CenterRect _player;
	CenterRect _anotherRc; // 겉도는 사각형
	CenterRect _wrapRc; // 두 번째 사각형
};

