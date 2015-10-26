#include <iostream>

using namespace std;

bool checkForPowerOfTwo(int number, int power)
{
    while (number > 1)
    {
        if (number % power != 0)
        {
            return false;
        }
        else
        {
            number /= power;
        }
    }

    return true;
}

int main()
{
    int number, power;
    cout<<"Number: ";
    cin>>number;
    cout<<"Power: ";
    cin>>power;

    bool isPowerOf2 = checkForPowerOfTwo(number, power);

    if (isPowerOf2)
    {
        cout<<"Its a power of "<<power<<endl;
    }
    else
    {
        cout<<"Its NOT a power of "<<power<<endl;
    }

    return 0;
}
