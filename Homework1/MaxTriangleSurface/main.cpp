#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int trianglesCount = 5;

    int trianglesDimensions[5][3] = {
        { 5, 7, 6},
        { 3, 2, 4},
        { 12, 7, 6},
        { 5, 7, 10},
        { 7, 7, 5},
    };

    int maxTriangleSurfaceNumber = 1;
    int a, b, c;
    double p = 0.0;
    double maxTriangleSurface = 0.0;

    for (int i = 0; i < trianglesCount; i++)
    {
        a = trianglesDimensions[i][0];
        b = trianglesDimensions[i][1];
        c = trianglesDimensions[i][2];
        p = (a + b + c) / 2;

        double currentTriangleSurface = sqrt(p * (p - a) * (p - b) * (p - c));

        if (currentTriangleSurface > maxTriangleSurface)
        {
            maxTriangleSurface = currentTriangleSurface;
            maxTriangleSurfaceNumber = i + 1;
        }
    }

    cout<<"The triangle with number "<<maxTriangleSurfaceNumber<<" and sides ("
    <<trianglesDimensions[maxTriangleSurfaceNumber - 1][0]<<", "
    <<trianglesDimensions[maxTriangleSurfaceNumber - 1][1]<<", "
    <<trianglesDimensions[maxTriangleSurfaceNumber - 1][2]<<") has the biggest surface"<<endl;

    return 0;
}
