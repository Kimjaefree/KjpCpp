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
    GOTOXY(0, 0); printf("┌───────────────────────────────────────┐");
    GOTOXY(0, 1); printf("│                                       │");
    GOTOXY(0, 2); printf("│         Student Record System         │");
    GOTOXY(0, 3); printf("│                                       │");
    GOTOXY(0, 4); printf("│          1. Record                    │");
    GOTOXY(0, 5); printf("│          2. Exit                      │");
    GOTOXY(0, 6); printf("│                                       │");
    GOTOXY(0, 7); printf("│                                       │");
    GOTOXY(0, 8); printf("│                                       │");
    GOTOXY(0, 9); printf("│                                       │");
    GOTOXY(0, 10); printf("└───────────────────────────────────────┘");
    GOTOXY(7, 4);
    printf("→");

    while (true)
    {
        if (_kbhit())
        {
            char inputkey = _getch();
            GOTOXY(7, 4 + choice);
            printf("　　");
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
            printf("→");
        }
    }
}

void EnglishScorePage()
{
    GOTOXY(0, 0); printf("┌───────────────────────────────────────┐");
    GOTOXY(0, 1); printf("│                                       │");
    GOTOXY(0, 2); printf("│         Enter Your English Score      │");
    GOTOXY(0, 3); printf("│                                       │");
    GOTOXY(0, 4); printf("│                                       │");
    GOTOXY(0, 5); printf("│                                       │");
    GOTOXY(0, 6); printf("│                                       │");
    GOTOXY(0, 7); printf("│                                       │");
    GOTOXY(0, 8); printf("│                                       │");
    GOTOXY(0, 9); printf("│                                       │");
    GOTOXY(0, 10); printf("└───────────────────────────────────────┘");
}

void MathScorePage()
{
    GOTOXY(0, 0); printf("┌───────────────────────────────────────┐");
    GOTOXY(0, 1); printf("│                                       │");
    GOTOXY(0, 2); printf("│         Enter Your Math Score         │");
    GOTOXY(0, 3); printf("│                                       │");
    GOTOXY(0, 4); printf("│                                       │");
    GOTOXY(0, 5); printf("│                                       │");
    GOTOXY(0, 6); printf("│                                       │");
    GOTOXY(0, 7); printf("│                                       │");
    GOTOXY(0, 8); printf("│                                       │");
    GOTOXY(0, 9); printf("│                                       │");
    GOTOXY(0, 10); printf("└───────────────────────────────────────┘");
}

void KoreanScorePage()
{
    GOTOXY(0, 0); printf("┌───────────────────────────────────────┐");
    GOTOXY(0, 1); printf("│                                       │");
    GOTOXY(0, 2); printf("│         Enter Your Korean Score       │");
    GOTOXY(0, 3); printf("│                                       │");
    GOTOXY(0, 4); printf("│                                       │");
    GOTOXY(0, 5); printf("│                                       │");
    GOTOXY(0, 6); printf("│                                       │");
    GOTOXY(0, 7); printf("│                                       │");
    GOTOXY(0, 8); printf("│                                       │");
    GOTOXY(0, 9); printf("│                                       │");
    GOTOXY(0, 10); printf("└───────────────────────────────────────┘");
}

void AveragePage()
{
    GOTOXY(0, 0); printf("┌───────────────────────────────────────┐");
    GOTOXY(0, 1); printf("│                                       │");
    GOTOXY(0, 2); printf("│                ★Score★              │");
    GOTOXY(0, 3); printf("│                                       │");
    GOTOXY(0, 4); printf("│                                       │");
    GOTOXY(0, 5); printf("│                                       │");
    GOTOXY(0, 6); printf("│                                       │");
    GOTOXY(0, 7); printf("│                                       │");
    GOTOXY(0, 8); printf("│                                       │");
    GOTOXY(0, 9); printf("│                                       │");
    GOTOXY(0, 10); printf("└───────────────────────────────────────┘");
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
// 숙제1: 그동안 만든것중에서 원하는거 1개 GotoXY를 활용해서 꾸미기 - 로또 추첨 프로그램 - 코드 완 gotoxy만 해보면 됨
//숙제2 : Day9 실습한거 올리기 - 완
//숙제3: 학생부 시스템 1) 영어 수학 국어 성적 입력하게 끔 해주고 2) 입력을 모두했으면, 학생의 평균점수를 확인해주는 프로그램 (이것도 고투XY 써서 이쁘게하면 좋음.)
//       실행 시켜보고 잘 돌아가는지, gotoxy 꾸미기 잘 되어있는지 확인하기
//숙제4: 다마고치, 스네이크게임, 테트리스 게임중에 만들 수 있는 사람만 만들어오기
