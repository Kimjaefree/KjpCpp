#include "MainGame.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void MainGame::Init()
{
	srand(time(NULL));

	cout << "화투를 초기화합니다." << endl;
	for (int i = 0; i < 12; i++)
	{
		_entireCard[i] = i + 1;
	}
}
void MainGame::ShuffleCard() // 2번
{
	for (int i = 0; i < 12; i++)
	{
		int index1 = (rand() % 12);
		int index2 = (rand() % 12);
		int temp = _entireCard[index1];
		_entireCard[index1] = _entireCard[index2];
		_entireCard[index2] = temp;
	}

	for (int i = 0; i < 4; i++)
	{
		_cardType[i] = rand() % 4;
	}
}
void MainGame::HandPlayerCard() // 3번
{
	_playerCard1 = _entireCard[0];
    _playerCard2 = _entireCard[1];
}
void MainGame::HandComputerCard() //3번
{	
	_computerCard1 = _entireCard[2];
	_computerCard2 = _entireCard[3];
}
void MainGame::CardCheck(int cardNum,int cardType) //4번
{
		switch (cardNum)
		{
		case 1:
			cout << "송학(1)";
			break;
		case 2:
			cout << "매조(2)";
			break;
		case 3:
			cout << "벚꽃(3)";
			break;
		case 4:
			cout << "등나무(4)";
			break;
		case 5:
			cout << "난초(5)";
			break;
		case 6:
			cout << "모란(6)";
			break;
		case 7:
			cout << "싸리(7)";
			break;
		case 8:
			cout << "억새(8)";
			break;
		case 9:
			cout << "국화(9)";
			break;
		case 10:
			cout << "단풍(10)";
			break;
		case 11:
			cout << "똥(11)";
			break;
		case 12:
			cout << "비(12)";
			break;
		default:
			break;
		}

		switch (cardType)
		{
		case 0:
			cout << "피" << endl;
			break;
		case 1:
			cout << "띠" << endl;
			break;
		case 2:
			cout << "열끗" << endl;
			break;
		case 3:
			if (cardNum == 1 || cardNum == 3 || cardNum == 8 || cardNum == 11 || cardNum == 12)
			{
				cout << "광" << endl;
			}
			else 
			{
				cout << "피" << endl;
			}
			break;
		default:
			break;
		}
}
void MainGame::CalculatePlayerCardRank()
{
	if (_playerCard1 == _playerCard2)
	{
		cout << _playerCard1 <<"땡" << endl;
		playerRank = 1;
	}
	else if (_playerCard1 != _playerCard2)
	{
		cout << (_playerCard1 + _playerCard2) % 10 <<"끗" << endl;
		playerRank = 0;
	}
}
void MainGame::CalculateComputerCardRank()
{
	if (_computerCard1 == _computerCard2)
	{
		cout << _computerCard1 << "땡" << endl;
		computerRank = 1;
	}
	else if (_computerCard1 != _computerCard2)
	{
		cout << (_computerCard1 + _computerCard2) % 10 << "끗" << endl;
		computerRank = 0;
	}
}
void MainGame::CompareCards()
{
	if (playerRank == 1 && computerRank == 1) // 둘다 땡
	{
		if (_playerCard1 > _computerCard1)
		{
			cout << "플레이어 승리!" << endl;
		}
		else if (_playerCard1 < _computerCard1)
		{
			cout << "컴퓨터 승리!" << endl;
		}
		else
		{
			cout << "무승부입니다 재경기" << endl;
		}
		Sleep(10000);
		isGameEnd = false;
	}
	else if (playerRank == 1 && computerRank == 0) // 땡과 끗
	{
		cout << "플레이어 승리!" << endl;
		Sleep(10000);
		isGameEnd = false;
	}
	else if (playerRank == 0 && computerRank == 1) // 끗과 땡
	{
		cout << "컴퓨터 승리!" << endl;
		Sleep(10000);
		isGameEnd = false;
	}
	else if (playerRank == 0 && computerRank == 0) // 둘다 끗
	{
		if ((_playerCard1 + _playerCard2) % 10 > (_computerCard1 + _computerCard2) % 10)
		{
			cout << "플레이어 승리!" << endl;
		}
		else if ((_playerCard1 + _playerCard2) % 10 < (_computerCard1 + _computerCard2) % 10)
		{
			cout << "컴퓨터 승리!" << endl;
		}
		else
		{
			cout << "무승부입니다 재경기" << endl;
		}
		Sleep(10000);
		isGameEnd = false;
	}
}
void MainGame::Update()
{
	ShuffleCard(); // 2번
	HandPlayerCard(); // 3번
	HandComputerCard(); // 3번
	cout << "플레이어 첫 번째 카드 : ";
	CardCheck(_playerCard1,_cardType[0]); // 4번
	cout << "플레이어 두 번째 카드 : ";
	CardCheck(_playerCard2, _cardType[1]);// 4번
	cout << "컴퓨터 첫 번째 카드 : ";
	CardCheck(_computerCard1, _cardType[2]);// 4번
	cout << "컴퓨터 두 번째 카드 : ";
	CardCheck(_computerCard2, _cardType[3]);// 4번
	cout << "플레이어 최종 족보 : ";
	CalculatePlayerCardRank();
	cout << "컴퓨터 최종 족보 : ";
	CalculateComputerCardRank();
	CompareCards();
}
void MainGame::Release()
{

}