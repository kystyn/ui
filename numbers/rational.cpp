#include <algorithm>
#include <iostream>
#include "rational.h"

std::ostream & operator<<( std::ostream &os, Rational const &q )
{
    os << q.numerator() << '/' << q.denumerator();
    return os;
}

Rational::Rational()
{
}

Rational::Rational( int64_t numerator, uint64_t denumerator ) :
    theNumerator(numerator), theDenumerator(denumerator)
{
}

void Rational::add( Rational const &q, int64_t &num, uint64_t &denum ) const
{
    num = theNumerator * int64_t(q.theDenumerator) +
                      int64_t(theDenumerator) * q.theNumerator;
    denum = theDenumerator * q.theDenumerator;

    auto div = gcd(uint64_t((2 * (num > 0) - 1) * num), denum);

    num /= div;
    denum /= uint64_t(div);
}

void Rational::sub( Rational const &q, int64_t &num, uint64_t &denum ) const
{
    num = theNumerator * int64_t(q.theDenumerator) -
                      int64_t(theDenumerator) * q.theNumerator;
    denum = theDenumerator * q.theDenumerator;

    auto div = gcd(uint64_t((2 * (num > 0) - 1) * num), denum);

    num /= div;
    denum /= uint64_t(div);
}

void Rational::mul( Rational const &q, int64_t &num, uint64_t &denum ) const
{
    num = theNumerator * q.theNumerator;
    denum = theDenumerator * q.theDenumerator;

    auto div = gcd(uint64_t((2 * (num > 0) - 1) * num), denum);

    num /= div;
    denum /= uint64_t(div);
}

void Rational::div( Rational const &q, int64_t &num, uint64_t &denum ) const
{
    num = theNumerator * int64_t(q.theDenumerator);
    auto newDenum = int64_t(theDenumerator) * q.theNumerator;
    num *= (2 * (newDenum >= 0) - 1);
    denum = uint64_t(newDenum * (2 * (newDenum >= 0) - 1));

    auto div = gcd(uint64_t((2 * (num > 0) - 1) * num), denum);

    num /= div;
    denum /= uint64_t(div);
}

Rational Rational::operator+( Rational const &q ) const
{
    int64_t num;
    uint64_t denum;
    add(q, num, denum);

    return Rational(num, denum);
}

Rational Rational::operator-( Rational const &q ) const
{
    int64_t num;
    uint64_t denum;
    sub(q, num, denum);

    return Rational(num, denum);
}

Rational Rational::operator*( Rational const &q ) const
{
    int64_t num;
    uint64_t denum;
    mul(q, num, denum);

    return Rational(num, denum);
}

Rational Rational::operator/( Rational const &q ) const
{
    int64_t num;
    uint64_t denum;
    div(q, num, denum);

    return Rational(num, denum);
}

Rational & Rational::operator+=( Rational const &q )
{
    int64_t num;
    uint64_t denum;
    add(q, num, denum);

    theNumerator = num;
    theDenumerator = denum;

    return *this;
}

Rational & Rational::operator-=( Rational const &q )
{
    int64_t num;
    uint64_t denum;
    sub(q, num, denum);

    theNumerator = num;
    theDenumerator = denum;

    return *this;
}

Rational & Rational::operator*=( Rational const &q )
{
    int64_t num;
    uint64_t denum;
    mul(q, num, denum);

    theNumerator = num;
    theDenumerator = denum;

    return *this;
}

Rational & Rational::operator/=( Rational const &q )
{
    int64_t num;
    uint64_t denum;
    div(q, num, denum);

    theNumerator = num;
    theDenumerator = denum;

    return *this;
}

Rational::operator float( void ) const
{
    return float(theNumerator) / theDenumerator;
}

Rational::operator double( void ) const
{
    return double(theNumerator) / theDenumerator;
}

int64_t Rational::numerator( void ) const
{
    return theNumerator;
}

uint64_t Rational::denumerator( void ) const
{
    return theDenumerator;
}

int64_t Rational::gcd( uint64_t n1, uint64_t n2 )
{
    auto
            a = std::max(n1, n2),
            b = std::min(n1, n2);

    auto t = a;

    while (b != 0)
    {
        t = b;
        b = a % b;
        a = t;
    }

    return int64_t(a);
}
