#include <cmath>
/* MultiplicativeCongruentialGenerator */
// ================================================================= //
// =========================== MGC ================================= //
// ================================================================= //

class MCG
{
private:
    // X_n = a * X_(n-1)  mod m

    unsigned long long _x0 = 0;    //seed
    unsigned long long _xLast = 0; //last X = X_(n-1)
    unsigned long long _a;
    unsigned long long _m;

public:
    MCG();
    MCG(unsigned long long, unsigned long long, unsigned long long);
    ~MCG();
    double GetNumber();
};
MCG::MCG()
{
    _a = std::pow(7, 20);
    _m = std::pow(2, 35) - 31;
    _x0 = _xLast = 1;
}

MCG::MCG(unsigned long long m, unsigned long long a, unsigned long long x0) : _m(m), _a(a), _x0(x0), _xLast(x0) {}

MCG::~MCG(){}

double MCG::GetNumber()
{
    _xLast = (_a * _xLast) % _m;
    return _xLast / (double)_m;
}

// ================================================================= //
// =========================== LCG ================================= //
// ================================================================= //

class LCG
{
private:
    // X_n = a * X_(n-1)  mod m

    unsigned long long _x0 = 0;    //seed
    unsigned long long _xLast = 0; //last X = X_(n-1)
    unsigned long long _a;
    unsigned long long _m;
    unsigned long long _c;

public:
    LCG();
    LCG(unsigned long long, unsigned long long, unsigned long long, unsigned long long);
    ~LCG();
    double GetNumber();
};
LCG::LCG()
{
    _a = std::pow(7, 20);
    _m = std::pow(2, 35) - 31;
    _x0 = _xLast = 1;
    _c = 150889;
}

LCG::LCG(unsigned long long m, unsigned long long a, unsigned long long x0, unsigned long long c) 
                                                            : _m(m), _a(a), _x0(x0), _xLast(x0), _c(c) {}

LCG::~LCG(){}

double LCG::GetNumber()
{
    _xLast = (_a * _xLast + _c) % _m;
    return _xLast / (double)_m;
}