#include <iostream>

using namespace std;

void swap(int a[], int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int swap = a[i];
        a[i] = b[i];
        b[i] = swap;
    }
}

int main()
{
    int size = 5;
    int a[] = { 5, 8, 10, 15, 20 };
    int b[] = { 12, 124, -5, 0, 90 };

    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<b[i]<<" ";
    }

    cout<<endl;
    cout<<endl;

    swap(a, b);

    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    for (int i = 0; i < size; i++)
    {
        cout<<b[i]<<" ";
    }

    return 0;
}
