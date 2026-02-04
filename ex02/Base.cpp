#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate(void)
{
    int gen;

    gen = rand() % 3;
    switch (gen)
    {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
    }
    return (NULL);
}

void Base::identify(Base& p)
{
    try {
        A& a= dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(std::exception& e) {}

    try {
        B& b= dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch(std::exception& e) {}

    try {
        C& c= dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch(std::exception& e) {}
}

void Base::identify(Base* p)
{
    A* a= dynamic_cast<A*>(p);
    B* b= dynamic_cast<B*>(p);
    C* c= dynamic_cast<C*>(p);
    (void)c;
    if (a)
        std::cout << "A" << std::endl;
    else if (b)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl; 
}
Base::~Base()
{

}