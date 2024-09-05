#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
int choice = 0;

int randLottoNum[45] = { 0, }; // 로또 숫자가 들어갈 배열 변수 선언 및 초기화
int userLottoNum[7] = { 0, };
int matchNum = 0;
int randomLottoNumLocation, userLottoNumLocation = 0;

void GoToXY(short x, short y)
{
    COORD pos = { x,y };
    ::SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void GetUserLottoNum()
{
    for (int i = 0; i < 7; i++) {
        printf("Choose Your %d Lotto Number (Only Between 1 to 45) : ", i + 1);
        scanf_s("%d", &userLottoNum[i]);

        
        if (userLottoNum[i] < 1 || userLottoNum[i] > 45) {
            printf("잘못된 숫자를 입력하셔서 프로그램이 종료됩니다!\n");
            exit(0);
        }

        
        for (int j = 0; j < i; j++) {
            if (userLottoNum[i] == userLottoNum[j]) {
                printf("중복된 숫자를 입력하셔서 프로그램이 종료됩니다!\n");
                exit(0);
            }
        }
    }

    printf("All numbers entered correctly!\n");
    Sleep(1000);
    system("cls");
}

void MixLottoNumber()
{
    for (int i = 0; i < 45; i++)
    {
        randLottoNum[i] = i + 1; // lotto 배열 변수에 1~45의 숫자 넣는 반복문
    }

    int temp = 0; // swap을 위한 temp 변수 선언

    for (int i = 44; i > 0; i--) // 배열 섞기를 위한 반복문
    {
        int j = rand() % (i + 1); // j에 임의의 정수 생성  
        temp = randLottoNum[i]; // lotto 배열의 i 번째 값과 lotto 배열의 임의의 정수 j 번의 값을 스왑해서 섞기
        randLottoNum[i] = randLottoNum[j];
        randLottoNum[j] = temp;
    }
}

void ShowLottoNumber() // 사용자가 뽑은 번호, 랜덤으로 뽑힌 로또 번호 출력해주기
{
    GoToXY(0, 0); printf(" Lotto Winning Numbers"); // 반복되면 안되는 출력문 반복문 전에 출력해서 가독성 높이기
    GoToXY(0, 2); printf("■■■　■■■　■■■　■■■　■■■　■■■　■■■");
    GoToXY(0, 3); printf("■　■　■　■　■　■　■　■　■　■　■　■　■　■"); // 출력 숫자가 들어갈 x좌표 : 5,11,17,23,29,35,41  
    GoToXY(0, 4); printf("■■■　■■■　■■■　■■■　■■■　■■■　■■■");
    
    for (int i = 0; i < 7; i++) // 섞인 배열에서 lotto 배열의 앞 7개 숫자 출력 반복문
    {
        GoToXY(2 + randomLottoNumLocation,3); printf("%d", randLottoNum[i]); // lotto 배열 0번째 인덱스 ~ 6번째 인덱스 까지 출력
        randomLottoNumLocation += 8;
    }

    GoToXY(0, 6); printf(" Your Lotto Numbers : "); // 반복되면 안되는 출력문 반복문 전에 출력해서 가독성 높이기
    GoToXY(0, 7); printf("■■■　■■■　■■■　■■■　■■■　■■■　■■■");
    GoToXY(0, 8); printf("■　■　■　■　■　■　■　■　■　■　■　■　■　■"); // 출력 숫자가 들어갈 x좌표 : 5,11,17,23,29,35,41  
    GoToXY(0, 9); printf("■■■　■■■　■■■　■■■　■■■　■■■　■■■");

    for (int i = 0; i < 7; i++) // 섞인 배열에서 lotto 배열의 앞 7개 숫자 출력 반복문
    {
        GoToXY(2 + userLottoNumLocation, 8); printf("%d", userLottoNum[i]); // lotto 배열 0번째 인덱스 ~ 6번째 인덱스 까지 출력
        userLottoNumLocation += 8;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("\n");
    }


}

void HowMuchCorrect()
{
    for (int i = 0; i < 7; i++)
    {
        if (randLottoNum[i] == userLottoNum[i])
        {
            matchNum++;
        }
    }

    switch (matchNum)
    {
    case 0:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?",matchNum);
        GoToXY(3, 15); printf("■■■　■■■　　");
        GoToXY(3, 16); printf("　　■　　　■　　■");
        GoToXY(3, 17); printf("　　■　　　■　　■");
        GoToXY(3, 18); printf("　　　　■　　　　■■");
        GoToXY(3, 19); printf("　　　　■　　　　■");
        GoToXY(3, 20); printf("　　■■■■■　　■");
        GoToXY(3, 21); printf("　　　■■■　　　　　");
        GoToXY(3, 22); printf("　　■　　　■　　　　");
        GoToXY(3, 23); printf("　　■　　　■　　　　");
        GoToXY(3, 24); printf("　　　■■■　　　　");
        printf("\n");
        break;

    case 1:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("■■■　■■■　　");
        GoToXY(3, 16); printf("　　■　　　■　　■");
        GoToXY(3, 17); printf("　　■　　　■　　■");
        GoToXY(3, 18); printf("　　　　■　　　　■■");
        GoToXY(3, 19); printf("　　　　■　　　　■");
        GoToXY(3, 20); printf("　　■■■■■　　■");
        GoToXY(3, 21); printf("　　　■■■　　　　　");
        GoToXY(3, 22); printf("　　■　　　■　　　　");
        GoToXY(3, 23); printf("　　■　　　■　　　　");
        GoToXY(3, 24); printf("　　　■■■　　　　");
        printf("\n");
        break;
    case 2:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("■■■　■■■　　");
        GoToXY(3, 16); printf("　　■　　　■　　■");
        GoToXY(3, 17); printf("　　■　　　■　　■");
        GoToXY(3, 18); printf("　　　　■　　　　■■");
        GoToXY(3, 19); printf("　　　　■　　　　■");
        GoToXY(3, 20); printf("　　■■■■■　　■");
        GoToXY(3, 21); printf("　　　■■■　　　　　");
        GoToXY(3, 22); printf("　　■　　　■　　　　");
        GoToXY(3, 23); printf("　　■　　　■　　　　");
        GoToXY(3, 24); printf("　　　■■■　　　　");
        printf("\n");
        break;
    case 3:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("3개의 번호를 맞추셔서 5등에 당첨되셨습니다!");
        break;
    case 4:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("4개의 번호를 맞추셔서 4등에 당첨되셨습니다!");
        break;
    case 5:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("5개의 번호를 맞추셔서 3등에 당첨되셨습니다!");
        break;
    case 6:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("6개의 번호를 맞추셔서 2등에 당첨되셨습니다!");
        break;
    case 7:
        GoToXY(3, 11); printf("총 %d개의 숫자를 맞추셨네요!! 결과는....?", matchNum);
        GoToXY(3, 15); printf("7개의 번호를 맞추셔서 1등에 당첨되셨습니다!");
        break;
    default:
        break;
    }

}

void StartPage()
{
    GoToXY(0, 0); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); // 40
    GoToXY(0, 1); printf("■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
    GoToXY(0, 2); printf("■　　■　　　　■■■■　■■■■■　■■■■■　■■■■　　■");
    GoToXY(0, 3); printf("■　　■　　　　■　　■　　　■　　　　　■　　　■　　■　　■");
    GoToXY(0, 4); printf("■　　■　　　　■　　■　　　■　　　　　■　　　■　　■　　■");
    GoToXY(0, 5); printf("■　　■■■■　■■■■　　　■　　　　　■　　　■■■■　　■");
    GoToXY(0, 6); printf("■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■");
    GoToXY(0, 7); printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    GoToXY(3, 10); printf("start");
    GoToXY(3, 11); printf("exit");
    GoToXY(1, 10); printf("▶");

    while (true)
    {
        if (_kbhit())
        {
            char inputkey = _getch();
            GoToXY(1, 10 + choice);
            printf("　　");
            if (inputkey == 's')
            {
                if (choice > 1 && choice < 0)
                {
                    choice = 0;
                }
                choice++;
            }
            else if (inputkey == 'w')
            {
                if (choice > 1 && choice < 0)
                {
                    choice = 0;
                }
                choice--;
            }
            else if (inputkey == 'g')
            {
                system("cls");
                break;
                if (choice == 0)
                {
                    exit(0);
                }
            }
            GoToXY(1, 5 + choice);
            printf("▶");
        }
    }
}

void NumMixPage()
{
    GoToXY(0, 0); printf("　　　　　　　■■■■■■■　　　　　　　　　　　");
    GoToXY(0, 1); printf("　　　　　　■　　⊙　　⊙　■　　　　　　　　　　");
    GoToXY(0, 2); printf("　　　　　■　⊙　　　⊙　⊙　■　　　　　　　　　");
    GoToXY(0, 3); printf("　　　　■　⊙　　　⊙　　　⊙　■　　　　　　　　");
    GoToXY(0, 4); printf("　　　■　　⊙　　⊙　　⊙　　　⊙■　　　　　　　");
    GoToXY(0, 5); printf("　　　　■　　⊙　　　　⊙　⊙　■　　　　　　　　");  // 8~12
    GoToXY(0, 6); printf("　　　　　■⊙⊙⊙⊙⊙⊙⊙⊙⊙■　　　　　　　　　 ");
    GoToXY(0, 7); printf("　　　　　　■⊙⊙⊙⊙⊙⊙⊙■　　　　　　　　　　 ");
    GoToXY(0, 8); printf("　　　　　　　■■■■■■■　　　　　　　　　　　");
    GoToXY(0, 8); printf("　　　　　　　■■■■■■■　　　　　　　　　　　");


    GoToXY(0, 10); printf("　　　　■　　　　　■　　■　　　　　　　■■■■■　");
    GoToXY(0, 11); printf("　　　■　■　　■■■　　■　　　　　　　　■　■　　");
    GoToXY(0, 12); printf("　　■　　　■　　　■　　■■■■　　　　■　　　■　");
    GoToXY(0, 13); printf("　　　　　　　　　　　　　　　　　　　　　　　　　　　");
    GoToXY(0, 14); printf("　　　■■■　■■■　　■■■■■■■　■■■■■■■");
    GoToXY(0, 15); printf("　　　　　■　　　■　　　　　　　　　　　　　■　　　");
    GoToXY(0, 16); printf("　　　　　■　　　■　　　■　　　　　　　　■■■　　");
    GoToXY(0, 17); printf("　　　　　　　　　　　　　■　　　　　　　■　　　■　");
    GoToXY(0, 18); printf("　　　　　　　　　　　　　■■■■　　　     ■■■　　　■　■　■");
    
    Sleep(5000);
    system("cls");
}

void main()
{
    srand(time(NULL));
    StartPage();
    GetUserLottoNum();
    NumMixPage();
    MixLottoNumber();
    ShowLottoNumber();
    HowMuchCorrect();

}

// 숙제1.gotoxy이용해서 로또번호 이쁘게 만들기@@
// 1. MixLottoNumber() 함수를 만들어서 로또번호 섞기 - 완
// 2. ShowLottoNumber() 함수를 만들어서 로또번호 공개 - 완
// 3. 사용자에게 숫자 7개를 입력받아서 사용자 로또번호 정하고 gotoxy로 꾸며서 출력해주기
// 4. gtxy로 랜덤으로 정해진 로또번호 7개도 사용자가 고른 숫자 위쪽에 출력되게 만들기
// 5. HowMuchCorrect() 맞춘 개수에 따라 등수를 출력해주는 부분 함수 생성 및 꾸미기 swith case 문과 증감연산자를 
//    사용하여 for반복문을 돌려 맞는것을 확인한 후 맞춘 개수에 따라 ++를 해주고 case 0일 때 꽝 case 1일 때 5등 이런식으로
//    출력하는 함수 짜기 