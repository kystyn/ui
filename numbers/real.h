#ifndef REAL_H
#define REAL_H

#include "rational.h"

class Real
{
public:
    Real();
    Real( Real const &r );
    Real( Rational const &theLeft, Rational const &theRight );
    Real( Rational const &r );

    Real & byCenterAndRadius( Rational const &center,
                              Rational const & radius );

    Real & operator=( Real const &r );

    Real operator+( Real const &r ) const;
    Real operator-( Real const &r ) const;
    Real operator*( Real const &r ) const;
    Real operator/( Real const &r ) const;

    Real operator-( void ) const;

    Real & operator+=( Real const &r );
    Real & operator-=( Real const &r );
    Real & operator*=( Real const &r );
    Real & operator/=( Real const &r );

    bool operator<( Real const &q ) const;
    bool operator<=( Real const &q ) const;
    bool operator>( Real const &q ) const;
    bool operator>=( Real const &q ) const;
    bool operator==( Real const &q ) const;

    operator float( void ) const;
    operator double( void ) const;

    Rational left( void ) const;
    Rational right( void ) const;

private:
    Rational theLeft, theRight;
};

std::ostream & operator<<( std::ostream &os, Real const &q );

#endif // REAL_H
