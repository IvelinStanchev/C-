#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
    int as[5];
    char bs[5];

    int name;
    char rent;

    ifstream infile;
    infile.open ("symbol.in");
    int currentLine = 0;
    while(infile >> name >> rent){
        as[currentLine] = name;
        bs[currentLine] = rent;
        currentLine++;
    }

    infile.close();

    int minA = as[0];
    int minIndex = 0;
    for (int i = 0; i < 5; i++){
        minA = as[i];
        minIndex = i;

        for (int j = i + 1; j < 5; j++){
            if (as[j] < minA){
                minA = as[j];
                minIndex = j;
            }
        }

        int swap = as[i];
        as[i] = as[minIndex];
        as[minIndex] = swap;

        char swapChar = bs[i];
        bs[i] = bs[minIndex];
        bs[minIndex] = swapChar;
    }

    string output = "";
    for (int i = 0; i < 5; i++){
        if (i < 4 && as[i] == as[i + 1]){
            if (int(bs[i]) > int(bs[i + 1])){
                char swapChar = bs[i];
                bs[i] = bs[i + 1];
                bs[i + 1] = swapChar;
            }
        }

        for (int j = 0; j < as[i]; j++){
            output += bs[i];
        }

        output += "\n";
    }

    ofstream myfile;
      myfile.open ("symbol.out");
      myfile << output;
      myfile.close();

    return 0;
}
