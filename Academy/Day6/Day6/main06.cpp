﻿#include <iostream>

using namespace std;

void main()
{
	//다차원 배열
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	//arr[0] ~ arr[9]

	int arr2[2][5] = { {1,2,3,4,5}, {6,7,8,9,10} };
	//arr2[0][0] ~ arr2[0][4]
	//arr2[1][0] ~ arr2[1][4]
	
	for (int i = 0; i < 10; i++)
	{
		cout << "arr[i] = " << arr[i] << endl;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "arr2[i][j] = " << arr2[i][j] << endl;
		}
	}

	//빙고판
	int bingo[25] = {};
	int bingo2[5][5] = {};
	for (int i = 0; i < 25; i++)
	{
		bingo[i] = i + 1;
		//0~4 => 0,0 ~ 0,4
		//5~9 => 1,0 ~ 1,4
		bingo2[i / 5][i % 5] = i + 1;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << bingo[i * 5 + j] << "\t";
		}
		cout << endl;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << bingo2[i][j] << "\t";
		}
		cout << endl;
	}

}

// 숙제 1. 
// 내 빙고판과 컴퓨터 빙고판이 존재한다
// 둘다 1~25까지의 숫자가 적혀있고
// 빙고판의 숫자는 랜덤으로 섞여져있다.
// 나와 컴퓨터가 돌아가면서 숫자를 외치면
// 둘다 그 숫자를 빙고판에서 X친다
// 둘중에 한명이라도
// 빙고를 3개를 완성하면 (가로줄, 세로줄, 대각선줄)
// 게임종료


// 숙제 2. 
// 하이로우세븐
// 카드게임
// (하실수있는분만 하세요!)
// 
// 트럼프카드 52장으로 시작
// ♤A ~ ♥K 까지 존재
// 이 트럼프카드를 섞고

// 플레이어가 입장
// 플레이어는 시작골드 10000원으로 시작
// 베팅을하는데
// 다음카드가 7보다작은지, 7보다큰지, 7이랑 같은지 베팅
// 베팅금액따로 존재
// 
// 베팅을하고, 맞추면 
// 7보다작은지, 7보다큰지 => 2배 지급
// 7인걸 맞추면 => 10배 지급
// 
// 트럼프카드를 다쓰거나 플레이어가 파산나면 게임종료

