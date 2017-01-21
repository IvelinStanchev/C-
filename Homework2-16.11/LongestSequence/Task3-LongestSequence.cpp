#include <iostream>

using namespace std;

int main()
{
    int sequence[] = { 1, 2, 2, 3, 3, 4, 4, 4, 4 ,4 , 5, 5, 5 };

    int n = sizeof(sequence) / sizeof(sequence[0]);

    int longestSequenceLength = 1;
    int longestRepeatingNumber;

    int currentRepeatingNumber;
    int currentSequenceLength;

    for (int i = 0; i < n - 1; i++)
    {
        currentSequenceLength = 1;

        while ((sequence[i] == sequence[i + 1]) && (i < (n - 1)))
        {
            currentSequenceLength++;
            i++;
        }

        if (currentSequenceLength > longestSequenceLength)
        {
            longestRepeatingNumber = sequence[i];
            longestSequenceLength = currentSequenceLength;
        }
    }

    if (longestSequenceLength == 1)
    {
        cout<<"There is no landing"<<endl;
    }
    else
    {
        cout<<"The landing is "<<longestRepeatingNumber<<" with length of "<<longestSequenceLength<<endl;
    }

    return 0;
}
