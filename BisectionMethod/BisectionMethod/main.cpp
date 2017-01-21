#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>

using namespace std;

const int PRECISION = 20;
const unsigned long double INTERVAL_MIN = 1.0L;
const long double INTERVAL_MAX = 10.0L;
const int MAX_ITERATIONS = 1000;
const long double TOLERANCE = 0.0000000000000000001L;

long double customPow(long double number, int degree)
{
    long double numberCopy = number;

    for (int i = 2; i <= degree; i++) {
        numberCopy *= (number * 1000000000);
        numberCopy /= 1000000000;
    }

    return numberCopy;
}

long double calculateFunctionValue(long double x, long double b, long double c)
{
    // f(x) = x^5 - b*x - c

    return customPow(x, 5) - (b * x) - c;
}

bool hasOppositeSigns(long double value1, long double value2) {
    if (value1 < (long double)0.0L && value2 > (long double)0.0L) {
        return true;
    }
    if (value1 > (long double)0.0L && value2 < (long double)0.0L) {
        return true;
    }

    return false;
}

void calculateAndPrintResultWithBisectionMethod(long double b, long double c) {

    long double x0 = INTERVAL_MIN, x1 = INTERVAL_MAX;
    long double lastFunctionValue = calculateFunctionValue(x0, b, c);

    if (lastFunctionValue == 0.0) {
        cout<<x0<<endl;
        return;
    }

    long double currentFunctionValue;

    for (int i = x0 + 1; i <= x1; i++) {
        currentFunctionValue = calculateFunctionValue(i, b, c);

        if (currentFunctionValue == 0.0) {
            cout<<i<<endl;
            return;
        }

        if (hasOppositeSigns(lastFunctionValue, currentFunctionValue)) {
            x1 = i;
            break;
        } else {
            x0 = i;
        }
    }

    if (x0 == x1 || x0 > x1) {
        cout<<"NO SOLUTION"<<endl;
        return;
    }

    long double mid, leftFunctionValue, rightFunctionValue, midFunctionValue;
    int iterations = 0;

    while (true) {

        mid = (long long int)(x0 * 10000000000 + x1 * 10000000000) / (long long int)(2.0 * 10000000000);
        midFunctionValue = calculateFunctionValue(mid, b, c);
        leftFunctionValue = calculateFunctionValue(x0, b, c);
        rightFunctionValue = calculateFunctionValue(x1, b, c);

        cout.precision(PRECISION + 20);
        cout<<"x0: "<<x0<<endl;
        cout<<"x1: "<<x1<<endl;
        cout<<"mid: "<<midFunctionValue<<endl;

        if ((midFunctionValue <= TOLERANCE &&
            midFunctionValue >= ((TOLERANCE * (1000000000 * (-1))) / 1000000000)) ||
            iterations > MAX_ITERATIONS) {
            cout<<setprecision(PRECISION)<<mid<<endl;
            break;
        } else {
            if (calculateFunctionValue(x0, b, c) * calculateFunctionValue(mid, b, c) > 0) {
                x0 = mid;
            } else {
                x1 = mid;
            }

            /*if (hasOppositeSigns(leftFunctionValue, midFunctionValue)) {
                x1 = mid;
            } else if (hasOppositeSigns(midFunctionValue, rightFunctionValue)) {
                x0 = mid;
            }*/
        }

        iterations++;
    }
}

int main() {
    long double currentNumber;
    int facultyNumber = 123456;
    cout.precision(PRECISION + 20);

    while (cin>>currentNumber) {
        calculateAndPrintResultWithBisectionMethod((long double)currentNumber, (long double)(facultyNumber % 100));
    }

    return 0;
}
