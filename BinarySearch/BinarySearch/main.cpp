#include <iostream>

using namespace std;

int indexOf(int sortedArray[], int start, int end, int numberForFinding)
{
    int index;

    if (start > end)
    {
        return -1;
    }
    else
    {
        int mid = (start + end) / 2;

        if (numberForFinding == sortedArray[mid])
        {
            return mid;
        }
        else
        {
            if (numberForFinding > sortedArray[mid])
            {
                index = indexOf(sortedArray, mid + 1, end, numberForFinding);
            }
            else
            {
                index = indexOf(sortedArray, start, mid - 1, numberForFinding);
            }
        }
    }

    return index;
}

int main()
{
    int n = 5;
    int sortedArray[] = { 1, 2, 3, 4, 5 };

    cout<<indexOf(sortedArray, 0, n - 1, 1);

    return 0;
}
