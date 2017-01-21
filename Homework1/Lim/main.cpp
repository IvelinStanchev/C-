#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n = 300000000;
    double result = 0.0;

    int counter = 1;
    for (int i = 1; i <= n; i++)
    {
        result += 1.0 / (sqrt(counter) + sqrt(counter + 2));

        counter += 2;
    }

    result = result / sqrt(n);

    cout<<1 / sqrt(2)<<endl;

    cout<<result;

    return 0;
}
