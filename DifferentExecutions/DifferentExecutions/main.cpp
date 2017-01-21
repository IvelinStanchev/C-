#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

int * primeNumbers = new int[2000];
int primeNumbersCount = 0;

bool isPrime(int number) {
    if (number % 2 == 0) {
        return false;
    }

    int i = 0;
    double sqrtNumber = sqrt(number);

    while (primeNumbers[i] <= sqrtNumber) {
        if (number % primeNumbers[i] == 0) {
            return false;
        }

        i++;
    }

    return true;
}

void initPrimeNumbers() {
    int n = 20000;

    bool * used = new bool[n];

    for (int j = 2; j <= n; j++)
    {
        used[j] = 0;
    }

    for (int i = 2; i < sqrt(n); i++)
    {
        for (int j = i * 2; j <= n; j += i)
        {
            if (!used[j]) {
                used[j] = 1;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (!used[i])
        {
            primeNumbers[primeNumbersCount] = i;
            primeNumbersCount++;
        }
    }
}

int getReversedNumber(int number) {
    int reversedNumber = 0;
    int remainder;

    while(number != 0)
    {
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number /= 10;
    }

    return reversedNumber;
}

int getPrimeNumbersCountInIntervalBoosted(int a, int b) {
    int primesCount = 0;

    if (b - a > 200) {


        int startingNumber = a;

        while (startingNumber < b) {
            if (startingNumber % 3 == 0 && startingNumber % 2 != 0) {
                break;
            }

            if (isPrime(startingNumber)) {
                primesCount++;
            }

            startingNumber++;
        }

        startingNumber += 2;

        int counter = 0;

        for (int i = startingNumber; i <= b; i++) {
            counter++;

            if (isPrime(i)) {
                primesCount++;
            }

            if (counter == 3) {
                counter = 0;
                i += 3;
            }

        }



    } else {
        for (int i = a; i <= b; i++) {
            if (isPrime(i)) {
                primesCount++;
            }
        }
    }

    return primesCount;
}

int getPrimeNumbersCountInInterval(int a, int b) {
    int primesCount = 0;

    bool isAEven = a % 2 == 0;

    int startingNumber = a;

    if (isAEven) {
        startingNumber++;

        if (isPrime(a)) {
            primesCount++;
        }
    }

    for (int i = startingNumber; i <= b; i += 2) {
        if (isPrime(i)) {
            primesCount++;
        }
    }

    return primesCount;
}

void printPrimeNumbersInInterval(int a, int b) {
    cout<<getPrimeNumbersCountInIntervalBoosted(a, b)<<endl;
}

void printLSDOfNumber(int number) {
    for (int i = 2; i < number; i++) {
        if (number % i == 0 && isPrime(i)) {
            cout<<i<<endl;
            return;
        }
    }
}

void printIsNumberPrime(int number) {
    if (isPrime(number)) {
        cout<<"1"<<endl;
    } else {
        cout<<"0"<<endl;
    }
}

void printIsReversedNumberPrime(int number) {
    int reversedNumber = getReversedNumber(number);
    printIsNumberPrime(reversedNumber);
}

void printNearestPrimeNumberToNumber(int number) {
    int nearestPrimeLeftNumber, nearestPrimeRightNumber;

    for (int i = number; i >= 2; i--) {
        if (isPrime(i)) {
            nearestPrimeLeftNumber = i;
            break;
        }
    }

    if (nearestPrimeLeftNumber != number) {
        for (int i = number + 1; i <= number * number; i++) {
            if (isPrime(i)) {
                nearestPrimeRightNumber = i;
                break;
            }
        }

        int leftDifference = number - nearestPrimeLeftNumber;
        int rightDifference = nearestPrimeRightNumber - number;

        if (leftDifference == rightDifference) {
            cout<<nearestPrimeLeftNumber<<" "<<nearestPrimeRightNumber<<endl;
        } else {
            if (leftDifference < rightDifference) {
                cout<<nearestPrimeLeftNumber<<endl;
            } else {
                cout<<nearestPrimeRightNumber<<endl;
            }
        }
    } else {
        cout<<nearestPrimeLeftNumber<<endl;
    }
}

void printPrimeNumbersCountLowerThanNumber(int number) {
    cout<<getPrimeNumbersCountInInterval(2, number)<<endl;
}

int main()
{
	string operation;
	int  number1, number2;

    initPrimeNumbers();

	while(cin>>operation) {
	    if (operation == "quit" || operation == "QUIT" || operation == "Quit") {
            break;
	    }

        if (operation == "a" || operation == "A") {
            cin>>number1>>number2;
            printPrimeNumbersInInterval(number1, number2);
        } else if (operation == "b" || operation == "B") {
            cin>>number1;
            printLSDOfNumber(number1);
        } else if (operation == "c" || operation == "C") {
            cin>>number1;
            printIsNumberPrime(number1);
        } else if (operation == "d" || operation == "D") {
            cin>>number1;
            printIsReversedNumberPrime(number1);
        } else if (operation == "e" || operation == "E") {
            cin>>number1;
            printNearestPrimeNumberToNumber(number1);
        } else if (operation == "f" || operation == "F") {
            cin>>number1;
            printPrimeNumbersCountLowerThanNumber(number1);
        }
	}

	return 0;
}
