#include <iostream>

using namespace std;

bool isInCircle(double x, double y)
{
    double circleCenterX = -1;
    double circleCenterY = 0;
    double radius = 1;

    if (((x - circleCenterX) * (x - circleCenterX) + (y - circleCenterY) * (y - circleCenterY)) <= (radius * radius))
    {
        return true;
    }

    return false;
}

bool isOutOfSmallRectangle(double x, double y)
{
    double rectangleLeftX = 1;
    double rectangleBottomY = 0.5;

    if (x > rectangleLeftX && y > rectangleBottomY)
    {
        return false;
    }

    return true;
}

bool checkIfInFigure(double x, double y)
{
    if (!isInCircle(x, y) &&
        (x >= -1 && x <= 2 && y <= 1 && y >= -1) && isOutOfSmallRectangle(x, y))
    {
        return true;
    }

    return false;
}

int main()
{
    double x, y;
    cout<<"x: ";
    cin>>x;
    cout<<"y: ";
    cin>>y;

    bool isInFigure = checkIfInFigure(x, y);

    if (isInFigure)
    {
        cout<<"The point ("<<x<<", "<<y<<") is in the figure"<<endl;
    }
    else
    {
        cout<<"The point ("<<x<<", "<<y<<") is NOT in the figure"<<endl;
    }

    return 0;
}

