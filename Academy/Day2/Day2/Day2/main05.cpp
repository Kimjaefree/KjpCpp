#include <iostream>

using namespace std;

void main()
{
	// �ǽ� ���� �����
	int num1, num2, choice, result = 0; // �ʿ��� ���� ����
	printf("���� 1�� �Է����ּ��� : "); // ����ڿ��� ���� �Է¹ޱ�
	scanf_s("%d", &num1);

	printf("���� 2�� �Է����ּ��� : ");
	scanf_s("%d", &num2);

	printf("� ������ �����Ͻðڽ��ϱ�? : ( 1 : +, 2 : -, 3 : *, 4 : / )"); // ���� ������ ���� choice ������ �Է¹޾� choice ������ ���ڴ�� ���ϱ�
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
	printf("��� : %d\n", result); // ��� result ��¹�
}