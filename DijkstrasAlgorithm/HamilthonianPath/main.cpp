#include <iostream>
#include <stdio.h>

using namespace std;

#define MAXN 150

unsigned n = 1;
int A[MAXN][MAXN];

const int MAX_VALUE = 10000;

char used[MAXN];
unsigned minCycle[MAXN], cycle[MAXN];
int curSum, minSum;

void printCycle(void) {
    if (minCycle[0] + 1 == 1) {
        printf("-1");
    } else {
        unsigned i;
        printf("1");
        for (i = 0; i < n - 1; i++) {
            printf(" %u", minCycle[i] + 1);
        }
    }
}

void hamilton(unsigned i, unsigned level) {
    unsigned k;
    if ((0 == i) && (level > 0)) {
        if (level == n) {
            minSum = curSum;
            for (k = 0; k < n; k++) {
                minCycle[k] = cycle[k];
            }
        }

        return;
    }

    if (used[i]) {
        return;
    }

    used[i] = 1;
    for (k = 0; k < n; k++) {
        if (A[i][k] && k != i) {
            cycle[level] = k;
            curSum += A[i][k];
            if (curSum < minSum) {
                hamilton(k, level + 1);
            }

            curSum -= A[i][k];
        }
    }

    used[i] = 0;
}

int main(void) {
    int graphPathsCount;
    int from, to, pathWeight;
    int maxFrom, maxTo, max;

    while (cin>>graphPathsCount) {
        maxFrom = 0, maxTo = 0, max = 0;

        for (int j = 0; j < MAXN; j++) {
            for (int k = 0; k < MAXN; k++) {
                A[j][k] = 0;
            }
        }

        for (int i = 0; i < graphPathsCount; i++) {
            cin>>from>>to>>pathWeight;

            if (from > maxFrom) {
                maxFrom = from;
            }
            if (to > maxTo) {
                maxTo = to;
            }
            if (maxFrom > max) {
                max = maxFrom;
            }
            if (maxTo > max) {
                max = maxTo;
            }

            A[from - 1][to - 1] = pathWeight;
            A[to - 1][from - 1] = pathWeight;
        }

        n = max;
        unsigned k;
        for (k = 0; k < n; k++) {
            used[k] = 0;
            minCycle[k] = 0;
        }

        minSum = MAX_VALUE;
        curSum = 0;
        cycle[0] = 1;
        hamilton(0, 0);
        printCycle();
        cout<<endl;
    }

    return 0;
}
