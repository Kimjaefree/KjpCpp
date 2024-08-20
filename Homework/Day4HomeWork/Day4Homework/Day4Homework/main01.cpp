#include <iostream>

using namespace std;


void lotto()
{
    // 1~45�� ���� ������ �迭 ���� ����
	// 1~45�� ���ڸ� ������� �������ִ� �迭 �����ֱ�
	// ���� �迭 ���°� ��� �ؾ��ұ�...? 
	// �����ð��� ��� ������ swap�� ����ؼ� �迭 ����..?
	// �ݺ����� ����Ͽ� 6���� ���� �̱�
	// ���� ���� ���

	int lotto[45] = {0,}; // �ζ� ���ڰ� �� �迭 ���� ���� �� �ʱ�ȭ

	srand(time(NULL)); 

	for (int i = 0; i < 45; i++)
	{
		lotto[i] = i + 1; // lotto �迭 ������ 1~45�� ���� �ִ� �ݺ���
	}

	int temp = 0; // swap�� ���� temp ���� ����

	for (int i = 44; i > 0; i--) // �迭 ���⸦ ���� �ݺ���
	{
		int j = rand() % (i + 1); // j�� ������ ���� ����  
		temp = lotto[i]; // lotto �迭�� i ��° ���� lotto �迭�� ������ ���� j ���� ���� �����ؼ� ����
		lotto[i] = lotto[j]; 
		lotto[j] = temp; 
	}

	printf("�̹� �ζ� ��÷ ��ȣ ����Ʈ : "); // �ݺ��Ǹ� �ȵǴ� ��¹� �ݺ��� ���� ����ؼ� ������ ���̱�

	for (int i = 0; i < 6; i++) // ���� �迭���� lotto �迭�� �� 6�� ���� ��� �ݺ���
	{
		printf("%d", lotto[i]); // lotto �迭 0��° �ε��� ~ 5��° �ε��� ���� ���
		printf("  "); // �������� ���̱� ���� ���� ���
	}

	printf("\n");

}

// ���� ���� �� enum ����
enum class RockScissorsPaper
{
	Rock,
	Scissors,
	Paper
};

//�޼� ������ enum ����
enum class LeftRight
{
	Left,
	Right
};
void rockScissorsPaperTakeOneOut()
{
	int playerLeftHand, playerRightHand = 0; // �÷��̾� �޼� ������ ���� ���� �� �ʱ�ȭ
	int computerLeftHand, computerRightHand = 0; // ��ǻ�� �޼� ������ ���� ���� �� �ʱ�ȭ
	int playerChoice, playerFinalChoice = 0; // �÷��̾� ���ð� ���� ������ ���� ���� �� �ʱ�ȭ	
	int computerFinalChoice = 0; // ��ǻ�� ���� ������ ���� ���� �� �ʱ�ȭ

	//�÷��̾� �޼� ������ ���� �� ������ ���
	printf("�޼տ� �� ����(0), ����(1), ��(2) �߿��� �������ּ��� : \n");
	scanf_s("%d", &playerLeftHand); // �޼� �� �Է¹ޱ�

	printf("�����տ� �� ����(0), ����(1), ��(2) �߿��� �������ּ��� : \n");
	scanf_s("%d", &playerRightHand); // ������ �� �Է¹ޱ�

	printf("�÷��̾��� ���� :"); 

	//�޼� ���
	if (playerLeftHand == (int)RockScissorsPaper::Rock)
	{
		printf("�޼�: ����");
		printf(" ");
	}
	else if (playerLeftHand == (int)RockScissorsPaper::Scissors)
	{
		printf("�޼�: ����");
		printf(" ");
	}
	else if (playerLeftHand == (int)RockScissorsPaper::Paper)
	{
		printf("�޼�: ��");
		printf(" ");
	}

	//������ ���
	if (playerRightHand == (int)RockScissorsPaper::Rock)
	{
		printf("������ : ����\n");
	}
	else if (playerRightHand == (int)RockScissorsPaper::Scissors)
	{
		printf("������ : ����\n");
	}
	else if (playerRightHand == (int)RockScissorsPaper::Paper)
	{
		printf("������ : ��\n");
	}

	//��ǻ�� ����
	printf("��ǻ�� ������...\n");

	srand(time(NULL));
	
	// ��ǻ�� �޼� ������ ���� ����
	computerLeftHand = rand() % 3; 
	computerRightHand = rand() % 3;

	printf("��ǻ���� ���� : ");

	// ��ǻ�� �޼� ���� �� ���
	if (computerLeftHand == (int)RockScissorsPaper::Rock)
	{
		printf("�޼�: ����");
		printf(" ");
	}
	else if (computerLeftHand == (int)RockScissorsPaper::Scissors)
	{
		printf("�޼�: ����");
		printf(" ");
	}
	else if (computerLeftHand == (int)RockScissorsPaper::Paper)
	{
		printf("�޼�: ��");
		printf(" ");
	}

	//��ǻ�� ������ ���� �� ��� 
	if (computerRightHand == (int)RockScissorsPaper::Rock)
	{
		printf("������: ����\n");	
	}
	else if (computerRightHand == (int)RockScissorsPaper::Scissors)
	{
		printf("������: ����\n");
	}
	else if (computerRightHand == (int)RockScissorsPaper::Paper)
	{
		printf("������: ��\n");
	}

	// �޼� ������ ������ ���� ��� �� ������ �Է¹ޱ�
	printf("�޼�(0) �Ǵ� ������(1)�� �����ϼ��� : \n");
	scanf_s("%d", &playerChoice);

	// ���Ἲ�� �������� ���� ���׿����ڸ� ����Ͽ� ���������� ���� (if���� ��밡��!)
	playerFinalChoice = (playerChoice == 0) ? playerLeftHand : playerRightHand;

	// ��ǻ�� ���� ������ ����
	printf("��ǻ�� ���� ������...\n");
	computerFinalChoice = rand() % 2;

	printf("���� ���� �� �ϳ�����~~~!\n");

	// �÷��̾�� ��ǻ���� ���� �������� ���� ��, ��, ���º� �����ϴ� if��
	if (playerFinalChoice == computerFinalChoice) {
		printf("�����ϴ�.");
	}
	else if ((playerFinalChoice == (int)RockScissorsPaper::Rock && computerFinalChoice == (int)RockScissorsPaper::Paper) ||
		(playerFinalChoice == (int)RockScissorsPaper::Scissors && computerFinalChoice == (int)RockScissorsPaper::Rock) ||
		(playerFinalChoice == (int)RockScissorsPaper::Paper && computerFinalChoice == (int)RockScissorsPaper::Scissors)) {
		printf("�����ϴ�.");
	}
	else {
		printf("�¸��Ͽ����ϴ�.");
	}
}

void main()
{
	lotto();
	rockScissorsPaperTakeOneOut();

}