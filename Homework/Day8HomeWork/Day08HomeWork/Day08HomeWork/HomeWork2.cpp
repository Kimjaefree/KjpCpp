#include <iostream>

using namespace std;

struct Monster
{
	float hp;
	float attack;
};

struct Player
{
	float hp;
	float attack;
};

enum RockScissorPaper
{
	Rock,
	Scissor,
	Paper
};

int playerHand, monsterHand = 0;
bool isGamePlaying = true;

void main()
{
	Monster monster = { };
	monster.hp = 10;
	monster.attack = 5;

	Player player = { };
	player.hp = 10;
	player.attack = 5;

	srand(time(NULL));

	printf("���Ϳ� �����ƽ��ϴ�! ������������ �����մϴ�!\n");

	while (isGamePlaying = true)
	{
		printf("����(0), ����(1), ��(2) �߿��� �������ּ��� : \n");
		scanf_s("%d", &playerHand); // �޼� �� �Է¹ޱ�

		printf("�÷��̾��� ���� :");

		if (playerHand == (int)RockScissorPaper::Rock)
		{
			printf("����\n");
		}
		else if (playerHand == (int)RockScissorPaper::Scissor)
		{
			printf("����\n");
		}
		else if (playerHand == (int)RockScissorPaper::Paper)
		{
			printf("��\n");
		}

		printf("���� ������...\n");

		printf("������ ���� : ");
		monsterHand = rand() % 3;

		if (monsterHand == (int)RockScissorPaper::Rock)
		{
			printf("����\n");
		}
		else if (monsterHand == (int)RockScissorPaper::Scissor)
		{
			printf("����\n");
		}
		else if (monsterHand == (int)RockScissorPaper::Paper)
		{
			printf("��\n");
		}

		if (playerHand == monsterHand) {
			printf("�����ϴ�.\n");
			printf("�÷��̾� ���� ü�� : %.f ���� ���� ü��: %.f\n", player.hp, monster.hp);
		}
		else if ((playerHand == (int)RockScissorPaper::Rock && monsterHand == (int)RockScissorPaper::Paper) ||
			(playerHand == (int)RockScissorPaper::Scissor && monsterHand == (int)RockScissorPaper::Rock) ||
			(playerHand == (int)RockScissorPaper::Paper && monsterHand == (int)RockScissorPaper::Scissor)) {
			printf("�÷��̾ �й��߽��ϴ�!! ������ ���մϴ�.\n");
			player.hp -= monster.attack;
			printf("�÷��̾� ���� ü�� : %.f ���� ���� ü��: %.f\n", player.hp, monster.hp);
		}
		else {
			printf("�÷��̾ �¸��Ͽ����ϴ�. ���Ϳ��� �����մϴ�!\n");
			monster.hp -= player.attack;
			printf("�÷��̾� ���� ü�� : %.f ���� ���� ü��: %.f\n", player.hp, monster.hp);
		}

		if (player.hp <= 0)
		{
			printf("�÷��̾ ����Ͽ����ϴ� ������ �����մϴ�...");
			isGamePlaying = false;
			break;
		}
		else if (monster.hp <= 0)
		{
			printf("���͸� óġ�߽��ϴ�!! ������ �����մϴ�...");
			isGamePlaying = false;
			break;
		}
	}
}

