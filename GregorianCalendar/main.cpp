#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool isLeapYear(int year)
{
    if (year % 4 != 0)
    {
        return false;
    }
    if (year % 100 != 0)
    {
        return true;
    }
    if (year % 400 != 0)
    {
        return false;
    }

    return true;
}

bool isCorrectDate(char cMonth[], char cDay[], char cYear[])
{
    int year = (cYear[0] - 48) * 1000 + (cYear[1] - 48) * 100 + (cYear[2] - 48) * 10 + (cYear[3] - 48);
    int month = (cMonth[0] - 48) * 10 + (cMonth[1] - 48);
    int day = (cDay[0] - 48) * 10 + (cDay[1] - 48);

    if (year <= 0)
    {
        return false;
    }

    if (month < 1 || month > 12)
    {
        return false;
    }
    else
    {
        switch(month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (day > 31 || day < 1)
                {
                    return false;
                }
            case 2:
                if (isLeapYear(year))
                {
                    if (day < 1 || day > 29)
                    {
                        return false;
                    }
                }
                else
                {
                    if (day < 1 || day > 28)
                    {
                        return false;
                    }
                }
            case 4:
            case 6:
            case 9:
            case 11:
                if (day > 31 || day < 1)
                {
                    return false;
                }
        }
    }

    return true;
}

int main()
{
    char cMonth[3];
    char cDay [3];
    char cYear[5];

    cout << "Enter a date in the form mm.dd.yyyy: " ;

    cin.get(cMonth, 3, '.');
    cin.ignore(2, '.');
    cin.get(cDay, 4, '.');
    cin.ignore(2, '.');
    cin.get(cYear, 5);

    if (isCorrectDate(cMonth, cDay, cYear))
    {
        cout<<"The date is correct";
    }
    else
    {
        cout<<"The date is NOT correct";
    }

    return 0;
}
