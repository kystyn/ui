#include <algorithm>
#include "real.h"

template<typename T1, typename T2>
T1 min( T1 val1, T2 val2 )
{
    return std::min(val1, val2);
}

template<typename T, typename ...Args>
T min( T val, Args... args )
{
    return std::min(val, min(args...));
}

template<typename T, typename ...Args>
T max( T val, Args... args )
{
    return -min(-val, (-args)...);
}

Real::Real() : theLeft(0), theRight(0)
{
}

Real::Real( const Real &r ) :
    theLeft(r.theLeft), theRight(r.theRight)
{
}

Real::Real( const Rational &left, const Rational &right ) :
    theLeft(std::min(left, right)),
    theRight(std::max(left, right))
{
}

Real::Real( Rational const &r ) : theLeft(r), theRight(r)
{
}

Real & Real::byCenterAndRadius( Rational const &center,
                                Rational const &radius )
{
    int sgn = 2 * (radius > Rational(0)) - 1;
    theLeft = center - Rational(sgn) * radius;
    theRight = center + Rational(sgn) * radius;

    return *this;
}

Real & Real::operator=( Real const &r )
{
    theLeft = r.theLeft;
    theRight = r.theRight;
    return *this;
}

Real Real::operator+( Real const &r ) const
{
    return Real(theLeft + r.theLeft, theRight + r.theRight);
}

Real Real::operator-( Real const &r ) const
{
    return Real(theLeft - r.theRight, theRight - r.theLeft);
}

Real Real::operator*( Real const &r ) const
{
    return Real(
                min(theLeft * r.theLeft,
                    theLeft * r.theRight,
                    theRight * r.theLeft,
                    theRight * r.theRight),
                max(theLeft * r.theLeft,
                    theLeft * r.theRight,
                    theRight * r.theLeft,
                    theRight * r.theRight));
}

Real Real::operator/( Real const &r ) const
{
    return Real(
                min(theLeft / r.theLeft,
                    theLeft / r.theRight,
                    theRight / r.theLeft,
                    theRight / r.theRight),
                max(theLeft / r.theLeft,
                    theLeft / r.theRight,
                    theRight / r.theLeft,
                    theRight / r.theRight));

}

Real Real::operator-( void ) const
{
    return Real(-theRight, -theLeft);
}

Real & Real::operator+=( Real const &r )
{
    theLeft += r.theLeft;
    theRight += r.theRight;
    return *this;
}

Real & Real::operator-=( Real const &r )
{
    theLeft -= r.theLeft;
    theRight -= r.theRight;
    return *this;
}

Real & Real::operator*=( Real const &r )
{
    theLeft = min(theLeft * r.theLeft,
        theLeft * r.theRight,
        theRight * r.theLeft,
        theRight * r.theRight);
    theRight = max(theLeft * r.theLeft,
        theLeft * r.theRight,
        theRight * r.theLeft,
        theRight * r.theRight);
    return *this;
}

Real & Real::operator/=( Real const &r )
{
    theLeft = min(theLeft / r.theLeft,
        theLeft / r.theRight,
        theRight / r.theLeft,
        theRight / r.theRight);
    theRight = max(theLeft / r.theLeft,
        theLeft / r.theRight,
        theRight / r.theLeft,
        theRight / r.theRight);

    return *this;
}

bool Real::operator<( Real const &q ) const
{
    return theRight < q.theLeft;
}

bool Real::operator<=( Real const &q ) const
{
    return *this < q || *this == q;
}

bool Real::operator>( Real const &q ) const
{
    return theLeft > q.theRight;
}

bool Real::operator>=( Real const &q ) const
{
    return *this > q || *this == q;
}

bool Real::operator==( Real const &q ) const
{
    return
            q.theLeft <= theRight ||
            theLeft <= q.theRight;
}

Real::operator float( void ) const
{
    return float((theLeft + theRight) / Rational(2));
}

Real::operator double( void ) const
{
    return double((theLeft + theRight) / Rational(2));
}

Rational Real::left( void ) const
{
    return theLeft;
}

Rational Real::right( void ) const
{
    return theRight;
}

std::ostream & operator<<( std::ostream &os, const Real &q )
{
    // ? os << double(q);
    // or:
    os << '[' << q.left() << "; " << q.right() << ']';
    return os;
}
