#include <iostream>

using namespace std;

void countAll(int a[], int size, int *countZeros, int *sumNegatives, int *multiplicationPositives)
{
    if (size == 0)
    {
        return;
    }

    if (a[0] == 0)
    {
        *countZeros += 1;
    }

    if (a[0] < 0)
    {
        *sumNegatives += a[0];
    }

    if (a[0] > 0)
    {
        *multiplicationPositives *= a[0];
    }

    countAll(a + 1, size - 1, countZeros, sumNegatives, multiplicationPositives);
}

int main()
{
    int size = 10;
    int a[] = { 10, 20, -5, 0, -100, 0, 100, 10, 1, 0 };

    int zeros = 0, sum = 0, multiplication = 1;
    countAll(a, size, &zeros, &sum, &multiplication);

    cout<<zeros;
    if (zeros == 1)
    {
        cout<<" zero"<<endl;
    }
    else
    {
        cout<<" zeros"<<endl;
    }

    cout<<"Sum of the negatives: "<<sum<<endl;

    cout<<"Multiplication of the positives: "<<multiplication<<endl;

    return 0;
}
