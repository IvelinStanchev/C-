#include <iostream>

using namespace std;

bool checkIfTheSame(char firstArray[], char secondArray[], int elementsCount)
{
    for (int i = 0; i < elementsCount; i++)
    {
        if (firstArray[i] != secondArray[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    cin>>n;

    char firstArray[n];
    char secondArray[n];

    cout<<"Enter "<<n<<" letters for the first array: "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>firstArray[i];
    }

    cout<<"Enter "<<n<<" letters for the second array: "<<endl;

    for (int i = 0; i < n; i++)
    {
        cin>>secondArray[i];
    }

    bool areTheSame = checkIfTheSame(firstArray, secondArray, n);

    if (areTheSame)
    {
        cout<<"The two arrays are the same"<<endl;
    }
    else
    {
        cout<<"The two arrays are NOT the same"<<endl;
    }

    return 0;
}
