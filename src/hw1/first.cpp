#include <iostream>
#include "../PseudoRamdomNumber.h"
using namespace std;

void CalcTossPoint(PsesudoRandom *PsesudoRandom, int *diePoint)
{
    //die toss four times
    for (int i = 0; i < 4; i++)
    {
        double temp = PsesudoRandom->GetMcgOfRamdom();
        //calc toss point
        for (int i = 0; i < 6; i++)
        {
            if (temp <= ((i+1) / 6.0))
            {
                diePoint[i]++;
                break;
            }
        }
    }
}

int CalcFourDifferent(int *diePoint)
{
    int temp = 0;
    for (int i = 0; i < 6; i++)
    {
        if (diePoint[i] == 1)
            temp++;
    }
    if (temp == 4)
    {
        return 1;
    }
    return 0;
}

void first(double preformTimes)
{
    PsesudoRandom PsesudoRandom;
    int count = 0;
    int success = 0;
    while (count < preformTimes)
    {
        int diePoint[6] = {0};
        CalcTossPoint(&PsesudoRandom, diePoint);
        success += CalcFourDifferent(diePoint);
        count++;
    }
    cout << "PreformTimes:" << preformTimes  << "\nProbability:" << success / preformTimes << endl;
}
