#include <iostream>

using namespace std;

int getLastDigit(int n)
{
    return n % 10;
}

bool isMonotonicallyDecreasingSequence(int n)
{
    if (n < 10)
    {
        return true;
    }

    int currentDigit = n % 10;

    return (currentDigit <= getLastDigit(n / 10)) ? isMonotonicallyDecreasingSequence(n / 10) : false;
}

int main()
{
    int a, b;
    cin>>a>>b;

    int counterOfMonotonicallyDecreasingSequences = 0;

    for (int i = a; i <= b; i++)
    {
        if (isMonotonicallyDecreasingSequence(i))
        {
            counterOfMonotonicallyDecreasingSequences++;
        }
    }

    cout<<counterOfMonotonicallyDecreasingSequences<<endl;

    return 0;
}
