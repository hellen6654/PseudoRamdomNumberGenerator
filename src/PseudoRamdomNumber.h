#ifndef PSESUDORANDOM_H
#define PSESUDORANDOM_H
#include <cmath>
#include <iostream>

class PsesudoRandom
{
private:
    // X_n = a * X_(n-1)  mod m
    // X_n = (a * X_(n-1)+c)  mod m
    unsigned long long _x0 = 0;    //seed
    unsigned long long _xLast = 0; //last X = X_(n-1)
    unsigned long long _a;
    unsigned long long _m;
    unsigned long long _c;

public:
    PsesudoRandom();                                                                               // defaut mcg or lcg
    PsesudoRandom(unsigned long long, unsigned long long, unsigned long long);                     //mcg
    PsesudoRandom(unsigned long long, unsigned long long, unsigned long long, unsigned long long); //lcg
    ~PsesudoRandom();
    double GetMcgOfRamdom();
    double GetMcgOfRamdom(double, double);
    double GetLcgOfRamdom();
    double GetLcgOfRamdom(double, double);
};
PsesudoRandom::PsesudoRandom()
{
    _a = std::pow(5, 5);
    _m = std::pow(2, 35) - 31;
    _x0 = _xLast = 87;
    _c = 150889;
}

PsesudoRandom::PsesudoRandom(unsigned long long m, unsigned long long a, unsigned long long x0)
    : _m(m), _a(a), _x0(x0), _xLast(x0), _c(150889) {}

PsesudoRandom::PsesudoRandom(unsigned long long m, unsigned long long a, unsigned long long x0, unsigned long long c)
    : _m(m), _a(a), _x0(x0), _xLast(x0), _c(c) {}

PsesudoRandom::~PsesudoRandom() {}

double PsesudoRandom::GetMcgOfRamdom()
{
    _xLast = (_a * _xLast) % _m;
    return _xLast / (double)_m;
}

double PsesudoRandom::GetMcgOfRamdom(double amplification, double bias)
{
    _xLast = (_a * _xLast) % _m;
    return (_xLast / (double)_m) * amplification + bias;
}
double PsesudoRandom::GetLcgOfRamdom()
{
    _xLast = (_a * _xLast+_c) % _m;
    return _xLast / (double)_m;
}

double PsesudoRandom::GetLcgOfRamdom(double amplification, double bias)
{
    _xLast = (_a * _xLast + _c) % _m;
    return (_xLast / (double)_m) * amplification + bias;
}
#endif