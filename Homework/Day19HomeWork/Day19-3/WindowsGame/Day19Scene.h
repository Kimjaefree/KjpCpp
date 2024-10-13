#pragma once
#include "Scene.h"

enum class Day19SceneState
{
	bRockTurn,
	wRockTurn,
	win
};
class Texture;
class Sprite;
class Day19Scene : public Scene
{
	DECLARE_CHILD(Day19Scene, Scene);
public:
	virtual void Init();
	virtual void Render(HDC hdc);
	virtual void Update();
	virtual void Release();

private:
	Texture* _mainTexture = nullptr;
	Texture* _wRock = nullptr;
	Texture* _bRock = nullptr;
	Sprite* _sprite = nullptr;

public:
	int _board[BOARD_SIZE][BOARD_SIZE];
	int _boardX;
	int _boardY;
	int _rx;
	int _ry;
	int _lx;
	int _ly;

	// 우측, 하단 
	int _rightX[4] = { 1, 0, 1, 1 }; // 1 0 은 오른쪽 한 칸 1 1 은 대각선 
	int _rightY[4] = { 0, 1, 1, -1 }; // 0 1 은 아래쪽 한칸 1 -1 은 대각선
	// 좌측, 상단
	int _leftX[4] = { -1, 0, -1, -1 }; // -1 0 은 왼쪽 한 칸 -1 -1 은 대각선 왼쪽 위
	int _leftY[4] = { 0, -1, -1, 1 }; // 0 -1 은 위쪽 한칸 -1 -1 은 대각선 왼쪽 아래
	int _rockCount; // 돌 개수 세기
	POINT _mousepos;

private:
	Day19SceneState _state;

private:
	void Update_bRock();
	void Update_wRock();
	void CountRock(int x, int y, int rockColor);
};
