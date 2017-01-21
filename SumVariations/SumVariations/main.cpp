#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool foundValue = false;
bool isValid = true;

static void calculateValues(string input, int depth, string output, vector<int> numbers, int arrayLength, int b)
{
    if (depth == 0)
    {
        int sum = numbers[0];

        for (int i = 0; i < output.length(); i++)
        {
            if (i == output.length() - 1)
            {
                if (sum == b)
                {
                    isValid = false;
                }
            }

            if (output[i] == '+')
            {
                sum += numbers[i + 1];
            }
            else if (output[i] == '-')
            {
                sum -= numbers[i + 1];
            }
        }

        if (sum == b && isValid && !foundValue)
        {
            cout<<numbers[0];

            for (int i = 0; i < output.length(); i++)
            {
                if (output[i] == '+')
                {
                    cout<<"+";
                }
                else if (output[i] == '-')
                {
                    cout<<"-";
                }

                cout<<numbers[i + 1];
            }

            cout<<"="<<b<<endl;

            foundValue = true;
        }

        isValid = true;
    }
    else
    {
        for (int i = 0; i < input.length(); i++) {
            output += input[i];
            calculateValues(input, depth - 1, output, numbers, arrayLength, b);
            output.erase(output.length() - 1, 1);
        }
    }
}

int main()
{
    string input;
    int k;

    while(getline(cin, input))
    {
        vector<int> v;
        istringstream is(input);
        while(is >> k)
        {
            v.push_back(k);
        }

        string output;
        calculateValues("+-", v.size() - 2, output, v, v.size(), v[v.size() - 1]);

        if (!foundValue)
        {
            cout<<endl;
        }

        foundValue = false;
        isValid = true;
    }

    return 0;
}
