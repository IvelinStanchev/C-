#include <iostream>

using namespace std;

bool checkIfSymmetric(char symbols[], int elementsCount)
{
    for (int i = 0; i < elementsCount / 2; i++)
    {
        if (symbols[i] != symbols[elementsCount - i - 1])
        {
            return false;
        }
    }

    return true;
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

        bool isSymmetric = checkIfSymmetric(symbols, n);

        if (isSymmetric)
        {
            cout<<"The sequence is symmetric"<<endl;
        }
        else
        {
            cout<<"The sequence is NOT symmetric"<<endl;
        }
    }

    return 0;
}
