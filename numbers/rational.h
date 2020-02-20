#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdint>
#include <iostream>

class Rational
{
public:
    Rational();

    Rational( int64_t theNumerator, uint64_t theDenumerator = 1 );
    Rational( Rational const &q );
    Rational & operator=( Rational const &q );

    Rational operator+( Rational const &q ) const;
    Rational operator-( Rational const &q ) const;
    Rational operator*( Rational const &q ) const;
    Rational operator/( Rational const &q ) const;

    Rational operator-( void ) const;

    Rational & operator+=( Rational const &q );
    Rational & operator-=( Rational const &q );
    Rational & operator*=( Rational const &q );
    Rational & operator/=( Rational const &q );

    bool operator<( Rational const &q ) const;
    bool operator<=( Rational const &q ) const;
    bool operator>( Rational const &q ) const;
    bool operator>=( Rational const &q ) const;
    bool operator==( Rational const &q ) const;

    operator float( void ) const;
    operator double( void ) const;

    int64_t numerator( void ) const;
    uint64_t denumerator( void ) const;

private:
    void add( Rational const &q, int64_t &num, uint64_t &denum ) const;
    void sub( Rational const &q, int64_t &num, uint64_t &denum ) const;
    void mul( Rational const &q, int64_t &num, uint64_t &denum ) const;
    void div( Rational const &q, int64_t &num, uint64_t &denum ) const;
    static int64_t gcd( uint64_t n1, uint64_t n2 );

    int64_t theNumerator;
    uint64_t theDenumerator;
};

std::ostream & operator<<( std::ostream &os, Rational const &q );

#endif // RATIONAL_H

