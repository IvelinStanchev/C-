#include <iostream>

using namespace std;

int fib(int index)
{
    if (index == 0)
    {
        return 0;
    }

    if (index == 1)
    {
        return 1;
    }

    return fib(index - 1) + fib(index - 2);
}

int main()
{
    int k = 34;
    bool isContained = false;

    cout<<"Calculating..."<<endl;
    for (int i = 0; i <= 45; i++)
    {
        int currentFib = fib(i);

        if (k == currentFib)
        {
            isContained = true;
            break;
        }

        if (k < currentFib)
        {
            break;
        }
    }

    if (isContained)
    {
        cout<<k<<" is contained in fibonacci sequence"<<endl;
    }
    else
    {
        cout<<k<<" is NOT contained in fibonacci sequence"<<endl;
    }

    return 0;
}
