#include <iostream>
#include <map>

using namespace std;

void printMagorant(string input[], int size)
{
    map<string, int> occurrences;

    for (int i = 0; i < size; i++)
    {
        int occurrencesOfCurrentString = occurrences[input[i]];
        occurrencesOfCurrentString++;

        occurrences[input[i]] = occurrencesOfCurrentString;
    }

    map<string, int>::iterator it;
    bool foundMagorant = false;

    for (it = occurrences.begin(); it != occurrences.end(); ++it)
    {
        if (it->second > (size / 2))
        {
            cout<<it->first<<endl;
            foundMagorant = true;
            break;
        }
    }

    if (!foundMagorant)
    {
        cout<<""<<endl;
    }
}

int main()
{
    int inputNumbersCount;
    string input[100001];

    while(cin>>inputNumbersCount)
    {
        for (int i = 0; i < inputNumbersCount; i++)
        {
            cin>>input[i];
        }

        printMagorant(input, inputNumbersCount);
    }

    return 0;
}
