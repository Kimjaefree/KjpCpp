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

	printf("몬스터와 마주쳤습니다! 가위바위보를 진행합니다!\n");

	while (isGamePlaying = true)
	{
		printf("바위(0), 가위(1), 보(2) 중에서 선택해주세요 : \n");
		scanf_s("%d", &playerHand); // 왼손 값 입력받기

		printf("플레이어의 선택 :");

		if (playerHand == (int)RockScissorPaper::Rock)
		{
			printf("바위\n");
		}
		else if (playerHand == (int)RockScissorPaper::Scissor)
		{
			printf("가위\n");
		}
		else if (playerHand == (int)RockScissorPaper::Paper)
		{
			printf("보\n");
		}

		printf("몬스터 선택중...\n");

		printf("몬스터의 선택 : ");
		monsterHand = rand() % 3;

		if (monsterHand == (int)RockScissorPaper::Rock)
		{
			printf("바위\n");
		}
		else if (monsterHand == (int)RockScissorPaper::Scissor)
		{
			printf("가위\n");
		}
		else if (monsterHand == (int)RockScissorPaper::Paper)
		{
			printf("보\n");
		}

		if (playerHand == monsterHand) {
			printf("비겼습니다.\n");
			printf("플레이어 남은 체력 : %.f 몬스터 남은 체력: %.f\n", player.hp, monster.hp);
		}
		else if ((playerHand == (int)RockScissorPaper::Rock && monsterHand == (int)RockScissorPaper::Paper) ||
			(playerHand == (int)RockScissorPaper::Scissor && monsterHand == (int)RockScissorPaper::Rock) ||
			(playerHand == (int)RockScissorPaper::Paper && monsterHand == (int)RockScissorPaper::Scissor)) {
			printf("플레이어가 패배했습니다!! 공격을 당합니다.\n");
			player.hp -= monster.attack;
			printf("플레이어 남은 체력 : %.f 몬스터 남은 체력: %.f\n", player.hp, monster.hp);
		}
		else {
			printf("플레이어가 승리하였습니다. 몬스터에게 공격합니다!\n");
			monster.hp -= player.attack;
			printf("플레이어 남은 체력 : %.f 몬스터 남은 체력: %.f\n", player.hp, monster.hp);
		}

		if (player.hp <= 0)
		{
			printf("플레이어가 사망하였습니다 게임을 종료합니다...");
			isGamePlaying = false;
			break;
		}
		else if (monster.hp <= 0)
		{
			printf("몬스터를 처치했습니다!! 게임을 종료합니다...");
			isGamePlaying = false;
			break;
		}
	}
}

