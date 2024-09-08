#pragma once

class MainGame
{
public:
	void Init(); // �ʱ�ȭ
	void Update(); // ���ӽ���
	void Release(); // ����
	void ShuffleCard(); // 2��
	void HandPlayerCard(); // 3��
	void HandComputerCard(); // 3��
	void CardCheck(int cardNum, int cardType); // 4��
	void CalculatePlayerCardRank(); // 5��
	void CalculateComputerCardRank(); // 5��
	void CompareCards(); // 6��

public:
	int _entireCard[13] = {0};
	char _cardType[4] = {0};
	int _playerCard1 = 0;
	int _playerCard2 = 0;
	int _computerCard1= 0;
	int _computerCard2 = 0;
	int playerRank = 0;
	int computerRank = 0;
	bool isGameEnd = true;
};

// ���� �������� ����
// 1. ���� ���忡 ���� ȯ�� �λ�!
// 2. ī�� ����
// 3. ī�� �����ֱ�
// 4. ���� ī�� ����ϱ�
// 5. ���� Ȯ�������ֱ�
// 6. ������ ī�� ���ϱ�
