#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int english, math, korean = 0;
float totalScore, averageScore = 0.0f;

void GOTOXY(int x, int y)
{
	COORD pos = { x,y };
	::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void EnterGrade(int e, int m, int k)
{
	printf("���������� �Է����ּ��� : ");
	scanf_s("%d\n", &e);
	printf("���������� �Է����ּ��� : ");
	scanf_s("%d\n,",&m);
	printf("���������� �Է����ּ��� : ");
	scanf_s("%d\n",&k);

	printf("��������: %d ��������: %d ��������: %d\n",e,m,k);
}

void CalculateStudentAverageScore(float t, float a)
{
	t = english + math + korean;
	a = t / 3;
	printf("�л��� ��� ������ %.f �Դϴ�.", a);
}

void FirstPage()
{
	GOTOXY(0, 0); printf("����������������������������������������������������������������������������������");
	GOTOXY(0, 1); printf("��                                       ��");
	GOTOXY(0, 2); printf("��         Student Record System         ��");
	GOTOXY(0, 3); printf("��                                       ��"); 
	GOTOXY(0, 4); printf("��          1. Record                    ��");
	GOTOXY(0, 5); printf("��          2. Exit                      ��");
	GOTOXY(0, 6); printf("��                                       ��");
	GOTOXY(0, 7); printf("��                                       ��");
	GOTOXY(0, 8); printf("��                                       ��");
	GOTOXY(0, 9); printf("��                                       ��");
	GOTOXY(0, 10); printf("����������������������������������������������������������������������������������");
	GOTOXY(7, 4);
	printf("��");
	int choice = 0;
	while (true)
	{
		if (_kbhit())
		{
			char inputkey = _getch();
			GOTOXY(7, 4 + choice);
			printf("����");
			if (inputkey == 's')
			{
				choice++;
			}
			else if (inputkey == 'w')
			{
				choice--;
			}
			else if (inputkey == 'g')
			{
				SecondPage();
				break;
			}
			GOTOXY(7, 5 + choice);
			printf("��");
		}
	}
}

void SecondPage()
{
	GOTOXY(0, 0); printf("����������������������������������������������������������������������������������");
	GOTOXY(0, 1); printf("��                                       ��");
	GOTOXY(0, 2); printf("��         Enter Your English Score        ��");
	GOTOXY(0, 3); printf("��                                       ��");
	GOTOXY(0, 4); printf("��                                       ��");
	GOTOXY(0, 5); printf("��                                       ��");
	GOTOXY(0, 6); printf("��                                       ��");
	GOTOXY(0, 7); printf("��                                       ��");
	GOTOXY(0, 8); printf("��                                       ��");
	GOTOXY(0, 9); printf("��                                       ��");
	GOTOXY(0, 10); printf("����������������������������������������������������������������������������������");
}

void main()
{
	FirstPage();
}
// ����1: �׵��� ������߿��� ���ϴ°� 1�� GotoXY�� Ȱ���ؼ� �ٹ̱� 
//����2 : Day9 �ǽ��Ѱ� �ø���
//����3: �л��� �ý��� 1) ���� ���� ���� ���� �Է��ϰ� �� ���ְ� 2) �Է��� ���������, �л��� ��������� Ȯ�����ִ� ���α׷� (�̰͵� ����XY �Ἥ �̻ڰ��ϸ� ����.)
//����4: �ٸ���ġ, ������ũ����, ��Ʈ���� �����߿� ���� �� �ִ� ����� ��������
