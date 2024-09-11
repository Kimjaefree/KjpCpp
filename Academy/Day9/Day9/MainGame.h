#pragma once
class MainGame
{
public:
	void Init();
	void Run();
	void Release();

	bool IsGameEnd();
	void ShuffleCard();
public:
	//클래스의 멤버변수는 _로 시작한다.
	int _card[52] = {};
};

