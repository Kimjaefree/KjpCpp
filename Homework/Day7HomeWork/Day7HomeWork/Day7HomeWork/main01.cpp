#include <iostream>

int trumpCard[52] = { 0 };
int randNum1, randNum2, temp = 0;
int player1CardNum[3], player1CardShape[3], player2CardNum[3], player2CardShape[3],debugCardNum[3], debugCardShape[3]; //카드모양과 번호
int player1Gold = 10000;
int player2Gold = 10000;
int player1BetGold, player2BetGold = 0;
int usedCard = 0; //사용한 카드
int player1HighLowCheck, player2HighLowCheck =0; // 하이로우세븐을 체크하는 용도
int player1HighLow, player2HighLow = 0;
int rep = 1;

void Bat()
{
    printf("플레이어1님 배팅할 금액을 선택해주세요(1000골드 이상) : ");
    scanf_s("%d", &player1BetGold);
    printf("플레이어2님 배팅할 금액을 선택해주세요(1000골드 이상) : ");
    scanf_s("%d", &player2BetGold);
}

void PlayerGoldBoard()
{
    printf("플레이어1님의 보유 골드 : %d\n", player1Gold);
    printf("플레이어2님의 보유 골드 : %d\n", player2Gold);
}

void GameStart()
{
    printf("하이로우세븐 게임에 오신걸 환영합니다.\n");
    printf("플레이어1 님이 입장하셨습니다.\n");
    printf("플레이어2 님이 입장하셨습니다.\n");
}

void GameOver()
{
    if (player1Gold <= 0)
    {
        printf("플레이어1 님이 파산하였습니다.\n");
        printf("플레이어2 님이 승리하셨습니다! 축하합니다.");
        rep = 0;
    }
    else if (player2Gold <= 0)
    {
        printf("플레이어2 님이 파산하였습니다.\n");
        printf("플레이어1 님이 승리하셨습니다! 축하합니다.");
        rep = 0;
    }
    else if (usedCard == 52 && player1Gold > player2Gold)
    {
        printf("카드를 모두 사용하여 게임이 종료되었습니다.\n");
        printf("남은 플레이어 골드 정산중....\n");
        printf("플레이어1님의 골드가 더 많이 남아있으므로 플레이어 1님이 승리하였습니다!");
        rep = 0;
    }
    else if (usedCard == 52 && player2Gold > player1Gold)
    {
        printf("카드를 모두 사용하여 게임이 종료되었습니다.\n");
        printf("남은 플레이어 골드 정산중....\n");
        printf("플레이어2님의 골드가 더 많이 남아있으므로 플레이어 2님이 승리하였습니다!");
        rep = 0;
    }
}

void MixCard()
{
    printf("카드를 섞는중입니다...\n");

    // 트럼프카드 배열 초기화
    for (int i = 0; i < 52; i++)
    {
        trumpCard[i] = i;
    }
    // 총 52장인 트럼프카드 셔플
    for (int i = 0; i < 52; i++)
    {
        randNum1 = rand() % 52;
        randNum2 = rand() % 52;
        temp = trumpCard[randNum1];
        trumpCard[randNum1] = trumpCard[randNum2];
        trumpCard[randNum2] = temp;
    }

    printf("카드가 모두 섞였습니다.\n");
}

void ShowingCard()
{
    for (int i = 0; i < 52; i++)
    {
        player1CardShape[i] = trumpCard[i + usedCard] / 13; // 카드 모양 확인
        player1CardNum[i] = trumpCard[i + usedCard] % 13; // 카드 숫자 확인

        player2CardShape[i] = trumpCard[i + 1 + usedCard] / 13; // 카드 모양 확인
        player2CardNum[i] = trumpCard[i + 1 + usedCard] % 13; // 카드 숫자 확인

        debugCardShape[i] = trumpCard[i + 2 + usedCard] / 13; // 디버그 카드 모양 확인
        debugCardNum[i] = trumpCard[i + 2 + usedCard] % 13; // 디버그 카드 숫자 확인

        if (player1CardNum[i] > 7-1)
        {
            player1HighLowCheck = 1;
        }
        if (player1CardNum[i] < 7 - 1)
        {
            player1HighLowCheck = 2;
        }
        if (player1CardNum[i] == 7 - 1)
        {
            player1HighLowCheck = 3;
        }
        if (player2CardNum[i] > 7 - 1)
        {
            player2HighLowCheck = 1;
        }
        if (player2CardNum[i] < 7 - 1)
        {
            player2HighLowCheck = 2;
        }
        if (player2CardNum[i] == 7 - 1)
        {
            player2HighLowCheck = 3;
        }

        if (i < 2)
        {
            printf("플레이어1 님이 뽑은 카드 : %d%d\n", player1CardShape[i], player1CardNum[i]);
            printf("플레이어2 님이 뽑은 카드 : %d%d\n", player2CardShape[i], player2CardNum[i]);
        }
        else
        {
            printf("디버그 카드: %d%d", debugCardShape[i], debugCardNum[i]);
        }
    }
}

void CheckCardShapeAndNum()
{
    for (int i = 0; i < 3; i++)
    {
        switch (player1CardShape[i])
        {
        case 0:
            printf("♤");
            break;
        case 1:
            printf("♡");
            break;
        case 2:
            printf("◇");
            break;
        case 3:
            printf("♧");
            break;
        }

        switch (player1CardNum[i])
        {
        case 0:
            printf("A \t");
            break;
        case 10:
            printf("J \t");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d\n", player1CardNum[i] + 1);
            break;
        }

        switch (player2CardShape[i])
        {
        case 0:
            printf("♤");
            break;
        case 1:
            printf("♡");
            break;
        case 2:
            printf("◇");
            break;
        case 3:
            printf("♧");
            break;
        }

        switch (player2CardNum[i])
        {
        case 0:
            printf("A \t");
            break;
        case 10:
            printf("J \t");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d\n", player2CardNum[i] + 1);
            break;
        }

        switch (debugCardShape[i])
        {
        case 0:
            printf("♤");
            break;
        case 1:
            printf("♡");
            break;
        case 2:
            printf("◇");
            break;
        case 3:
            printf("♧");
            break;
        }

        switch (debugCardNum[i])
        {
        case 0:
            printf("A \t");
            break;
        case 10:
            printf("J \t");
            break;
        case 11:
            printf("Q");
            break;
        case 12:
            printf("K");
            break;
        default:
            printf("%d\n", player2CardNum[i] + 1);
            break;
        }
    }
}

void ChoiceHighLowSeven()
{
    printf("플레이어 1님 하이(1)로우(2)세븐(3) 중 하나를 선택하세요 : ");
    scanf_s("%d", &player1HighLow);
    printf("플레이어 2님 하이(1)로우(2)세븐(3) 중 하나를 선택하세요 : ");
    scanf_s("%d", &player2HighLow);
}

void WinOrLose()
{
    //승패 판정
    if (player1HighLowCheck == player1HighLow && (player1HighLowCheck == 3) && (player1HighLow == 3))
    {
        player1Gold += player1BetGold * 10;
        printf("축하합니다 플레이어1님 세븐을 맞추셨네요. 배팅금의 10배를 얻습니다.\n");
    }
    else if (player1HighLowCheck == player1HighLow)
    {
        player1Gold += player1BetGold * 2;
        printf("플레이어1님 승리. 배팅금의 2배를 얻습니다.\n");
    }
    else
    {
        player1Gold -= player1BetGold;
        printf("플레이어1님 패배. 배팅금을 잃습니다.\n");
    }

    if (player2HighLowCheck == player2HighLow && (player2HighLowCheck == 3) && (player2HighLow == 3))
    {
        player2Gold += player2BetGold * 10;
        printf("축하합니다 플레이어2님 세븐을 맞추셨네요. 배팅금의 10배를 얻습니다.\n");
    }
    else if (player2HighLowCheck == player2HighLow)
    {
        player2Gold += player2BetGold * 2;
        printf("플레이어2님 승리. 배팅금의 2배를 얻습니다.\n");
    }
    else
    {
        player2Gold -= player2BetGold;
        printf("플레이어2님 패배. 배팅금을 잃습니다.\n");
    }
    usedCard += 3; //사용한카드는 버리기
}

using namespace std;

void main()
{
    srand(time(NULL));
    GameStart(); // 게임 시작 출력문 출력 함수 - 1번완료
    MixCard();
    while (rep == 1)
    {
        PlayerGoldBoard(); // 플레이어 골드 현황 출력 함수 - 2번완료
        ShowingCard(); // 4번 본인이 소지한 카드 문양 및 숫자 출력
        CheckCardShapeAndNum(); // 카드 문양 및 숫자 확인 함수
        Bat(); // 5번 배팅 및 하이로우 고르기
        ChoiceHighLowSeven(); // 하이로우 고르기
        WinOrLose();
        GameOver(); // 6번 조건에 따른 게임종료 함수
    }

    // 하이로우게임 진행 순서
    // 1. 플레이어 1,2,님이 입장하였습니다
    // 2. 현재 플레이어 골드 상황 출력 ex) 플레이어 1님의 보유 골드: 10000 
    // 3. 카드 셔플
    // 4. 카드 나눠주기
    // 5. 배팅
    // 6. 승패 판정
    // 7. 결과에 따른 배팅금액 지급
    // 8. 트럼프카드를 다 쓰거나 플레이어가 파산시 게임 종료.

}

