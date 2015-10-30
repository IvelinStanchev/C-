#include <iostream>

using namespace std;

long long int calculateScalarProduct(int aVectors[], int bVectors[], int vectorsCount)
{
    long long scalarProduct = 0;

    for (int i = 0; i < vectorsCount; i++)
    {
        scalarProduct += aVectors[i] * bVectors[i];
    }

    return scalarProduct;
}

int main()
{
    int n;
    cout<<"n [1, 100]: ";
    cin>>n;

    if (n < 1 || n > 100)
    {
        cout<<"n should be between 1 and 100"<<endl;
    }
    else
    {
        int aVectors[n];
        int bVectors[n];

        for (int i = 0; i < n; i++)
        {
            cout<<"a"<<i<<"= ";
            cin>>aVectors[i];
            cout<<"b"<<i<<"= ";
            cin>>bVectors[i];
        }

        long long int scalarProduct = calculateScalarProduct(aVectors, bVectors, n);

        cout<<"The scalar product is: "<<scalarProduct;
    }

    return 0;
}
