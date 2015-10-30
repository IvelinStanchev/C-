#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int findNewNumber(int n, int k)
{
    stack<int> digits;

    int digitsCount = 0;
    while(n > 0)
    {
        int currentDigit = n - ((n / 10) * 10);

        digitsCount++;

        if (digitsCount != k)
        {
            digits.push(currentDigit);
        }

        n /= 10;
    }

    if (digits.size() == 0)
    {
        return 0;
    }
    else
    {
        int newNumber = 0;
        int currentDigit = 1;

        while (digits.size() > 0)
        {
            currentDigit = digits.top();
            newNumber += currentDigit * pow(10, digits.size() - 1);
            digits.pop();
        }

        return newNumber;
    }
}

int main()
{
    int n, k;

    cout<<"N: ";
    cin>>n;
    cout<<"K: ";
    cin>>k;

    int newNumber = findNewNumber(n, k);

    cout<<"The new number is: "<<newNumber<<endl;

    return 0;
}
