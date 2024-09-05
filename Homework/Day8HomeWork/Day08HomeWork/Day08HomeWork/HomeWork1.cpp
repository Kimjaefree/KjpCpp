#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;
int choice = 0;

int randLottoNum[45] = { 0, }; // �ζ� ���ڰ� �� �迭 ���� ���� �� �ʱ�ȭ
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
            printf("�߸��� ���ڸ� �Է��ϼż� ���α׷��� ����˴ϴ�!\n");
            exit(0);
        }

        
        for (int j = 0; j < i; j++) {
            if (userLottoNum[i] == userLottoNum[j]) {
                printf("�ߺ��� ���ڸ� �Է��ϼż� ���α׷��� ����˴ϴ�!\n");
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
        randLottoNum[i] = i + 1; // lotto �迭 ������ 1~45�� ���� �ִ� �ݺ���
    }

    int temp = 0; // swap�� ���� temp ���� ����

    for (int i = 44; i > 0; i--) // �迭 ���⸦ ���� �ݺ���
    {
        int j = rand() % (i + 1); // j�� ������ ���� ����  
        temp = randLottoNum[i]; // lotto �迭�� i ��° ���� lotto �迭�� ������ ���� j ���� ���� �����ؼ� ����
        randLottoNum[i] = randLottoNum[j];
        randLottoNum[j] = temp;
    }
}

void ShowLottoNumber() // ����ڰ� ���� ��ȣ, �������� ���� �ζ� ��ȣ ������ֱ�
{
    GoToXY(0, 0); printf(" Lotto Winning Numbers"); // �ݺ��Ǹ� �ȵǴ� ��¹� �ݺ��� ���� ����ؼ� ������ ���̱�
    GoToXY(0, 2); printf("���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ����");
    GoToXY(0, 3); printf("�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ��"); // ��� ���ڰ� �� x��ǥ : 5,11,17,23,29,35,41  
    GoToXY(0, 4); printf("���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ����");
    
    for (int i = 0; i < 7; i++) // ���� �迭���� lotto �迭�� �� 7�� ���� ��� �ݺ���
    {
        GoToXY(2 + randomLottoNumLocation,3); printf("%d", randLottoNum[i]); // lotto �迭 0��° �ε��� ~ 6��° �ε��� ���� ���
        randomLottoNumLocation += 8;
    }

    GoToXY(0, 6); printf(" Your Lotto Numbers : "); // �ݺ��Ǹ� �ȵǴ� ��¹� �ݺ��� ���� ����ؼ� ������ ���̱�
    GoToXY(0, 7); printf("���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ����");
    GoToXY(0, 8); printf("�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ�ᡡ��"); // ��� ���ڰ� �� x��ǥ : 5,11,17,23,29,35,41  
    GoToXY(0, 9); printf("���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ���ᡡ����");

    for (int i = 0; i < 7; i++) // ���� �迭���� lotto �迭�� �� 7�� ���� ��� �ݺ���
    {
        GoToXY(2 + userLottoNumLocation, 8); printf("%d", userLottoNum[i]); // lotto �迭 0��° �ε��� ~ 6��° �ε��� ���� ���
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
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?",matchNum);
        GoToXY(3, 15); printf("���ᡡ���ᡡ��");
        GoToXY(3, 16); printf("�����ᡡ�����ᡡ����");
        GoToXY(3, 17); printf("�����ᡡ�����ᡡ����");
        GoToXY(3, 18); printf("���������ᡡ���������");
        GoToXY(3, 19); printf("���������ᡡ��������");
        GoToXY(3, 20); printf("���������ᡡ����");
        GoToXY(3, 21); printf("���������ᡡ��������");
        GoToXY(3, 22); printf("�����ᡡ�����ᡡ������");
        GoToXY(3, 23); printf("�����ᡡ�����ᡡ������");
        GoToXY(3, 24); printf("���������ᡡ������");
        printf("\n");
        break;

    case 1:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("���ᡡ���ᡡ��");
        GoToXY(3, 16); printf("�����ᡡ�����ᡡ����");
        GoToXY(3, 17); printf("�����ᡡ�����ᡡ����");
        GoToXY(3, 18); printf("���������ᡡ���������");
        GoToXY(3, 19); printf("���������ᡡ��������");
        GoToXY(3, 20); printf("���������ᡡ����");
        GoToXY(3, 21); printf("���������ᡡ��������");
        GoToXY(3, 22); printf("�����ᡡ�����ᡡ������");
        GoToXY(3, 23); printf("�����ᡡ�����ᡡ������");
        GoToXY(3, 24); printf("���������ᡡ������");
        printf("\n");
        break;
    case 2:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("���ᡡ���ᡡ��");
        GoToXY(3, 16); printf("�����ᡡ�����ᡡ����");
        GoToXY(3, 17); printf("�����ᡡ�����ᡡ����");
        GoToXY(3, 18); printf("���������ᡡ���������");
        GoToXY(3, 19); printf("���������ᡡ��������");
        GoToXY(3, 20); printf("���������ᡡ����");
        GoToXY(3, 21); printf("���������ᡡ��������");
        GoToXY(3, 22); printf("�����ᡡ�����ᡡ������");
        GoToXY(3, 23); printf("�����ᡡ�����ᡡ������");
        GoToXY(3, 24); printf("���������ᡡ������");
        printf("\n");
        break;
    case 3:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("3���� ��ȣ�� ���߼ż� 5� ��÷�Ǽ̽��ϴ�!");
        break;
    case 4:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("4���� ��ȣ�� ���߼ż� 4� ��÷�Ǽ̽��ϴ�!");
        break;
    case 5:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("5���� ��ȣ�� ���߼ż� 3� ��÷�Ǽ̽��ϴ�!");
        break;
    case 6:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("6���� ��ȣ�� ���߼ż� 2� ��÷�Ǽ̽��ϴ�!");
        break;
    case 7:
        GoToXY(3, 11); printf("�� %d���� ���ڸ� ���߼̳׿�!! �����....?", matchNum);
        GoToXY(3, 15); printf("7���� ��ȣ�� ���߼ż� 1� ��÷�Ǽ̽��ϴ�!");
        break;
    default:
        break;
    }

}

void StartPage()
{
    GoToXY(0, 0); printf("���������������������������������"); // 40
    GoToXY(0, 1); printf("�ᡡ������������������������������������������������������������");
    GoToXY(0, 2); printf("�ᡡ���ᡡ����������ᡡ�����ᡡ�����ᡡ����ᡡ����");
    GoToXY(0, 3); printf("�ᡡ���ᡡ�������ᡡ���ᡡ�����ᡡ���������ᡡ�����ᡡ���ᡡ����");
    GoToXY(0, 4); printf("�ᡡ���ᡡ�������ᡡ���ᡡ�����ᡡ���������ᡡ�����ᡡ���ᡡ����");
    GoToXY(0, 5); printf("�ᡡ������ᡡ����ᡡ�����ᡡ���������ᡡ��������ᡡ����");
    GoToXY(0, 6); printf("�ᡡ������������������������������������������������������������");
    GoToXY(0, 7); printf("���������������������������������");
    GoToXY(3, 10); printf("start");
    GoToXY(3, 11); printf("exit");
    GoToXY(1, 10); printf("��");

    while (true)
    {
        if (_kbhit())
        {
            char inputkey = _getch();
            GoToXY(1, 10 + choice);
            printf("����");
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
            printf("��");
        }
    }
}

void NumMixPage()
{
    GoToXY(0, 0); printf("���������������������ᡡ��������������������");
    GoToXY(0, 1); printf("�������������ᡡ�������������ᡡ������������������");
    GoToXY(0, 2); printf("�����������ᡡ�����������������ᡡ����������������");
    GoToXY(0, 3); printf("���������ᡡ���������������������ᡡ��������������");
    GoToXY(0, 4); printf("�������ᡡ�������������������������ᡡ������������");
    GoToXY(0, 5); printf("���������ᡡ���������������������ᡡ��������������");  // 8~12
    GoToXY(0, 6); printf("������������������������������ᡡ���������������� ");
    GoToXY(0, 7); printf("����������������������������ᡡ������������������ ");
    GoToXY(0, 8); printf("���������������������ᡡ��������������������");
    GoToXY(0, 8); printf("���������������������ᡡ��������������������");


    GoToXY(0, 10); printf("���������ᡡ���������ᡡ���ᡡ�����������������ᡡ");
    GoToXY(0, 11); printf("�������ᡡ�ᡡ�����ᡡ���ᡡ���������������ᡡ�ᡡ��");
    GoToXY(0, 12); printf("�����ᡡ�����ᡡ�����ᡡ������ᡡ�������ᡡ�����ᡡ");
    GoToXY(0, 13); printf("������������������������������������������������������");
    GoToXY(0, 14); printf("���������ᡡ���ᡡ���������ᡡ��������");
    GoToXY(0, 15); printf("�����������ᡡ�����ᡡ�������������������������ᡡ����");
    GoToXY(0, 16); printf("�����������ᡡ�����ᡡ�����ᡡ�����������������ᡡ��");
    GoToXY(0, 17); printf("���������������������������ᡡ�������������ᡡ�����ᡡ");
    GoToXY(0, 18); printf("������������������������������ᡡ����     ���ᡡ�����ᡡ�ᡡ��");
    
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

// ����1.gotoxy�̿��ؼ� �ζǹ�ȣ �̻ڰ� �����@@
// 1. MixLottoNumber() �Լ��� ���� �ζǹ�ȣ ���� - ��
// 2. ShowLottoNumber() �Լ��� ���� �ζǹ�ȣ ���� - ��
// 3. ����ڿ��� ���� 7���� �Է¹޾Ƽ� ����� �ζǹ�ȣ ���ϰ� gotoxy�� �ٸ缭 ������ֱ�
// 4. gtxy�� �������� ������ �ζǹ�ȣ 7���� ����ڰ� �� ���� ���ʿ� ��µǰ� �����
// 5. HowMuchCorrect() ���� ������ ���� ����� ������ִ� �κ� �Լ� ���� �� �ٹ̱� swith case ���� ���������ڸ� 
//    ����Ͽ� for�ݺ����� ���� �´°��� Ȯ���� �� ���� ������ ���� ++�� ���ְ� case 0�� �� �� case 1�� �� 5�� �̷�������
//    ����ϴ� �Լ� ¥�� 