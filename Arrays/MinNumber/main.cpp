#include <iostream>

using namespace std;

int findMin(int numbers[], int elementsCount)
{
    int minNumber = numbers[0];

    for (int i = 1; i < elementsCount; i++)
    {
        if (numbers[i] < minNumber)
        {
            minNumber = numbers[i];
        }
    }

    return minNumber;
}

int main()
{
    int n;
    cout<<"n [1, 50]: ";
    cin>>n;

    if (n < 1 || n > 50)
    {
        cout<<"n should be between 1 and 50"<<endl;
    }
    else
    {
        int numbers[n];

        for (int i = 0; i < n; i++)
        {
            cin>>numbers[i];
        }

        int minNumber = findMin(numbers, n);

        cout<<"Min: "<<minNumber<<endl;
    }

    return 0;
}
