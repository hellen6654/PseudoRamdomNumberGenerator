#include <iostream>
#include <vector>
#include <cmath>
#include "../PseudoRamdomNumber.h"

using namespace std;
double P(double p, int k)
{
    // (1-p)^(k-1)*p
    return pow((1 - p), k - 1) * p;
}
void second(double n)
{
    /*A */
    vector<double> T;
    int times[31] = {0};
    PsesudoRandom mcg;
    for (int i = 0; i < n; i++)
    {
        double t = 1 + floor(log(mcg.GetMcgOfRamdom()) / log(0.9));
        T.push_back(t);
    }

    for (int i = 1; i <= 30; i++)
    {
        for (auto it : T)
        {
            if (it == i)
            {
                times[i]++;
            }
        }
    }
    for (int it = 1; it <= 31; it++)
    {
        cout << times[it] / n << endl;
    }

    /*B */
    double mean = 0.0, var = 0.0;
    for (auto it : T)
    {
        mean += it;
    }
    mean /= n;
    for (auto it : T)
    {
        var += pow(it - mean, 2);
    }
    var /= n;
    cout << "mean: " << mean << endl;
    cout << "vari: " << var << endl;
}
