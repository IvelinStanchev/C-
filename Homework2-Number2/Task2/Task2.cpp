#include <iostream>

using namespace std;

char* findLongestOccurences(char baseArray[], char searchingArray[], int lenBase, int lenSearching, int *maxLength)
{
    char *pMax = NULL;
    bool isSubset = true;
    int maxRepeats = 0;
    int currentRepeats = 0;

    int iCopy = 0;
    for (int i = 0; i < lenBase; i++)
    {
        isSubset = true;
        iCopy = i;

        for (int j = 0; j < lenSearching && isSubset == true; j++)
        {
            if (i + lenSearching < lenBase)
            {
                if (baseArray[iCopy] == searchingArray[j])
                {
                    iCopy++;
                }
                else
                {
                    isSubset = false;
                }
            }
            else
            {
                isSubset = false;
                break;
            }
        }

        if (isSubset)
        {
            currentRepeats++;

            if (currentRepeats > maxRepeats)
            {
                pMax = &baseArray[i - (currentRepeats - 1) * lenSearching];
                maxRepeats = currentRepeats;
            }

            i += lenSearching - 1;//if we got a subset move i to the next symbols
        }
        else
        {
            currentRepeats = 0;
        }
    }

    *maxLength = maxRepeats * lenSearching;

    if (*maxLength == 0)
    {
        *maxLength = -1;
    }

    return pMax;
}

int main()
{
    //int lenB = 19, lenC = 3;
    int lenB = 10, lenC = 1;

    char b[] = { 'a', 'b', 'b', 'b', 'b', 'b', 'a', 'b', 'b', 'c' };
    //char b[] = { 'a', 'b', 'b', 'b', 'a', 'c', 'b', 'c', 'a', 'b', 'a', 'c', 'b', 'a', 'c', 'c', 'b', 'b', 'c' };
    char c[] = { 'b' };
    //char c[] = { 'b', 'a', 'c' };

    int maxLength = -1;
    char *pMax = findLongestOccurences(b, c, lenB, lenC, &maxLength);

    if (pMax == NULL)
    {
        cout<<"NULL, len="<<maxLength<<endl;
    }
    else
    {
        cout<<pMax;
        cout<<", len="<<maxLength<<endl;
    }

    return 0;
}
