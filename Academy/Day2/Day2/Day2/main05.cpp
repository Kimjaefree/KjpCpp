#include <iostream>

using namespace std;

void main()
{
	// 실습 계산기 만들기
	int num1, num2, choice, result = 0; // 필요한 변수 선언
	printf("숫자 1을 입력해주세요 : "); // 사용자에게 숫자 입력받기
	scanf_s("%d", &num1);

	printf("숫자 2을 입력해주세요 : ");
	scanf_s("%d", &num2);

	printf("어떤 연산을 진행하시겠습니까? : ( 1 : +, 2 : -, 3 : *, 4 : / )"); // 무슨 연산을 할지 choice 변수를 입력받아 choice 변수의 숫자대로 정하기
	scanf_s("%d", &choice);
	if (choice == 1)
	{
		result = num1 + num2;
	}
	else if (choice == 2)
	{
		result = num1 - num2;
	}
	else if (choice == 3)
	{
		result = num1 * num2;
	}
	else if (choice == 4)
	{
		result = num1 /num2;
	}
	printf("결과 : %d\n", result); // 결과 result 출력문
}