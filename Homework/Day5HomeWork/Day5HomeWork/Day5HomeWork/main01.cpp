#include <iostream>
using namespace std;

int randNum, strike, ball, attempts = 0;
int randArr[10] , computerNum[3], guessNum[3] = { 0 };

void ComputerChooseRandomNumber() // 플레이어가 맞춰야 할 숫자 랜덤 생성 함수
{
	for (int i = 0; i < 3; i++)
	{
		do
		{
			randNum = rand() % 10;
		} while (randArr[randNum] != 0);

		randArr[randNum] = 1;
		computerNum[i] = randNum;
	}
}

void UserChoice() // 유저가 세 자리 숫자를 결정하는 함수
{
	printf("세 자리 숫자를 입력하세요 (각 자리 숫자는 서로 달라야 합니다) :");
	scanf_s("%1d %1d %1d", &guessNum[0], &guessNum[1], &guessNum[2]);
}

void CompareNumber() // 컴퓨터가 생성한 랜덤 숫자와 유저가 결정한 세 자리 숫자를 비교하는 함수
{
	strike = 0;
	ball = 0;

	for (int i = 0; i < 3; i++)
	{
		if (guessNum[i] == computerNum[i]) // 자릿수와 숫자가 다 맞다면
		{
			strike++; // strike 증감
		}
		else
		{
			for (int j = 0; j < 3; j++) 
			{
				if (guessNum[i] == computerNum[j]) // 자릿수는 다르지만 숫자가 맞다면
				{
					ball++; // ball 증감
				}
			}
		}
	}
}

void StatusBoard() // 컴퓨터가 고른 숫자, 플레이어가 부른 숫자 , strike, ball 현황을 출력해주는 함수
{	
	printf("컴퓨터가 고른 숫자 : ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d", computerNum[i]);
	}
	printf("\n");

	printf("플레이어가 부른 숫자 : ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d", guessNum[i]);
	}
	printf("\n");

	printf("%ds %db\n", strike, ball);
}
void main()
{
	srand(time(NULL));
	printf("숫자야구 게임 시작!\n");
	ComputerChooseRandomNumber();

	do
	{
		UserChoice();
		CompareNumber();
		StatusBoard();
		attempts++;
	} while (strike < 3);

	printf("%d번 만에 숫자를 맞추셨습니다.\n", attempts);
}