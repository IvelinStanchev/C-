#include <iostream>

using namespace std;

int sizeA = 0;
int sizeB = 0;

bool compare(char a[], char b[], int sizeA, int sizeB, int maxIndexA, int maxIndexB)
{
    if (maxIndexA >= maxIndexB && sizeA == 0) {
        return true;
    }

    if (maxIndexB > maxIndexA && sizeB == 0)
    {
        return true;
    }

    bool found = false;

    for (int i = maxIndexB - 1; i >= 0 && !found ; i--)
    {
        if (sizeA > 0)
        {
            if (a[sizeA - 1] == b[i])
            {
                found = true;
            }
        }
    }

    if (sizeA <= 0)
    {
        found = true;
    }

    if (found && sizeB > 0)
    {
        found = false;
        for (int i = maxIndexA - 1; i >= 0 && !found ; i--)
        {
            if (b[sizeB - 1] == a[i])
            {
                found = true;
            }
        }
    }

    return found ? compare(a, b, sizeA - 1, sizeB - 1, maxIndexA, maxIndexB) : false;
}

bool equalLetterSets(char a[], char b[])
{
    return compare(a, b, sizeA, sizeB, sizeA, sizeB);
}

int main()
{
    char a[] = { 'a', 'a', 'b', 'c', 'd', 'a', 'a' };
    char b[] = { 'c', 'c', 'b', 'a', 'd', 'b', 'a' , 'a', 'a' };

    sizeA = sizeof(a) / sizeof(a[0]);
    sizeB = sizeof(b) / sizeof(b[0]);

    if(equalLetterSets(a, b))
    {
        cout<<"The sets are the same"<<endl;
    }
    else
    {
        cout<<"The sets are NOT the same"<<endl;
    }

    return 0;
}
