#include <iostream>

using namespace std;

int findMax(int a[], int size)
{
    if (size == 1)
    {
        return a[0];
    }

    if (size == 2)
    {
        return (a[1] > a[0]) ? a[1] : a[0];
    }

    return (a[0] > findMax(a + 1, size - 1)) ? a[0] : findMax(a + 1, size - 1);
}

int main()
{
    int a[] = { 5, 10, -5, 20, 9 };

    cout<<findMax(a, 5)<<endl;

    return 0;
}
