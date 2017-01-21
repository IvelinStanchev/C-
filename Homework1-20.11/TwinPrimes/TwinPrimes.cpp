#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int number)
{
    if (number == 1)
    {
        return false;
    }

    if (number == 2)
    {
        return true;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool areTwinPrimes(int firstNumber, int secondNumber)
{
    if ((firstNumber + 2 == secondNumber) && isPrime(firstNumber) && isPrime(secondNumber))
    {
        return true;
    }

    return false;
}

int main()
{
    int a, b;
    cin>>a>>b;

    if (areTwinPrimes(a, b))
    {
        cout<<"The numbers "<<a<<" and "<<b<<" are twin primes"<<endl;
    }
    else
    {
        cout<<"The numbers "<<a<<" and "<<b<<" are NOT twin primes"<<endl;
    }

    return 0;
}
