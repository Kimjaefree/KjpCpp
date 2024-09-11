#include "MainGame.h"
#include <iostream>
using namespace std;

void MainGame::Init()
{
	srand(time(NULL));
	cout << "카드를 초기화 합니다." << endl;
	for (int i = 0; i < 52; i++)
	{
		_card[i] = i;
	}
}

void MainGame::ShuffleCard()
{
	for (int i = 0; i < 100000; i++)
	{
		int index1 = rand() % 52;
		int index2 = rand() % 52;
		int temp = _card[index1];
		_card[index1] = _card[index2];
		_card[index2] = temp;
	}
}

void MainGame::Run()
{
	ShuffleCard();

	for (int i = 0; i < 52; i++)
	{
		cout << _card[i] << endl;
	}
}
void MainGame::Release()
{

}

bool MainGame::IsGameEnd()
{
	return false;
}


//실습 
// 하이로우세븐만든거를 MainGame으로 이식하기
