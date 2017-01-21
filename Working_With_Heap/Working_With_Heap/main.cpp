#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

char car(const char* x)
{
    return x[0];
}

char* cdr(char* x)
{
    return x + 1;
}

char* cons(char x, const char* y)
{
    int yLength = strlen(y);

    char* dynamic = new char[yLength + 2];

    dynamic[0] = x;

    for (int i = 1; i <= yLength; i++)
    {
        dynamic[i] = y[i - 1];
    }

    dynamic[yLength + 1] = '\0';

    return dynamic;
}

bool eq(const char* x, const char* y)
{
    return strcmp(x, y) == 0;
}

char* reverseWord (char* x)
{
    int xLength = strlen(x);

    char *reversed = new char [xLength];

    reversed[xLength] = '\0';

    for (int i = xLength - 1; i >= 0; i--)
    {
        reversed[i] = car(x);

        x = cdr(x);
    }

    return reversed;
}

char* copy(char* x)
{
    int xLength = strlen(x);

    char* copyChar = new char[xLength + 1];

    copyChar = cons('a', x);

    copyChar = cdr(copyChar);

    copyChar[xLength] = '\0';

    return copyChar;
}

char* car_n(char* x, int n)
{
    int xLength = strlen(x);

    char* extracted = new char[xLength];

    int counter = 0;

    while (counter < n)
    {
        extracted[counter] = car(x);

        x = cdr(x);

        counter++;
    }

    extracted[counter] = '\0';

    return extracted;
}

char* cdr_n(char* x, int n)
{
    int xLength = strlen(x);

    char* extracted = new char[xLength - n];

    for (int i = 0; i < n; i++)
    {
        x = cdr(x);
    }

    extracted = x;

    return extracted;
}

int number_of_char(char* x, char ch)
{
    int xLength = strlen(x);

    int count = 0;

    for (int i = 0; i < xLength; i++)
    {
        if (car(x) == ch)
        {
            count++;
        }

        x = cdr(x);
    }

    return count;
}

int number_of_substr(char* x, char* y)
{
    int count = 0;

    int xLength = strlen(x);
    int yLength = strlen(y);

    char* extractedFromX = new char[yLength];

    for (int i = 0; i < xLength; i++)
    {
        extractedFromX = car_n(x, yLength);

        if (eq(extractedFromX, y))
        {
            count++;
        }

        x = cdr(x);
    }

    return count;
}

char* delete_substr(char* x, char* y)
{
    int xLength = strlen(x);
    int yLength = strlen(y);

    char* charWithDeletedY = new char[xLength];
    int currentIndex = 0;

    char* extractedFromX = new char[yLength];

    for (int i = 0; i < xLength; i++)
    {
        extractedFromX = car_n(x, yLength);

        if (!eq(extractedFromX, y))
        {
            charWithDeletedY[currentIndex] = car(x);

            currentIndex++;
        }
        else
        {
            x = cdr_n(x, yLength - 1);

            i += yLength - 1;
        }

        x = cdr(x);
    }

    charWithDeletedY[currentIndex] = '\0';

    return charWithDeletedY;
}

int main()
{
    cout<<reverseWord("p1eshoo")<<endl;

    cout<<copy("pesho")<<endl;

    cout<<car_n("pesho", 2)<<endl;

    cout<<cdr_n("pesho", 3)<<endl;

    cout<<number_of_char("pesho", 'p')<<endl;

    cout<<number_of_substr("afasfaasf", "a")<<endl;

    cout<<delete_substr("abeacdea", "ea")<<endl;

    return 0;
}
