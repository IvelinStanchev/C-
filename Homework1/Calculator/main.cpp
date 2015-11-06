#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a, b;
    char operation;
    bool isValidOperation = true;

    cout<<"Enter first number: ";
    cin>>a;
    cout<<"Enter operation: ";
    cin>>operation;
    cout<<"Enter second number: ";
    cin>>b;

    double result;
    double isInCompareMode = false;
    double compareResult = false;

    switch (operation)
    {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '/':
            result = a / b;
            break;
        case '*':
            result = a * b;
            break;
        case '^':
            result = pow(a, b);
            break;
        case '<':
            isInCompareMode = true;

            if (a < b)
            {
                compareResult = true;
            }

            break;
        case '>':
            isInCompareMode = true;

            if (a > b)
            {
                compareResult = true;
            }

            break;
        case '=':
            isInCompareMode = true;

            if (a == b)
            {
                compareResult = true;
            }

            break;
        default:
            isValidOperation = false;
            break;
    }

    if (!isValidOperation)
    {
        cout<<"Invalid operation!";
    }
    else
    {
        if (isInCompareMode)
        {
            if (compareResult)
            {
                cout<<a<<" "<<operation<<" "<<b<<" = "<<"TRUE";
            }
            else
            {
                cout<<a<<" "<<operation<<" "<<b<<" = "<<"FALSE";
            }
        }
        else
        {
            cout<<a<<" "<<operation<<" "<<b<<" = "<<result;
        }
    }

    return 0;
}
