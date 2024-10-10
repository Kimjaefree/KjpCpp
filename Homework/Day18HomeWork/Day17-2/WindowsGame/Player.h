#pragma once
class Ball;
class Stadium;
class Player
{
private:
	Ball* _ball = nullptr;
	Stadium* _stadium = nullptr;
	CenterRect _p1Body;
	CenterRect _p2Body;
	float _moveSpeed = 200.0f;
	float _ballSpeed = 300.0f;
	Vector2 _targetPoint = {};

public:
	void Init();			// 생성될떄, 초기화해야할때.
	void Render(HDC hdc);	// 그림 그릴때,
	void Update();			// 매 프레임에 대한 로직
	void Release();			// 해제할때, 객체를 없앨때

public:
	void SetLinkBall(Ball* ballBox) { _ball = ballBox; }
	void SetLinkStadium(Stadium* stadiumBox) { _stadium = stadiumBox; }

public:
	short _player1Score;
	short _player2Score;
};

