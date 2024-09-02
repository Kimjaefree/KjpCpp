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

	int lotto[45] = { 0, }; // 로또 숫자가 들어갈 배열 변수 선언 및 초기화

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

// 숙제1.gotoxy이용해서 로또번호 이쁘게 만들기@@