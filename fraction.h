#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>
using namespace std;
class fraction
{
    public:
        fraction();//default
        fraction(int a, int b=1);//set denominator as 1
        ~fraction();//destructor
        fraction(const fraction &other);//copy
        fraction& operator=(const int& other);//overload operator = with integer
        fraction& operator=(const fraction& other);//overload operator = with fraction
        fraction& operator-=(const fraction& other);//overload operator -= with fraction
        fraction& operator/=(const fraction& other);//overload operator /= with fraction
        fraction& operator+=(const fraction& other);//overload operator += with fraction
        friend bool operator==(const fraction &x, const fraction &y);//overload operator ==
        friend bool operator!=(const fraction &x, const fraction &y);//overload operator !=
        friend bool operator>(const fraction &x, const fraction &y);//overload operator >
        friend fraction operator+(const fraction &x, const fraction &y);//overload operator +
        friend fraction operator-(const fraction &x, const fraction &y);//overload operator -
        friend fraction operator*(const fraction &x, const fraction &y);//overload operator *
        friend fraction operator/(const fraction &x, const fraction &y);//overload operator /
        friend istream& operator>>(istream& in, fraction &f);//overload operator >>
        friend ostream& operator<<(ostream& out, const fraction &f);//overload operator <<
        void reduce();//simplify the fraction
    private:
        int num, denom;
        int gcd(int p, int q);//common denominator
};
#endif // FRACTION_H
