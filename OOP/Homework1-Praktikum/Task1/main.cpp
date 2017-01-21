#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Hex
{
    private:
        char *number;

    public:
        Hex ()
        {
        }

        Hex (int decimalNumber)
        {
            char *buffer;
            itoa (decimalNumber, buffer, 16);

            this->number = buffer;
        }

        Hex (char *decimalNumberAsString)
        {
            this->number = decimalNumberAsString;
        }

        friend Hex operator+(const Hex& first, const Hex& second);

        char* toString()
        {
            return this->number;
        }
};

Hex operator + (Hex lhs, Hex rhs)
{
    return lhs;
}

int main()
{
    int i;
    cout<<"Enter decimal number: ";
    cin>>i;

    Hex hexadecimalNumber(i);
    Hex hexadecimalNumberString("face");

    cout<<hexadecimalNumber.toString()<<endl;
    cout<<hexadecimalNumberString.toString()<<endl;

    return 0;
}
