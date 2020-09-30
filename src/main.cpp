#include <iostream>
#include "PseudoRamdomNumber.h"
using namespace std;

int main()
{
    MCG mcg;
    for(int i = 0; i<5;i++)
    {
        cout << mcg.GetNumber() << endl;
    }
}