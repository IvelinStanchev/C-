#include <iostream>
#include <math.h>

using namespace std;

double calculateSurface(double radius)
{
    double surface = M_PI * radius * radius;

    return surface;
}

int main()
{
    double radius;
    cout<<"Enter radius: ";
    cin>>radius;

    double circleSurface = calculateSurface(radius);

    cout<<"The surface is: "<<circleSurface<<endl;

    return 0;
}
