#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

void calculatePrimeNumbers(int n, bool used[])
{
    //0 and 1 are not prime
    used[0] = 1;
    used[1] = 1;

    for (int j = 2; j <= n; j++)
    {
        used[j] = 0;
    }

    for (int i = 2; i < sqrt(n); i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            if (!used[j])
            {
                used[j] = 1;
            }
        }
    }
}

int main()
{
    int maxN = 1001;

    bool primeNumbersUsed[maxN];
    calculatePrimeNumbers(maxN, primeNumbersUsed);

    int s;
    int N;
    string input;
    int i;
    int inputNumbers[3];
    int arrayCounter;
    int currentNumber;
    int base;

    long long int counter;
    int currentRandomNumber;

    while (getline(cin, input))
    {
        i = input.length() - 1;

        arrayCounter = 0;
        currentNumber = 0;
        base = 1;

        while (i >= 0)
        {
            if (!isdigit(input[i]))
            {
                inputNumbers[arrayCounter] = currentNumber;
                currentNumber = 0;
                base = 1;
                arrayCounter++;

            }
            else
            {
                currentNumber += ((int) input[i] - 48) * base;
                base *= 10;
            }

            if (i == 0)
            {
                inputNumbers[arrayCounter] = currentNumber;
            }

            i--;
        }

        s = inputNumbers[1];
        N = inputNumbers[0];

        srand(s);

        counter = 0;
        for (int i = 0; i < N; i++)
        {
            currentRandomNumber = rand() % (maxN - 1);

            if (!primeNumbersUsed[currentRandomNumber])
            {
                counter++;
            }
        }

        cout<<counter<<endl;
    }

    return 0;
}
