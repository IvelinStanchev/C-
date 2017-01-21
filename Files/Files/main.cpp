#include <fstream>
#include <iostream>
using namespace std;

void display_members()
{
    string getcontent;
    ifstream openfile ("example.txt");
    if(openfile.is_open())
    {
        while(! openfile.eof())
        {
            getline(openfile, getcontent);
            cout << getcontent << endl;
        }
    }
}

int main ()
{
    display_members();

    return 0;
}
