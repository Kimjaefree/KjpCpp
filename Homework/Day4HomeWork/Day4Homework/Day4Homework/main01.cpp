#include <iostream>

using namespace std;


void lotto()
{
    // 1~45의 수를 가지는 배열 변수 선언
	// 1~45의 숫자를 순서대로 가지고있는 배열 섞어주기
	// 과연 배열 섞는걸 어떻게 해야할까...? 
	// 수업시간에 배운 랜덤과 swap을 사용해서 배열 섞기..?
	// 반복문을 사용하여 6개의 숫자 뽑기
	// 뽑은 숫자 출력

	int lotto[45] = {0,}; // 로또 숫자가 들어갈 배열 변수 선언 및 초기화

	srand(time(NULL)); 

	for (int i = 0; i < 45; i++)
	{
		lotto[i] = i + 1; // lotto 배열 변수에 1~45의 숫자 넣는 반복문
	}

	int temp = 0; // swap을 위한 temp 변수 선언

	for (int i = 44; i > 0; i--) // 배열 섞기를 위한 반복문
	{
		int j = rand() % (i + 1); // j에 임의의 정수 생성  
		temp = lotto[i]; // lotto 배열의 i 번째 값과 lotto 배열의 임의의 정수 j 번의 값을 스왑해서 섞기
		lotto[i] = lotto[j]; 
		lotto[j] = temp; 
	}

	printf("이번 로또 당첨 번호 리스트 : "); // 반복되면 안되는 출력문 반복문 전에 출력해서 가독성 높이기

	for (int i = 0; i < 6; i++) // 섞인 배열에서 lotto 배열의 앞 6개 숫자 출력 반복문
	{
		printf("%d", lotto[i]); // lotto 배열 0번째 인덱스 ~ 5번째 인덱스 까지 출력
		printf("  "); // 가독성을 높이기 위한 공백 출력
	}

	printf("\n");

}

// 바위 가위 보 enum 생성
enum class RockScissorsPaper
{
	Rock,
	Scissors,
	Paper
};

//왼손 오른손 enum 생성
enum class LeftRight
{
	Left,
	Right
};
void rockScissorsPaperTakeOneOut()
{
	int playerLeftHand, playerRightHand = 0; // 플레이어 왼손 오른손 변수 생성 및 초기화
	int computerLeftHand, computerRightHand = 0; // 컴퓨터 왼손 오른손 변수 생성 및 초기화
	int playerChoice, playerFinalChoice = 0; // 플레이어 선택과 최종 선택지 변수 생성 및 초기화	
	int computerFinalChoice = 0; // 컴퓨터 최종 선택지 변수 생성 및 초기화

	//플레이어 왼손 오른손 선택 및 선택지 출력
	printf("왼손에 낼 바위(0), 가위(1), 보(2) 중에서 선택해주세요 : \n");
	scanf_s("%d", &playerLeftHand); // 왼손 값 입력받기

	printf("오른손에 낼 바위(0), 가위(1), 보(2) 중에서 선택해주세요 : \n");
	scanf_s("%d", &playerRightHand); // 오른손 값 입력받기

	printf("플레이어의 선택 :"); 

	//왼손 출력
	if (playerLeftHand == (int)RockScissorsPaper::Rock)
	{
		printf("왼손: 바위");
		printf(" ");
	}
	else if (playerLeftHand == (int)RockScissorsPaper::Scissors)
	{
		printf("왼손: 가위");
		printf(" ");
	}
	else if (playerLeftHand == (int)RockScissorsPaper::Paper)
	{
		printf("왼손: 보");
		printf(" ");
	}

	//오른손 출력
	if (playerRightHand == (int)RockScissorsPaper::Rock)
	{
		printf("오른손 : 바위\n");
	}
	else if (playerRightHand == (int)RockScissorsPaper::Scissors)
	{
		printf("오른손 : 가위\n");
	}
	else if (playerRightHand == (int)RockScissorsPaper::Paper)
	{
		printf("오른손 : 보\n");
	}

	//컴퓨터 선택
	printf("컴퓨터 선택중...\n");

	srand(time(NULL));
	
	// 컴퓨터 왼손 오른손 랜덤 설정
	computerLeftHand = rand() % 3; 
	computerRightHand = rand() % 3;

	printf("컴퓨터의 선택 : ");

	// 컴퓨터 왼손 선택 및 출력
	if (computerLeftHand == (int)RockScissorsPaper::Rock)
	{
		printf("왼손: 바위");
		printf(" ");
	}
	else if (computerLeftHand == (int)RockScissorsPaper::Scissors)
	{
		printf("왼손: 가위");
		printf(" ");
	}
	else if (computerLeftHand == (int)RockScissorsPaper::Paper)
	{
		printf("왼손: 보");
		printf(" ");
	}

	//컴퓨터 오른손 선택 및 출력 
	if (computerRightHand == (int)RockScissorsPaper::Rock)
	{
		printf("오른손: 바위\n");	
	}
	else if (computerRightHand == (int)RockScissorsPaper::Scissors)
	{
		printf("오른손: 가위\n");
	}
	else if (computerRightHand == (int)RockScissorsPaper::Paper)
	{
		printf("오른손: 보\n");
	}

	// 왼손 오른손 선택지 문구 출력 및 선택지 입력받기
	printf("왼손(0) 또는 오른손(1)을 선택하세요 : \n");
	scanf_s("%d", &playerChoice);

	// 간결성과 가독성을 위해 삼항연산자를 사용하여 최종선택지 결정 (if문도 사용가능!)
	playerFinalChoice = (playerChoice == 0) ? playerLeftHand : playerRightHand;

	// 컴퓨터 최종 선택지 설정
	printf("컴퓨터 최종 선택중...\n");
	computerFinalChoice = rand() % 2;

	printf("가위 바위 보 하나빼기~~~!\n");

	// 플레이어와 컴퓨터의 최종 선택지를 보고 승, 패, 무승부 결정하는 if문
	if (playerFinalChoice == computerFinalChoice) {
		printf("비겼습니다.");
	}
	else if ((playerFinalChoice == (int)RockScissorsPaper::Rock && computerFinalChoice == (int)RockScissorsPaper::Paper) ||
		(playerFinalChoice == (int)RockScissorsPaper::Scissors && computerFinalChoice == (int)RockScissorsPaper::Rock) ||
		(playerFinalChoice == (int)RockScissorsPaper::Paper && computerFinalChoice == (int)RockScissorsPaper::Scissors)) {
		printf("졌습니다.");
	}
	else {
		printf("승리하였습니다.");
	}
}

void main()
{
	lotto();
	rockScissorsPaperTakeOneOut();

}