#include <iostream>

using namespace std;

int findLengthOfLongestIncreasingSequence(int numbers[], int elementsCount)
{
    int maxLength = 1;
    int currentLength = 1;

    for (int i = 0; i < elementsCount - 1; i++)
    {
        if (numbers[i] <= numbers[i + 1])
        {
            currentLength++;
        }
        else
        {
            currentLength = 1;
        }

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }

    return maxLength;
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

        int lengthOfLongestIncreasingSequence = findLengthOfLongestIncreasingSequence(numbers, n);

        cout<<"Length of longest increasing sequence: "<<lengthOfLongestIncreasingSequence<<endl;
    }

    return 0;
}
