#include <iostream>

using namespace std;

void printSuffix(char suffix[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            cout<<(int)suffix[i];
        }
        else
        {
            cout<<(int)suffix[i]<<" + ";
        }
    }

    cout<<endl;
}

void printPartitions(int target, int maxValue, char suffix[], int suffixLength) {
    if (target == 0)
    {
        printSuffix(suffix, suffixLength);
        suffixLength = 0;
    }
    else
    {
        if (maxValue > 1)
        {
            printPartitions(target, maxValue - 1, suffix, suffixLength);
        }

        if (maxValue <= target)
        {
            suffix[suffixLength] = (char)maxValue;

            printPartitions(target - maxValue, maxValue, suffix, suffixLength + 1);
        }
    }
}

int main()
{
    int n;
    cin>>n;

    printPartitions(n, n, new char[100000], 0);

    return 0;
}
