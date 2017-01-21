#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<char, int> symbolsOccurrences;

    for (int i = 0; i < 255; i++)
    {
        symbolsOccurrences[(char)i] = 0;
    }

    string sentence = "";

    cout<<"Enter the sentence: ";
    std::getline(std::cin, sentence);

    for (int i = 0, length = sentence.length(); i < length; i++)
    {
        symbolsOccurrences[sentence[i]]++;
    }

    for (int i = 1; i <= 255; i++)
    {
        if (symbolsOccurrences[(char)i] != 0)
        {
            cout<<(char)i<<" -> "<<symbolsOccurrences[(char)i];

            if (symbolsOccurrences[(char)i] > 1)
            {
                cout<<" times"<<endl;
            }
            else
            {
                cout<<" time"<<endl;
            }
        }
    }

    return 0;
}
