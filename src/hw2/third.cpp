#include <iostream>
#include <vector>
#include <cmath>
#include "../PseudoRamdomNumber.h"
using namespace std;

class point
{
private:
    double _x, _y;

public:
    point(double x, double y) : _x(x), _y(y){};
    double getX() { return _x; }
    double getY() { return _y; }
    double D()
    {
        // Distance for point to (0,0)
        return _x * _x + _y * _y;
    }
    double D(point A)
    {
        return sqrt(pow(A.getX() - _x, 2) + pow((A.getY() - _y), 2));
    }
};

void third(unsigned interval)
{
    //monte carlo to calc pi
    // pi = 4 * (num of point inside the circle / num of total point)
    /*
                       1 
        ┌----------------------------┐
        │///////++++++║║++++++///////│
        │/////++++++++║║+++++++++////│
        │///++++++++++║║++++++++++///│
        │/++++++++++++║║++++++++++++/│
        │+++++++++++++║║+++++++++++++│
        │+++++++++++++║║+++++++++++++│
        │═════════════╣╠═════════════│ 1
        │+++++++++++++║║+++++++++++++│
        │+++++++++++++║║+++++++++++++│
        │/++++++++++++║║++++++++++++/│
        │///++++++++++║║++++++++++///│
        │/////++++++++║║++++++++/////│
        │///////++++++║║++++++///////│
        └----------------------------┘
        ramdom a point between 1,-1
        when point locate in '+' , num of point inside the circle++ 
    */
    double pi = 0.0;
    int circlePointNum = 0;
    int squarePointNum = 0; // also mean total point
    PsesudoRandom lcg;
    for (unsigned long long i = 0; i < interval; i++)
    {
        point temp(lcg.GetLcgOfRamdom(2, -1), lcg.GetLcgOfRamdom(2, -1));
        squarePointNum++;
        if (temp.D() <= 1)
            circlePointNum++;
        pi = 4.0 * circlePointNum / squarePointNum;

        if ((i+1) % 100000000 == 0)
        {
            cout <<"After " << squarePointNum << "/"<< interval << " times calc:" << endl;
            cout << pi << endl;
        }
    }
}