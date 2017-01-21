#include <iostream>

using namespace std;

void printString(char symbol, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout<<symbol;
    }
}

void printSandglassFigure(int n)
{
    //print top row
    printString('*', n);
    cout<<endl;

    //print top part
    for (int i = 0; i < n / 2 - 1; i++)
    {
        printString(' ', i + 1);

        cout<<"*";

        printString(' ', n  - 4 - 2*i);

        cout<<"*";

        cout<<endl;
    }

    printString(' ', n / 2);
    cout<<"*";
    printString(' ', n / 2);
    cout<<endl;
    printString(' ', n / 2);
    cout<<"*";
    printString(' ', n / 2);
    cout<<endl;

    //print bottom part
    for (int i = 0; i < n / 2 - 1; i++)
    {
        printString(' ', n / 2  - i - 1);

        cout<<"*";

        printString(' ', 2 * i + 1);

        cout<<"*"<<endl;
    }

    //print bottom row
    printString('*', n);
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    if (n % 2 != 0)
    {
        printSandglassFigure(n);
    }
    else
    {
        cout<<"n must be odd"<<endl;
    }

    return 0;
}
