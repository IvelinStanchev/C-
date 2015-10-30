#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    map<char, int> symbolsOccurrences;
    cin>>n;

    char symbols[n];

    for (char i = 'a'; i <= 'z'; i++)
    {
        symbolsOccurrences[i] = 0;
    }

    cout<<"Enter "<<n<<" symbols"<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>symbols[i];
        symbolsOccurrences[symbols[i]]++;
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        if (symbolsOccurrences[i] != 0)
        {
            cout<<i<<" -> "<<symbolsOccurrences[i];
            if (symbolsOccurrences[i] == 1)
            {
                cout<<" time"<<endl;
            }
            else
            {
                cout<<" times"<<endl;
            }
        }
    }

    return 0;
}
