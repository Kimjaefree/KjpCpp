#include <iostream>
#include <Windows.h>
using namespace std;

void Lotto();

void main()
{
	// 4���� �ڵ� ���� 
	// 1. �ζǹ�ȣ ������
	Lotto();
	// 2. ���������� �ϳ�����
}

void Lotto()
{
	// �ζǹ�ȣ�� �� 1~45 ���� �� 45���� ���ڷ� �̷��������
	int lottoNum[45] = {};
	// �ζ� �迭 �ʱ�ȭ
	for (int i = 0; i < 45; i++)
	{
		lottoNum[i] = i + 1;
	}

	// �ζ� �迭 ����
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

	cout << "�ζǹ�ȣ �̱� ���α׷��� ���Ű��� ȯ���մϴ�!" << endl;

	int choice = 0;
	cout << "�����Ͻ÷��� (1) �����Ͻ÷���(2)�� �Է����ּ��� : " << endl;
	cin >> choice;

	if (choice == 1)
	{
		cout << "�ζ� ��ȣ�� �̱� �����մϴ�! �α��α��α�" << endl;
	}
	else if (choice == 2)
	{
		cout << "���α׷��� 1�ʵ� �����մϴ�." << endl;
		Sleep(1000);
		exit(0);
	}
	else
	{
		cout << "�߸��� ���ڸ� �Է��ϼ̽��ϴ� �ٽ� �Է����ּ��� : " << endl;
		cout << "���� : (1) ���� : (2) " << endl;
		cin >> choice;
	}

	int playerLottoNum[7] = {};

	for (int i = 0; i < 7; i++)
	{
		cout << "�ζǹ�ȣ �� 7�ڸ��� �Է����ּ���" << endl;
		cout << i + 1 << "��° �ζǹ�ȣ �Է� : " << endl;
		cin >> playerLottoNum[i];
	}
	cout << "�ζ� ��ȣ�� �� ����̽��ϴ�! ����� �ζǹ�ȣ�� �̽��ϴ�" << endl;
	Sleep(1000);

	cout << "�ζǹ�ȣ�� �� �̾ҽ��ϴ� �ζǹ�ȣ�� �����մϴ�!" << endl;
	
	for (int i = 0; i < 7; i++)
	{
		cout << lottoNum[i] << "\t";
	}
	cout << endl;
	
	cout << "����ڴ��� ����� �ζǹ�ȣ" << endl;

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

	cout << "��� �������Դϴ� ��ø� ��ٷ��ּ���..." << endl;
	Sleep(1000);

	switch (count)
	{
	case 0 :
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�ƽ����� ���Դϴ�..." << endl;
		break;
	case 1:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�ƽ����� ���Դϴ�..." << endl;
		break;
	case 2:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�ƽ����� ���Դϴ�..." << endl;
		break;
	case 3:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�����մϴ� 5� ��÷�Ǽ̽��ϴ�!" << endl;
		break;
	case 4:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�����մϴ� 4� ��÷�Ǽ̽��ϴ�!" << endl;
		break;
	case 5:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�����մϴ� 3� ��÷�Ǽ̽��ϴ�!" << endl;
		break;
	case 6:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�����մϴ� 2� ��÷�Ǽ̽��ϴ�!" << endl;
		break;
	case 7:
		cout << "����ڴ��� ���� �ζ� ��ȣ ���� : " << count << endl;
		cout << "�����մϴ� 1� ��÷�Ǽ̽��ϴ�!" << endl;
		break;
	default:
		break;
	}
}