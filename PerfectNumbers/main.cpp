#include <iostream>
#include <math.h>

using namespace std;

bool isPerfect(int number)
{
    int divisorsSum = 1;
    for (int i = 2; i <= sqrt(number); i++){
        if (number % i == 0)
        {
            divisorsSum += i;
            divisorsSum += number / i;
        }
    }

    if (divisorsSum == number)
    {
        return true;
    }

    return false;
}

void printAllPerfectNumbers(int boundary)
{
    for (int i = 2; i <= boundary; i++)
    {
        if (isPerfect(i))
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    int boundary;
    cout<<"Enter boundary: ";
    cin>>boundary;

    printAllPerfectNumbers(boundary);
    return 0;
}
