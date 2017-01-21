#include <iostream>

using namespace std;

#define MAXN 150

unsigned N = 1;
unsigned A[MAXN][MAXN];

const int MAX_VALUE = 10000;

unsigned T[MAXN], d[MAXN];
int pred[MAXN];

void dijkstra(unsigned s) {
    unsigned i;
    for (i = 0; i < N; i++) {
        if (A[s][i] == 0) {
            d[i] = MAX_VALUE;
            pred[i] = -1;
        }
        else {
            d[i] = A[s][i];
            pred[i] = s;
        }
    }

    for (i = 0; i < N; i++) {
        T[i] = 1;
    }

    T[s] = 0;
    pred[s] = -1;

    while (true) {
        int j = -1;
        int di = MAX_VALUE;

        for (i = 0; i < N; i++) {
            if (T[i] && d[i] < di) {
                di = d[i];
                j = i;
            }
        }

        if (j == -1) {
            break;
        }

        T[j] = 0;

        for (i = 0; i < N; i++) {
            if (T[i] && A[j][i] != 0) {
                if (d[i] > d[j] + A[j][i]) {
                    d[i] = d[j] + A[j][i];
                    pred[i] = j;
                }
            }
        }
    }
}

void printResult(unsigned s) {
    unsigned i;
    for (i = 0; i < N; i++) {
        if (i != s) {
            if (d[i] == MAX_VALUE) {
                cout<<"-1 ";
            }
            else {
                cout<<d[i]<<" ";
            }
        } else {
            cout<<"0 ";
        }
    }
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
        }

        N = max;
        for (int i = 1; i <= N; i++) {
            dijkstra(i-1);
            printResult(i-1);
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
