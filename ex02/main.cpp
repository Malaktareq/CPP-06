#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    // Seed random generator
    std::srand(std::time(NULL));

    // Generate a random Base pointer (A, B, or C)
    Base* p = generate();
    Base* a = generate();
    Base* r = generate();
    // Identify using pointer
    identify(p);
    identify(a);
    identify(r);
    // Identify using reference
    identify(*p);

    // Clean up
    delete p;

    return 0;
}
