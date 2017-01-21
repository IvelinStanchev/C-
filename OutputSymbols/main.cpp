#include <iostream>

using namespace std;

void printDigits(char symbols[], int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        if (isdigit(symbols[i]))
        {
            cout<<symbols[i]<< "  ";
        }
    }
}

void printSmallSymbols(char symbols[], int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        if (symbols[i] >= 'a' && symbols[i] <= 'z')
        {
            cout<<symbols[i]<< "  ";
        }
    }
}

void printOtherSymbols(char symbols[], int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        if ((symbols[i] < 'a' || symbols[i] > 'z') && !isdigit(symbols[i]))
        {
            cout<<symbols[i]<< "  ";
        }
    }
}

int main()
{
    int n;
    cout<<"n [1, 100]: ";
    cin>>n;

    if (n < 1 || n > 100)
    {
        cout<<"n should be between 1 and 100"<<endl;
    }
    else
    {
        char symbols[n];

        for (int i = 0; i < n; i++)
        {
            cin>>symbols[i];
        }

        cout<<endl;
        cout<<"Digits: ";
        printDigits(symbols, n);
        cout<<endl;

        cout<<"Small Symbols: ";
        printSmallSymbols(symbols, n);
        cout<<endl;

        cout<<"Other Symbols: ";
        printOtherSymbols(symbols, n);
        cout<<endl;
    }

    return 0;
}
