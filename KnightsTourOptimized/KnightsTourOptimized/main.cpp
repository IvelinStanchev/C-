#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAXN 10
#define MAXD 10

int n;
int startX;
int startY;
const unsigned maxDiff = 8;
const int diffX[MAXD] = { 1, 1, -1, -1, 2, -2, 2, -2 };
const int diffY[MAXD] = { 2, -2, 2, -2, 1, 1, -1, -1 };

unsigned board[MAXN][MAXN];
unsigned newX, newY;

bool printed = false;

void printBoard(void) {
    unsigned i, j;
    for (i = n; i > 0; i--) {
        for (j = 0; j < n; j++) {
            printf("%3u", board[i-1][j]);
        }
        printf("\n");
    }

    printf("\n");
    printed = true;
}

void printZeroTour(int N) {
    unsigned i, j;
    for (i = n; i > 0; i--) {
        for (j = 0; j < n; j++) {
            printf("%3u", 0);
        }
        printf("\n");
    }

    printf("\n");
}

void nextMove(unsigned X, unsigned Y, unsigned i) {
    unsigned k;
    board[X][Y] = i;
    if (i == n * n) {
        printBoard();
        return;
    }

    if (!printed) {
        for (k = 0; k < maxDiff; k++) {
            newX = X + diffX[k];
            newY = Y + diffY[k];

            if ((newX >= 0 && newX < n && newY >= 0 && newY < n) && (0 == board[newX][newY])) {
                nextMove(newX, newY, i + 1);
            }
        }
        board[X][Y] = 0;
    }
}

int main() {
    while(cin>>n>>startX>>startY) {
        printed = false;

        if (startX > n || startY > n) {
            printZeroTour(n);
        } else if (startX <= 0 || startY <= 0) {
            printZeroTour(n);
        } else if (n < 4) {
            printZeroTour(n);
        } else {
            unsigned i, j;
            for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) board[i][j] = 0;
            nextMove(startX-1, startY-1, 1);

            if (!printed) {
                printZeroTour(n);
            }
        }
    }

    return 0;
}
