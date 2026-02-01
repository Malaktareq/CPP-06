#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * Base::generate(void)
{
    int gen;

    gen = rand() % 3;
    switch (gen)
    {
        case 0:
            return new A;
        
    }
}