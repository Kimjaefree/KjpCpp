#pragma once

class MainGame
{
public:
	void Init(); // 초기화
	void Update(); // 게임실행
	void Release(); // 삭제
	void ShuffleCard(); // 2번
	void HandPlayerCard(); // 3번
	void HandComputerCard(); // 3번
	void CardCheck(int cardNum, int cardType); // 4번
	void CalculatePlayerCardRank(); // 5번
	void CalculateComputerCardRank(); // 5번
	void CompareCards(); // 6번

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

// 섯다 게임진행 순서
// 1. 게임 입장에 대한 환영 인사!
// 2. 카드 섞기
// 3. 카드 나눠주기
// 4. 뽑은 카드 출력하기
// 5. 족보 확정시켜주기
// 6. 서로의 카드 비교하기
