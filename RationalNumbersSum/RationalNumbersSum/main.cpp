#include <iostream>
#include <string>

using namespace std;

int calculateLCM(int n, int q)
{
    int max = (n > q) ? n : q;

    do
    {
        if (max % n == 0 && max % q == 0)
        {
            return max;
        }
        else
        {
            max++;
        }
    } while (true);
}

void printSimplifiedRationalNumber(int numerator, int denominator)
{
    if (numerator == 0)
    {
        cout<<"0"<<endl;
    }
    else if (numerator == denominator)
    {
        cout<<"1"<<endl;
    }
    else if (numerator > denominator && numerator % denominator == 0)
    {
        cout<<numerator / denominator<<endl;
    }
    else if (numerator < denominator && denominator % numerator == 0)
    {
        cout<<"1"<<"/"<<denominator / numerator<<endl;
    }
    else
    {
        int min = (numerator < denominator) ? numerator : denominator;
        int max = (numerator > denominator) ? numerator : denominator;

        while (numerator % min != 0 || denominator % min != 0 && min > 1)
        {
            min--;
        }

        cout<<numerator / min<<"/"<<denominator / min<<endl;
    }
}

int main()
{
    int m, n, p, q;
    string input;

    while(getline(cin, input))
    {
        m = n = p = q = 0;

        int inputLength = input.length();
        int i = inputLength - 1;

        //trim end
        while (!isdigit(input[i]))
        {
            i--;
        }

        //get q
        int counter = 1;
        while (isdigit(input[i]) && i >= 0)
        {
            q += counter * ((int) input[i] - 48);
            counter *= 10;
            i--;
        }

        i--;

        //get p
        counter = 1;
        while (isdigit(input[i]) && i >= 0)
        {
            p += counter * ((int) input[i] - 48);
            counter *= 10;
            i--;
        }

        i -= 3;

        //get n
        counter = 1;
        while (isdigit(input[i]) && i >= 0)
        {
            n += counter * ((int) input[i] - 48);
            counter *= 10;
            i--;
        }

        i--;

        //get m
        counter = 1;
        while (isdigit(input[i]) && i >= 0)
        {
            m += counter * ((int) input[i] - 48);
            counter *= 10;
            i--;
        }

        int lcm = calculateLCM(n, q);

        int resultM = m * (lcm / n) + p * (lcm / q);

        printSimplifiedRationalNumber(resultM, lcm);
    }

    return 0;
}
