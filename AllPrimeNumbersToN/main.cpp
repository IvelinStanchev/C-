#include <iostream>
#include <math.h>

using namespace std;

void printAllPrimeNumbers(int n)
{
    bool used[n];

    for (int j = 2; j <= n; j++)
    {
        used[j] = 0;
    }

    for (int i = 2; i < sqrt(n); i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            if (!used[j])
            {
                used[j] = 1;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (!used[i])
        {
            cout<<i<<endl;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    printAllPrimeNumbers(n);

    return 0;
}
