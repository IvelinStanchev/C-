#include <iostream>

using namespace std;

template <typename T>
void input(T elements[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin>>elements[i];
    }
}

int main()
{
    int n = 5;
    int elements[n];

    input<int>(elements, n);

    for (int i = 0; i < n; i++)
    {
        cout<<elements[i]<<endl;
    }

    return 0;
}
