#include <iostream>
#include <Windows.h>
using namespace std;

void Lotto();

void main()
{
	// 4일차 코드 복습 
	// 1. 로또번호 생성기
	Lotto();
	// 2. 가위바위보 하나빼기
}

void Lotto()
{
	// 로또번호는 총 1~45 숫자 총 45개의 숫자로 이루어져있음
	int lottoNum[45] = {};
	// 로또 배열 초기화
	for (int i = 0; i < 45; i++)
	{
		lottoNum[i] = i + 1;
	}

	// 로또 배열 섞기
	srand(time(NULL));
	for (int i = 0; i < 45; i++)
	{
		int temp = 0;
		int index1 = rand() % 45;
		int index2 = rand() % 45;
		temp = lottoNum[index1];
		lottoNum[index1] = lottoNum[index2];
		lottoNum[index2] = temp;
	}

	cout << "로또번호 뽑기 프로그램에 오신것을 환영합니다!" << endl;

	int choice = 0;
	cout << "실행하시려면 (1) 종료하시려면(2)를 입력해주세요 : " << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "로또 번호를 뽑기 시작합니다! 두구두구두구" << endl;
	}
	else if (choice == 2)
	{
		cout << "프로그램을 1초뒤 종료합니다." << endl;
		Sleep(1000);
		exit(0);
	}
	else
	{
		cout << "잘못된 숫자를 입력하셨습니다 다시 입력해주세요 : " << endl;
		cout << "실행 : (1) 종료 : (2) " << endl;
		cin >> choice;
	}

	int playerLottoNum[7] = {};

	for (int i = 0; i < 7; i++)
	{
		cout << "로또번호 총 7자리를 입력해주세요" << endl;
		cout << i + 1 << "번째 로또번호 입력 : " << endl;
		cin >> playerLottoNum[i];
	}
	cout << "로또 번호를 다 적어내셨습니다! 잠시후 로또번호를 뽑습니다" << endl;
	Sleep(1000);

	cout << "로또번호를 다 뽑았습니다 로또번호를 공개합니다!" << endl;
	
	for (int i = 0; i < 7; i++)
	{
		cout << lottoNum[i] << "\t";
	}
	cout << endl;
	
	cout << "사용자님이 적어내신 로또번호" << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << playerLottoNum[i] << "\t";
	}
	cout << endl;
	
	int count = 0;
	for (int i = 0; i < 7; i++)
	{
		if (playerLottoNum[i] == lottoNum[i])
		{
			count++;
		}
	}

	cout << "결과 도출중입니다 잠시만 기다려주세요..." << endl;
	Sleep(1000);

	switch (count)
	{
	case 0 :
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "아쉽지만 꽝입니다..." << endl;
		break;
	case 1:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "아쉽지만 꽝입니다..." << endl;
		break;
	case 2:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "아쉽지만 꽝입니다..." << endl;
		break;
	case 3:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "축하합니다 5등에 당첨되셨습니다!" << endl;
		break;
	case 4:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "축하합니다 4등에 당첨되셨습니다!" << endl;
		break;
	case 5:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "축하합니다 3등에 당첨되셨습니다!" << endl;
		break;
	case 6:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "축하합니다 2등에 당첨되셨습니다!" << endl;
		break;
	case 7:
		cout << "사용자님이 맞춘 로또 번호 개수 : " << count << endl;
		cout << "축하합니다 1등에 당첨되셨습니다!" << endl;
		break;
	default:
		break;
	}
}