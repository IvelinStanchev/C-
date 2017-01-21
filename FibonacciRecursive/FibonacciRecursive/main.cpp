#include <iostream>

using namespace std;

int fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }

    int left = fib(n - 1);
    int right = fib(n - 2);

    return left + right;
}

int main()
{
    cout<<fib(4);
    return 0;
}
