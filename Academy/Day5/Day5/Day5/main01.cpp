#include <iostream>

using namespace std;

void main()
{
	// 반복문
	// 3가지
	// for, while, do ~ while

	// for문 사용법
	for (int i = 0; i < 1000; i++)
	{

	}

	// => 1000번 반복한다.
	// 주로 for문은 i = 0 i++ 고정
	// 배열이랑 같이 쓰기 좋음

	// while문 사용법
	bool isGamePlaying = true;
	while (isGamePlaying == true)
	{
		printf("게임을 종료하시겠습니까? (0 : 예, 그 외 : 아니오)\n" );
		int choice;
		scanf_s("%d", &choice);
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}

	// while(조건식)
	// {
	//		실행구문
	// }

	// 조건식이 참 = 실행구문 실행
	// 조건식이 거짓 = 실행구문 실행 X

	// while 문은 ~~ 하는 동안 이라는 느낌이 나면 while 문을 사용함.

	// 실습

	// for문을 while 문으로 변경
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", i);
	}

	int howMuch = 0;
	while (howMuch < 10)
	{
		printf("%d\n", howMuch);
		howMuch++;
	}

	// do while문

	int choice = 0;
	do
	{
		cout << "왼손(0)과 오른손(1)중에 선택해주세요." << endl;
		cin >> choice;
	} while ();


	