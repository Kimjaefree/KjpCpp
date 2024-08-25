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
    // ���� �ϼ��� �ķ� ��� �ߺ� ������ �ȵǵ��� �ʱ�ȭ ��Ű��
    playerBingoCount = 0;

    // ���� ���� üũ
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

    // ���� ���� üũ
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

    // �밢�� ���� üũ (�»�� -> ���ϴ�)
    diagonalBingo1 = 1;
    for (int i = 0; i < 5; i++) {
        if (playerBingoBoard[i][i] != -1) {
            diagonalBingo1 = 0;
            break;
        }
    }
    if (diagonalBingo1 == 1) playerBingoCount++;

    // �밢�� ���� üũ (���� -> ���ϴ�)
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
    // ���� ���� üũ
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

    // ���� ���� üũ
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

    // �밢�� ���� üũ (�»�� -> ���ϴ�)
    diagonalBingo1 = 1;
    for (int i = 0; i < 5; i++) {
        if (computerBingoBoard[i][i] != -1) {
            diagonalBingo1 = 0;
            break;
        }
    }
    if (diagonalBingo1 == 1) computerBingoCount++;

    // �밢�� ���� üũ (���� -> ���ϴ�)
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
            return 1; // �̹� �Ҹ� ����
        }
    }
    return 0; // ���� �Ҹ��� ���� ����
}

int main() {
    srand(time(NULL));
    MakePlayerBingoBoard();
    MakeComputerBingoBoard();

    while (1) {
        printf("�÷��̾� ������\n");
        PrintPlayerBingoBoard();
        printf("\n");
        printf("��ǻ�� ������\n");
        PrintComputerBingoBoard();
        printf("\n");

        if (turn == 1) {
            printf("���� �����Դϴ�! ���ڸ� �Է��� �ּ��� (�� 1~25�� ���ڸ� �����մϴ�) : ");
            scanf_s("%d", &playerNum);
            printf("���� ���� : %d\n", playerNum);
            printf("\n");
            MarkPlayerNumber();
            CheckPlayerBingo();
            turn = -1;
        }
        else {
            do {
                computerNum = (rand() % 25) + 1;
            } while (IsComputerNumberDup(computerNum));
            printf("��ǻ���� ���� : %d\n", computerNum);
            printf("\n");
            MarkComputerNumber();
            RecordComputerNumberCalled();
            CheckComputerBingo();
            turn = 1;
        }

        if (playerBingoCount >= 3) {
            printf("�÷��̾ �¸��Ͽ����ϴ�!\n");
            break;
        }
        else if (computerBingoCount >= 3) {
            printf("��ǻ�Ͱ� �¸��Ͽ����ϴ�!\n");
            break;
        }
    }

    return 0;
}
