#include <iostream>

using namespace std;

int playerBingoBoard[5][5] = { {0}, {0} };
int computerBingoBoard[5][5] = { {0}, {0} };
int numbers[25] = { 0 };
int playerNum, computerNum = 0;
int rowBingo, colBingo, diagonalBingo1, diagonalBingo2 = 1;
int playerBingoCount, computerBingoCount = 0;
int turn = 1;
int isComputerNumberCalled[25] = { 0 };

void MakePlayerBingoBoard() {
    for (int i = 0; i < 25; i++) {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < 25; i++) {
        int randomNum = rand() % 25;
        int temp = numbers[i];
        numbers[i] = numbers[randomNum];
        numbers[randomNum] = temp;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            playerBingoBoard[i][j] = numbers[(i * 5) + j];
        }
    }
}

void MakeComputerBingoBoard() {
    for (int i = 0; i < 25; i++) {
        numbers[i] = i + 1;
    }

    for (int i = 0; i < 25; i++) {
        int randomNum = rand() % 25;
        int temp = numbers[i];
        numbers[i] = numbers[randomNum];
        numbers[randomNum] = temp;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            computerBingoBoard[i][j] = numbers[(i * 5) + j];
        }
    }
}

void PrintPlayerBingoBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (playerBingoBoard[i][j] == -1) {
                printf(" X ");
            }
            else {
                printf("%2d ", playerBingoBoard[i][j]);
            }
        }
        printf("\n");
    }
}

void PrintComputerBingoBoard() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (computerBingoBoard[i][j] == -1) {
                printf(" X ");
            }
            else {
                printf("%2d ", computerBingoBoard[i][j]);
            }
        }
        printf("\n");
    }
}

void MarkPlayerNumber() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (playerBingoBoard[i][j] == playerNum) {
                playerBingoBoard[i][j] = -1;
            }
        }
    }
}

void MarkComputerNumber() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (computerBingoBoard[i][j] == computerNum) {
                computerBingoBoard[i][j] = -1;
            }
        }
    }
}

void CheckPlayerBingo() {
    // 빙고가 완성된 후로 계속 중복 증감이 안되도록 초기화 시키기
    playerBingoCount = 0;

    // 가로 빙고 체크
    for (int i = 0; i < 5; i++) {
        rowBingo = 1;
        for (int j = 0; j < 5; j++) {
            if (playerBingoBoard[i][j] != -1) {
                rowBingo = 0;
                break;
            }
        }
        if (rowBingo == 1) playerBingoCount++;
    }

    // 세로 빙고 체크
    for (int j = 0; j < 5; j++) {
        colBingo = 1;
        for (int i = 0; i < 5; i++) {
            if (playerBingoBoard[i][j] != -1) {
                colBingo = 0;
                break;
            }
        }
        if (colBingo == 1) playerBingoCount++;
    }

    // 대각선 빙고 체크 (좌상단 -> 우하단)
    diagonalBingo1 = 1;
    for (int i = 0; i < 5; i++) {
        if (playerBingoBoard[i][i] != -1) {
            diagonalBingo1 = 0;
            break;
        }
    }
    if (diagonalBingo1 == 1) playerBingoCount++;

    // 대각선 빙고 체크 (우상단 -> 좌하단)
    diagonalBingo2 = 1;
    for (int i = 0; i < 5; i++) {
        if (playerBingoBoard[i][5 - i - 1] != -1) {
            diagonalBingo2 = 0;
            break;
        }
    }
    if (diagonalBingo2 == 1) playerBingoCount++;
}

void CheckComputerBingo() {
    computerBingoCount = 0;
    // 가로 빙고 체크
    for (int i = 0; i < 5; i++) {
        rowBingo = 1;
        for (int j = 0; j < 5; j++) {
            if (computerBingoBoard[i][j] != -1) {
                rowBingo = 0;
                break;
            }
        }
        if (rowBingo == 1) computerBingoCount++;
    }

    // 세로 빙고 체크
    for (int j = 0; j < 5; j++) {
        colBingo = 1;
        for (int i = 0; i < 5; i++) {
            if (computerBingoBoard[i][j] != -1) {
                colBingo = 0;
                break;
            }
        }
        if (colBingo == 1) computerBingoCount++;
    }

    // 대각선 빙고 체크 (좌상단 -> 우하단)
    diagonalBingo1 = 1;
    for (int i = 0; i < 5; i++) {
        if (computerBingoBoard[i][i] != -1) {
            diagonalBingo1 = 0;
            break;
        }
    }
    if (diagonalBingo1 == 1) computerBingoCount++;

    // 대각선 빙고 체크 (우상단 -> 좌하단)
    diagonalBingo2 = 1;
    for (int i = 0; i < 5; i++) {
        if (computerBingoBoard[i][5 - i - 1] != -1) {
            diagonalBingo2 = 0;
            break;
        }
    }
    if (diagonalBingo2 == 1) computerBingoCount++;
}

void RecordComputerNumberCalled() {
    for (int i = 0; i < 25; i++) {
        if (isComputerNumberCalled[i] == 0) {
            isComputerNumberCalled[i] = computerNum;
            break;
        }
    }
}

int IsComputerNumberDup(int num) {
    for (int i = 0; i < 25; i++) {
        if (isComputerNumberCalled[i] == num) {
            return 1; // 이미 불린 숫자
        }
    }
    return 0; // 아직 불리지 않은 숫자
}

int main() {
    srand(time(NULL));
    MakePlayerBingoBoard();
    MakeComputerBingoBoard();

    while (1) {
        printf("플레이어 빙고판\n");
        PrintPlayerBingoBoard();
        printf("\n");
        printf("컴퓨터 빙고판\n");
        PrintComputerBingoBoard();
        printf("\n");

        if (turn == 1) {
            printf("나의 차례입니다! 숫자를 입력해 주세요 (단 1~25의 숫자만 가능합니다) : ");
            scanf_s("%d", &playerNum);
            printf("나의 선택 : %d\n", playerNum);
            printf("\n");
            MarkPlayerNumber();
            CheckPlayerBingo();
            turn = -1;
        }
        else {
            do {
                computerNum = (rand() % 25) + 1;
            } while (IsComputerNumberDup(computerNum));
            printf("컴퓨터의 선택 : %d\n", computerNum);
            printf("\n");
            MarkComputerNumber();
            RecordComputerNumberCalled();
            CheckComputerBingo();
            turn = 1;
        }

        if (playerBingoCount >= 3) {
            printf("플레이어가 승리하였습니다!\n");
            break;
        }
        else if (computerBingoCount >= 3) {
            printf("컴퓨터가 승리하였습니다!\n");
            break;
        }
    }

    return 0;
}
