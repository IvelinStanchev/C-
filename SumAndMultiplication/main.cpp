#include <iostream>

using namespace std;

int calculateSumOfPositiveNumbers (int numbers[], int elementsCount)
{
    int sum = 0;

    for (int i = 0; i < elementsCount; i++)
    {
        if (numbers[i] >= 0)
        {
            sum += numbers[i];
        }
    }

    return sum;
}

int calculateMultiplicationOfNegativeNumbers (int numbers[], int elementsCount)
{
    int result = 1;

    for (int i = 0; i < elementsCount; i++)
    {
        if (numbers[i] < 0)
        {
            result *= numbers[i];
        }
    }

    return result;
}

int main()
{
    int n;
    cout<<"n [1, 20]: ";
    cin>>n;

    if (n < 1 || n > 20)
    {
        cout<<"n should be between 1 and 20"<<endl;
    }
    else
    {
        int numbers[n];

        for (int i = 0; i < n; i++)
        {
            cin>>numbers[i];
        }

        int sumOfPositiveNumbers = calculateSumOfPositiveNumbers(numbers, n);
        int multiplicationOfNegativeNumbers = calculateMultiplicationOfNegativeNumbers(numbers, n);

        cout<<"Sum of positive numbers: "<<sumOfPositiveNumbers<<endl;
        cout<<"Multiplication of negative numbers: "<<multiplicationOfNegativeNumbers<<endl;
    }

    return 0;
}
