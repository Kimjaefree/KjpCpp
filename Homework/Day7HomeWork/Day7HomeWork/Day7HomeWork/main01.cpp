#include <iostream>

int trumpCard[52] = { 0 };
int randNum1, randNum2, temp = 0;
int player1CardNum[3], player1CardShape[3], player2CardNum[3], player2CardShape[3],debugCardNum[3], debugCardShape[3]; //ī����� ��ȣ
int player1Gold = 10000;
int player2Gold = 10000;
int player1BetGold, player2BetGold = 0;
int usedCard = 0; //����� ī��
int player1HighLowCheck, player2HighLowCheck =0; // ���̷ο켼���� üũ�ϴ� �뵵
int player1HighLow, player2HighLow = 0;
int rep = 1;

void Bat()
{
    printf("�÷��̾�1�� ������ �ݾ��� �������ּ���(1000��� �̻�) : ");
    scanf_s("%d", &player1BetGold);
    printf("�÷��̾�2�� ������ �ݾ��� �������ּ���(1000��� �̻�) : ");
    scanf_s("%d", &player2BetGold);
}

void PlayerGoldBoard()
{
    printf("�÷��̾�1���� ���� ��� : %d\n", player1Gold);
    printf("�÷��̾�2���� ���� ��� : %d\n", player2Gold);
}

void GameStart()
{
    printf("���̷ο켼�� ���ӿ� ���Ű� ȯ���մϴ�.\n");
    printf("�÷��̾�1 ���� �����ϼ̽��ϴ�.\n");
    printf("�÷��̾�2 ���� �����ϼ̽��ϴ�.\n");
}

void GameOver()
{
    if (player1Gold <= 0)
    {
        printf("�÷��̾�1 ���� �Ļ��Ͽ����ϴ�.\n");
        printf("�÷��̾�2 ���� �¸��ϼ̽��ϴ�! �����մϴ�.");
        rep = 0;
    }
    else if (player2Gold <= 0)
    {
        printf("�÷��̾�2 ���� �Ļ��Ͽ����ϴ�.\n");
        printf("�÷��̾�1 ���� �¸��ϼ̽��ϴ�! �����մϴ�.");
        rep = 0;
    }
    else if (usedCard == 52 && player1Gold > player2Gold)
    {
        printf("ī�带 ��� ����Ͽ� ������ ����Ǿ����ϴ�.\n");
        printf("���� �÷��̾� ��� ������....\n");
        printf("�÷��̾�1���� ��尡 �� ���� ���������Ƿ� �÷��̾� 1���� �¸��Ͽ����ϴ�!");
        rep = 0;
    }
    else if (usedCard == 52 && player2Gold > player1Gold)
    {
        printf("ī�带 ��� ����Ͽ� ������ ����Ǿ����ϴ�.\n");
        printf("���� �÷��̾� ��� ������....\n");
        printf("�÷��̾�2���� ��尡 �� ���� ���������Ƿ� �÷��̾� 2���� �¸��Ͽ����ϴ�!");
        rep = 0;
    }
}

void MixCard()
{
    printf("ī�带 �������Դϴ�...\n");

    // Ʈ����ī�� �迭 �ʱ�ȭ
    for (int i = 0; i < 52; i++)
    {
        trumpCard[i] = i;
    }
    // �� 52���� Ʈ����ī�� ����
    for (int i = 0; i < 52; i++)
    {
        randNum1 = rand() % 52;
        randNum2 = rand() % 52;
        temp = trumpCard[randNum1];
        trumpCard[randNum1] = trumpCard[randNum2];
        trumpCard[randNum2] = temp;
    }

    printf("ī�尡 ��� �������ϴ�.\n");
}

void ShowingCard()
{
    for (int i = 0; i < 52; i++)
    {
        player1CardShape[i] = trumpCard[i + usedCard] / 13; // ī�� ��� Ȯ��
        player1CardNum[i] = trumpCard[i + usedCard] % 13; // ī�� ���� Ȯ��

        player2CardShape[i] = trumpCard[i + 1 + usedCard] / 13; // ī�� ��� Ȯ��
        player2CardNum[i] = trumpCard[i + 1 + usedCard] % 13; // ī�� ���� Ȯ��

        debugCardShape[i] = trumpCard[i + 2 + usedCard] / 13; // ����� ī�� ��� Ȯ��
        debugCardNum[i] = trumpCard[i + 2 + usedCard] % 13; // ����� ī�� ���� Ȯ��

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
            printf("�÷��̾�1 ���� ���� ī�� : %d%d\n", player1CardShape[i], player1CardNum[i]);
            printf("�÷��̾�2 ���� ���� ī�� : %d%d\n", player2CardShape[i], player2CardNum[i]);
        }
        else
        {
            printf("����� ī��: %d%d", debugCardShape[i], debugCardNum[i]);
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
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        case 2:
            printf("��");
            break;
        case 3:
            printf("��");
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
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        case 2:
            printf("��");
            break;
        case 3:
            printf("��");
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
            printf("��");
            break;
        case 1:
            printf("��");
            break;
        case 2:
            printf("��");
            break;
        case 3:
            printf("��");
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
    printf("�÷��̾� 1�� ����(1)�ο�(2)����(3) �� �ϳ��� �����ϼ��� : ");
    scanf_s("%d", &player1HighLow);
    printf("�÷��̾� 2�� ����(1)�ο�(2)����(3) �� �ϳ��� �����ϼ��� : ");
    scanf_s("%d", &player2HighLow);
}

void WinOrLose()
{
    //���� ����
    if (player1HighLowCheck == player1HighLow && (player1HighLowCheck == 3) && (player1HighLow == 3))
    {
        player1Gold += player1BetGold * 10;
        printf("�����մϴ� �÷��̾�1�� ������ ���߼̳׿�. ���ñ��� 10�踦 ����ϴ�.\n");
    }
    else if (player1HighLowCheck == player1HighLow)
    {
        player1Gold += player1BetGold * 2;
        printf("�÷��̾�1�� �¸�. ���ñ��� 2�踦 ����ϴ�.\n");
    }
    else
    {
        player1Gold -= player1BetGold;
        printf("�÷��̾�1�� �й�. ���ñ��� �ҽ��ϴ�.\n");
    }

    if (player2HighLowCheck == player2HighLow && (player2HighLowCheck == 3) && (player2HighLow == 3))
    {
        player2Gold += player2BetGold * 10;
        printf("�����մϴ� �÷��̾�2�� ������ ���߼̳׿�. ���ñ��� 10�踦 ����ϴ�.\n");
    }
    else if (player2HighLowCheck == player2HighLow)
    {
        player2Gold += player2BetGold * 2;
        printf("�÷��̾�2�� �¸�. ���ñ��� 2�踦 ����ϴ�.\n");
    }
    else
    {
        player2Gold -= player2BetGold;
        printf("�÷��̾�2�� �й�. ���ñ��� �ҽ��ϴ�.\n");
    }
    usedCard += 3; //�����ī��� ������
}

using namespace std;

void main()
{
    srand(time(NULL));
    GameStart(); // ���� ���� ��¹� ��� �Լ� - 1���Ϸ�
    MixCard();
    while (rep == 1)
    {
        PlayerGoldBoard(); // �÷��̾� ��� ��Ȳ ��� �Լ� - 2���Ϸ�
        ShowingCard(); // 4�� ������ ������ ī�� ���� �� ���� ���
        CheckCardShapeAndNum(); // ī�� ���� �� ���� Ȯ�� �Լ�
        Bat(); // 5�� ���� �� ���̷ο� ����
        ChoiceHighLowSeven(); // ���̷ο� ����
        WinOrLose();
        GameOver(); // 6�� ���ǿ� ���� �������� �Լ�
    }

    // ���̷ο���� ���� ����
    // 1. �÷��̾� 1,2,���� �����Ͽ����ϴ�
    // 2. ���� �÷��̾� ��� ��Ȳ ��� ex) �÷��̾� 1���� ���� ���: 10000 
    // 3. ī�� ����
    // 4. ī�� �����ֱ�
    // 5. ����
    // 6. ���� ����
    // 7. ����� ���� ���ñݾ� ����
    // 8. Ʈ����ī�带 �� ���ų� �÷��̾ �Ļ�� ���� ����.

}

