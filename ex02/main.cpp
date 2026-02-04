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
    Base* p = Base::generate();
    Base* a = Base::generate();
    Base* r = Base::generate();
    // Identify using pointer
    Base::identify(p);
    Base::identify(a);
    Base::identify(r);
    // Identify using reference
    Base::identify(*p);

    // Clean up
    delete p;

    return 0;
}
