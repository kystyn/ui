#ifndef TESTER_H_
#define TESTER_H_

#include <string>
#include <iostream>

bool allPassed = true;

template<class ...args>
void test( std::string const &testName, bool (*f)(args...), args... arg )
{
    auto res = f(arg...);
    if (!res)
        allPassed = false;
    std::cout << testName << ": " << (res ? "PASSED" : "FAILED") << "\n";
}

#endif /* TESTER_H */
