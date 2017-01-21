#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int rowNumbersCounter;

    while (cin>>rowNumbersCounter) {
        vector<int> numbers;
        int currentNumber;

        for (int i = 0; i < rowNumbersCounter; i++) {
            cin>>currentNumber;
            numbers.push_back(currentNumber);
        }

        int currentMax = 1;
        int totalMax = 1;
        int currentBiggerThanLast = 0;

        for (int j = 0; j < rowNumbersCounter; j++) {
            currentBiggerThanLast = numbers[j];
            currentMax = 1;

            for (int p = j + 1; p < rowNumbersCounter; p++) {
                if (numbers[p] >= currentBiggerThanLast) {
                    currentBiggerThanLast = numbers[p];
                    currentMax++;
                }
            }

            if (currentMax > totalMax) {
                totalMax = currentMax;
            }
        }

        cout<<totalMax<<endl;
    }

    return 0;
}
