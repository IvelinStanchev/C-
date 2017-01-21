#include <iostream>

using namespace std;

void printNumber(int n, int base, int powers[], int index, int difference)
{
    if (index == 0)
    {
        cout<<difference / powers[index];
        return;
    }

    cout<<difference / powers[index];

    return printNumber(n, base, powers, index - 1, n - ((n / powers[index]) * powers[index]));
}

int main()
{
    int n;
    int base;

    cin>>n;
    cin>>base;

    int powersSize = 0;
    int currentPower = 1;
    int powers[100];

    while (currentPower < n)
    {
        powers[powersSize] = currentPower;
        currentPower *= base;
        powersSize++;;
    }

    printNumber(n, base, powers, powersSize - 1, n);

    return 0;
}
