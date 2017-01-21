#include <iostream>

using namespace std;

bool checkForSequentialElements(int numbers[], int elementsCount)
{
    for (int i = 0; i < elementsCount - 1; i++)
    {
        if (numbers[i] == numbers[i + 1])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    int n;
    cout<<"n [1, 100]: ";
    cin>>n;

    if (n < 1 || n > 100)
    {
        cout<<"n should be between 1 and 100"<<endl;
    }
    else
    {
        int numbers[n];

        for (int i = 0; i < n; i++)
        {
            cin>>numbers[i];
        }

        bool hasTwoSequentialElements = checkForSequentialElements(numbers, n);

        if (hasTwoSequentialElements)
        {
            cout<<"Has two sequential equal elements"<<endl;
        }
        else
        {
            cout<<"Don't have two sequential equal elements"<<endl;
        }
    }

    return 0;
}
