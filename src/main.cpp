#include <iostream>
#include "hw2/first.cpp"
#include "hw2/second.cpp"
#include "hw2/third.cpp"
#include "hw2/fourth.cpp"

using namespace std;

int main()
{
    cout << "=====first======" <<endl;
    cout << "=====10000======" <<endl;
    first(10000);
    cout << "=====50000======" << endl;
    first(50000);
    cout << "====100000======" <<endl;
    first(100000);
    cout << "================" <<endl;
    cout << "=====second=====" <<endl;
    cout << "======5000======" <<endl;
    second(5000);
    cout << "=====second=====" <<endl;
    cout << "=====10000======" <<endl;
    second(10000);
    cout << "=====second=====" <<endl;
    cout << "=====50000======" <<endl;
    second(50000);
    cout << "=====third======" <<endl;
    third(1000000000);
    cout << "=====fourth=====" <<endl;
    fourth();
}

