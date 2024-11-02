#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status { CONTINUE, WON, LOST };

// �ŧi rollDice ���
int rollDice(void);

int main(void) {
    int sum;
    int myPoint;
    enum Status gameStatus;

    srand(time(NULL)); // ��l���H���ƥͦ���
    sum = rollDice();

    // �P�_��l��l���G
    switch (sum) {
    case 7:
    case 11:
        gameStatus = WON;
        break;
    case 2:
    case 3:
    case 12:
        gameStatus = LOST;
        break;
    default:
        gameStatus = CONTINUE;
        myPoint = sum;
        printf("Point is %d\n", myPoint);
        break;
    }

    // ��C�����A�� CONTINUE �ɶi��j��
    while (gameStatus == CONTINUE) {
        sum = rollDice();

        if (sum == myPoint) {
            gameStatus = WON;
        }
        else if (sum == 7) {
            gameStatus = LOST;
        }

        if (gameStatus == WON) {
            printf("Player wins\n");
        }
        else if (gameStatus == LOST) {
            printf("Player loses\n");
        }
    }

    return 0;
}

// �w�q rollDice ���
int rollDice(void) {
    int die1 = 1 + (rand() % 6);
    int die2 = 1 + (rand() % 6);
    int workSum = die1 + die2;

    printf("Player rolled %d + %d = %d\n", die1, die2, workSum);
    return workSum;
}
