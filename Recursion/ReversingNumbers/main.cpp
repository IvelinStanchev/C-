#include <iostream>

using namespace std;

void printReversed(int a[], int n)
{
    if (n == 0)
    {
        return;
    }

    printReversed(a + 1, n - 1);

    cout<<a[0]<<endl;
}

int main()
{
    int n = 5;
    int a[n];
    int index = 0;

    while (n > 0)
    {
        cin>>a[index];

        index++;
        n--;
    }

    cout<<endl;
    printReversed(a, index);

    return 0;
}
