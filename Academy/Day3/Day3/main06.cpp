﻿#include <iostream>

using namespace std;

void main()
{
	// 랜덤
	// 
	// 랜덤 사용 방법
	int random1 = rand();
	cout << "랜덤값 : " << random1 << endl;
	int random2 = rand();
	cout << "랜덤값 : " << random2 << endl;

	// rand()를 쓸때마다 값이 달라집니다.
	//  ==> 이는 곧 무작위 수 라는 뜻이죠

	// 생기는 의문이 있을거에요.
	// 1. 모든 PC가 똑같은 수를 순서대로 배출하는 이유가 무엇일까?
	// 2. 모든 PC가 똑같은 수를 순서대로 배출하는데 우리가 쓰는 랜덤이랑
	//   의미가 똑같을 쓸수나 있을까?

	// 컴퓨터는 거짓말을 못합니다.
	// 다른결과를 내거나, 속이거나 그런행동을 하지못해요.

	// 그래서 무작위수라는거는, 컴퓨터는 똑같은 결과값만 낼수있기때문에
	// 현실적으로 존재할수가 없습니다.

	// rand() 는 무작위수를 뽑기위해 구현한 함수
	// 미리 고정된 난수를 seed를 통해 통안에 숫자들을 순서대로 넣은걸 그대로 뽑아오는 결과일뿐입니다.
	// 41 -> 18467
	// 이런순서로 나오게 되는거에요.

	// seed (통안에 숫자를 넣는 방법)을 바꾸면
	// 진짜로 랜덤값을 뽑아온것처럼 느끼게할 수 있다.

	// 우리가 난수라고 느낄수밖에 없는 절대적인 값이 하나 있습니다.
	// 뭐냐면 현재 시간 (마이크로세컨드)
	// 저시간을 seed값으로 넣는거에요

	// seed를 섞는 함수
	// srand(값);
	// 현재시간 : time(NULL)

	srand(time(NULL));
	int random3 = rand();
	cout << "랜덤값 : " << random3 << endl;
	int random4 = rand();
	cout << "랜덤값 : " << random4 << endl;


	// 랜덤값으로 실습
	// 1. 0~3 사이의 랜덤숫자 뽑아보기
	// 
	// 메이플 공격력 ( 51 ~ 53 )
	// 51 ~ 53의 랜덤한 데미지가 들어가죠
	// 2. 51~53 사이의 랜덤숫자 뽑아보기

	// 0 ~ 2

	int myRandom1 = rand() % 4;
	int myRandom2 = rand() % 3 + 51;

	
	int computerHand = rand() % 3;
	// computerHand => 0이면 가위라고 생각하고
	// computerHand => 1이면 바위라고 생각하고
	// computerHand => 2면 보라고 생각하고
	// 수도코드를 작성하면 됩니다.
}

/*
1. 텍스트 알피지 만들기
 - 내용은 마음대로 수정하세요!
 - 선택과, 랜덤만 들어가면 뭐든 ok입니다!
 - 아스키아트를 활용하면 재미붙일 수 있을거에요.
 
출력예시)

플레이어는 1레벨 입니다.
던전에 입장하였습니다.

1레벨 고블린과 조우하였습니다.
(1: 싸우기, 2: 도망가기)

 -> 싸우기 선택시, (고블린 레벨)/(1+플레이어레벨*2) 확률로 사망
 -> 사망하면 게임 종료, 전투에서 승리시, 레벨업

 -> 도망가기 선택시, 10% 확률로 사망
 -> 사망하면 게임 종료


2레벨 고블린과 조우하였습니다.
(1: 싸우기, 2: 도망가기)

 -> 싸우기 선택시, (고블린 레벨)/(1+플레이어레벨*2) 확률로 사망
 -> 사망하면 게임 종료, 전투에서 승리시, 레벨업

 -> 도망가기 선택시, 10% 확률로 사망
 -> 사망하면 게임 종료

3레벨 고블린과 조우하였습니다.
(1: 싸우기, 2: 도망가기)

 -> 싸우기 선택시, (고블린 레벨)/(1+플레이어레벨*2) 확률로 사망
 -> 사망하면 게임 종료, 전투에서 승리시, 레벨업

 -> 도망가기 선택시, 10% 확률로 사망
 -> 사망하면 게임 종료

플레이어는 몇레벨로 던전에 탈출하였습니다.
축하드립니다 게임을 클리어하셨습니다.

*/

// 2. 가위바위보게임 만들기
/*
출력예시)
가위(0), 바위(1), 보(2) 중에서 선택해주세요
가위를 선택하셨습니다.

컴퓨터는 보를 선택하였습니다.

승리하였습니다.
*/