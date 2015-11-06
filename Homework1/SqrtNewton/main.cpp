#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double calculateSqrt(long double number, long double E)
{
    long double lastNumber = number;
    long double currentNumber = (1.0 / 2.0)  * (lastNumber + (number / lastNumber));

    while (fabs(currentNumber - lastNumber) > E)
    {
        lastNumber = currentNumber;
        currentNumber = (1.0 / 2.0) * (lastNumber + (number / lastNumber));
    }

    return lastNumber;
}

int main()
{
    long double number, E;
    cout<<"Your number: ";
    cin>>number;
    cout<<"Your E: ";
    cin>>E;

    long double numberSqrt = calculateSqrt(number, E);

    cout<<"sqrt("<<number<<") = "<<setprecision(15)<<numberSqrt<<endl;

    return 0;
}
