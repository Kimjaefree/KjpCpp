#include <iostream>
using namespace std;

int randNum, strike, ball, attempts = 0;
int randArr[10] , computerNum[3], guessNum[3] = { 0 };

void ComputerChooseRandomNumber() // �÷��̾ ����� �� ���� ���� ���� �Լ�
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

void UserChoice() // ������ �� �ڸ� ���ڸ� �����ϴ� �Լ�
{
	printf("�� �ڸ� ���ڸ� �Է��ϼ��� (�� �ڸ� ���ڴ� ���� �޶�� �մϴ�) :");
	scanf_s("%1d %1d %1d", &guessNum[0], &guessNum[1], &guessNum[2]);
}

void CompareNumber() // ��ǻ�Ͱ� ������ ���� ���ڿ� ������ ������ �� �ڸ� ���ڸ� ���ϴ� �Լ�
{
	strike = 0;
	ball = 0;

	for (int i = 0; i < 3; i++)
	{
		if (guessNum[i] == computerNum[i]) // �ڸ����� ���ڰ� �� �´ٸ�
		{
			strike++; // strike ����
		}
		else
		{
			for (int j = 0; j < 3; j++) 
			{
				if (guessNum[i] == computerNum[j]) // �ڸ����� �ٸ����� ���ڰ� �´ٸ�
				{
					ball++; // ball ����
				}
			}
		}
	}
}

void StatusBoard() // ��ǻ�Ͱ� �� ����, �÷��̾ �θ� ���� , strike, ball ��Ȳ�� ������ִ� �Լ�
{	
	printf("��ǻ�Ͱ� �� ���� : ");
	for (int i = 0; i < 3; i++)
	{
		printf("%d", computerNum[i]);
	}
	printf("\n");

	printf("�÷��̾ �θ� ���� : ");
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
	printf("���ھ߱� ���� ����!\n");
	ComputerChooseRandomNumber();

	do
	{
		UserChoice();
		CompareNumber();
		StatusBoard();
		attempts++;
	} while (strike < 3);

	printf("%d�� ���� ���ڸ� ���߼̽��ϴ�.\n", attempts);
}