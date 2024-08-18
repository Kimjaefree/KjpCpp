#include <iostream>

using namespace std;

void Rock_Scissors_Paper()
{
	int playerNum = 0;

	printf("가위(0), 바위(1), 보(2) 중에서 선택해주세요 : ");
	scanf_s("%d", &playerNum);

	printf("컴퓨터 선택중...\n");

	srand(time(NULL));
	int computerNum = rand() % 3;

	if (computerNum == 0)
	{
		printf("컴퓨터는 가위를 선택하였습니다.\n");
	}
	else if (computerNum == 1)
	{
		printf("컴퓨터는 바위를 선택하였습니다.\n");
	}
	else if (computerNum == 2)
	{
		printf("컴퓨터는 보를 선택하였습니다.\n");
	}

	if (playerNum == computerNum) {
		printf("비겼습니다.\n");
	}
	else if ((playerNum == 0 && computerNum == 2) ||
		(playerNum == 1 && computerNum == 0) ||
		(playerNum == 2 && computerNum == 1)) {
		printf("승리하였습니다.\n");
	}
	else {
		printf("졌습니다.\n");
	}
}

void TextRPG()
{
	int monsterLevel = 1;
    int playerLevel = 1;// 몬스터 레벨, 플레이어 레벨변수 선언
	int choice, end = 0;
	int player_Exp = 0; // 무한루프 탈출 변수, 플레이어 경험치 변수 선언
	int monster_Exp = 25; // 몬스터를 처치할시 얻는 경험치 변수 선언 및 값 설정
	int run_Exp = 10; // 도망치기에 성공시 얻는 경험치 변수 선언 및 값 설정
	
	srand(time(NULL));
	
	while (end == 0) // end가 1이 될 때까지 무한 반복하는 루프 사망하면 end의 값이 1이되어 프로그램 종료
	{
		int die = rand() % 100; // 사망확률을 조정하는 die 변수 선언 및 랜덤 값 설정 0~99까지

		if (player_Exp >= 60) // 경험치에 따른 플레이어 레벨 조정 (저만의 밸런스 조절 느낌으로 짜봤습니다!)
		{
			playerLevel++;
			printf("축하합니다 레벨업 하셨습니다! 현재레벨 : %d\n", playerLevel);
			player_Exp = 0; // 레벨업을 위한 플레이어 경험치 양 초기화
		}

		if (playerLevel == 10)
		{
			printf("던전 탈출에 성공하였습니다! 다음 모험에도 건투를 빕니다!");
			end =1;
		}

		printf("플레이어는 %d레벨 입니다.\n", playerLevel);
		printf("던전에 입장하였습니다.\n");
		printf("%d 레벨 초록달팽이와 조우하였습니다 `ㅁ`\n", monsterLevel);

		printf("1 → 싸우기, 2 → 도망가기\n");
		scanf_s("%d", &choice);

		if (choice == 1 && die < monsterLevel * (1 + playerLevel * 2))
		{
			printf("몬스터와의 전투에서 패배하여 사망하였습니다. 게임이 종료됩니다.....\n");
			end = 1; //무한루프 탈출 
		}
		else if (choice == 2 && die < 10)
		{
			printf("도망가다가 발을 헛디뎌 사망하였습니다. 게임이 종료됩니다.....\n");
			end = 1; //무한루프 탈출 
		}
		else if (choice == 1 && die > monsterLevel * (1 + playerLevel * 2))
		{
			printf("몬스터와의 전투에서 승리하였습니다! 경험치를 %d만큼 획득하셨습니다!", monster_Exp);
			monsterLevel++; // 몬스터 레벨 상승 증감연산자
		}
		else if (choice == 2 && die > 10)
		{
			printf("재빠르게 도망을 쳐 몬스터의 모습이 보이지 않습니다 경험치를 %d만큼 획득했습니다. 안도감을 느낍니다.....", run_Exp);
			//도망쳤을때는 몬스터 레벨이 상승 안하도록 증감연산자 사용 X (저만의 밸런스 조절 느낌으로 짜봤습니다!)
		}
	}
}

void main()
{
	//Rock_Scissors_Paper(); // 가위바위보 게임
	TextRPG(); // 텍스트RPG
}