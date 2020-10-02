#include <iostream>
#include "PseudoRamdomNumber.h"
using namespace std;

void second(int preformTimes)
{
    PsesudoRandom lcg;
    int count = 0;
    int success = 0;
    while (count < preformTimes)
    {
        double x = lcg.GetLcgOfRamdom(2,0.5);
        double y = lcg.GetLcgOfRamdom(3,-1.5);
        if ( (x-y) < 0.5) success++;
        count++;
    }
    cout << "PreformTimes:" << preformTimes  << "\nProbability:" << success / (double)preformTimes << endl;
}
