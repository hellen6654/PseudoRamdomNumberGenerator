#include <iostream>
#include "PseudoRamdomNumber.h"
using namespace std;

int xWin(PsesudoRandom *lcg);

void third(int preformTimes)
{
    PsesudoRandom lcg;
    int count = 0;
    int success = 0;
    while (count < preformTimes)
    {
        success+=xWin(&lcg);
        count++;
    }
    cout << "PreformTimes:" << preformTimes << "\nProbability:" << success / (double)preformTimes << endl;
}

int xWin(PsesudoRandom *lcg)
{
    while (1)
    {
        double x = lcg->GetLcgOfRamdom();
        
        if (x < 0.4)
        {
            return 1;
        }
        double y = lcg->GetLcgOfRamdom();
        if(y < 0.4)
        {
            return 0;
        }
    }
}