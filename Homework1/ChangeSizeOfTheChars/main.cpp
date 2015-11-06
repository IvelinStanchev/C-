#include <iostream>

using namespace std;

int main()
{
    char symbols[100];
    char newSymbols[100];

    cout<<"Enter the word: ";
    cin>>symbols;

    int index = 0;
    while (symbols[index] != '\0')
    {
        cout<<symbols[index];

        if (isupper(symbols[index]) && isalpha(symbols[index]))
        {
            newSymbols[index] = (char) ((int) symbols[index] + 32);
        }
        else if (!isupper(symbols[index]) && isalpha(symbols[index]))
        {
            newSymbols[index] = (char) ((int) symbols[index] - 32);
        }
        else
        {
            newSymbols[index] = symbols[index];
        }

        index++;
    }

    cout<<" -> ";

    for (int i = 0; i < index; i++)
    {
        cout<<newSymbols[i];
    }

    return 0;
}
