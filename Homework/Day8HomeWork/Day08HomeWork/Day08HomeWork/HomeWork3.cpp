#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int english, math, korean, choice= 0;
float totalScore, averageScore = 0.0f;

void GOTOXY(int x, int y)
{
    COORD pos = { x,y };
    ::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void EnterEnglishScore()
{
    GOTOXY(3, 5);
    printf("Score : ");
    GOTOXY(11, 5);
    scanf_s("%d", &english);
}

void EnterMathScore()
{
    GOTOXY(3, 5);
    printf("Score : ");
    GOTOXY(11, 5);
    scanf_s("%d", &math);
}

void EnterKoreanScore()
{
    GOTOXY(3, 5);
    printf("Score : ");
    GOTOXY(11, 5);
    scanf_s("%d", &korean);
}

void CalculateStudentAverageScore()
{
    totalScore = english + math + korean;
    averageScore = totalScore / 3;
}

void ShowTotalAndAverageScore()
{
    GOTOXY(3, 5);
    printf("Total Score : %.f", totalScore);
    GOTOXY(3, 7);
    printf("Average Score : %.f", averageScore);
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
                break;
            }
            GOTOXY(7, 5 + choice);
            printf("��");
        }
    }
}

void EnglishScorePage()
{
    GOTOXY(0, 0); printf("����������������������������������������������������������������������������������");
    GOTOXY(0, 1); printf("��                                       ��");
    GOTOXY(0, 2); printf("��         Enter Your English Score      ��");
    GOTOXY(0, 3); printf("��                                       ��");
    GOTOXY(0, 4); printf("��                                       ��");
    GOTOXY(0, 5); printf("��                                       ��");
    GOTOXY(0, 6); printf("��                                       ��");
    GOTOXY(0, 7); printf("��                                       ��");
    GOTOXY(0, 8); printf("��                                       ��");
    GOTOXY(0, 9); printf("��                                       ��");
    GOTOXY(0, 10); printf("����������������������������������������������������������������������������������");
}

void MathScorePage()
{
    GOTOXY(0, 0); printf("����������������������������������������������������������������������������������");
    GOTOXY(0, 1); printf("��                                       ��");
    GOTOXY(0, 2); printf("��         Enter Your Math Score         ��");
    GOTOXY(0, 3); printf("��                                       ��");
    GOTOXY(0, 4); printf("��                                       ��");
    GOTOXY(0, 5); printf("��                                       ��");
    GOTOXY(0, 6); printf("��                                       ��");
    GOTOXY(0, 7); printf("��                                       ��");
    GOTOXY(0, 8); printf("��                                       ��");
    GOTOXY(0, 9); printf("��                                       ��");
    GOTOXY(0, 10); printf("����������������������������������������������������������������������������������");
}

void KoreanScorePage()
{
    GOTOXY(0, 0); printf("����������������������������������������������������������������������������������");
    GOTOXY(0, 1); printf("��                                       ��");
    GOTOXY(0, 2); printf("��         Enter Your Korean Score       ��");
    GOTOXY(0, 3); printf("��                                       ��");
    GOTOXY(0, 4); printf("��                                       ��");
    GOTOXY(0, 5); printf("��                                       ��");
    GOTOXY(0, 6); printf("��                                       ��");
    GOTOXY(0, 7); printf("��                                       ��");
    GOTOXY(0, 8); printf("��                                       ��");
    GOTOXY(0, 9); printf("��                                       ��");
    GOTOXY(0, 10); printf("����������������������������������������������������������������������������������");
}

void AveragePage()
{
    GOTOXY(0, 0); printf("����������������������������������������������������������������������������������");
    GOTOXY(0, 1); printf("��                                       ��");
    GOTOXY(0, 2); printf("��                ��Score��              ��");
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
    EnglishScorePage();
    EnterEnglishScore();
    MathScorePage();
    EnterMathScore();
    KoreanScorePage();
    EnterKoreanScore();
    CalculateStudentAverageScore();
    AveragePage();
    ShowTotalAndAverageScore();
}
// ����1: �׵��� ������߿��� ���ϴ°� 1�� GotoXY�� Ȱ���ؼ� �ٹ̱� - �ζ� ��÷ ���α׷� - �ڵ� �� gotoxy�� �غ��� ��
//����2 : Day9 �ǽ��Ѱ� �ø��� - ��
//����3: �л��� �ý��� 1) ���� ���� ���� ���� �Է��ϰ� �� ���ְ� 2) �Է��� ���������, �л��� ��������� Ȯ�����ִ� ���α׷� (�̰͵� ����XY �Ἥ �̻ڰ��ϸ� ����.)
//       ���� ���Ѻ��� �� ���ư�����, gotoxy �ٹ̱� �� �Ǿ��ִ��� Ȯ���ϱ�
//����4: �ٸ���ġ, ������ũ����, ��Ʈ���� �����߿� ���� �� �ִ� ����� ��������
