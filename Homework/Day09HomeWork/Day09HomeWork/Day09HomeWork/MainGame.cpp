#include "MainGame.h"
#include <iostream>
#include <Windows.h>
using namespace std;

void MainGame::Init()
{
	srand(time(NULL));

	cout << "ȭ���� �ʱ�ȭ�մϴ�." << endl;
	for (int i = 0; i < 12; i++)
	{
		_entireCard[i] = i + 1;
	}
}
void MainGame::ShuffleCard() // 2��
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
void MainGame::HandPlayerCard() // 3��
{
	_playerCard1 = _entireCard[0];
    _playerCard2 = _entireCard[1];
}
void MainGame::HandComputerCard() //3��
{	
	_computerCard1 = _entireCard[2];
	_computerCard2 = _entireCard[3];
}
void MainGame::CardCheck(int cardNum,int cardType) //4��
{
		switch (cardNum)
		{
		case 1:
			cout << "����(1)";
			break;
		case 2:
			cout << "����(2)";
			break;
		case 3:
			cout << "����(3)";
			break;
		case 4:
			cout << "���(4)";
			break;
		case 5:
			cout << "����(5)";
			break;
		case 6:
			cout << "���(6)";
			break;
		case 7:
			cout << "�θ�(7)";
			break;
		case 8:
			cout << "���(8)";
			break;
		case 9:
			cout << "��ȭ(9)";
			break;
		case 10:
			cout << "��ǳ(10)";
			break;
		case 11:
			cout << "��(11)";
			break;
		case 12:
			cout << "��(12)";
			break;
		default:
			break;
		}

		switch (cardType)
		{
		case 0:
			cout << "��" << endl;
			break;
		case 1:
			cout << "��" << endl;
			break;
		case 2:
			cout << "����" << endl;
			break;
		case 3:
			if (cardNum == 1 || cardNum == 3 || cardNum == 8 || cardNum == 11 || cardNum == 12)
			{
				cout << "��" << endl;
			}
			else 
			{
				cout << "��" << endl;
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
		cout << _playerCard1 <<"��" << endl;
		playerRank = 1;
	}
	else if (_playerCard1 != _playerCard2)
	{
		cout << (_playerCard1 + _playerCard2) % 10 <<"��" << endl;
		playerRank = 0;
	}
}
void MainGame::CalculateComputerCardRank()
{
	if (_computerCard1 == _computerCard2)
	{
		cout << _computerCard1 << "��" << endl;
		computerRank = 1;
	}
	else if (_computerCard1 != _computerCard2)
	{
		cout << (_computerCard1 + _computerCard2) % 10 << "��" << endl;
		computerRank = 0;
	}
}
void MainGame::CompareCards()
{
	if (playerRank == 1 && computerRank == 1) // �Ѵ� ��
	{
		if (_playerCard1 > _computerCard1)
		{
			cout << "�÷��̾� �¸�!" << endl;
		}
		else if (_playerCard1 < _computerCard1)
		{
			cout << "��ǻ�� �¸�!" << endl;
		}
		else
		{
			cout << "���º��Դϴ� ����" << endl;
		}
		Sleep(10000);
		isGameEnd = false;
	}
	else if (playerRank == 1 && computerRank == 0) // ���� ��
	{
		cout << "�÷��̾� �¸�!" << endl;
		Sleep(10000);
		isGameEnd = false;
	}
	else if (playerRank == 0 && computerRank == 1) // ���� ��
	{
		cout << "��ǻ�� �¸�!" << endl;
		Sleep(10000);
		isGameEnd = false;
	}
	else if (playerRank == 0 && computerRank == 0) // �Ѵ� ��
	{
		if ((_playerCard1 + _playerCard2) % 10 > (_computerCard1 + _computerCard2) % 10)
		{
			cout << "�÷��̾� �¸�!" << endl;
		}
		else if ((_playerCard1 + _playerCard2) % 10 < (_computerCard1 + _computerCard2) % 10)
		{
			cout << "��ǻ�� �¸�!" << endl;
		}
		else
		{
			cout << "���º��Դϴ� ����" << endl;
		}
		Sleep(10000);
		isGameEnd = false;
	}
}
void MainGame::Update()
{
	ShuffleCard(); // 2��
	HandPlayerCard(); // 3��
	HandComputerCard(); // 3��
	cout << "�÷��̾� ù ��° ī�� : ";
	CardCheck(_playerCard1,_cardType[0]); // 4��
	cout << "�÷��̾� �� ��° ī�� : ";
	CardCheck(_playerCard2, _cardType[1]);// 4��
	cout << "��ǻ�� ù ��° ī�� : ";
	CardCheck(_computerCard1, _cardType[2]);// 4��
	cout << "��ǻ�� �� ��° ī�� : ";
	CardCheck(_computerCard2, _cardType[3]);// 4��
	cout << "�÷��̾� ���� ���� : ";
	CalculatePlayerCardRank();
	cout << "��ǻ�� ���� ���� : ";
	CalculateComputerCardRank();
	CompareCards();
}
void MainGame::Release()
{

}