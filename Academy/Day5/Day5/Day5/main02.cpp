#include <iostream>

using namespace std;

void main()
{
	// countinue; break;

	// �ݺ����� ���� �����ϰ� ����ϱ����� ���� ����

	// countinue; => �̹��б⸦ skip�ϰ� ��� �����Ѵ�.
	// �ݺ��� �����ȿ��� ��ȿ�� üũ�� �� ���� ���δ�.

	// break; => �߰��� �ݺ����� ���͹�����.

	int arr[1000] = {};
	for (int i = 0; i < 1000; i++)
	{
		// i�� 3�� ����� Ư���ϰ� ó�����ְ� �ʹ�.
		if (i % 3 == 0)
		{
			arr[i] = 1000 + i;
		}
		else
		{
			arr[i] = i;
		}
	}

	// arr�� �迭���� 3�� ����� ����ϰ�ʹ�.
	for (int i = 0; i < 1000; i++)
	{
		if (arr[i] % 3 != 0)
		{
			continue;
		}
		printf("%d\n", arr[i]);
	}
