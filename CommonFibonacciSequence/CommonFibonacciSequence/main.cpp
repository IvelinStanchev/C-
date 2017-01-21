#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void printIndecesOfNumbersInFibonacciSequence(int a, int b, int numbers[], int n)
{
    int maxNumber = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (numbers[i] > maxNumber)
        {
            maxNumber = numbers[i];
        }
    }

    int fibNMinus1 = 1;
    int fibNMinus2 = 1;
    int currentFib = 1;

    vector<int> fibonacci;

    fibonacci.push_back(1);//fib1
    fibonacci.push_back(1);//fib2

    currentFib = a * fibNMinus1 + b * fibNMinus2;

    while (currentFib <= maxNumber)
    {
        fibonacci.push_back(currentFib);

        fibNMinus2 = fibNMinus1;
        fibNMinus1 = currentFib;

        currentFib = a * fibNMinus1 + b * fibNMinus2;
    }

    for (int i = 0; i < n; i++)
    {
        int pos = find(fibonacci.begin(), fibonacci.end(), numbers[i]) - fibonacci.begin();

        if(pos >= fibonacci.size())
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<pos + 1<<endl;
        }
    }
}

int main()
{
    int rowCounter = 1;
    int counter;
    int a = 0, b = 0, n = 0;
    string input;

    while(getline(cin, input))
    {
        counter = 1;

        if (rowCounter == 4)
        {
            rowCounter = 1;
        }

        int inputLength = input.length();
        int i = inputLength - 1;

        //trim end
        while (!isdigit(input[i]))
        {
            i--;
        }

        if (rowCounter == 1)//a and b
        {
            //get b
            counter = 1;
            while (isdigit(input[i]) && i >= 0)
            {
                b += counter * ((int) input[i] - 48);
                counter *= 10;
                i--;
            }

            i--;

            //get a
            counter = 1;
            while (isdigit(input[i]) && i >= 0)
            {
                a += counter * ((int) input[i] - 48);
                counter *= 10;
                i--;
            }
        }
        else if (rowCounter == 2)//numbers count
        {
            //get n
            counter = 1;
            while (isdigit(input[i]) && i >= 0)
            {
                n += counter * ((int) input[i] - 48);
                counter *= 10;
                i--;
            }

            int numbers[n];
            for (int j = 0; j < n; j++)
            {
                cin>>numbers[j];
            }

            printIndecesOfNumbersInFibonacciSequence(a, b, numbers, n);

            a = b = n = 0;
        }

        rowCounter++;
    }

    return 0;
}
