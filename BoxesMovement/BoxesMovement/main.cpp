#include <iostream>
#include <bitset>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

const int MAX_BOXES_COUNT = 25;

int calculateSumOfNumbers(vector<int> numbers)
{
    int result = 0;

    for (int i = 0; i < numbers.size(); i++)
    {
        result += numbers[i];
    }

    return result;
}

void processInput(vector<int> numbers)
{
    int numbersSum = calculateSumOfNumbers(numbers);
    const int numbersCount = numbers.size();
    int combinationsCount = pow(2, numbersCount);

    int bestDifference = numbersSum;
    int bestDifferenceFirstSum = numbersSum;

    int numbersCounter;
    int currentSum;
    int difference;
    int currentDifference;
    for (int i = 0; i < combinationsCount; i++)
    {
        string binary = bitset<MAX_BOXES_COUNT>(i).to_string();
        int fromIndex = binary.length() - 1;
        int toIndex = binary.length() - numbersCount;

        numbersCounter = 0;
        currentSum = 0;
        for (int i = fromIndex; i >= toIndex; i--)
        {
            if (binary[i] == '1')
            {
                currentSum += numbers[numbersCounter];
            }

            numbersCounter++;
        }

        difference = numbersSum - currentSum;

        currentDifference = fabs(difference - currentSum);

        if (currentDifference < bestDifference)
        {
            bestDifference = currentDifference;
            bestDifferenceFirstSum = currentSum;
        }
    }

    int firstNumber = bestDifferenceFirstSum;
    int secondNumber = numbersSum - bestDifferenceFirstSum;

    if (firstNumber < secondNumber)
    {
        cout<<firstNumber<<" "<<secondNumber<<endl;
    }
    else
    {
        cout<<secondNumber<<" "<<firstNumber<<endl;
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

        processInput(v);
    }

    return 0;
}
