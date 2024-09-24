#include <iostream>

using namespace std;

void main()
{
	// 여태까지 배웠던 내용 집합
	// enum (사용자 정의 자료형)
	// enum 예 ->

	/*enum class RockScissorPaper
	{
		Rock,
		Scissor,
		Paper,
		End
	};*/

	// enum 대입방법
	// -> class 이름 :: class 안 변수이름;
	// =====================================
	
	// 배열
	// int arr[배열크기] = {};
	// 주의사항 -> 배열의 인덱스 번호는 항상 '0' 부터 시작하니 조심할 것!
	// 배열에 자주 사용하는 알고리즘 -> Swap 알고리즘
	/* temp = a;
	 a = b;
	 b = temp;*/
	// =====================================

	// 반복문
	// 1. for 반복문
	// -> 반복횟수가 확실하게 정해져 있을 때 많이 사용
	// 2. while 반복문
	// -> ~하는 동안, 무한루프 설계시 사용
	// 3. do~while 반복문 (거의 사용X)
	// -> while 문과는 다르게 조건이 맞든 틀리는 무조건 1번은 실행
	// -> 반복문은 배열과 자주 사용할 일이 많음!
	// 반복문에 자주 사용하는 알고리즘 -> 배열 섞기
	/*srand(time(NULL));
	for (int i = 0; i < 9999; i++)
	{
		int index1 = rand() % 100;
		int index2 = rand() % 100;
		int temp = arr[index1];        -> 배열 섞기 알고리즘을 사용할 때 Swap 알고리즘이 사용된다!
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}*/

	// -> 반복문 추가문법
	// 1. break
	// -> 반복문을 탈출하는 문법
	// 2. continue
	// -> 이번 분기를 'skip' 하고 계속 진행한다.
	// =====================================

	// switch case 문
	// -> 정수만 가능하고 가독성이 좋다.

	// =====================================

	// typedef
	// -> type define의 약자
	// define -> 전역으로 무언가를 선언할 때 사용한다 (매크로 식으로 사용할 때)
	// type -> 전역으로 타입을 선언해주는 역할
	// ex) -> typedef int 정수;

	// =====================================

	// 포인터(pointer) -> 변수(메모리) 주소
	// & -> 주소값을 가져오는 연산자
	// * -> 뒤에 온 값을 주소값으로 인지했을 때의 값
	// 포인터 자료형 -> 주소를 들고있는 자료형

	// =====================================

	// 매개변수
	// 구조체
	// 동적할당
	// 동적배열
	// 클래스
	// 자료구조
	// 1. LinkedList
	// 2. Template
	// 3. Vector

	// =====================================
	
	// Windows.Api
}