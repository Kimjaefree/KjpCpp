#include <iostream>
#include "MainGame.h"
using namespace std;
// 못한 부분 + 헷갈리는 부분
// 1. 1,3, 광땡이나 3,8 광땡을 비교하는 방법 , 47암행어사 등.
void main()
{
	MainGame* mainGame = new MainGame();
	mainGame->Init();

	cout << "섯다에 오신걸 환영합니다!" << endl; // 1번

	while (mainGame->isGameEnd == true)
	{
		mainGame->Update();
	}

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}