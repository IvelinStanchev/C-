#include <iostream>

using namespace std;

int main()
{
    int max = 11;
    int min = 0;
    int sum = 33;
    int counter = 0;

    for (int i = min; i <= max; i++)
    {
        for (int j = min; j <= max; j++)
        {
            for (int z = min; z <= max; z++)
            {
                for (int p = min; p <= max; p++)
                {
                    if ((i + j + z + p) == sum)
                    {
                        cout<<i<<" "<<j<<" "<<z<<" "<<p<<endl;
                        counter++;
                    }
                }
            }
        }
    }

    cout<<"Result: "<<counter<<endl;

    return 0;
}
