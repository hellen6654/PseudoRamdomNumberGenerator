#include <iostream>
#include <vector>
#include <cmath>
#include "../PseudoRamdomNumber.h"

using namespace std;

void fourth()
{
    int times = 0;
    PsesudoRandom lcg;
    for (int i = 0; i < 10000; i++)
    {
        int day[365] = {0};
        for (int i = 0; i < 23; i++)
            day[(int)(lcg.GetLcgOfRamdom(365, 0))]++;
        for (int i = 0; i < 365; i++)
        {
            if (day[i] >= 2)
            {
                times++;
                break;
            }
        }
        if ((i+1) % 1000 == 0 )
        {
            cout <<string("Run ");
            cout << (i+1) ;
            cout << string(" time: ") <<   times / (i+1.0) << endl;
        }
        
        
    }
}
