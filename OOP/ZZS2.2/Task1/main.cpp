#include <iostream>
#include <string.h>

using namespace std;

int calculateLength(char* input)
{
    int length = 0;
    while (input[length] != '\0')
    {
        length++;
    }

    return length;
}

class BankAccount
{
    char clientName[50];
    char accountNumber[20];
    double balance;

public:
    void set_values(char[], char[], double);

    void depositMoney(double amount)
    {
        balance += amount;
    }

    void withdrawMoney(double amount)
    {
        balance -= amount;
    }

    void printAccountInformation()
    {
        cout<<"Account Balance: "<<balance<<endl;

        cout<<"Your name: ";
        for (int i = 0; i < strlen(clientName); i++)
        {
            cout<<clientName[i];
        }

        cout<<endl;

        cout<<"Your account number: ";
        for (int i = 0; i < strlen(accountNumber); i++)
        {
            cout<<accountNumber[i];
        }

        cout<<endl;
        cout<<endl;
    }
};

void BankAccount::set_values(char clientName[50], char accountNumber[20], double balance)
{
    for (int i = 0; i < strlen(clientName); i++)
    {
        this->clientName[i] = clientName[i];
    }

    this->clientName[strlen(clientName)] = '\0';

    for (int i = 0; i < strlen(accountNumber); i++)
    {
        this->accountNumber[i] = accountNumber[i];
    }

    this->accountNumber[strlen(accountNumber)] = '\0';

    this->balance = balance;
}

int main()
{
    BankAccount bankAccount;

    bankAccount.set_values("Pesho", "PeshoTest", 100);
    bankAccount.printAccountInformation();

    bankAccount.depositMoney(150.5);
    bankAccount.printAccountInformation();

    bankAccount.withdrawMoney(150.5);
    bankAccount.printAccountInformation();

    return 0;
}
