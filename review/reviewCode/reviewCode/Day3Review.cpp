#include <iostream>

using namespace std;

enum class RockScissorsPaper
{
	Scissor,
	Rock,
	Paper,
};

void main() 
{
	// 3일차 코드 복습 
	// 1. 텍스트RPG 만들기 선택과 랜덤만 들어가면 만사 OK
	// 2. 가위바위보 게임 만들기
}

void TextRpg()
{
	srand(time(NULL));
	int playerLv = 1;
	cout << "플레이어는" << playerLv << "입니다." << endl;
	cout << "던전에 입장하였습니다." << endl;
	int goblinLv = 1;
	cout << "1레벨 고블린과 조우하였습니다. (1: 싸우기, 2: 도망가기)" << endl;
	int choice = 0;

	cin >> choice;

	if (choice == 1)
	{
		cout << "싸우기를 선택하였습니다" << endl;
		float diePoint = (float)goblinLv / (float)(1 + playerLv * 2) * 100; // %로 변환
		int rnd = rand() % 100;
		if (rnd < diePoint)
		{
			cout << "플레이어는 사망하였습니다." << endl;
			exit(0);
		}
		else
		{
			playerLv++;
			cout << "고블린과의 전투에서 승리하였습니다. " << endl;
			cout << "플레이어 레벨이 올랐습니다. 현재 레벨 : " << playerLv << endl;
		}
	}
	else if (choice == 2)
	{
		int rnd = rand() % 100;

		if (rnd < 10)
		{
			cout << "플레이어는 사망하였습니다." << endl;
			exit(0);
		}
		else
		{
			cout << "도망쳤습니다!" << endl;
		}
	}

	cout << "플레이어는 " << playerLv << "레벨로 던전에 탈출하였습니다." << endl;
	cout << "축하드립니다. 게임을 클리어하였습니다." << endl;
}

void RockScissorPaper()
{
	srand(time(NULL));
	cout << " 가위(0), 바위(1), 보(2) 중에서 선택해주세요" << endl;
	int playerHand = 0;
	cin >> playerHand;
	int comHand = 0;
	comHand = rand() % 3;
	
	if (playerHand == (int)RockScissorsPaper :: Scissor)
	{
		cout << "플레이어는 가위를 선택하셨습니다." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Rock)
	{
		cout << "플레이어는 바위를 선택하셨습니다." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Paper)
	{
		cout << "플레이어는 보를 선택하셨습니다." << endl;
	}

	if (comHand == (int)RockScissorsPaper::Scissor)
	{
		cout << "컴퓨터는 가위를 선택하셨습니다." << endl;
	}
	else if (comHand == (int)RockScissorsPaper::Rock)
	{
		cout << "컴퓨터는 바위를 선택하셨습니다." << endl;
	}
	else if (comHand == (int)RockScissorsPaper::Paper)
	{
		cout << "컴퓨터는 보를 선택하셨습니다." << endl;
	}

	if (playerHand == comHand)
	{
		cout << "비겼습니다." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Scissor && comHand == (int)RockScissorsPaper::Rock)
	{
		cout << "졌습니다." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Rock && comHand == (int)RockScissorsPaper::Paper)
	{
		cout << "졌습니다." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Paper && comHand == (int)RockScissorsPaper::Scissor)
	{
		cout << "졌습니다." << endl;
	}
	else
	{
		cout << "이겼습니다." << endl;
	}

}