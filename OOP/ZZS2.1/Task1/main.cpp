#include <iostream>

using namespace std;

template <typename T>
T* strduplicate(int &n)
{
    cin>>n;

    T* result = new T[n];
    for (int i = 0; i < n; i++)
    {
        cin>>result[i];
    }

    return result;
}

int main()
{
    int n;
    int *numbers;
    numbers = strduplicate <int> (n);

    for (int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<endl;
    }

    return 0;
}
