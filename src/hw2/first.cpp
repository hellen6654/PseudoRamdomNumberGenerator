#include <iostream>
#include <vector>
#include <cmath>
#include "../PseudoRamdomNumber.h"

using namespace std;

void first(double n)
{
    /*A */
    vector<double> seq;
    PsesudoRandom  mcg;
    int times[10]={0};
    for (int i = 0; i < n; i++)
    {
        double number = mcg.GetMcgOfRamdom();
        seq.push_back(number);
        times[(int)(number*10)]++;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << i/10.0<<"-"<<(i+1)/10.0<<": "<<times[i]/n << endl;
    }
    /*B */
    double total=0.0;
    for (auto it :seq)
        total += it;
    double mean = total/n;
    double var = 0.0;
    for (auto it:seq)
    {
        var+= pow((it-mean),2);
    }
    var = var / (n-1);
    cout << "mean:" << mean << endl;
    cout << "var:" << var << endl;
}