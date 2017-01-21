#include <iostream>

using namespace std;

template <typename T>
bool ordered(T elements[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (elements[i + 1] < elements[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n = 5;
    int elements[] = { 1, 2, 3, 4, 4 };

    if (ordered<int>(elements, n))
    {
        cout<<"Monotically increasing sequence"<<endl;
    }
    else
    {
        cout<<"NOT A Monotically increasing sequence"<<endl;
    }

    return 0;
}
