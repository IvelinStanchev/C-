#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right, int partitionNumber) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j)
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
    {
        quickSort(arr, left, j, ++partitionNumber);
        cout<<partitionNumber<<endl;
    }
    if (i < right)
    {
        quickSort(arr, i, right, ++partitionNumber);
        cout<<partitionNumber<<endl;
    }
}

int main()
{
    int n = 7;
    int numbers[] = { 1, 5, 8, 0, 2, 10, 3 };

    quickSort(numbers, 0, n - 1, 0);

    for (int i = 0; i < n; i++)
    {
        cout<<numbers[i]<<" ";
    }

    cout<<endl;

    return 0;
}
