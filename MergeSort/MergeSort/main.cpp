#include <iostream>

using namespace std;

void mergeArrays(int leftSubArray[], int leftSize, int rightSubArray[], int rightSize, int mergedArray[])
{
    int iLeft, iRight, iTemp;

    iLeft = iRight = iTemp = 0;

    while(iLeft < leftSize && iRight < rightSize)
    {
        if (leftSubArray[iLeft] < rightSubArray[iRight])
        {
            mergedArray[iTemp] = leftSubArray[iLeft];
            iLeft++;
        }
        else
        {
            mergedArray[iTemp] = rightSubArray[iRight];
            iRight++;
        }

        iTemp++;
    }

    //copy the rest of the elements of the bigger sized array
    while(iLeft < leftSize)
    {
        mergedArray[iTemp] = leftSubArray[iLeft];
        iTemp++;
        iLeft++;
    }

    while(iRight < rightSize)
    {
        mergedArray[iTemp] = rightSubArray[iRight];
        iTemp++;
        iRight++;
    }
}

void mergeSortRecursion(int numbers[], int size)
{
    int mid;
    int tempArray[size];

    if (size < 2)
    {
        return;
    }

    mid = size / 2;
    mergeSortRecursion(numbers, mid);

    mergeSortRecursion(numbers + mid, size - mid);

    mergeArrays(numbers, mid, numbers + mid, size - mid, tempArray);//merge left and right Sub-arrays

    for (int i = 0; i < size; i++)
    {
        numbers[i] = tempArray[i];
    }
}

int main()
{
    int n = 10;
    int numbers[] = { 1, 5, 3, 0, 10, 7, 20, 100, -50, 0 };

    for (int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }

    cout<<endl;

    mergeSortRecursion(numbers, n);

    for (int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }

    cout<<endl;

    return 0;
}
