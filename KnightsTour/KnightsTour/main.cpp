#include<iostream>

using namespace std;

const int possibleMoves = 8;

int getNumberCharactersCount(int number) {
    int returnValue = 1;

    if (number < 10) {
        returnValue = 1;
    } else if (number < 100) {
        returnValue = 2;
    } else if (number < 1000) {
        returnValue = 3;
    }

    return returnValue;
}

typedef struct chess_moves {
    int x, y;
}chess_moves;

void printTour(int **tour, int N) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {

            //print spaces
            if (getNumberCharactersCount(tour[i][j]) == (getNumberCharactersCount(N * N) - 1)) {
                cout<<" ";
            } else if (getNumberCharactersCount(tour[i][j]) == (getNumberCharactersCount(N * N) - 2)) {
                cout<<"  ";
            }

            cout<<tour[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

void printZeroTour(int N) {
    int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout<<"0"<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
}

bool isMovePossible(chess_moves next_move, int **tour, int N) {
    int i = next_move.x;
    int j = next_move.y;
    if ((i >= 0 && i < N) && (j >= 0 && j < N) && (tour[i][j] == 0)) {
        return true;
    }

    return false;
}

bool findTour(int **tour, chess_moves move_KT[],
               chess_moves curr_move, int move_count, int N) {
   int i;
   chess_moves next_move;
   //cout<<move_count<<endl;
   if (move_count == N*N) {
      return true;
   }

   for (i = 0; i < possibleMoves; i++) {
      next_move.x = curr_move.x + move_KT[i].x;
      next_move.y = curr_move.y + move_KT[i].y;

      if (isMovePossible(next_move, tour, N)) {
         tour[next_move.x][next_move.y] = move_count + 1;
         if (findTour(tour, move_KT, next_move, move_count + 1, N) == true) {
            return true;
         } else {
            tour[next_move.x][next_move.y] = 0;
         }
      }
   }
   return false;
}

void knightTour(int startX, int startY, int N) {
    int **tour;
    tour = new int *[N];
    int i,j;

    for (i = 0; i < N; i++) {
        tour[i] = new int[N];

        for (j = 0; j < N; j++) {
         tour[i][j] = 0;
        }
    }

    tour[startX][startY] = 1;

    //all possible moves that knight can take
    chess_moves move_KT[possibleMoves] = { {2,1},{1,2},{-1,2},{-2,1},
                              {-2,-1},{-1,-2},{1,-2},{2,-1} };


    chess_moves curr_move = {startX,startY};

    if(findTour(tour, move_KT, curr_move, 1, N) == false) {
        printZeroTour(N);
    } else {
        printTour(tour, N);
    }
}

int main() {
    int startX, startY, N;

    while(cin>>N>>startX>>startY) {
        if (startX > N || startY > N) {
            printZeroTour(N);
        } else if (startX <= 0 || startY <= 0) {
            printZeroTour(N);
        } else if (N < 4) {
            printZeroTour(N);
        } else {
            knightTour(N - startX, startY - 1, N);
        }
    }

    return 0;
}
