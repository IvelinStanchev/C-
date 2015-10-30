#include <iostream>

using namespace std;

bool checkIfSumIsDividibleByThree(int digitsSum, int divider)
{
    if (digitsSum % divider == 0)
    {
        return true;
    }

    return false;
}

int main()
{
    int number;
    cin>>number;

    int digitsSum = 0;
    int currentDigit = 1;

    while(number > 0)
    {
        currentDigit = number - ((number / 10) * 10);

        digitsSum += currentDigit;

        number /= 10;
    }

    bool isDividable = checkIfSumIsDividibleByThree(digitsSum, 3);

    if (isDividable)
    {
        cout<<"The sum of the digits of the number is dividable by three"<<endl;
    }
    else
    {
        cout<<"The sum of the digits of the number is NOT dividable by three"<<endl;
    }

    return 0;
}
