#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand((int)time(0));

    int randomNumber = (rand() % 100) + 1;

    int input;
    int tries = 0;

    while (true)
    {
        cin>>input;
        tries++;

        if (input == randomNumber)
        {
            break;
        }

        if (input < randomNumber)
        {
            cout<<"Your number was smaller"<<endl;
        }
        else
        {
            cout<<"Your number was bigger"<<endl;
        }
    }

    cout<<"Tries: "<<tries<<endl;

    return 0;
}
