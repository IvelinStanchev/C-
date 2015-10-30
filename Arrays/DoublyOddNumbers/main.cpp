#include <iostream>

using namespace std;

int calculateSumDoublyOdd(int numbers[], int elementsCount)
{
    int sum = 0;

    for (int i = 0; i < elementsCount; i++)
    {
        if (numbers[i] % 4 == 0)
        {
            sum += numbers[i];
        }
    }

    return sum;
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

        int sumOfDoublyOddNumbers = calculateSumDoublyOdd(numbers, n);

        cout<<"Sum of doubly odd numbers: "<<sumOfDoublyOddNumbers<<endl;
    }

    return 0;
}
