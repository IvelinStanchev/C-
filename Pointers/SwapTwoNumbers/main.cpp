#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int swap = *a;
    *a = *b;
    *b = swap;
}

int main()
{
    int a = 5, b = 10;

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    swap(&a, &b);

    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;

    return 0;
}
