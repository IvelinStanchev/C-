#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long int inputCounter;
    cin>>inputCounter;

    unsigned long long int rowInputCounter;

    for (long int i = 0; i < inputCounter; i++) {
        cin>>rowInputCounter;

        unsigned long long int *numbers = new unsigned long long int[rowInputCounter];

        for (unsigned long long int j = 0; j < rowInputCounter; j++) {
            cin>>numbers[j];
        }

        sort(numbers, numbers + rowInputCounter);

        if (rowInputCounter % 2 != 0) {
            cout<<numbers[rowInputCounter / 2]<<endl;
        }
        else {
            cout<<numbers[(rowInputCounter / 2) - 1]<<endl;
        }
    }

    return 0;
}
