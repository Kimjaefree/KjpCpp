#include <iostream>

using namespace std;

enum class RockScissorsPaper
{
	Scissor,
	Rock,
	Paper,
};

void main() 
{
	// 3���� �ڵ� ���� 
	// 1. �ؽ�ƮRPG ����� ���ð� ������ ���� ���� OK
	// 2. ���������� ���� �����
}

void TextRpg()
{
	srand(time(NULL));
	int playerLv = 1;
	cout << "�÷��̾��" << playerLv << "�Դϴ�." << endl;
	cout << "������ �����Ͽ����ϴ�." << endl;
	int goblinLv = 1;
	cout << "1���� ����� �����Ͽ����ϴ�. (1: �ο��, 2: ��������)" << endl;
	int choice = 0;

	cin >> choice;

	if (choice == 1)
	{
		cout << "�ο�⸦ �����Ͽ����ϴ�" << endl;
		float diePoint = (float)goblinLv / (float)(1 + playerLv * 2) * 100; // %�� ��ȯ
		int rnd = rand() % 100;
		if (rnd < diePoint)
		{
			cout << "�÷��̾�� ����Ͽ����ϴ�." << endl;
			exit(0);
		}
		else
		{
			playerLv++;
			cout << "������� �������� �¸��Ͽ����ϴ�. " << endl;
			cout << "�÷��̾� ������ �ö����ϴ�. ���� ���� : " << playerLv << endl;
		}
	}
	else if (choice == 2)
	{
		int rnd = rand() % 100;

		if (rnd < 10)
		{
			cout << "�÷��̾�� ����Ͽ����ϴ�." << endl;
			exit(0);
		}
		else
		{
			cout << "�����ƽ��ϴ�!" << endl;
		}
	}

	cout << "�÷��̾�� " << playerLv << "������ ������ Ż���Ͽ����ϴ�." << endl;
	cout << "���ϵ帳�ϴ�. ������ Ŭ�����Ͽ����ϴ�." << endl;
}

void RockScissorPaper()
{
	srand(time(NULL));
	cout << " ����(0), ����(1), ��(2) �߿��� �������ּ���" << endl;
	int playerHand = 0;
	cin >> playerHand;
	int comHand = 0;
	comHand = rand() % 3;
	
	if (playerHand == (int)RockScissorsPaper :: Scissor)
	{
		cout << "�÷��̾�� ������ �����ϼ̽��ϴ�." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Rock)
	{
		cout << "�÷��̾�� ������ �����ϼ̽��ϴ�." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Paper)
	{
		cout << "�÷��̾�� ���� �����ϼ̽��ϴ�." << endl;
	}

	if (comHand == (int)RockScissorsPaper::Scissor)
	{
		cout << "��ǻ�ʹ� ������ �����ϼ̽��ϴ�." << endl;
	}
	else if (comHand == (int)RockScissorsPaper::Rock)
	{
		cout << "��ǻ�ʹ� ������ �����ϼ̽��ϴ�." << endl;
	}
	else if (comHand == (int)RockScissorsPaper::Paper)
	{
		cout << "��ǻ�ʹ� ���� �����ϼ̽��ϴ�." << endl;
	}

	if (playerHand == comHand)
	{
		cout << "�����ϴ�." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Scissor && comHand == (int)RockScissorsPaper::Rock)
	{
		cout << "�����ϴ�." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Rock && comHand == (int)RockScissorsPaper::Paper)
	{
		cout << "�����ϴ�." << endl;
	}
	else if (playerHand == (int)RockScissorsPaper::Paper && comHand == (int)RockScissorsPaper::Scissor)
	{
		cout << "�����ϴ�." << endl;
	}
	else
	{
		cout << "�̰���ϴ�." << endl;
	}

}