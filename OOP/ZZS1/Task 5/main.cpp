#include <iostream>

using namespace std;

double multiplyBy5(double n)
{
    return n * 5;
}

double divideBy5(double n)
{
    return n / 5;
}

double fmax(double (*functionF) (double), double (*functionG) (double), double x)
{
    return functionF(x) > functionG(x) ? functionF(x) : functionG(x);
}

int main()
{
    cout<<fmax(multiplyBy5, divideBy5, 150.1)<<endl;

    return 0;
}
