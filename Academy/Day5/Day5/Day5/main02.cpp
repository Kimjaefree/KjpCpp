#include <iostream>

using namespace std;

void main()
{
	// countinue; break;

	// 반복문을 조금 윤택하게 사용하기위해 나온 문법

	// countinue; => 이번분기를 skip하고 계속 진행한다.
	// 반복문 로직안에서 유효성 체크할 때 많이 쓰인다.

	// break; => 중간에 반복문을 나와버린다.

	int arr[1000] = {};
	for (int i = 0; i < 1000; i++)
	{
		// i가 3의 배수만 특별하게 처리해주고 싶다.
		if (i % 3 == 0)
		{
			arr[i] = 1000 + i;
		}
		else
		{
			arr[i] = i;
		}
	}

	// arr의 배열에서 3의 배수만 출력하고싶다.
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] % 3 != 0)
		{
			continue;
		}
		printf("%d\n", arr[i]);
	}
