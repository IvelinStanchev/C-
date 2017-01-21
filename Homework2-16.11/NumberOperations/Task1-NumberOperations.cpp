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

void printSumOfFirstAndLastDigits(int number, int digits[], int digitsCount)
{
    int sum = 0;

    sum += digits[digitsCount - 1] + digits[0];

    cout<<"The sum of the first and last digit of the number "<<number<<" is: "<<sum * 2<<endl;
}

void printChangedNumber(int number, int digits[], int digitsCount)
{
    int digitsCopy[digitsCount - 1];
    int newNumber = 0;

    for (int i = 0; i < digitsCount; i++)
    {
        digitsCopy[i] = digits[i];
    }

    for (int i = digitsCount - 1; i >= 0; i--)
    {
        if (digitsCopy[i] % 3 == 0)
        {
            digitsCopy[i] /= 3;
        }
        else
        {
            if (digitsCopy[i] % 2 == 0)
            {
                digitsCopy[i] += 1;
            }
            else
            {
                digitsCopy[i] += 2;
            }
        }

        newNumber += digitsCopy[i] * intPow(10, i);
    }

    cout<<"The changed number "<<number<<" is: "<<newNumber<<endl;
}

void printBiggerThanOriginalAndReversedNumber(int number, int digits[], int digitsCount)
{
    int reversedNumber = 0;

    for (int i = 0; i < digitsCount; i++)
    {
        reversedNumber += digits[i] * intPow(10, digitsCount - 1 - i);
    }


    if (reversedNumber > number)
    {
        cout<<"The bigger number of the numbers "<<number<<" and "<<reversedNumber<<" is "<<reversedNumber<<endl;
    }
    else if (reversedNumber < number)
    {
        cout<<"The bigger number of the numbers "<<number<<" and "<<reversedNumber<<" is "<<number<<endl;
    }
    else
    {
        cout<<"The number "<<number<<" and "<<reversedNumber<<" are the same"<<endl;
    }

}

int main()
{
    int number;
    cout<<"Enter your number bigger than 0: ";
    cin>>number;

    if (number <= 0)
    {
        cout<<"The number should be positive";
    }
    else
    {
        int digits[20];
        int digitsCount = 0;
        int numberCopy = number;

        while (numberCopy > 0)
        {
            digits[digitsCount] = numberCopy % 10;
            numberCopy /= 10;
            digitsCount++;
        }

        //Task A
        if (digitsCount < 2)
        {
            cout<<"There is no last digit. The entered number has only one digit"<<endl;
        }
        else
        {
            printSumOfFirstAndLastDigits(number, digits, digitsCount);
        }

        //Task B
        printChangedNumber(number, digits, digitsCount);

        //Task C
        printBiggerThanOriginalAndReversedNumber(number, digits, digitsCount);








    }

    return 0;
}
