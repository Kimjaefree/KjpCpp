#include <iostream>
#include "MainGame.h"
using namespace std;
// ���� �κ� + �򰥸��� �κ�
// 1. 1,3, �����̳� 3,8 ������ ���ϴ� ��� , 47������ ��.
void main()
{
	MainGame* mainGame = new MainGame();
	mainGame->Init();

	cout << "���ٿ� ���Ű� ȯ���մϴ�!" << endl; // 1��

	while (mainGame->isGameEnd == true)
	{
		mainGame->Update();
	}

	mainGame->Release();
	delete mainGame;
	mainGame = nullptr;
}