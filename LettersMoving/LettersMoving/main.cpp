#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

void printCurrentMovement(string input, int number)
{
    int inputLength = input.length();
    int moves = number % inputLength;

    int counter = 0;
    int currentPosition = moves;
    string output = "";

    while (counter < inputLength)
    {
        if (currentPosition == inputLength)
        {
            currentPosition = 0;
        }

        output += input[currentPosition];

        currentPosition++;
        counter++;
    }

    cout<<output<<endl;
}

int main()
{
    string input;
    string numbersInput;
    string currentNumber = "";
    int i;

    while (cin>>input)
    {
        cin.ignore(256, '\n');
        getline(cin, numbersInput);

        i = 0;
        currentNumber = "";

        while (i < numbersInput.length())
        {
            if (!isdigit(numbersInput[i]))
            {
                printCurrentMovement(input, atoi(currentNumber.c_str()));
                currentNumber = "";
            }
            else
            {
                currentNumber += numbersInput[i];
            }

            i++;
        }

        printCurrentMovement(input, atoi(currentNumber.c_str()));
    }

    return 0;
}
