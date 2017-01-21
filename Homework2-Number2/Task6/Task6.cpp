#include <iostream>

using namespace std;

void replaceOccurrence(int a[], int size, int currentIndex, bool used[])
{
    if (size - currentIndex <= 2)
    {
        return;
    }

    int occurrences = 0;
    for (int i = currentIndex; i < size; i++)
    {
        if (a[currentIndex] == a[i] && !used[i])
        {
            occurrences++;
        }
    }

    if (occurrences >= 3)
    {
        for (int i = currentIndex + 1; i < size; i++)
        {
            if (a[currentIndex] == a[i])
            {
                a[i] = currentIndex;
                used[i] = 1;
            }
        }

        a[currentIndex] = currentIndex;
        used[currentIndex] = 1;
    }

    return replaceOccurrence(a, size, currentIndex + 1, used);
}

int main()
{
    int sizeA = 12;
    int a[] = { 5, 5, 5, 2, 2, 5, 3, 3, 4, 3, 5, 3 };
    bool used[12] = { 0 };

    cout<<"Before using replace function: ";
    for (int i = 0; i < sizeA; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    replaceOccurrence(a, sizeA, 0, used);

    cout<<"After using replace function: ";
    for (int i = 0; i < sizeA; i++)
    {
        cout<<a[i]<<" ";
    }

    cout<<endl;

    return 0;
}
