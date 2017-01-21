#include <iostream>

using namespace std;

int intPow(int base, int power)
{
    int result = 1;

    for (int i = 1; i <= power; i++)
    {
        result *= base;
    }

    return result;
}

bool isArmstrongNumber(int number, int digits[], int digitsCount)
{
    int sum = 0;

    for (int i = 0; i < digitsCount; i++)
    {
        sum += intPow(digits[i], 3);
    }

    if (sum == number)
    {
        return true;
    }

    return false;
}

void printSameElements(int n1, int n2, int firstArray[], int secondArray[])
{
    cout<<"The common elements are: ";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (firstArray[i] == secondArray[j])
            {
                cout<<firstArray[i]<<"   ";
                break;
            }
        }
    }

    cout<<endl;
}

void printFirstArrayElementsWhichAreNotCommon(int n1, int n2, int firstArray[], int secondArray[])
{
    bool isInSecondArray = false;
    cout<<"The first array elements which are not common and are not divisible by 17 are: ";
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (firstArray[i] == secondArray[j])
            {
                isInSecondArray = true;
                break;
            }
        }

        if (!isInSecondArray && firstArray[i] % 17 != 0)
        {
            cout<<firstArray[i]<<"   ";
        }

        isInSecondArray = false;
    }

    cout<<endl;
}

void printFirstArrayArmstrongNumbers(int n1, int firstArray[])
{
    int digitsCount = 0;
    int digits[20];
    int currentNumber;
    int currentNumberCopy;

    cout<<"Armstrong numbers from first array: ";
    for (int i = 0; i < n1; i++)
    {
        currentNumber = firstArray[i];
        currentNumberCopy = currentNumber;

        while (currentNumberCopy > 0)
        {
            digits[digitsCount] = currentNumberCopy % 10;
            currentNumberCopy /= 10;
            digitsCount++;
        }

        if (isArmstrongNumber(currentNumber, digits, digitsCount))
        {
            cout<<currentNumber<<"   ";
        }

        digitsCount = 0;
    }

    cout<<endl;
}

int main()
{
    int n1, n2;

    cout<<"Enter the length of the first array: ";
    cin>>n1;
    cout<<"Enter the length of the second array: ";
    cin>>n2;

    int firstArray[n1], secondArray[n2];

    cout<<"Enter "<<n1<<" numbers for the first array:"<<endl;

    for (int i = 0; i < n1; i++)
    {
        cin>>firstArray[i];
    }

    cout<<"Enter "<<n2<<" numbers for the second array:"<<endl;

    for (int i = 0; i < n2; i++)
    {
        cin>>secondArray[i];
    }

    //TaskA
    printSameElements(n1, n2, firstArray, secondArray);
    //TaskB
    printFirstArrayElementsWhichAreNotCommon(n1, n2, firstArray, secondArray);
    //TaskC
    printFirstArrayArmstrongNumbers(n1, firstArray);

    return 0;
}
