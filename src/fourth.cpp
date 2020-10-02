#include <iostream>
#include <vector>
#include "PseudoRamdomNumber.h"
using namespace std;

char checkTorH(double num)
{
    //tail = 0 / head = 1
    if (num > 0.5)
    {
        return 'T';
    }
    else
    {
        return 'H';
    }
}

int calc(PsesudoRandom *mcg)
{
    vector<char> temp;
    while (1)
    {
        temp.push_back(checkTorH(mcg->GetMcgOfRamdom()));
        int tPos = 0;
        int hAmount = 0;
        vector<char>::iterator begin = temp.begin();
        vector<char>::iterator i;
        for (i = begin; i != temp.end(); i++)
        {

            if (*i == 'T')
            {
                tPos = i - begin;
                if (hAmount < 4 && tPos <= 4)
                {
                    return 0;
                }

                if (hAmount >= 4 && tPos > 4)
                {
                    return 1;
                }
            }
            else
            {
                hAmount++;
            }
        }
    }
}

void fourth(int preformTimes)
{
    PsesudoRandom mcg;
    int count = 0;
    int success = 0;
    while (count < preformTimes)
    {
        success += calc(&mcg);
        count++;
    }
    cout << "PreformTimes:" << preformTimes << "\nProbability:" << success / (double)preformTimes << endl;
}
