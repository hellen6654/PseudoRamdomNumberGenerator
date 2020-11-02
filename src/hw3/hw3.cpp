#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../PseudoRamdomNumber.h"

using namespace std;

double transform(double u, double lambda)
{
    return (-1) * (1 / lambda) * log(1 - u);
}

void first(double n, double lambda)
{
    /*A */
    vector<double> t;
    PsesudoRandom lcg;
    int times[40] = {0};
    for (int i = 0; i < n; i++)
    {
        double un = lcg.GetLcgOfRamdom();
        double tn = transform(un, lambda);
        t.push_back(tn);
        if (tn < 40)
            times[(int)tn]++;
    }
    for (auto t : times)
        cout << t << endl;
    /*B */
    double total = 0.0;

    for (auto it : t)
        total += it;
    double mean = total / n;

    double var = 0.0;
    for (auto it : t)
    {
        var += pow((it - mean), 2);
    }
    var = var / (n - 1);
    cout << "n:" << n << endl;
    cout << "mean:" << mean << endl;
    cout << "var:" << var << '\n'
         << endl;
}

void second(double meanA, double meanB)
{
    double n = 100000;
    PsesudoRandom lcg;
    double lambdaA = 1 / meanA;
    double lambdaB = 1 / meanB;
    double times = 0;
    for (int i = 0; i < n; i++)
    {
        double A = transform(lcg.GetLcgOfRamdom(), lambdaA);
        double B = transform(lcg.GetLcgOfRamdom(), lambdaB);

        if (B < A) // B的間隔時間比A的間隔時間還小 => B比A早發生
            times++;
    }
    cout << "n:" << n << endl;
    cout << times / n << endl;
}

double z(double v, double w)
{
    return cos(2 * M_PI * v) * sqrt((-2) * log(w));
}

void third()
{
    double n = 100000;
    int times = 0;
    PsesudoRandom lcg, mcg;
    for (int i = 0; i < n; i++)
    {
        double temp = z(mcg.GetMcgOfRamdom(), lcg.GetLcgOfRamdom());
        if (temp > -1 && temp < 2)
            times++;
    }
    cout << "n:" << n << endl;
    cout << "P=" << times / n << endl;
}
vector<int> exchange(vector<int> x, int indexA, int indexB)
{
    int temp = x[indexA];
    x[indexA] = x[indexB];
    x[indexB] = temp;
    return x;
}

int checkConsecutive(vector<int> x)
{
    for (int m = 0; m < 6; m++)
    {
        for (int n = m; n < 6; n++)
        {
            if (x[m] + 1 == x[n] || x[m] - 1 == x[n])
            {
                //有連續
                return 1;
            }
        }
    }
    return 0;
}

void fourth()
{
    double n = 100000;
    PsesudoRandom mcg;
    int times = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> x;
        for (int t = 1; t <= 45; t++)
            x.push_back(t);
        int count = 44;
        for (int j = 0; j < 6; j++)
        {
            int r = mcg.GetMcgOfRamdom(count, 0);
            x = exchange(x,r , count);
            count--;
        }
        reverse(x.begin(), x.end());
        times += checkConsecutive(x);
    }
    cout << "n:" << n << endl;
    cout << "P=" << times / n << endl;
}