#include <iostream>
#include <string.h>

using namespace std;

char* replaceLast(char* pch, const char* findWhat, char* replaceWith)
{
    int sizeFindWhat = strlen(findWhat);
    int sizeReplaceWith = strlen(replaceWith);
    int sizePch = strlen(pch);

    int lastOccurrenceIndex = -1;
    int iCopy = 0;
    int findWhatIndex = 0;
    for (int i = 0; i < sizePch; i++)
    {
        iCopy = i;
        findWhatIndex = 0;

        if (i + sizeFindWhat - 1 < sizePch)
        {

            while(pch[iCopy] == findWhat[findWhatIndex] && findWhatIndex < sizeFindWhat)
            {
                iCopy++;
                findWhatIndex++;
            }

            if (findWhatIndex == sizeFindWhat)
            {
                lastOccurrenceIndex = iCopy - sizeFindWhat;
            }
        }
    }

    char *newString = new char[1000000];

    if (lastOccurrenceIndex != -1)
    {
        for (int i = 0; i < lastOccurrenceIndex; i++)
        {
            newString[i] = pch[i];
        }

        int newIndex = 0;

        for (int i = lastOccurrenceIndex; i < lastOccurrenceIndex + sizeReplaceWith; i++)
        {
            newString[i] = replaceWith[newIndex];
            newIndex++;
        }

        newIndex = lastOccurrenceIndex + sizeReplaceWith;

        for (int i = lastOccurrenceIndex + sizeFindWhat; i < sizePch; i++)
        {
            newString[newIndex] = pch[i];
            newIndex++;
        }
    }
    else
    {
        return pch;
    }

    return &newString[0];
}

char* replaceAll(char* pch, const char* findWhat, char* replaceWith)
{
    int sizeFindWhat = strlen(findWhat);
    int sizeReplaceWith = strlen(replaceWith);
    int sizePch = strlen(pch);

    char *newString = new char[1000000];
    int newStringIndex = 0;

    int firstOccurrenceIndex = -1;
    int iCopy = 0;
    int findWhatIndex = 0;
    for (int i = 0; i < sizePch; i++)
    {
        iCopy = i;
        findWhatIndex = 0;

        newString[newStringIndex] = pch[i];
        newStringIndex++;

        if (i + sizeFindWhat - 1 < sizePch)
        {
            while(pch[iCopy] == findWhat[findWhatIndex] && findWhatIndex < sizeFindWhat)
            {
                iCopy++;
                findWhatIndex++;
            }

            if (findWhatIndex == sizeFindWhat)
            {
                newStringIndex--;

                for (int j = 0; j < sizeReplaceWith; j++)
                {
                    newString[newStringIndex] = replaceWith[j];
                    newStringIndex++;
                }

                i += sizeFindWhat - 1;
            }
        }
    }

    return &newString[0];
}

char* replaceFirst(char* pch, const char* findWhat, char* replaceWith)
{
    int sizeFindWhat = strlen(findWhat);
    int sizeReplaceWith = strlen(replaceWith);
    int sizePch = strlen(pch);

    int firstOccurrenceIndex = -1;
    int iCopy = 0;
    int findWhatIndex = 0;
    for (int i = 0; i < sizePch; i++)
    {
        iCopy = i;
        findWhatIndex = 0;

        if (i + sizeFindWhat - 1 < sizePch)
        {
            while(pch[iCopy] == findWhat[findWhatIndex] && findWhatIndex < sizeFindWhat)
            {
                iCopy++;
                findWhatIndex++;
            }

            if (findWhatIndex == sizeFindWhat)
            {
                firstOccurrenceIndex = iCopy - sizeFindWhat;
                break;
            }
        }
    }

    char *newString = new char[1000000];

    if (firstOccurrenceIndex != -1)
    {
        for (int i = 0; i < firstOccurrenceIndex; i++)
        {
            newString[i] = pch[i];
        }

        int newIndex = 0;

        for (int i = firstOccurrenceIndex; i < firstOccurrenceIndex + sizeReplaceWith; i++)
        {
            newString[i] = replaceWith[newIndex];
            newIndex++;
        }

        newIndex = firstOccurrenceIndex + sizeReplaceWith;

        for (int i = firstOccurrenceIndex + sizeFindWhat; i < sizePch; i++)
        {
            newString[newIndex] = pch[i];
            newIndex++;
        }
    }
    else
    {
        return pch;
    }

    return &newString[0];
}

int main()
{
    char *pch = "asfkhasaskkasaskasfgask";
    char *findWhat = "ask";
    char *replaceWith = "pesho";

    char *newArray;
    cout<<"Before replaceFirst function: "<<pch<<endl;

    newArray = replaceFirst(pch, findWhat, replaceWith);

    cout<<"After replaceFirst function: "<<newArray<<endl;

    newArray = replaceLast(pch, findWhat, replaceWith);

    cout<<"After replaceLast function: "<<newArray<<endl;

    newArray = replaceAll(pch, findWhat, replaceWith);

    cout<<"After replaceAll function: "<<newArray<<endl;

    return 0;
}
