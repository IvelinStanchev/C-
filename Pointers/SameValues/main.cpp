#include <iostream>

using namespace std;

bool checkForSameValues(int *pointers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i != j && *pointers[i] == *pointers[j])
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    int a = 5, b = 9, c = 10, d = -10, e = 5;
    int size = 5;
    int *pointers[] = { &a, &b, &c, &d, &e };

    checkForSameValues(pointers, size) ? cout<<"There are two variables with same values" :
        cout<<"There are NOT two variables with same values";

    return 0;
}
