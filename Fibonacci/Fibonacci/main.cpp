#include <iostream>

using namespace std;

long long int calculateFibonacci(int N)
{
    if (N == 0)
    {
        return 0;
    }

    if (N == 1)
    {
        return 1;
    }

    return calculateFibonacci(N - 1) + calculateFibonacci(N - 2);
}

int main()
{
    int N;
    cin>>N;

    for (int i = 1; i <= N; i++)
    {
        cout<<calculateFibonacci(i)<<" ";
    }

    return 0;
}
