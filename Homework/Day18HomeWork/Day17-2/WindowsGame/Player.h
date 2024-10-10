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
	void Init();			// �����ɋ�, �ʱ�ȭ�ؾ��Ҷ�.
	void Render(HDC hdc);	// �׸� �׸���,
	void Update();			// �� �����ӿ� ���� ����
	void Release();			// �����Ҷ�, ��ü�� ���ٶ�

public:
	void SetLinkBall(Ball* ballBox) { _ball = ballBox; }
	void SetLinkStadium(Stadium* stadiumBox) { _stadium = stadiumBox; }

public:
	short _player1Score;
	short _player2Score;
};

