#include <iostream>

using namespace std;

bool checkForMonotonicallyIncreasing(int numbers[], int elementsCount)
{
    for (int i = 0; i < elementsCount - 1; i++)
    {
        if (numbers[i] > numbers[i + 1])
        {
            return false;
        }
    }

    return true;
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

        bool isMonotonicallyIncreasing = checkForMonotonicallyIncreasing(numbers, n);

        if (isMonotonicallyIncreasing)
        {
            cout<<"The sequence is monotonically increasing"<<endl;
        }
        else
        {
            cout<<"The sequence is NOT monotonically increasing"<<endl;
        }
    }

    return 0;
}
