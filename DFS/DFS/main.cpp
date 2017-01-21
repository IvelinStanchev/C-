#include <iostream>
#include <stdio.h>

using namespace std;

int MAXN = 1;
int v = 1;

void DFS(unsigned i, char ** A, char used[]) {
    unsigned k;
    used[i] = 1;
    printf("%u ", i + 1);
    for (k = 0; k < MAXN; k++) {
        if (A[i][k] && !used[k]) {
            DFS(k, A, used);
        }
    }
}

int main() {

    int inputCount;
    cin>>inputCount;

    MAXN = inputCount + 1;

    char **A;
    A = new char *[MAXN];

    for (int i = 0; i < MAXN; i++) {
        A[i] = new char[MAXN];
    }

    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            A[i][j] = 0;
        }
    }

    int fromVertex, toVertex;CSCB300 2016 - Домашно 7 - F84784

    for (int i = 0; i < inputCount; i++) {
        cin>>fromVertex>>toVertex;
        A[fromVertex - 1][toVertex - 1] = 1;
    }

    char used[MAXN];

    unsigned k;
    for (k = 1; k < MAXN; k++) {
        used[k] = 0;
    }

    DFS(v - 1, A, used);

    return 0;
}
