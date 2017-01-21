#include <iostream>

using namespace std;

int getIntFromHexChar(char hexChar)
{
    switch(hexChar)
    {
        case 'A':
            return 10;
            break;
        case 'B':
            return 11;
            break;
        case 'C':
            return 12;
            break;
        case 'D':
            return 13;
            break;
        case 'E':
            return 14;
            break;
        case 'F':
            return 15;
            break;

        default:
            return (int) hexChar - '0';
            break;
    }
}

int eighteen2ten(string s)
{
    int m = 0;
    for (int i = 0; i < s.length(); i++)
    {
        m = 16 * m + getIntFromHexChar(s[i]);
    }

    return m;
}

int eight2ten(string s)
{
    int m = 0;
    for (int i = 0; i < s.length(); i++)
    {
        m = 8 * m + (s[i] - '0');
    }

    return m;
}

int two2ten(string s)
{
    int m = 0;
    for (int i = 0; i < s.length(); i++)
    {
        m = 2 * m + (s[i] - '0');
    }

    return m;
}

int main()
{
    int k;
    string s;

    while (cin >> k)
    {
        cin >> s;

        if (k == 2)
        {
            cout<<two2ten(s);
        }
        else if (k == 8)
        {
            cout<<eight2ten(s);
        }
        else if (k == 16)
        {
            cout<<eighteen2ten(s);
        }

        cout << endl;
    }

    return 0;
}
