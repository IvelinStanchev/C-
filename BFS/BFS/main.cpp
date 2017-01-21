#include <iostream>
#include <stdio.h>

using namespace std;

int MAXN = 1;
int v = 1;

void BFS(unsigned i, char ** A, char used[]) {
    unsigned k, j, p, queue[MAXN], currentVert, levelVertex, queueEnd;
    for (k = 0; k < MAXN; k++) {
        queue[k] = 0;
    }

    for (k = 0; k < MAXN; k++) {
        used[k] = 0;
    }

    queue[0] = i;
    used[i] = 1;
    currentVert = 0;
    levelVertex = 1;
    queueEnd = 1;
    while (currentVert < queueEnd) {
        for (p = currentVert; p < levelVertex; p++) {
            printf("%u ", queue[p] + 1);
            currentVert++;

            for (j = 0; j < MAXN; j++) {
                if (A[queue[p]][j] && !used[j]) {
                    queue[queueEnd++] = j;
                    used[j] = 1;
                }
            }
        }

        levelVertex = queueEnd;
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

    int fromVertex, toVertex;

    for (int i = 0; i < inputCount; i++) {
        cin>>fromVertex>>toVertex;
        A[fromVertex - 1][toVertex - 1] = 1;
    }

    char used[MAXN];

    BFS(v - 1, A, used);

    return 0;
}
