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
    return min(val, args...);
}

template<typename T, typename ...Args>
T max( T val, Args... args )
{
    return -max(-val, (-args)...);
}

Real::Real()
{

}

Real::Real( const Rational &left, const Rational &right ) :
    theLeft(std::min(left, right)),
    theRight(std::max(left, right))
{
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
    return theLeft <= q.theLeft && q.theLeft <= theRight;
}

bool Real::operator>( Real const &q ) const
{
    return theLeft > q.theRight;
}

// think about <=, >=, ==

bool Real::operator>=( Real const &q ) const
{
    return theRight >= q.theRight;
}

bool Real::operator==( Real const &q ) const
{
    return *this <= q && *this >= q;
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
