#include <iostream>

using namespace std;

void main()
{
	// �ݺ���
	// 3����
	// for, while, do ~ while

	// for�� ����
	for (int i = 0; i < 1000; i++)
	{

	}

	// => 1000�� �ݺ��Ѵ�.
	// �ַ� for���� i = 0 i++ ����
	// �迭�̶� ���� ���� ����

	// while�� ����
	bool isGamePlaying = true;
	while (isGamePlaying == true)
	{
		printf("������ �����Ͻðڽ��ϱ�? (0 : ��, �� �� : �ƴϿ�)\n" );
		int choice;
		scanf_s("%d", &choice);
		if (choice == 0)
		{
			isGamePlaying = false;
		}
	}

	// while(���ǽ�)
	// {
	//		���౸��
	// }

	// ���ǽ��� �� = ���౸�� ����
	// ���ǽ��� ���� = ���౸�� ���� X

	// while ���� ~~ �ϴ� ���� �̶�� ������ ���� while ���� �����.

	// �ǽ�

	// for���� while ������ ����
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

	// do while��

	int choice = 0;
	do
	{
		cout << "�޼�(0)�� ������(1)�߿� �������ּ���." << endl;
		cin >> choice;
	} while ();


	