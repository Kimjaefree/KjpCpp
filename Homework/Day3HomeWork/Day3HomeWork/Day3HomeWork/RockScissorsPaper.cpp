#include <iostream>

using namespace std;

void Rock_Scissors_Paper()
{
	int playerNum = 0;

	printf("����(0), ����(1), ��(2) �߿��� �������ּ��� : ");
	scanf_s("%d", &playerNum);

	printf("��ǻ�� ������...\n");

	srand(time(NULL));
	int computerNum = rand() % 3;

	if (computerNum == 0)
	{
		printf("��ǻ�ʹ� ������ �����Ͽ����ϴ�.\n");
	}
	else if (computerNum == 1)
	{
		printf("��ǻ�ʹ� ������ �����Ͽ����ϴ�.\n");
	}
	else if (computerNum == 2)
	{
		printf("��ǻ�ʹ� ���� �����Ͽ����ϴ�.\n");
	}

	if (playerNum == computerNum) {
		printf("�����ϴ�.\n");
	}
	else if ((playerNum == 0 && computerNum == 2) ||
		(playerNum == 1 && computerNum == 0) ||
		(playerNum == 2 && computerNum == 1)) {
		printf("�¸��Ͽ����ϴ�.\n");
	}
	else {
		printf("�����ϴ�.\n");
	}
}

void TextRPG()
{
	int monsterLevel = 1;
    int playerLevel = 1;// ���� ����, �÷��̾� �������� ����
	int choice, end = 0;
	int player_Exp = 0; // ���ѷ��� Ż�� ����, �÷��̾� ����ġ ���� ����
	int monster_Exp = 25; // ���͸� óġ�ҽ� ��� ����ġ ���� ���� �� �� ����
	int run_Exp = 10; // ����ġ�⿡ ������ ��� ����ġ ���� ���� �� �� ����
	
	srand(time(NULL));
	
	while (end == 0) // end�� 1�� �� ������ ���� �ݺ��ϴ� ���� ����ϸ� end�� ���� 1�̵Ǿ� ���α׷� ����
	{
		int die = rand() % 100; // ���Ȯ���� �����ϴ� die ���� ���� �� ���� �� ���� 0~99����

		if (player_Exp >= 60) // ����ġ�� ���� �÷��̾� ���� ���� (������ �뷱�� ���� �������� ¥�ý��ϴ�!)
		{
			playerLevel++;
			printf("�����մϴ� ������ �ϼ̽��ϴ�! ���緹�� : %d\n", playerLevel);
			player_Exp = 0; // �������� ���� �÷��̾� ����ġ �� �ʱ�ȭ
		}

		if (playerLevel == 10)
		{
			printf("���� Ż�⿡ �����Ͽ����ϴ�! ���� ���迡�� ������ ���ϴ�!");
			end =1;
		}

		printf("�÷��̾�� %d���� �Դϴ�.\n", playerLevel);
		printf("������ �����Ͽ����ϴ�.\n");
		printf("%d ���� �ʷϴ����̿� �����Ͽ����ϴ� `��`\n", monsterLevel);

		printf("1 �� �ο��, 2 �� ��������\n");
		scanf_s("%d", &choice);

		if (choice == 1 && die < monsterLevel * (1 + playerLevel * 2))
		{
			printf("���Ϳ��� �������� �й��Ͽ� ����Ͽ����ϴ�. ������ ����˴ϴ�.....\n");
			end = 1; //���ѷ��� Ż�� 
		}
		else if (choice == 2 && die < 10)
		{
			printf("�������ٰ� ���� ��� ����Ͽ����ϴ�. ������ ����˴ϴ�.....\n");
			end = 1; //���ѷ��� Ż�� 
		}
		else if (choice == 1 && die > monsterLevel * (1 + playerLevel * 2))
		{
			printf("���Ϳ��� �������� �¸��Ͽ����ϴ�! ����ġ�� %d��ŭ ȹ���ϼ̽��ϴ�!", monster_Exp);
			monsterLevel++; // ���� ���� ��� ����������
		}
		else if (choice == 2 && die > 10)
		{
			printf("������� ������ �� ������ ����� ������ �ʽ��ϴ� ����ġ�� %d��ŭ ȹ���߽��ϴ�. �ȵ����� �����ϴ�.....", run_Exp);
			//������������ ���� ������ ��� ���ϵ��� ���������� ��� X (������ �뷱�� ���� �������� ¥�ý��ϴ�!)
		}
	}
}

void main()
{
	//Rock_Scissors_Paper(); // ���������� ����
	TextRPG(); // �ؽ�ƮRPG
}