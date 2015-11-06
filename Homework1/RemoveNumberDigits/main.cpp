#include <iostream>

using namespace std;

int intPow(int base, int power)
{
    int result = 1;

    for (int i = 1; i <= power; i++)
    {
        result *= base;
    }

    return result;
}

bool isFullfillingTheCondition(int baseNumber, int digits[], int digitsCount)
{
    int currentNumber;
    int currentPower;

    for (int i = digitsCount - 1; i >= 0; i--)
    {
        currentNumber = 0;
        currentPower = digitsCount - 2;

        for (int j = digitsCount - 1; j >= 0 ; j--)
        {
            if (i != j)
            {
                currentNumber += digits[j] * intPow(10, currentPower);
                currentPower--;
            }
        }

        if (currentNumber * 9 == baseNumber && currentNumber % 9 == 0)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n;
    int digits[20];
    int digitsCount = 0;

    cout<<"N: ";
    cin>>n;

    if (n <= 0)
    {
       cout<<"The number should be bigger than 0"<<endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            int currentNumber = i;
            while (currentNumber > 0)
            {
                digits[digitsCount] = currentNumber % 10;
                currentNumber /= 10;
                digitsCount++;
            }

            if(isFullfillingTheCondition(i, digits, digitsCount))
            {
                cout<<i<<endl;
            }

            digitsCount = 0;
        }
    }

    return 0;
}
