#include <iostream>

#include "rational.h"

int main()
{
    Rational
            r1(-1, 2),
            r2(-3, 4);
    std::cout << r1 + r2 << "\n" <<
                 r1 - r2 << "\n" <<
                 r1 * r2 << "\n" <<
                 r1 / r2 << std::endl;
    return 0;
}
