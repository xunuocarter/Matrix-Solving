#include "fraction.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

fraction::fraction()
{
    num = 0;
    denom = 1;
}

fraction :: fraction(int a, int b)
{
    num=a;
    denom = b;
}
fraction :: fraction(const fraction &other)
{
    num = other.num;
    denom = other.denom;
}

fraction::~fraction()
{
    num = 0;
    denom = 1;
}

ostream& operator<<(ostream& out, const fraction& f)
{
    out << f.num;
    if (f.denom != 1 && f.num != 0)
    {
        out<<"/"<<f.denom;
    }
    return out;
}

fraction& fraction::operator=(const int& other)
{
    num = other;
    denom = 1;
    return *this;
}

fraction& fraction::operator=(const fraction& other)
{
    num = other.num;
    denom = other.denom;
    return *this;
}

fraction& fraction::operator-=(const fraction& other)
{
    num = num * other.denom - other.num * denom;
    denom = other.denom * denom;
    reduce();
    return *this;
}

fraction& fraction::operator+=(const fraction& other)
{
    num = num * other.denom + other.num * denom;
    denom =other.denom * denom;
    reduce();
    return *this;
}

fraction& fraction::operator/=(const fraction& other)
{
    num = num * other.denom;
    denom =other.num * denom;
    reduce();
    return *this;
}

bool operator==(const fraction &x, const fraction &y)
{
   return x.num * y.denom == x.denom * y.num;
}

bool operator!=(const fraction &x, const fraction &y)
{
    return !(x == y);
}

bool operator>(const fraction &x, const fraction &y)
{
   return x.num * y.denom > x.denom * y.num;
}

fraction operator+(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.denom + y.num * x.denom;
    z.denom = x.denom * y.denom;
    z.reduce();//simplify
    return z;
}
fraction operator-(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.denom - y.num * x.denom;
    z.denom = x.denom * y.denom;
    z.reduce();
    return z;
}
fraction operator*(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.num;
    z.denom =y.denom * x.denom;
    z.reduce();
    return z;
}

fraction operator/(const fraction &x, const fraction &y)
{
    fraction z;
    z.num = x.num * y.denom;
    z.denom = x.denom * y.num;
    z.reduce();
    return z;
}

void  fraction:: reduce()
{
    int div;//the common factor
    div = gcd(num, denom);
    div = abs(div);
    num /= div;
    denom /= div;
    if((num < 0 && denom <0) ||(num > 0 && denom <0))
    {
        num *=-1;
        denom *=-1;
    }
}

int fraction::gcd(int p, int q)
{
    return q == 0 ? p : gcd(q, p%q);
}
