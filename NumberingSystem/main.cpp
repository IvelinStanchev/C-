#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void printCurrentSymbol(int currentDigit)
{
    switch(currentDigit)
    {
        case 10:
            cout<<"A";
            break;
        case 11:
            cout<<"B";
            break;
        case 12:
            cout<<"C";
            break;
        case 13:
            cout<<"D";
            break;
        case 14:
            cout<<"E";
            break;
        case 15:
            cout<<"F";
            break;
        case 16:
            cout<<"G";
            break;
        case 17:
            cout<<"H";
            break;
        case 18:
            cout<<"I";
            break;
        case 19:
            cout<<"J";
            break;
        case 20:
            cout<<"K";
            break;
        case 21:
            cout<<"L";
            break;
        case 22:
            cout<<"M";
            break;
        case 23:
            cout<<"N";
            break;
        case 24:
            cout<<"O";
            break;
        case 25:
            cout<<"P";
            break;
        case 26:
            cout<<"Q";
            break;
        case 27:
            cout<<"R";
            break;
        case 28:
            cout<<"S";
            break;
        case 29:
            cout<<"T";
            break;
        case 30:
            cout<<"U";
            break;
        case 31:
            cout<<"V";
            break;
        case 32:
            cout<<"W";
            break;
        case 33:
            cout<<"X";
            break;
        case 34:
            cout<<"Y";
            break;
        case 35:
            cout<<"Z";
            break;
    }
}

void printNewNumber(int n, int base)
{
    stack<int> powersOfBase;

    int power = 1;
    while(power <= n)
    {
        powersOfBase.push(power);
        power *= base;
    }

    while(powersOfBase.size() > 0)
    {
        int currentPower = powersOfBase.top();
        int currentDigit = n / currentPower;
        int currentDifference = n - (currentDigit * currentPower);

        n = currentDifference;
        if (base > 10)
        {
            if (currentDigit > 9)
            {
                printCurrentSymbol(currentDigit);
            }
            else
            {
                cout<<currentDigit;
            }
        }
        else
        {
            cout<<currentDigit;
        }

        powersOfBase.pop();
    }
}

int main()
{
    int n, base;
    cout<<"Enter decimal number: ";
    cin>>n;
    cout<<"Enter base: ";
    cin>>base;

    printNewNumber(n, base);

    return 0;
}
