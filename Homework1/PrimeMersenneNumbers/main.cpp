#include <iostream>
#include <math.h>

using namespace std;

void calculatePrimeNumbers (bool used[], int endBoundary)
{
    for (int j = 2; j <= endBoundary; j++)
    {
        used[j] = 0;
    }

    for (int i = 2; i < sqrt(endBoundary); i++)
    {
        for (int j = i * 2; j <= endBoundary; j += i)
        {
            if (!used[j])
            {
                used[j] = 1;
            }
        }
    }
}

bool isMersenneNumber(int number)
{
    int originalNumber = number + 1;

    while ((originalNumber > 1) && (originalNumber % 2 == 0))
    {
        originalNumber /= 2;
    }

    return originalNumber == 1;
}

void printAllPrimeMersenneNumbers(int startBoundary, int endBoundary, bool used[])
{
    for (int i = startBoundary; i <= endBoundary; i++)
    {
        if (isMersenneNumber(i) && !used[i])
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    int startBoundary = 1;
    int endBoundary = 65535;

    bool used[endBoundary];

    calculatePrimeNumbers(used, endBoundary);

    printAllPrimeMersenneNumbers(startBoundary, endBoundary, used);

    return 0;
}
